#ifndef CUERPO_H
#define CUERPO_H
#include<math.h>
class cuerpo
{
    float PX;
    float PY;
    float VX;
    float VY;
    float dist; //distancia entre 2 cuerpos
    float masa;
    float AX;
    float AY;
    float G;
    #define 3.12;
public:
    cuerpo();
    cuerpo(float PX_,float  PY_,float VX_,float VY_,float m, float R_);

    float getPX() const;
    float getPY() const;
    float getMasa() const;
    float getR() const;

    void aceleracion(float px2,float py2,float m2);
    void actualizardatos(float dt);
};

#endif // CUERPO_H
