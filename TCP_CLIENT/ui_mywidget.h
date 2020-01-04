/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *connectGroup;
    QHBoxLayout *horizontalLayout;
    QTextEdit *msgsTextEdit;
    QLineEdit *hostLineEdit;
    QSpinBox *portSpinBox;
    QPushButton *conectBtn;
    QGroupBox *talkGroup;
    QGridLayout *gridLayout;
    QPushButton *fourthBtn;
    QLabel *questionLabel;
    QPushButton *firstBtn;
    QPushButton *thirdBtn;
    QPushButton *secondBtn;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(1330, 565);
        verticalLayout = new QVBoxLayout(MyWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        connectGroup = new QGroupBox(MyWidget);
        connectGroup->setObjectName(QStringLiteral("connectGroup"));
        horizontalLayout = new QHBoxLayout(connectGroup);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        msgsTextEdit = new QTextEdit(connectGroup);
        msgsTextEdit->setObjectName(QStringLiteral("msgsTextEdit"));
        msgsTextEdit->setMaximumSize(QSize(500, 100));

        horizontalLayout->addWidget(msgsTextEdit, 0, Qt::AlignTop);

        hostLineEdit = new QLineEdit(connectGroup);
        hostLineEdit->setObjectName(QStringLiteral("hostLineEdit"));
        hostLineEdit->setMaximumSize(QSize(400, 16777215));

        horizontalLayout->addWidget(hostLineEdit);

        portSpinBox = new QSpinBox(connectGroup);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setMaximumSize(QSize(200, 16777215));
        portSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        portSpinBox->setMinimum(1);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(8080);

        horizontalLayout->addWidget(portSpinBox);

        conectBtn = new QPushButton(connectGroup);
        conectBtn->setObjectName(QStringLiteral("conectBtn"));
        conectBtn->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(conectBtn);


        verticalLayout->addWidget(connectGroup);

        talkGroup = new QGroupBox(MyWidget);
        talkGroup->setObjectName(QStringLiteral("talkGroup"));
        talkGroup->setEnabled(false);
        gridLayout = new QGridLayout(talkGroup);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        fourthBtn = new QPushButton(talkGroup);
        fourthBtn->setObjectName(QStringLiteral("fourthBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fourthBtn->sizePolicy().hasHeightForWidth());
        fourthBtn->setSizePolicy(sizePolicy);
        fourthBtn->setMaximumSize(QSize(300, 50));

        gridLayout->addWidget(fourthBtn, 5, 0, 1, 1, Qt::AlignHCenter);

        questionLabel = new QLabel(talkGroup);
        questionLabel->setObjectName(QStringLiteral("questionLabel"));
        sizePolicy.setHeightForWidth(questionLabel->sizePolicy().hasHeightForWidth());
        questionLabel->setSizePolicy(sizePolicy);
        questionLabel->setMaximumSize(QSize(1000, 100));

        gridLayout->addWidget(questionLabel, 0, 0, 1, 1);

        firstBtn = new QPushButton(talkGroup);
        firstBtn->setObjectName(QStringLiteral("firstBtn"));
        sizePolicy.setHeightForWidth(firstBtn->sizePolicy().hasHeightForWidth());
        firstBtn->setSizePolicy(sizePolicy);
        firstBtn->setMaximumSize(QSize(300, 50));

        gridLayout->addWidget(firstBtn, 1, 0, 1, 1, Qt::AlignHCenter);

        thirdBtn = new QPushButton(talkGroup);
        thirdBtn->setObjectName(QStringLiteral("thirdBtn"));
        sizePolicy.setHeightForWidth(thirdBtn->sizePolicy().hasHeightForWidth());
        thirdBtn->setSizePolicy(sizePolicy);
        thirdBtn->setMaximumSize(QSize(300, 50));

        gridLayout->addWidget(thirdBtn, 4, 0, 1, 1, Qt::AlignHCenter);

        secondBtn = new QPushButton(talkGroup);
        secondBtn->setObjectName(QStringLiteral("secondBtn"));
        sizePolicy.setHeightForWidth(secondBtn->sizePolicy().hasHeightForWidth());
        secondBtn->setSizePolicy(sizePolicy);
        secondBtn->setMaximumSize(QSize(300, 50));

        gridLayout->addWidget(secondBtn, 2, 0, 1, 1, Qt::AlignHCenter);


        verticalLayout->addWidget(talkGroup);

        QWidget::setTabOrder(portSpinBox, hostLineEdit);
        QWidget::setTabOrder(hostLineEdit, conectBtn);

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "Simple TCP client", 0));
        connectGroup->setTitle(QString());
        hostLineEdit->setText(QApplication::translate("MyWidget", "localhost", 0));
        conectBtn->setText(QApplication::translate("MyWidget", "connect", 0));
        talkGroup->setTitle(QString());
        fourthBtn->setText(QApplication::translate("MyWidget", "Odpowiedz 4", 0));
        questionLabel->setText(QApplication::translate("MyWidget", "Pytanie", 0));
        firstBtn->setText(QApplication::translate("MyWidget", "Odpowiedz 1", 0));
        thirdBtn->setText(QApplication::translate("MyWidget", "Odpowiedz 3", 0));
        secondBtn->setText(QApplication::translate("MyWidget", "Odpowiedz 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
