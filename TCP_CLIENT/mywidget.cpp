#include "mywidget.h"
#include "ui_mywidget.h"

#include <QMessageBox>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyWidget) {
    ui->setupUi(this);

    connect(ui->conectBtn, &QPushButton::clicked, this, &MyWidget::connectBtnHit);
    connect(ui->hostLineEdit, &QLineEdit::returnPressed, ui->conectBtn, &QPushButton::click);

    connect(ui->firstBtn, &QPushButton::clicked, this, &MyWidget::firstBtnHit);
    connect(ui->secondBtn, &QPushButton::clicked, this, &MyWidget::secondBtnHit);
    connect(ui->thirdBtn, &QPushButton::clicked, this, &MyWidget::thirdBtnHit);
    connect(ui->fourthBtn, &QPushButton::clicked, this, &MyWidget::fourthBtnHit);
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
    ui->talkGroup->setEnabled(true);
}

void MyWidget::socketDisconnected(){
    ui->msgsTextEdit->append("<b>Disconnected</b>");
    ui->talkGroup->setEnabled(false);
}

void MyWidget::socketError(QTcpSocket::SocketError err){
    if(err == QTcpSocket::RemoteHostClosedError)
        return;
    QMessageBox::critical(this, "Error", sock->errorString());
    ui->msgsTextEdit->append("<b>Socket error: "+sock->errorString()+"</b>");
    ui->talkGroup->setEnabled(false);
}

void MyWidget::socketReadable(){
    QByteArray ba = sock->readAll();
    QList<QByteArray> ga = ba.split('*');
  //  if (counter == 0){
        ui->questionLabel->setText(QString::fromUtf8(ga[0]).trimmed());
        ui->questionLabel->setAlignment(Qt::AlignCenter);
        ui->firstBtn->setText(QString::fromUtf8(ga[1]).trimmed());
        ui->secondBtn->setText(QString::fromUtf8(ga[2]).trimmed());
        ui->thirdBtn->setText(QString::fromUtf8(ga[3]).trimmed());
        ui->fourthBtn->setText(QString::fromUtf8(ga[4]).trimmed());
        ui->talkGroup->setEnabled(true);
       /* this->setEnabled(false);
        ui->msgsTextEdit->append("<b>Odebralem</b>");
        ui->msgsTextEdit->append(ga[0]);
        updateUI();
        this->setEnabled(true);*/
 //       counter++;
    /*}
    else if (counter == 1){
        ui->firstBtn->setText(QString::fromUtf8(ba).trimmed());
        counter++;
    }
    else if (counter == 2){
        ui->secondBtn->setText(QString::fromUtf8(ba).trimmed());
        counter++;
    }
    else if (counter == 3){
        ui->thirdBtn->setText(QString::fromUtf8(ba).trimmed());
        counter++;
    }
    else if (counter == 4){
        ui->fourthBtn->setText(QString::fromUtf8(ba).trimmed());
        counter = 0;
    }*/
    //ui->msgsTextEdit->append(QString::fromUtf8(ba).trimmed());
    //ui->msgsTextEdit->setAlignment(Qt::AlignLeft);
}

void MyWidget::updateUI(){
    if(this->isEnabled()) return;

    this->repaint();
    qApp -> processEvents();
}

void MyWidget::firstBtnHit(){
    QString txt = ui->firstBtn->text().trimmed();
    sock->write(txt.toUtf8());

    ui->talkGroup->setEnabled(false);

   // ui->msgsTextEdit->append("<span style=\"color: blue\">"+txt+"</span>");
    //ui->msgsTextEdit->setAlignment(Qt::AlignRight);

  //  ui->msgLineEdit->clear();
  //  ui->msgLineEdit->setFocus();
}

void MyWidget::secondBtnHit(){
    QString txt = ui->secondBtn->text().trimmed();
    sock->write(txt.toUtf8());

    ui->talkGroup->setEnabled(false);

    /*ui->msgsTextEdit->append("<span style=\"color: blue\">"+txt+"</span>");
    ui->msgsTextEdit->setAlignment(Qt::AlignRight);

    ui->msgLineEdit->clear();
    ui->msgLineEdit->setFocus();*/
}

void MyWidget::thirdBtnHit(){
    QString txt = ui->thirdBtn->text().trimmed();
    sock->write(txt.toUtf8());

    ui->talkGroup->setEnabled(false);

    /*ui->msgsTextEdit->append("<span style=\"color: blue\">"+txt+"</span>");
    ui->msgsTextEdit->setAlignment(Qt::AlignRight);

    ui->msgLineEdit->clear();
    ui->msgLineEdit->setFocus();*/
}

void MyWidget::fourthBtnHit(){
    QString txt = ui->fourthBtn->text().trimmed();
    sock->write(txt.toUtf8());

    ui->talkGroup->setEnabled(false);

   /* ui->msgsTextEdit->append("<span style=\"color: blue\">"+txt+"</span>");
    ui->msgsTextEdit->setAlignment(Qt::AlignRight);

    ui->msgLineEdit->clear();
    ui->msgLineEdit->setFocus();*/
}
