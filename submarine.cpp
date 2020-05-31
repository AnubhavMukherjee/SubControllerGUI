#include <QKeyEvent>
#include <QTextStream>
#include "submarine.h"
#include "ui_submarine.h"
#include <QShortcut>
#include <QSerialPort>
#include <QString>
#include <QDebug>
#include <string>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <qcgaugewidget.h>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QTimer>
#include <cstring>
#include <iostream>

using namespace std;


QSerialPort comm;                                           //declaration of object for the class Serial Port
QSerialPort *atmega328p=&comm;
QTimer *updateValue;
Submarine::Submarine(QWidget *parent): QMainWindow(parent), ui(new Ui::Submarine) // constructor

{
    ui->setupUi(this);

     valueStr = "";
     player = new QMediaPlayer;
//******************************************MEDIA-STREAM SECTION************************************
     video = new QVideoWidget;
     player->setVideoOutput(ui->videoWidget);
     //player->setMedia(QUrl::fromLocalFile("http://192.168.0.100:8080/video"));
     player->setMedia(QUrl::fromLocalFile("E:/hero.mp4"));
     //player->setMedia(QUrl::fromLocalFile(""));
     ui->videoWidget->setGeometry(330,50,1280,720);
     ui->videoWidget->show();
     player->play();
     qDebug()<<player->state();

//******************************************MEDIA-STREAM END*****************************************

//******************************************ATMEGA328P QSerialStart**********************************


     atmega328p->setPortName("COM3");
     atmega328p->setBaudRate(QSerialPort::Baud115200);
     atmega328p->setDataBits(QSerialPort::Data8);
     atmega328p->setParity(QSerialPort::NoParity);
     atmega328p->setStopBits(QSerialPort::OneStop);
     atmega328p->setFlowControl(QSerialPort::NoFlowControl);
     atmega328p->open(QIODevice::ReadWrite);
     QObject::connect(atmega328p, SIGNAL(readyRead()), this, SLOT(readSerial()));
     atmega328p->clear();
     //connect(updateValue,SIGNAL(&QTimer::timeout()),this,SLOT(readSerial()));
     //updateValue->start();

//*****************************************ATMEGA328P QSerial END***********************************

//*****************************************GAUGES-SETUP**********************************************

     rpmGauge = new QcGaugeWidget;
            rpmGauge->addArc(55);
            rpmGauge->addDegrees(65)->setValueRange(0,100);
            QcColorBand *clrBand0 = rpmGauge->addColorBand(50);
            clrBand0->setValueRange(0,100);
            rpmGauge->addValues(80)->setValueRange(0,100);
            rpmGauge->addLabel(70)->setText("RPM");
            QcLabelItem *lab0 = rpmGauge->addLabel(50);
            lab0->setText("TACHO");
            Needle0 = rpmGauge->addNeedle(60);
            Needle0->setLabel(lab0);
            Needle0->setColor(Qt::red);
            Needle0->setValueRange(0,100);
            rpmGauge->addBackground(7);
            ui->rpmLayout->addWidget(rpmGauge);

    currentGauge = new QcGaugeWidget;
            currentGauge->addArc(55); //Circular Arch dia.
            currentGauge->addDegrees(55)->setValueRange(0,100); //Size of splits - No. of splits.
            QcColorBand *clrBand1 = currentGauge->addColorBand(30);
            clrBand1->setValueRange(0,100);
            currentGauge->addValues(80)->setValueRange(0,50); //Outer Ring Text
            currentGauge->addLabel(70)->setText("Amperes");
            QcLabelItem *lab1 = currentGauge->addLabel(40);
            lab1->setText("Current");
            Needle1 = currentGauge->addNeedle(60); //Needle size
            Needle1->setLabel(lab1);
            Needle1->setColor(Qt::red);
            Needle1->setValueRange(0,100);
            currentGauge->addBackground(7);
            ui->currentLayout->addWidget(currentGauge);

    voltageGauge= new QcGaugeWidget;
             voltageGauge->addArc(55);
             voltageGauge->addDegrees(65)->setValueRange(0,100);
             QcColorBand *clrBand2 = voltageGauge->addColorBand(50); //here.
             clrBand2->setValueRange(0,100); //here.
             voltageGauge->addValues(80)->setValueRange(0,100);
             voltageGauge->addLabel(70)->setText("Volts");
             QcLabelItem *lab2 = voltageGauge->addLabel(50); //here.
             lab2->setText("Main Voltage");//here/
             Needle2 = voltageGauge->addNeedle(60);
             Needle2->setLabel(lab2);
             Needle2->setColor(Qt::red);
             Needle2->setValueRange(0,100);
             voltageGauge->addBackground(7);
             ui->voltageLayout->addWidget(voltageGauge);

    speedGauge = new QcGaugeWidget;
            speedGauge->addArc(55);
            speedGauge->addDegrees(65)->setValueRange(0,100);
            QcColorBand *clrBand3 = speedGauge->addColorBand(50);
            clrBand3->setValueRange(0,100);
            speedGauge->addValues(80)->setValueRange(0,100);
            speedGauge->addLabel(70)->setText("kts");
            QcLabelItem *lab3 = speedGauge->addLabel(50);
            lab3->setText("Speedometer");
            Needle3 = speedGauge->addNeedle(60);
            Needle3->setLabel(lab3);
            Needle3->setColor(Qt::red);
            Needle3->setValueRange(0,100);
            speedGauge->addBackground(7);
            ui->speedLayout->addWidget(speedGauge);


    pumpGauge = new QcGaugeWidget;
            pumpGauge->addArc(55); //Circular Arch dia.
            pumpGauge->addDegrees(55)->setValueRange(0,100); //Size of splits - No. of splits.
            QcColorBand *clrBand4 = pumpGauge->addColorBand(30);
            clrBand4->setValueRange(0,100);
            pumpGauge->addValues(80)->setValueRange(0,50); //Outer Ring Text
            pumpGauge->addLabel(70)->setText("PSI");
            QcLabelItem *lab4 = pumpGauge->addLabel(40);
            lab4->setText("pump");
            Needle4 = pumpGauge->addNeedle(60); //Needle size
            Needle4->setLabel(lab4);
            Needle4->setColor(Qt::red);
            Needle4->setValueRange(0,100);
            pumpGauge->addBackground(7);
            ui->pumpLayout->addWidget(pumpGauge);

            //***************************************************

    headingGauge = new QcGaugeWidget;
    headingGauge = new QcGaugeWidget;

        headingGauge->addBackground(99);
        QcBackgroundItem *bkg1 = headingGauge->addBackground(92);
        bkg1->clearrColors();
        bkg1->addColor(0.1,Qt::black);
        bkg1->addColor(1.0,Qt::white);

        QcBackgroundItem *bkg2 = headingGauge->addBackground(88);
        bkg2->clearrColors();
        bkg2->addColor(0.1,Qt::white);
        bkg2->addColor(1.0,Qt::black);

        QcLabelItem *w = headingGauge->addLabel(80);
        w->setText("W");
        w->setAngle(0);
        w->setColor(Qt::white);

        QcLabelItem *n = headingGauge->addLabel(80);
        n->setText("N");
        n->setAngle(90);
        n->setColor(Qt::white);

        QcLabelItem *e = headingGauge->addLabel(80);
        e->setText("E");
        e->setAngle(180);
        e->setColor(Qt::white);

        QcLabelItem *s = headingGauge->addLabel(80);
        s->setText("S");
        s->setAngle(270);
        s->setColor(Qt::white);

        QcDegreesItem *deg = headingGauge->addDegrees(70);
        deg->setStep(5);
        deg->setMaxDegree(270);
        deg->setMinDegree(-75);
        deg->setColor(Qt::white);
        Needle5 = headingGauge->addNeedle(60);
        Needle5->setNeedle(QcNeedleItem::CompassNeedle);
        Needle5->setValueRange(0,360);
        Needle5->setMaxDegree(360);
        Needle5->setMinDegree(0);
        headingGauge->addBackground(7);
        headingGauge->addGlass(88);
        ui->headingLayout->addWidget(headingGauge);



//*************************************GaugeSetup-END**********************************************************

} //Submarine Class Close Brace




