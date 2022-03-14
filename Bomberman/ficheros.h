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


public:
    ficheros();

    void lecturaFichero(string nombreFichero, QGraphicsScene *scene, QList<muroEstatico*> &murosEstaticos,QList<MuroDinamico*> &murosDinamicos);
    int getPosx();
    int getPosy();


};

#endif // FICHEROS_H
