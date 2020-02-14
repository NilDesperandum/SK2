#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <error.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <poll.h> 
#include <thread>
#include <unordered_set>
#include <signal.h>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define POLL_MAX_VALUE 51
#define ANSWER_TIME 30
#define TIME_TO_START 60

using namespace std;
// server socket
bool serverWait = true;
int servFd;
int countCustomers = 1;
int offsetPoints = 0;
int actualAnswer = 0;
pollfd polltab[POLL_MAX_VALUE]{};
string pytania[10] = {"Jakie miasto jest stolicą Portugalii ?","Jakie miasto jest stolicą Indii ?","Jakie miasto jest stolicą Szwecji ?",
"Stolicą jakiego kraju jest Bangkok ?","Jakie miasto jest stolicą Rosji ?","Stolicą jakiego państwa jest Canberra ?",
"Stolicą jakiego państwa jest Nikozja ?","Jakie miasto jest stolicą Łotwy ?","Jakie miasto jest stolicą Argentyny ?",
"Jakie miasto jest siedzibą rządu Szwajcarii ?"};
string const odpowiedziA[10]= {"Lizbona","Delhi","Kopenhaga","Wietnamu","Nowosybirsk","Walii","Maroko","Ryga","Buenos Aires","Genewa"};
string const odpowiedziB[10]= {"Madryt","Mumbaj","Sztokholm","Malezji","Jekaterynburg","Urugwaju","Malty","Wilno","La Plata","Berno"};
string const odpowiedziC[10]= {"Barcelona","New Dehli","Helsinki","Tajlandii","Petersburg","Australii","Cypru","Tallinn","Rio de Janeiro","Zurych"};
string const odpowiedziD[10]= {"Ankara","Madras","Oslo","Laosu","Moskwa","Monako","Grecji","Mińsk","Los Angeles","Lucerna"};
string const poprawne[10]= {"Lizbona","New Dehli","Sztokholm","Tajlandii","Moskwa","Australii","Cypru","Ryga","Buenos Aires","Berno"};
std::vector< std::pair<int,int> > clientPoints;
// client sockets
std::unordered_set<int> clientFds;

// handles SIGINT
void ctrl_c(int);

// sends data to clientFds excluding fd
void sendToAllBut(int fd, char * buffer, int count);

// converts cstring to port
uint16_t readPort(char * txt);

// sets SO_REUSEADDR
void setReuseAddr(int sock);

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
	return (a.second > b.second);
}

void kontrolaCzasu(){
	sleep(TIME_TO_START);
	serverWait = false;
	offsetPoints = countCustomers;
	string temp;
	char* buffer;
	for(int i = 0;i<10;i++){
		actualAnswer = i;
		offsetPoints = 0;
		temp = pytania[i];
		temp = temp + "*" + odpowiedziA[i]+"*"+odpowiedziB[i]+"*"+odpowiedziC[i]+"*"+odpowiedziD[i];
		buffer = &temp[0];
		printf("Wysylam\n");
		sendToAllBut(servFd,buffer,strlen(buffer));
		sleep(ANSWER_TIME);
	}
	cout<<"Koniec"<<endl;
	for(auto &id: clientPoints){
		cout<< id.first << "  "<<id.second<<endl;
	}
	sort(clientPoints.begin(),clientPoints.end(),sortbysec);
	for(int i=0;i<(int)clientPoints.size();i++){
		temp = "QA";
		temp = temp +"Id: "+to_string(clientPoints[i].first)+" Punkty: "+to_string(clientPoints[i].second)+"*";
		buffer = &temp[0];
		sendToAllBut(servFd,buffer,strlen(buffer));
	}
	ctrl_c(1);
}

void deleteClient(int clientFd){
	int index = 0;
	for(int i=0;i < (int)clientPoints.size();i++){
		if(clientPoints[i].first == clientFd){
			index = i;
		}
	}
	clientPoints.erase(clientPoints.begin()+index);
	for(int i=0;i<POLL_MAX_VALUE;i++){
		if(polltab[i].fd == clientFd){
			polltab[i].fd = clientFd * (-1);
		}
	}
	clientFds.erase(clientFd);
	close(clientFd);
}

