#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTimer>
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
    int counter = 0;
    QTcpSocket * sock;
    QTimer * connTimeoutTimer;
    void connectBtnHit();
    void socketConnected();
    void socketDisconnected();
    void socketError(QTcpSocket::SocketError);
    void socketReadable();
    void sendBtnHit();
    void testKlik();
    void updateUI();
    void firstBtnHit();
    void secondBtnHit();
    void thirdBtnHit();
    void fourthBtnHit();
private:
    Ui::MyWidget * ui;


};

#endif // MYWIDGET_H
