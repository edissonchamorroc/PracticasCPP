#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include<QGraphicsItem>
#include<QPainter>
#include<QTimer>
#include<QPixmap>
#include<QObject>
#include<iostream>

using namespace std;
class BomberMan: public QGraphicsItem,public QObject
{
    int posx,posy,ancho,alto,velocidad=4;
public:
    BomberMan();
    BomberMan(int posx,int posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    int filas=0, columnas=0;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();

    int getPosx() const;

    int getPosy() const;

signals:
public slots:
    void actualizacion();


};

#endif // BOMBERMAN_H
