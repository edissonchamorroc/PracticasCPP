#include "muroDinamico.h"

MuroDinamico::MuroDinamico()
{

}
MuroDinamico::MuroDinamico(int posx, int posy,int ancho,int alto)
{
    this->ancho=ancho;
    this->alto=alto;
    this->posx=posx;
    this->posy=posy;
    imagen=new QImage(":/imagenes/murodinamico.png");
}
QRectF MuroDinamico::boundingRect() const
{
    return QRectF(-posx,-posy,ancho,alto);
}

void MuroDinamico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     painter->drawImage(boundingRect(),*imagen);
}
