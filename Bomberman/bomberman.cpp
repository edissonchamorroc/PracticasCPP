#include "bomberman.h"



int BomberMan::getPosx() const
{
    return posx;
}

int BomberMan::getPosy() const
{
    return posy;
}

BomberMan::BomberMan()
{

}
BomberMan::BomberMan(int posx,int posy)
{
    timer =new QTimer();

    this->posx=posx;

    this->posy=posy;

    setPos(posx,posy);

    ancho=34;alto=34;

    filas=0;

    columnas=0;

    pixmap=new QPixmap(":/imagenes/bomberman.png");

    timer->start(100);

    connect(timer,&QTimer::timeout,this,&BomberMan::actualizacion);

}
QRectF BomberMan::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}
void BomberMan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}
void BomberMan::MoveRight()
{
    this->posx+=velocidad;
    filas=52;
    setPos(posx,posy);
}

void BomberMan::MoveLeft()
{
    this->posx-=velocidad;
    filas=156;
    setPos(posx,posy);
}

void BomberMan::MoveUp()
{
    this->posy-=velocidad;
    filas=0;
    setPos(posx,posy);
}

void BomberMan::MoveDown()
{
    this->posy+=velocidad;
    filas=104;
    setPos(posx,posy);
}

void BomberMan::actualizacion()
{
    columnas+=38;
    if(columnas>=265){
        columnas=0;
    }

    this->update(-ancho,-alto,ancho,alto);
}