class output{                                              // for checking the code
public:
    void out_putf(){
QTextStream stream(stdout);                               //Constructor
  stream<< "u just pressed forward button"<<endl;
     atmega328p->write("1");
    }
    void out_puts(){
QTextStream stream(stdout);
  stream<< "u just pressed stop button"<<endl;
     atmega328p->write("2");
    }
   void out_putl(){
QTextStream stream(stdout);
  stream<< "u just pressed left button"<<endl;
   atmega328p->write("3");
   }
    void out_putr(){
QTextStream stream(stdout);
  stream<< "u just pressed right button"<<endl;
     atmega328p->write("4");
    }
   void out_putu(){
QTextStream stream(stdout);
  stream<< "u just pressed up button(U)"<<endl;
    atmega328p->write("5");
   }
    void out_putd(){
QTextStream stream(stdout);
  stream<< "u just pressed down button(J)"<<endl;
     atmega328p->write("6");
    }
    void out_putinfo(){
QTextStream stream(stdout);
  stream<< "u just pressed info button(I)"<<endl;
     atmega328p->write("7");


    }

};

output classout;                                        // declaration of object for the class output

void Submarine::keyPressEvent(QKeyEvent *event)  //assigning keys for the movement of submarine start
{  if(event->key()==Qt::Key_W)
     { classout.out_putf();
    }
    if(event->key()==Qt::Key_A)
         { classout.out_putl();
        }
    if(event->key()==Qt::Key_D)
         { classout.out_putr();
        }
    if(event->key()==Qt::Key_S)
         { classout.out_puts();
        }
    if(event->key()==Qt::Key_U)
         { classout.out_putu();
        }
    if(event->key()==Qt::Key_J)
         { classout.out_putd();
        }
    if(event->key()==Qt::Key_I)
         {      classout.out_putinfo();

        }


}                                                           // end of it


