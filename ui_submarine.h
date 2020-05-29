/********************************************************************************
** Form generated from reading UI file 'submarine.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBMARINE_H
#define UI_SUBMARINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_Submarine
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *forward;
    QHBoxLayout *horizontalLayout;
    QPushButton *left;
    QPushButton *stop;
    QPushButton *right;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *up;
    QPushButton *down;
    QPushButton *infobutton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *rpmLayout;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *currentLayout;
    QSlider *verticalSlider;
    QTextBrowser *textBrowser;
    QVideoWidget *videoWidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *voltageLayout;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *speedLayout;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *pumpLayout;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *headingLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Submarine)
    {
        if (Submarine->objectName().isEmpty())
            Submarine->setObjectName(QString::fromUtf8("Submarine"));
        Submarine->resize(1920, 960);
        Submarine->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(Submarine);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(460, 800, 397, 67));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        forward = new QPushButton(layoutWidget);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 255, 0);"));

        verticalLayout->addWidget(forward);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        left = new QPushButton(layoutWidget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 169, 19);"));

        horizontalLayout->addWidget(left);

        stop = new QPushButton(layoutWidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(stop);

        right = new QPushButton(layoutWidget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 169, 19);"));

        horizontalLayout->addWidget(right);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(880, 800, 95, 65));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        up = new QPushButton(layoutWidget1);
        up->setObjectName(QString::fromUtf8("up"));
        up->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 193, 193);"));

        verticalLayout_2->addWidget(up);

        down = new QPushButton(layoutWidget1);
        down->setObjectName(QString::fromUtf8("down"));
        down->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 193, 193);"));

        verticalLayout_2->addWidget(down);

        infobutton = new QPushButton(centralwidget);
        infobutton->setObjectName(QString::fromUtf8("infobutton"));
        infobutton->setGeometry(QRect(990, 800, 61, 61));
        infobutton->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 193, 193);"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 570, 241, 221));
        rpmLayout = new QHBoxLayout(horizontalLayoutWidget);
        rpmLayout->setObjectName(QString::fromUtf8("rpmLayout"));
        rpmLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 339, 241, 221));
        currentLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        currentLayout->setObjectName(QString::fromUtf8("currentLayout"));
        currentLayout->setContentsMargins(0, 0, 0, 0);
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(270, 630, 22, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(1060, 800, 471, 61));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        videoWidget = new QVideoWidget(centralwidget);
        videoWidget->setObjectName(QString::fromUtf8("videoWidget"));
        videoWidget->setGeometry(QRect(330, 50, 1280, 720));
        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 110, 241, 221));
        voltageLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        voltageLayout->setObjectName(QString::fromUtf8("voltageLayout"));
        voltageLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(1650, 570, 241, 221));
        speedLayout = new QHBoxLayout(horizontalLayoutWidget_4);
        speedLayout->setObjectName(QString::fromUtf8("speedLayout"));
        speedLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_5 = new QWidget(centralwidget);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(1650, 330, 241, 221));
        pumpLayout = new QHBoxLayout(horizontalLayoutWidget_5);
        pumpLayout->setObjectName(QString::fromUtf8("pumpLayout"));
        pumpLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_6 = new QWidget(centralwidget);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(1640, 50, 261, 261));
        headingLayout = new QHBoxLayout(horizontalLayoutWidget_6);
        headingLayout->setObjectName(QString::fromUtf8("headingLayout"));
        headingLayout->setContentsMargins(0, 0, 0, 0);
        Submarine->setCentralWidget(centralwidget);
        videoWidget->raise();
        layoutWidget1->raise();
        layoutWidget1->raise();
        infobutton->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        verticalSlider->raise();
        textBrowser->raise();
        horizontalLayoutWidget_3->raise();
        horizontalLayoutWidget_4->raise();
        horizontalLayoutWidget_5->raise();
        horizontalLayoutWidget_6->raise();
        menubar = new QMenuBar(Submarine);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 26));
        Submarine->setMenuBar(menubar);
        statusbar = new QStatusBar(Submarine);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Submarine->setStatusBar(statusbar);

        retranslateUi(Submarine);

        QMetaObject::connectSlotsByName(Submarine);
    } // setupUi

    void retranslateUi(QMainWindow *Submarine)
    {
        Submarine->setWindowTitle(QCoreApplication::translate("Submarine", "Submarine", nullptr));
        forward->setText(QCoreApplication::translate("Submarine", "Throttle Up", nullptr));
        left->setText(QCoreApplication::translate("Submarine", "Rudder Left", nullptr));
        stop->setText(QCoreApplication::translate("Submarine", "Throttle Down", nullptr));
        right->setText(QCoreApplication::translate("Submarine", "Rudder Right", nullptr));
        up->setText(QCoreApplication::translate("Submarine", "Elevator Up", nullptr));
        down->setText(QCoreApplication::translate("Submarine", "Elevator Down", nullptr));
        infobutton->setText(QCoreApplication::translate("Submarine", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Submarine: public Ui_Submarine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBMARINE_H
