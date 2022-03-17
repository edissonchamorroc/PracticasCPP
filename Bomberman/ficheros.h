#ifndef FICHEROS_H
#define FICHEROS_H

#include<string>
#include<fstream>
#include<QGraphicsScene>
#include<utilidades.h>
#include<muroDinamico.h>
#include<muroestatico.h>

using namespace std;
class ficheros
{

    int posiciones, posx,posy;
public:
    ficheros();

    void lecturaFichero(string nombreFichero, QGraphicsScene *scene, QList<muroEstatico*> &murosEstaticos,QList<MuroDinamico*> &murosDinamicos);
    void setPosiciones();



    int getPosx() const;
    int getPosy() const;
};

#endif // FICHEROS_H
