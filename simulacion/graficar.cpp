#include "graficar.h"

graficar::graficar()
{

}
cuerpo *graficar::getPlaneta() const
{
    return planeta;
}
graficar::graficar(float x, float y, float vx, float vy, float m, float r):escala(0.05)
{
    planeta=new cuerpo(x,y,vx,vy,m,r);
}
QRectF graficar::boundingRect() const
{
    return QRectF(-1*escala*planeta->getR(),-1*escala*planeta->getR(),2*escala*planeta->getR(),2*escala*planeta->getR());
}

void graficar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

void graficar::setEscala(float s)
{
    escala = s;
}

void graficar::actualizar(float dt)
{
    planeta->actualizardatos(dt);
    setPos(planeta->getPX()*escala,planeta->getPY()*escala);
}
