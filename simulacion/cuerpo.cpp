#include "cuerpo.h"
cuerpo::cuerpo(float PX_, float PY_, float VX_, float VY_, float m, float R_)
{
    PX=PX_; PY=PY_;VX=VX_;VY=VY_;masa=m;AX=0;AY=0;G=6.67384*(pow(10,-11)); R=R_;
}

float cuerpo::getPX() const
{
    return PX;
}

float cuerpo::getPY() const
{
    return PY;
}

float cuerpo::getMasa() const
{
    return masa;
}

float cuerpo::getR() const
{
    return R;
}

void cuerpo::aceleracion(float px2, float py2, float m2)
{
    dist=pow((pow((px2-PX),2)+pow((py2-PY),2)),1/2);
    AX= G*m2*(px2-PX)/pow(dist,2);
    AY= G*m2*(py2-PY)/pow(dist,2);
}

void cuerpo::actualizardatos(float dt)
{
    VX=VX +(AX*dt);
    VY=VY +(AY*dt);
    PX=PX +(VX*dt);
    PY=PY +(VY*dt);
}
cuerpo::cuerpo()
{

}
