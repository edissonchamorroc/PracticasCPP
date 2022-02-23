#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include<map>

#include<iostream>

using namespace std;

class Enrutador
{
private:
    char nombreNodo;

    map<char,int> rutas;

public:
    Enrutador();

    Enrutador(char nombreNodo);

    char getNombreNodo();

    void crearRuta(string nodo);

    void eliminarRuta(char nodo);

    void modificarRuta(char nodo,int costoEnlace);

    int costoEnlace(char nodo);

    bool buscarKey(char nodo);

    void impresionRutas();

    bool conexion(char );
};

#endif // ENRUTADOR_H
