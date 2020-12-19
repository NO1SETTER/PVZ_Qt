#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFileDialog>
#include "Common.h"
#include "Cards.h"
#include "Grassland.h"
#include "Shovel.h"
#include "SunPanel.h"
#include "NormalZombie.h"
#include "ConeHeadZombie.h"
#include "BucketHeadZombie.h"
#include "FlagZombie.h"
#include "PoleVaultingZombie.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void GenerateZombie();
    void GenerateSun();
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QTimer* timer;
    QTimer* timer2;
    QTimer* sunTimer;

};
#endif // MAINWINDOW_H
