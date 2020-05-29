#include "submarine.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Submarine w;



    w.show();
    return a.exec();
}
