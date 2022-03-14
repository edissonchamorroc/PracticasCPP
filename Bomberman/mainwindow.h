#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<muroestatico.h>
#include<muroDinamico.h>
#include<bomberman.h>
#include<fuego.h>
#include<string>
#include<fstream>
#include<QKeyEvent>
#include<bomba.h>
#include<QTimer>
#include<ficheros.h>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ifstream lector;
    int puntaje=0,tiempo=174;


public slots:

private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;

    QList<muroEstatico *> murosEstaticos;
    QList<MuroDinamico *> murosDinamicos;
    ficheros *fichero;
    BomberMan *bomberman;
    QList<fuego *> fuegos;
    fuego * fire;
    Bomba *bomba=nullptr;
    QTimer *tiempoExplosion,*tiempoFuego,*tiempoJuego;


    void keyPressEvent(QKeyEvent *evento);
    bool evaluarBombermanColisionMuroEstatico();
    bool evaluarBombermanColisionMuroDinamico();
    void evaluarFuegoColisionMuroEstatico();
    void evaluarFuegoColisionMuroDinamico();

signals:
public slots:
    void explosion();
    void temporizadorLLamas();
    void temporizadorJuego();
};
#endif // MAINWINDOW_H
