#ifndef FIRE_H
#define FIRE_H

#include<QGraphicsItem>
#include<QPainter>
#include<QTimer>
#include<QObject>

class fire:public QObject,public QGraphicsItem
{
    int posx,posy,ancho,alto;
public:
    fire();

    fire(int posx,int posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void conato();

    QTimer *timer;
    QPixmap *pixmap;
    QImage *imagen;

//signals:
//public slots:
//    void apagarLLama();

};

#endif // FIRE_H
