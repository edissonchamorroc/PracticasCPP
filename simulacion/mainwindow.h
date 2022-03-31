#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<cuerpo.h>
#include<graficar.h>
#include<QList>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void actualizar();
private slots:
    void on_agregar_clicked();

    void on_simular_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QTimer *timer;
    float dt;
    float entrada;
    int altura;
    int ancho;
    QList<graficar*> planetas;
};
#endif // MAINWINDOW_H