void Submarine::on_forward_pressed()         //Declaration of method inside Submarine class
{
classout.out_putf();
}
void Submarine::on_right_pressed()
{
classout.out_putr();
}

void Submarine::on_left_pressed()
{
classout.out_putl();
}

void Submarine::on_stop_pressed()
{
classout.out_puts();
}

void Submarine::on_up_pressed()
{
classout.out_putu();
}

void Submarine::on_down_pressed()
{
classout.out_putd();
}

void Submarine::on_infobutton_clicked()
{classout.out_putinfo();

}

Submarine::~Submarine()                                   // destructor
{
    delete ui;
    atmega328p->close();
}

void Submarine::readSerial()
{
    QTextStream stream(stdout);                          //constructor
    //stream<<atmega328p->readAll();
    stream<<"Reading COM3...\n";
    if(atmega328p->write("R"))stream<<"Ready Read";

    QByteArray raw = atmega328p->readLine(); //atmega328p is our serial ref. object
    valueStr = valueStr + QString::fromStdString(raw.toStdString()); //readAll() return QByteArray type. Hence must convert to string first to store
    //if(bufferLine.length()<100)
    bufferLine << QString::fromStdString(raw.toStdString()).split("\n");//Spliting the string into a string list to evaluate.
    while(i<bufferLine.length()){bufferSplit << bufferLine[i].split(","); i++;}
    //if(bufferSplit.length()>99)bufferSplit.clear(); //was gonna do something, kinda forgot later.
    qDebug()<<bufferSplit; //simple output



    if(bufferSplit.length()>6){

        rpm = bufferSplit[(bufferSplit.length()-3)].toFloat();
        current = bufferSplit[(bufferSplit.length()-4)].toFloat();
        voltage = bufferSplit[(bufferSplit.length()-5)].toFloat();
        speed = bufferSplit[(bufferSplit.length()-6)].toFloat();
        pump = bufferSplit[(bufferSplit.length()-7)].toFloat();
        heading = bufferSplit[(bufferSplit.length()-8)].toFloat();


    Needle0->setCurrentValue(rpm);//bufferSplit[bufferSplit.last()].toFloat()); //various gauge needle values
    Needle1->setCurrentValue(current);
    Needle2->setCurrentValue(voltage);
    Needle3->setCurrentValue(speed);
    Needle4->setCurrentValue(pump);
    Needle5->setCurrentValue(heading);
    }
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("RAW VALUES RECIEVED THIS CYCLE: ");
    ui->textBrowser->insertPlainText(raw);

    //updateValue->start(1000);


}



