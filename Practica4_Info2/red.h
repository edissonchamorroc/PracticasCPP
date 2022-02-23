#ifndef RED_H
#define RED_H


#include<list>
#include<string>
#include<enrutador.h>

using namespace std;

class red
{

private:

    list<Enrutador> Red;

    string enrutadores;

public:

  red();

  red(string enrutadores);

  void crecionRed();

  bool buscarEnrutador(char nodo);

  void enlazarRed(int cantidadEnlaces);

  void eliminarEnrutador(char nodo);

  void eliminarEnrutadorString(char nodo);

  void eliminarRutas(char nodo);

  void modificarEnlaces(char nodo1,char nodo2,int costoEnlace);

  void agregarEnrutador(char nodoAdicional,int enlaces);

  void reset();

  void imprimirRed();

  void imprimirEnrutador(char nodo);

  void setListEnrutadores(string enrutadores);

  void costoenvio(char nodoOrigen,char nodoDestino,string &ruta,int &valor);

  bool repetido(char,string );




};


#endif // RED_H
