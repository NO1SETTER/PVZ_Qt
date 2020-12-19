#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <qdir.h>

int main(int argc, char *argv[])
{
    srand((int)time(0));
    QApplication a(argc, argv);
    QString nowPath("../PlantVSZombiesQt");
    QDir::setCurrent(nowPath);//工作目录设置到源代码目录下

    MainWindow w;
    w.setWindowTitle("PlantsVsZombies");
    w.show();
    return a.exec();
}
