#include "bomba.h"

int bomba::getPosx() const
{
    return posx;
}

int bomba::getPosy() const
{
    return posy;
}



bomba::bomba()
{

}


bomba::bomba(int posx,int posy)
{
    this->posx=posx;

    this->posy=posy;

    setPos(posx,posy);

    ancho=34;alto=34;

    imagen=new QImage(":/imagenes/bomb.png");

    timer = new QTimer();

    timer->start(5000);

    connect(timer,&QTimer::timeout,this,&bomba::explosion);

}
QRectF bomba::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void bomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

   painter->drawImage(boundingRect(),*imagen);

}
void bomba::explosion()
{
    delete this;
}


