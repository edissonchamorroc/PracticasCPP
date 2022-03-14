#ifndef BOMBA_H
#define BOMBA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QPainter>
#include<fuego.h>
class Bomba:public QObject,public QGraphicsItem
{
    int posx,posy,ancho=34,alto=34;
public:
    Bomba();
    Bomba(int posx,int posy);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QTimer *timer;
    QPixmap *pixmap;
    QImage *imagen;

    int getPosx() ;

    int getPosy() ;

signals:
public slots:
    void explosion();

};

#endif // BOMBA_H
