#include "bomba.h"

int Bomba::getPosx()
{
    return posx;
}

int Bomba::getPosy()
{
    return posy;
}

Bomba::Bomba()
{

}
Bomba::Bomba(int posx,int posy)
{
    timer =new QTimer();

    this->posx=posx;

    this->posy=posy;

    setPos(posx,posy);

    imagen=new QImage(":/imagenes/bomb.png");

    timer->start(5000);

    connect(timer,&QTimer::timeout,this,&Bomba::explosion);

}
QRectF Bomba::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void Bomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

   painter->drawImage(boundingRect(),*imagen);

}

void Bomba::explosion()
{

    delete this;

}
