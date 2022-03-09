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

    lecturaFichero("murosEstaticos.txt");

    lecturaFichero("murosDinamicos.txt");

    bomberman=new BomberMan(74,74);

    scene->addItem(bomberman);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *evento){

    QList<muroEstatico*>::iterator it=murosEstaticos.begin();
    QList<MuroDinamico*>::iterator it1=murosDinamicos.begin();

    if(evento->key()==Qt::Key_W){
        bomberman->MoveUp();
        if(evaluarBombermanColisionMuroEstatico(it) || evaluarBombermanColisionMuroDinamico(it1)){
            bomberman->MoveDown();
        }

    }
    else if(evento->key()==Qt::Key_S){
        bomberman->MoveDown();
        if(evaluarBombermanColisionMuroEstatico(it) || evaluarBombermanColisionMuroDinamico(it1)){
            bomberman->MoveUp();
        }

    }
    else if(evento->key()==Qt::Key_D){
        bomberman->MoveRight();
        if(evaluarBombermanColisionMuroEstatico(it) || evaluarBombermanColisionMuroDinamico(it1)){
            bomberman->MoveLeft();
        }

    }
    else if(evento->key()==Qt::Key_A){
        bomberman->MoveLeft();
        if(evaluarBombermanColisionMuroEstatico(it) || evaluarBombermanColisionMuroDinamico(it1)){
            bomberman->MoveRight();
        }
    }
    else if(evento->key()==Qt::Key_F){
        bomba = new Bomba(bomberman->getPosx(),bomberman->getPosy());
        scene->addItem(bomba);
    }
}
void MainWindow::lecturaFichero(string nombre){

    lector.open(nombre);
    string leido;
    int posicion[4],contador=0;

    if(!lector.fail()){

        while(!lector.eof()){

            lector>>leido;
            posicion[contador]=conversionStr2Int(leido);
            contador++;

            if(contador==4){

                if(nombre=="murosEstaticos.txt"){
                    murosEstaticos.append(new muroEstatico(posicion[0],posicion[1],posicion[2],posicion[3]));
                    scene->addItem(murosEstaticos.back());
                    posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                    contador=0;
                }

                else if(nombre=="murosDinamicos.txt"){
                    murosDinamicos.append(new MuroDinamico(posicion[0],posicion[1],posicion[2],posicion[3]));
                    scene->addItem(murosDinamicos.back());
                    posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                    contador=0;
                }

            }

        }
    }
    lector.close();
}
int MainWindow::contadorDigitos(string numero){
    int digitos=0;

    for(int i=0;i<numero.length();i++){
        digitos=(numero.at(i)!='-')?digitos+=1:digitos;
    }

    return digitos;
}
int MainWindow::conversionStr2Int(string numero)
{
    int multi=1,char2int=0,signo=1;

    for(int i=0;i<contadorDigitos(numero)-1;++i)
    {
        multi*=10;
    }

    for(int i=0;i<numero.length();++i){

        if(numero.at(i)!='-'){
            char2int+=(numero.at(i)-48)*multi;
            multi/=10;
        }else{
            signo=-1;
        }

    }


    return char2int*signo;
}
bool MainWindow::evaluarBombermanColisionMuroEstatico(QList<muroEstatico*>::iterator &ite)
{
    bool colision=false;

    for(ite=murosEstaticos.begin();ite!=murosEstaticos.end();ite++){
        if(bomberman->collidesWithItem(*ite)){
            colision=true;
            break;
        }
    }
    return colision;
}
bool MainWindow::evaluarBombermanColisionMuroDinamico(QList<MuroDinamico *>::iterator &ite)
{
    bool colision=false;

    for(ite=murosDinamicos.begin();ite!=murosDinamicos.end();ite++){
        if(bomberman->collidesWithItem(*ite)){
            colision=true;
            break;
        }
    }
    return colision;
}
