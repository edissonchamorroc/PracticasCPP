#ifndef LLAVE_H
#define LLAVE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QPainter>
#include<QTimer>
class Llave:public QObject,public QGraphicsItem
{
    int posx,posy,ancho=34,alto=34;


public:
    Llave();
    Llave(int posx,int posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    QPixmap *pixmap;
    QImage *imagen;
    void setPosx(int newPosx);
    void setPosy(int newPosy);
};

#endif // LLAVE_H
