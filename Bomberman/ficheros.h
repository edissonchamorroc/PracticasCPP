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

    string posiciones;
public:
    ficheros();

    void lecturaFichero(string nombreFichero, QGraphicsScene *scene, QList<muroEstatico*> &murosEstaticos,QList<MuroDinamico*> &murosDinamicos);
    int []getPosiciones();



};

#endif // FICHEROS_H
