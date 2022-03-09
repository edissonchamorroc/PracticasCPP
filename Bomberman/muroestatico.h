#ifndef MUROESTATICO_H
#define MUROESTATICO_H

#include<QGraphicsItem>
#include<QPainter>

class muroEstatico:public QGraphicsItem
{
    int posx,posy,ancho,alto;
    QImage *imagen;
public:
    muroEstatico();
    muroEstatico( int posx, int posy,int ancho,int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosx() ;
    int getPosy() ;
};

#endif // MUROESTATICO_H