void newAnswer(int clientFd){
	char buffer[20];
	int count = read(clientFd, buffer, 20);
	if(count >= 0 ){
		buffer[count]='\n';
	}
	string temp = "";
	for(int i =0;i< 20;i++){
		if(buffer[i] == '\n'){ break;}
		temp += buffer[i];
	}
	if(temp==""){
		deleteClient(clientFd);
	}
	for(auto &id : clientPoints){
		if(id.first == clientFd){
			cout << "answer:"<<temp<<endl;
			if(temp == poprawne[actualAnswer]){
				id.second += (countCustomers-offsetPoints);
				offsetPoints += 1;
			}
		}
	}
}

void newClient(){
// prepare placeholders for client address
	sockaddr_in clientAddr{0};
	socklen_t clientAddrSize = sizeof(clientAddr);

	// accept new connection
	auto clientFd = accept(servFd, (sockaddr*) &clientAddr, &clientAddrSize);
	if(clientFd == -1) error(1, errno, "accept failed");
	
	if(countCustomers < POLL_MAX_VALUE && serverWait){	
	// add client to all clients set
	clientFds.insert(clientFd);
	clientPoints.push_back(make_pair(clientFd,0));
	polltab[countCustomers].fd=clientFd;
	polltab[countCustomers].events=POLLIN;
	countCustomers++;
	string temp = "ID";
	temp = temp + "Twoje Id to: "+to_string(clientFd);
	char* buffer = &temp[0];
	write(clientFd,buffer,strlen(buffer));
	// tell who has connected
	printf("new connection from: %s:%hu (fd: %d)\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), clientFd);
	}
	else{
		cout << "Brak miejsca dla nowego gracza!"<<endl;
		close(clientFd);
	}
	if(countCustomers == 3){
		std::thread(kontrolaCzasu).detach();
	}
}

int main(int argc, char ** argv){
	// get and validate port number
	if(argc != 2) error(1, 0, "Need 1 arg (port)");
	auto port = readPort(argv[1]);	

	// create socket
	servFd = socket(AF_INET, SOCK_STREAM, 0);
	if(servFd == -1) error(1, errno, "socket failed");
	
	// graceful ctrl+c exit
	signal(SIGINT, ctrl_c);
	// prevent dead sockets from throwing pipe errors on write
	signal(SIGPIPE, SIG_IGN);
	
	setReuseAddr(servFd);
	
	// bind to any address and port provided in arguments
	sockaddr_in serverAddr{.sin_family=AF_INET, .sin_port=htons((short)port), .sin_addr={INADDR_ANY}};
	int res = bind(servFd, (sockaddr*) &serverAddr, sizeof(serverAddr));
	if(res) error(1, errno, "bind failed");
	
	// enter listening mode
	res = listen(servFd, 1);
	if(res) error(1, errno, "listen failed");
	
	polltab[0].fd=servFd;
	polltab[0].events=POLLIN;
	
	while(true){
		poll(polltab,POLL_MAX_VALUE,-1);
	
		for(pollfd & opis : polltab) {       
			if(opis.revents & POLLIN) { 
			  if(opis.fd == servFd) {          
				newClient(); 
				}   
			  if(opis.fd != servFd){
				newAnswer(opis.fd);		
				}		
			}
		}
	}
}

uint16_t readPort(char * txt){
	char * ptr;
	auto port = strtol(txt, &ptr, 10);
	if(*ptr!=0 || port<1 || (port>((1<<16)-1))) error(1,0,"illegal argument %s", txt);
	return port;
}

void setReuseAddr(int sock){
	const int one = 1;
	int res = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
	if(res) error(1,errno, "setsockopt failed");
}

void ctrl_c(int){
	for(int clientFd : clientFds)
		close(clientFd);
	close(servFd);
	printf("Closing server\n");
	exit(0);
}

void sendToAllBut(int fd, char * buffer, int count){
	int res;
	decltype(clientFds) bad;
	for(int clientFd : clientFds){
		if(clientFd == fd) continue;
		res = write(clientFd, buffer, count);
		if(res == -1)
			bad.insert(clientFd);
	}
	for(int clientFd : bad){
		printf("removing %d\n", clientFd);
		clientFds.erase(clientFd);
		close(clientFd);
	}
}