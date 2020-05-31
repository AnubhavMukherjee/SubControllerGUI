#ifndef SUBMARINE_H
#define SUBMARINE_H

#include <QMainWindow>
#include <QSerialPort>
#include <qcgaugewidget.h>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QTimer>
#include <cstring>
#include <iostream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Submarine; }
QT_END_NAMESPACE

class Submarine : public QMainWindow
{
    Q_OBJECT

public:
    Submarine(QWidget *parent = nullptr);
    ~Submarine();

private slots:
    void on_forward_pressed();

    void on_right_pressed();

    void on_left_pressed();

    void on_stop_pressed();

    void on_up_pressed();

    void on_down_pressed();

    void readSerial();

    void on_infobutton_clicked();

private:
    Ui::Submarine *ui;
    void keyPressEvent(QKeyEvent *);    // for assigning keys to control submarine


    //**************
    QcGaugeWidget *rpmGauge;
    QcGaugeWidget *currentGauge; //QcGaugeWidget *Gauge;
    QcGaugeWidget *voltageGauge;
    QcGaugeWidget *speedGauge;
    QcGaugeWidget *pumpGauge;
    QcGaugeWidget *headingGauge;


    QcNeedleItem *Needle0;
    QcNeedleItem *Needle1;
    QcNeedleItem *Needle2;
    QcNeedleItem *Needle3;
    QcNeedleItem *Needle4;
    QcNeedleItem *Needle5;
    QString valueStr;
    QStringList bufferLine;
    QStringList lineSplit;
    QStringList bufferSplit;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QVideoWidget *video;
    QByteArray raw;
    float i = 0, rpm = 0, current = 0, voltage = 0, speed = 0, pump = 0, heading = 0;
    string a ="LOL";


};
#endif // SUBMARINE_H
