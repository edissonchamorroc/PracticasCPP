#include "muroestatico.h"

muroEstatico::muroEstatico()
{

}
int muroEstatico::getPosx()
{
    return posx;
}

int muroEstatico::getPosy()
{
    return posy;
}

muroEstatico::muroEstatico(int posx, int posy,int ancho,int alto)
{
    this->ancho=ancho;
    this->alto=alto;
    this->posx=posx;
    this->posy=posy;
    imagen= new QImage(":/imagenes/muroestatico.PNG");
}


QRectF muroEstatico::boundingRect() const
{
    return QRectF(-posx,-posy,ancho,alto);
}

void muroEstatico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect(),*imagen);
}

