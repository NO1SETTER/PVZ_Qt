#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isEnd = 0;
    QPixmap backGroundImage = QPixmap("images/interface/background1.jpg");
    ui->view->setBackgroundBrush(backGroundImage);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1,1);
    for(int i = 0;i< 10;i++)
    {   cards[i] = new Card(i);
        scene->addItem(cards[i]);
    }
    Shovel* shovel = new Shovel();
    scene->addItem(shovel);
    SunPanel* sunpanel = new SunPanel();
    scene->addItem(sunpanel);

    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 9;j++)
        {
            Grassland* grass = new Grassland(j,i);
            scene->addItem(grass);
        }

    music = new QSound("CrazyDave.wav");
    music->setLoops(QSound::Infinite);
    music->play();

    timer = new QTimer();
    timer->setInterval(100);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(update()));
    connect(timer,SIGNAL(timeout()),this,SLOT(GenerateZombie()));
    connect(timer,SIGNAL(timeout()),this,SLOT(CheckZombie()));
    timer->start();

    timer2 = new QTimer();
    timer2->setInterval(10000000);//最多运行10000秒
    timer2->start();

    sunTimer = new QTimer();
    sunTimer->setInterval(10000);
    connect(sunTimer,SIGNAL(timeout()),this,SLOT(GenerateSun()));
    sunTimer->start();

    PauseButton* pbutton = new PauseButton(timer,timer2,sunTimer);
    scene->addItem(pbutton);
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
int freq;
if(timer2->remainingTime()>=1000000 - 30000) freq = 300;
else if(timer2->remainingTime()>= 1000000 - 60000) freq = 200;
else if(timer2->remainingTime()>= 1000000 - 120000) freq = 120;
else if(timer2->remainingTime()>= 1000000 - 180000) freq = 80;
else freq = 50;

if(rand()%freq==0)
{
    int row = rand()%5;
    int kind = rand()%5;
    zombie* newzombie;//=new PoleVaultingZombie(row,grassX[9],grassY[row]);
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

void MainWindow::GenerateSun()
{
    sun = sun + 25;
}

void MainWindow::CheckZombie()
{
    if(isEnd) assert(0);
    QList<QGraphicsItem*> items = scene->items();
    for(auto it = items.begin();it!=items.end();it++)
    {
        if((*it)->type()!=KIND_ZOMBIE) continue;
        zombie* zb = qgraphicsitem_cast<zombie*>(*it);
        if(zb->getX()<150&&zb->name!="polevaultingzombie")
        {
            EndSign* sign =new EndSign();
            scene->addItem(sign);
            isEnd = 1;
        }
        else if (zb->getX()<50&&zb->name=="polevaultingzombie")
        {
            EndSign* sign =new EndSign();
            scene->addItem(sign);
            isEnd = 1;
        }
    }
}

