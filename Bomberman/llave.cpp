#include "llave.h"

void Llave::setPosx(int newPosx)
{
    posx = newPosx;
}

void Llave::setPosy(int newPosy)
{
    posy = newPosy;
}

Llave::Llave()
{

}

Llave::Llave(int posx, int posy)
{
    this->posx=posx;

    this->posy=posy;

    setPos(posx,posy);

    imagen=new QImage(":/imagenes/puerta.png");
}

QRectF Llave::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void Llave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

   painter->drawImage(boundingRect(),*imagen);

}
