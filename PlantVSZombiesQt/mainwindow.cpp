#include "mainwindow.h"
#include "ui_mainwindow.h"

Card* cards[10];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap backGroundImage = QPixmap("images/interface/background1.jpg");
    ui->view->setBackgroundBrush(backGroundImage);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1,1);
    for(int i = 0;i< 10;i++)
    {   cards[i] = new Card(i);
        if(i<curPlantNum)
        scene->addItem(cards[i]);
    }
    Shovel* shovel = new Shovel();
    scene->addItem(shovel);
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 9;j++)
        {
            Grassland* grass = new Grassland(j,i);
            scene->addItem(grass);
        }

    timer = new QTimer();
    timer->setInterval(100);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(update()));
    connect(timer,SIGNAL(timeout()),this,SLOT(GenerateZombie()));
    timer->start();

    ui->view->setScene(scene);
    ui->view->resize(backGroundImage.width(),backGroundImage.height());
    ui->view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GenerateZombie()
{
if(rand()%100==0)
{
    int row = rand()%5;
    int kind = rand()%5;
    zombie* newzombie;
    switch(kind)
    {
    case 0:newzombie = new NormalZombie(row,grassX[9],grassY[row]);break;
    case 1:newzombie = new ConeHeadZombie(row,grassX[9],grassY[row]);break;
    case 2:newzombie = new BucketHeadZombie(row,grassX[9],grassY[row]);break;
    case 3:newzombie = new FlagZombie(row,grassX[9],grassY[row]);break;
    case 4:newzombie = new PoleVaultingZombie(row,grassX[9],grassY[row]);break;
    default:break;
    }
    scene->addItem(newzombie);
    return;
}
}




