#include "fuego.h"

fuego::fuego()
{

}

fuego::fuego(int posx, int posy)
{
    this->posx=posx;

    this->posy=posy;

    setPos(posx,posy);

    imagen=new QImage(":/imagenes/fire.png");
}

QRectF fuego::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void fuego::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

   painter->drawImage(boundingRect(),*imagen);

}


QList<fuego*> fuego::creacionExplosion(int posx, int posy)
{
    QList<fuego *> fuegos;
    fuegos.append(new fuego(posx-37,posy));
    fuegos.append(new fuego(posx,posy));
    fuegos.append(new fuego(posx+37,posy));
    fuegos.append(new fuego(posx,posy-37));
    fuegos.append(new fuego(posx,posy+37));
    return fuegos;
}
