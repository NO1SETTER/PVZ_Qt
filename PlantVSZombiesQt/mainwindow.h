#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFileDialog>
#include <QPushButton>
#include <QSound>
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
#include "EndSign.h"
#include "PauseButton.h"
#include "Sun.h"

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
    void CheckZombie();
private:
    Ui::MainWindow *ui;
    QSound* music;
    QGraphicsScene* scene;
    QTimer* timer;
    QTimer* timer2;
    QTimer* sunTimer;
    bool isEnd;

};
#endif // MAINWINDOW_H
