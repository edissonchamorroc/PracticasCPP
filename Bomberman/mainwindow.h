#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<muroestatico.h>
#include<muroDinamico.h>
#include<bomberman.h>
#include<string>
#include<fstream>
#include<QKeyEvent>
#include<bomba.h>
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
public slots:

private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    muroEstatico * muro;
    QList<muroEstatico *> murosEstaticos;
    QList<MuroDinamico *> murosDinamicos;
    BomberMan *bomberman;
    Bomba *bomba;

    void keyPressEvent(QKeyEvent *evento);
    void lecturaFichero(string nombreFichero);
    int contadorDigitos(string numero);
    int conversionStr2Int(string numero);
    bool evaluarBombermanColisionMuroEstatico(QList<muroEstatico*>::iterator &ite);
    bool evaluarBombermanColisionMuroDinamico(QList<MuroDinamico*>::iterator &ite);
};
#endif // MAINWINDOW_H
