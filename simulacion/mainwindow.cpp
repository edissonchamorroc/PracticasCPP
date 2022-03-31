#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    altura=1000;
    ancho=1000;
    dt=0.1;
    timer =new QTimer(this);

    escena = new QGraphicsScene(this);
    escena->setSceneRect(-250,-250,500,500);
    escena->setSceneRect(-altura/2,-ancho/2,altura,ancho);
    ui->graphicsView->setScene(escena);
    ui->centralwidget->adjustSize();
    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete escena;
}

void MainWindow::actualizar()
{
    for (int i=0;i<planetas.size() ;i++ ) {
        for (int j=0;j<planetas.size() ;j++ ) {
            if(i!=j){
                planetas.at(i)->getPlaneta()->aceleracion(planetas.at(j)->getPlaneta()->getPX(),planetas.at(j)->getPlaneta()->getPY(),planetas.at(j)->getPlaneta()->getMasa());
                planetas.at(i)->actualizar(dt);
            }
        }
    }
}


void MainWindow::on_agregar_clicked()
{

    float pix=ui->posix->text().toFloat();
    float  piy=ui->posiy->text().toFloat();
    float vx=ui->vix->text().toFloat();
    float vy=ui->viy->text().toFloat();
    float mas=ui->masa->text().toFloat();
    float rad=ui->radio->text().toFloat();
    planetas.push_back(new graficar(pix,piy,vx,vy,mas,rad));
    planetas.back()->actualizar(dt);
    escena->addItem(planetas.back());
    ui->posix->clear();
    ui->posiy->clear();
    ui->vix->clear();
    ui->viy->clear();
    ui->masa->clear();
    ui->radio->clear();


}

void MainWindow::on_simular_clicked()
{

     timer->start(dt);
}
