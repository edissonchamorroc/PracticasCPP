#ifndef MURODINAMICO_H
#define MURODINAMICO_H
#include<QGraphicsItem>
#include<QPainter>
#include<QObject>
class MuroDinamico: public QGraphicsItem,public QObject
{
     int posx,posy,ancho,alto;
     QImage *imagen;
public:
    MuroDinamico();
    MuroDinamico( int posx, int posy,int ancho,int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getPosx() ;
    int getPosy() ;
};

#endif // MURODINAMICO_H
