#include "fire.h"

fire::fire()
{

}

fire::fire(int posx,int posy)
{
    this->posx=posx;

    this->posy=posy;

    setPos(posx,posy);

    ancho=34;alto=34;

    imagen=new QImage(":/imagenes/fire.png");

//    timer = new QTimer();

//    timer->start(10000);

//    connect(timer,&QTimer::timeout,this,&fire::apagarLLama);

}
QRectF fire::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void fire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

   painter->drawImage(boundingRect(),*imagen);

}

//void fire::apagarLLama()
//{
//    delete this;
//}

