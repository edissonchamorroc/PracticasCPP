#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<bomba.h>
#include<fire.h>
#include<QGraphicsScene>
#include<QTimer>

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


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<fire *>fuego;
    QTimer * temporizador;
    bomba * bomb;
    void llamas();
signals:
public slots:
    void explosion();
};
#endif // MAINWINDOW_H
