#include "mywidget.h"
#include "ui_mywidget.h"
#include <QMessageBox>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyWidget) {
    ui->setupUi(this);

    connect(ui->conectBtn, &QPushButton::clicked, this, &MyWidget::connectBtnHit);
    connect(ui->hostLineEdit, &QLineEdit::returnPressed, ui->conectBtn, &QPushButton::click);

    connect(ui->firstBtn, &QPushButton::clicked, this, &MyWidget::SomeBtnHit);
    connect(ui->secondBtn, &QPushButton::clicked, this, &MyWidget::SomeBtnHit);
    connect(ui->thirdBtn, &QPushButton::clicked, this, &MyWidget::SomeBtnHit);
    connect(ui->fourthBtn, &QPushButton::clicked, this, &MyWidget::SomeBtnHit);
}

MyWidget::~MyWidget() {
    sock->close();
    delete ui;
}

void MyWidget::connectBtnHit(){
    ui->connectGroup->setEnabled(false);
    ui->msgsTextEdit->append("<b>Connecting to " + ui->hostLineEdit->text() + ":" + QString::number(ui->portSpinBox->value())+"</b>");
    sock = new QTcpSocket(this);
    connTimeoutTimer = new QTimer(this);
    connTimeoutTimer->setSingleShot(true);
    connect(connTimeoutTimer, &QTimer::timeout,this,&MyWidget::testKlik);
    answerTimer = new QTimer(this);
    connect(answerTimer,&QTimer::timeout,this,&MyWidget::LcdUpdate);

    connect(sock, &QTcpSocket::connected, this, &MyWidget::socketConnected);
    connect(sock, &QTcpSocket::disconnected, this, &MyWidget::socketDisconnected);
    connect(sock, (void(QTcpSocket::*)(QTcpSocket::SocketError)) &QTcpSocket::error, this, &MyWidget::socketError);
    connect(sock, &QTcpSocket::readyRead, this, &MyWidget::socketReadable);

    sock->connectToHost(ui->hostLineEdit->text(), ui->portSpinBox->value());
    connTimeoutTimer->start(3000);
}

void MyWidget::testKlik(){
    sock->abort();
    sock->deleteLater();
    connTimeoutTimer->deleteLater();
    ui->connectGroup->setEnabled(true);
    ui->msgsTextEdit->append("<b>Connect timed out</b>");
    QMessageBox::critical(this, "Error", "Connect timed out");
}

void MyWidget::socketConnected(){
    connTimeoutTimer->stop();
    connTimeoutTimer->deleteLater();
    ui->talkGroup->setEnabled(false);
}

void MyWidget::socketDisconnected(){
    ui->msgsTextEdit->append("<b>Disconnected</b>");
    ui->connectGroup->setEnabled(true);
    ui->talkGroup->setEnabled(false);
    ui->conectBtn->setEnabled(false);
    ui->hostLineEdit->setEnabled(false);
    ui->portSpinBox->setEnabled(false);
}

void MyWidget::socketError(QTcpSocket::SocketError err){
    if(err == QTcpSocket::RemoteHostClosedError)
        return;
    QMessageBox::critical(this, "Error", sock->errorString());
    ui->msgsTextEdit->append("<b>Socket error: "+sock->errorString()+"</b>");
    ui->talkGroup->setEnabled(false);
}

void MyWidget::LcdUpdate(){
    ui->lcdNumber->display(time);
    if ( time == 1 ){
        answerTimer -> stop();
        time -= 1;
    } else{
        time -= 1;
    }
}

void MyWidget::socketReadable(){
    QByteArray ba = sock->readAll();
    QList<QByteArray> ga;
    if(ba.startsWith("QA")){
        ui->talkGroup->setEnabled(false);
        ga = ba.split('*');
        for(int i =0;i<ga.size();i++){
            ui->msgsTextEdit->append("<b>"+ga[i].mid(2)+"</b>");
        }
        ui->msgsTextEdit->setEnabled(true);
    }else if(ba.startsWith("ID")){
        ui->msgsTextEdit->append("<b>"+ba.mid(2)+"</b>");
    }
    else{
        ga = ba.split('*');
        ui->questionLabel->setText(QString::fromUtf8(ga[0]).trimmed());
        ui->questionLabel->setAlignment(Qt::AlignCenter);
        ui->firstBtn->setText(QString::fromUtf8(ga[1]).trimmed());
        ui->secondBtn->setText(QString::fromUtf8(ga[2]).trimmed());
        ui->thirdBtn->setText(QString::fromUtf8(ga[3]).trimmed());
        ui->fourthBtn->setText(QString::fromUtf8(ga[4]).trimmed());
        ui->talkGroup->setEnabled(true);
        time = 29;
        answerTimer->start(1000);
     }
}

void MyWidget::SomeBtnHit(){
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    if(button == NULL){
        qWarning("SomeBtnHit called not by a QPushButton");
        return;
    }
    QString txt = button->text().trimmed();
    sock->write(txt.toUtf8());

    ui->talkGroup->setEnabled(false);
}
