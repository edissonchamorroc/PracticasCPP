#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene();

    ui->graphicsView->setScene(scene);


    setWindowTitle("BOMBERMAN");


    scene->setSceneRect(0,0,10,20);

    temporizador = new QTimer();

    temporizador->start(5000);

    connect(temporizador,&QTimer::timeout,this,&MainWindow::explosion);
    bomb=new bomba(74,74);

    scene->addItem(bomb);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::llamas()
{

    for(int i=bomb->getPosx()-37;i<=bomb->getPosx()+37;i+=37){
         fuego.append(new fire(i,bomb->getPosy()));


    }
    for(int i=bomb->getPosy()-37;i<=bomb->getPosy()+37;i+=37){
         fuego.append(new fire(bomb->getPosx(),i));

    }
    for(int i=0;i<fuego.size();i++){
        scene->addItem(fuego.at(i));
    }
}

void MainWindow::explosion()
{
    llamas();

}

