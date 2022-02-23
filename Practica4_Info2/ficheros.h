#ifndef FICHEROS_H
#define FICHEROS_H

#include<red.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class ficheros:public red
{
    string nombreFichero,lectura;

    ifstream lector;ofstream escritor;

public:
    ficheros();

    ficheros(string nombreFichero);

    void setNombreFichero(string);

    void lecturaEnrutadores();

    void modificarRelacion(red &);

    void escrituraEnlaces();

    int converChr2Int(string);

    string getLectura();


};

#endif // FICHEROS_H
