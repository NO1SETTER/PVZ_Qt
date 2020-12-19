#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <qdir.h>

int main(int argc, char *argv[])
{
    srand((int)time(0));
    QApplication a(argc, argv);
    QString nowPath("../PlantVSZombiesQt");
    QDir::setCurrent(nowPath);//����Ŀ¼���õ�Դ����Ŀ¼��

    MainWindow w;
    w.setWindowTitle("PlantsVsZombies");
    w.show();
    return a.exec();
}
