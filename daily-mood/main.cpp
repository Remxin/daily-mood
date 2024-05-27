#include "dailymood.h"
#include <QObject>
#include <QWidget>
#include <QtWidgets/QApplication>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    dailymood w;



    w.show();
    return a.exec();
}

