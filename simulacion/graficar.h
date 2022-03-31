#ifndef GRAFICAR_H
#define GRAFICAR_H
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<cuerpo.h>

class graficar: public QGraphicsItem
{
    float escala; cuerpo *planeta;
public:
    graficar();
    graficar(float x, float y, float vx, float vy, float m, float r);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setEscala(float s);
    void actualizar(float dt);

    cuerpo *getPlaneta() const;
};

#endif // GRAFICAR_H
