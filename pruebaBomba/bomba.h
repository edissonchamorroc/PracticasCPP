#ifndef BOMBA_H
#define BOMBA_H

#include<QGraphicsItem>
#include<QPainter>
#include<QTimer>
#include<QObject>


class bomba:public QObject,public QGraphicsItem
{
    int posx,posy,ancho,alto;

public:
    bomba();
    bomba(int posx,int posy);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


    QTimer *timer;
    QPixmap *pixmap;
    QImage *imagen;




    int getPosx() const;

    int getPosy() const;

    bool getActivo() const;

signals:
public slots:
    void explosion();

};

#endif // BOMBA_H
