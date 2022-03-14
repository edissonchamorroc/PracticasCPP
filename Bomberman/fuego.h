#ifndef FUEGO_H
#define FUEGO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QPainter>
#include<QTimer>

class fuego:public QObject,public QGraphicsItem
{
   int posx,posy,ancho=34,alto=34;


public:
    fuego();

    fuego(int posx,int posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QList<fuego*> creacionExplosion(int posx, int poxy);
    QPixmap *pixmap;
    QImage *imagen;

};

#endif // FUEGO_H
