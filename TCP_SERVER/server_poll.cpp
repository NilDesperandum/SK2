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

using namespace std;
// server socket
bool serverWait = true;
int servFd;
int countCustomers = 1;
pollfd polltab[51]{};
string pytania[10] = {"Jakie miasto jest stolicą Portugalii ?","Jakie miasto jest stolicą Indii ?","Jakie miasto jest stolicą Szwecji ?",
"Stolicą jakiego kraju jest Bangkok ?","Jakie miasto jest stolicą Rosji ?","Stolicą jakiego państwa jest Canberra ?",
"Stolicą jakiego państwa jest Nikozja ?","Jakie miasto jest stolicą Łotwy ?","Jakie miasto jest stolicą Argentyny ?",
"Jakie miasto jest siedzibą rządu Szwajcarii ?"};
string const odpowiedziA[10]= {"Lizbona","Delhi","Kopenhaga","Wietnamu","Nowosybirsk","Walii","Maroko","Ryga","Buenos Aires","Genewa"};
string const odpowiedziB[10]= {"Madryt","Mumbaj","Sztokholm","Malezji","Jekaterynburg","Urugwaju","Malty","Wilno","La Plata","Berno"};
string const odpowiedziC[10]= {"Barcelona","New Dehli","Helsinki","Tajlandii","Petersburg","Australii","Cypru","Tallinn","Rio de Janeiro","Zurych"};
string const odpowiedziD[10]= {"Ankara","Madras","Oslo","Laosu","Moskwa","Monako","Grecji","Mińsk","Los Angeles","Lucerna"};
string const poprawne[10]= {"Lizbona","New Dehli","Sztokholm","Tajlandii","Moskwa","Australii","Cypru","Ryga","Buenos Aires","Berno"};

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

void kontrolaCzasu(){
	while(countCustomers < 3){};
	sleep(10);
	serverWait = false;
	string temp;
	char* buffer;
	for(int i = 0;i<10;i++){
		temp = pytania[i];
		temp = temp + "*" + odpowiedziA[i]+"*"+odpowiedziB[i]+"*"+odpowiedziC[i]+"*"+odpowiedziD[i];
		buffer = &temp[0];
		printf("Wysylam\n");
		sendToAllBut(servFd,buffer,255);
		sleep(10);
	}
	
	/*sendToAllBut(servFd, pytania[0],255);
	sleep(1);
	sendToAllBut(servFd, odpowiedziA[0],255);
	sleep(1);
	sendToAllBut(servFd, odpowiedziB[0],255);
	sleep(1);
	sendToAllBut(servFd, odpowiedziC[0],255);
	sleep(1);
	sendToAllBut(servFd, odpowiedziD[0],255);*/
}

void newAnswer(int clientFd){
	char buffer[20];
	int count = read(clientFd, buffer, 20);
	buffer[count]='\n';
	write(1,buffer,count+1);
}

void newClient(){
// prepare placeholders for client address
	sockaddr_in clientAddr{0};
	socklen_t clientAddrSize = sizeof(clientAddr);

	// accept new connection
	auto clientFd = accept(servFd, (sockaddr*) &clientAddr, &clientAddrSize);
	if(clientFd == -1) error(1, errno, "accept failed");
	
	if(countCustomers < 4 && serverWait){	
	// add client to all clients set
	clientFds.insert(clientFd);
	
	polltab[countCustomers].fd=clientFd;
	polltab[countCustomers].events=POLLIN;
	countCustomers++;
	// tell who has connected
	printf("new connection from: %s:%hu (fd: %d)\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), clientFd);
	}
	else{
		write(clientFd,"Error\n",6);
	}
}
void newMessage(int clientFd){
// read a message
	char buffer[255];
	int count = read(clientFd, buffer, 255);
	
	if(count < 1) {
		printf("removing %d\n", clientFd);
		clientFds.erase(clientFd);
		close(clientFd);
	} else {
		// broadcast the message
		sendToAllBut(clientFd, buffer, count);
	}
}

int main(int argc, char ** argv){
	// get and validate port number
	//if(argc != 2) error(1, 0, "Need 1 arg (port)"); --zmiana
	//auto port = readPort("8080");//readPort(argv[1]); -- zmiana
	uint16_t  port = 8080;	

	// create socket
	servFd = socket(AF_INET, SOCK_STREAM, 0);
	if(servFd == -1) error(1, errno, "socket failed");
	std::thread(kontrolaCzasu).detach();
	
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
	
/****************************/
	
	polltab[0].fd=servFd;
	polltab[0].events=POLLIN;
	
	while(true){
		/*int gotowe =*/ poll(polltab,51,-1);
	 	
	
		for(pollfd & opis : polltab) {        // \.
			if(opis.revents & POLLIN) { 
			  if(opis.fd == servFd) {           //  
				newClient(); 
				}   
			  if(opis.fd != servFd){
				newAnswer(opis.fd);		
				}		
			}
		}
	}
/****************************/
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
		if(res!=count)
			bad.insert(clientFd);
	}
	for(int clientFd : bad){
		printf("removing %d\n", clientFd);
		clientFds.erase(clientFd);
		close(clientFd);
	}
}