#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColor>
#include<string>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene();

    ui->graphicsView->setScene(scene);


    setWindowTitle("BOMBERMAN");


    scene->setSceneRect(567,224,10,20);

    scene->setBackgroundBrush(Qt::green);

    llave =new Llave(fichero->getPosx(),fichero->getPosy());

    scene->addItem(llave);

    fichero->lecturaFichero("murosEstaticos.txt",scene,murosEstaticos,murosDinamicos);

    fichero->lecturaFichero("murosDinamicos.txt",scene,murosEstaticos,murosDinamicos);

    bomberman=new BomberMan(74,74);

    scene->addItem(bomberman);

    ui->labelLifes->setText(utilidades::conversionInt2Str(bomberman->getVidas()));

    ui->labelScore->setText(utilidades::conversionInt2Str(puntaje));

    tiempoJuego = new QTimer();

    tiempoJuego->start(1000);

    connect(tiempoJuego,&QTimer::timeout,this,&MainWindow::temporizadorJuego);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento){

    if(evento->key()==Qt::Key_W){
        bomberman->MoveUp();
        if(evaluarBombermanColisionMuroEstatico() || evaluarBombermanColisionMuroDinamico( )){
            bomberman->MoveDown();
        }

    }
    else if(evento->key()==Qt::Key_S){
        bomberman->MoveDown();
        if(evaluarBombermanColisionMuroEstatico() || evaluarBombermanColisionMuroDinamico()){
            bomberman->MoveUp();
        }

    }
    else if(evento->key()==Qt::Key_D){
        bomberman->MoveRight();
        if(evaluarBombermanColisionMuroEstatico() || evaluarBombermanColisionMuroDinamico()){
            bomberman->MoveLeft();
        }

    }
    else if(evento->key()==Qt::Key_A){
        bomberman->MoveLeft();
        if(evaluarBombermanColisionMuroEstatico() || evaluarBombermanColisionMuroDinamico()){
            bomberman->MoveRight();
        }
    }
    else if(evento->key()==Qt::Key_F && bomba==nullptr && fuegos.size()==0){

        bomba = new Bomba(bomberman->getPosx(),bomberman->getPosy());

        scene->addItem(bomba);

        tiempoExplosion = new QTimer();tiempoFuego=new QTimer();

        tiempoExplosion->start(5000);tiempoFuego->start(8000);

        connect(tiempoExplosion,&QTimer::timeout,this,&MainWindow::explosion);

        connect(tiempoFuego,&QTimer::timeout,this,&MainWindow::temporizadorLLamas);

    }
}

bool MainWindow::evaluarBombermanColisionMuroEstatico()
{
    bool colision=false;
    QList<muroEstatico*>::iterator ite=murosEstaticos.begin();
    for(ite=murosEstaticos.begin();ite!=murosEstaticos.end();ite++){
        if(bomberman->collidesWithItem(*ite)){
            colision=true;
            break;
        }
    }
    return colision;
}
bool MainWindow::evaluarBombermanColisionMuroDinamico()
{
    bool colision=false;
    QList<MuroDinamico*>::iterator ite=murosDinamicos.begin();
    for(ite=murosDinamicos.begin();ite!=murosDinamicos.end();ite++){
        if(bomberman->collidesWithItem(*ite)){
            colision=true;
            break;
        }
    }
    return colision;
}

void MainWindow::evaluarBombermanFuego()
{
    QList<fuego*>::iterator ite=fuegos.begin();
    for(ite=fuegos.begin();ite!=fuegos.end();ite++){
        if(bomberman->collidesWithItem(*ite)){
            bomberman->setVidas(bomberman->getVidas()-1);
            ui->labelLifes->setText(utilidades::conversionInt2Str(bomberman->getVidas()));
            bomberman->setPosx(74);bomberman->setPosy(74);
            break;
        }
    }
}

void MainWindow::evaluarFuegoColisionMuroEstatico()
{
    QList<muroEstatico*>::iterator iteM=murosEstaticos.begin(); bool colision=false;

    for(int i=0;i<fuegos.size();i++){

        for(iteM=murosEstaticos.begin();iteM!=murosEstaticos.end();iteM++){

            if(fuegos.at(i)->collidesWithItem(*iteM)){
               colision=true;
               break;
            }
        }

        if(!colision) scene->addItem(fuegos.at(i));
        else colision=false;

    }

}

void MainWindow::evaluarFuegoColisionMuroDinamico()
{
    QList<MuroDinamico*>::iterator iteM;

    for(int i=0;i<fuegos.size();i++){

        for(iteM=murosDinamicos.begin();iteM!=murosDinamicos.end();iteM++){

            if(fuegos.at(i)->collidesWithItem(*iteM)){

                scene->removeItem(*iteM);

                murosDinamicos.erase(iteM);

                puntaje++;

                ui->labelScore->setText(utilidades::conversionInt2Str(puntaje));

                break;
            }
        }
        scene->addItem(fuegos.at(i));

    }
}


void MainWindow::explosion(){


    fuegos=fire->creacionExplosion(bomba->getPosx(),bomba->getPosy());
    evaluarBombermanFuego();
    evaluarFuegoColisionMuroEstatico();
    evaluarFuegoColisionMuroDinamico();
    tiempoExplosion->deleteLater();
    bomba=nullptr;

}

void MainWindow::temporizadorLLamas()
{
    QList<fuego*>::iterator ite;

    for(ite=fuegos.begin();ite!=fuegos.end();ite++){
        scene->removeItem(*ite);
    }

    fuegos.clear();
    tiempoFuego->deleteLater();
}

void MainWindow::temporizadorJuego()
{
    if(tiempo==0){
        delete this;
    }else{
        tiempo--;
        ui->labelTime->setText(utilidades::conversionInt2Str(tiempo));
    }

}
