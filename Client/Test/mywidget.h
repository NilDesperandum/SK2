#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTimer>
#include <QLCDNumber>
#include <QApplication>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

protected:
    int time;
    QTcpSocket * sock;
    QTimer * connTimeoutTimer;
    QTimer* answerTimer;
    void connectBtnHit();
    void socketConnected();
    void socketDisconnected();
    void socketError(QTcpSocket::SocketError);
    void socketReadable();
    void sendBtnHit();
    void testKlik();
    void SomeBtnHit();
    void firstBtnHit();
    void secondBtnHit();
    void thirdBtnHit();
    void fourthBtnHit();
    void LcdUpdate();
private:
    Ui::MyWidget * ui;


};

#endif // MYWIDGET_H
