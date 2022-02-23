#include "enrutador.h"


using namespace std;


Enrutador::Enrutador()
{


}

Enrutador::Enrutador(char nombreNodo)
{
    this->nombreNodo=nombreNodo;
    this->rutas.insert(pair<char,int>(this->nombreNodo,0));
}

char Enrutador::getNombreNodo()
{
    return nombreNodo;
}

void Enrutador::crearRuta(string nodo)
{
    map<char,int>::iterator ite=rutas.begin();

    for(int i=0;i<nodo.size();i++){

        while(ite!=rutas.end()){

            if(!this->buscarKey(nodo.at(i))){

                this->rutas.insert(pair<char,int>(nodo.at(i),0));

            }ite++;

        }
        ite=rutas.begin();

    }

}

void Enrutador::eliminarRuta(char nodo)
{
    this->rutas.erase(this->rutas.find(nodo));
}

void Enrutador::modificarRuta(char nodo, int costoEnlace)
{
    map<char,int>::iterator ite=rutas.begin();

    while(ite!=rutas.end()){

        if(ite->first==nodo){

         rutas.erase(nodo); rutas.insert(pair<char,int>(nodo,costoEnlace));

        }
        ite++;
    }
}


int Enrutador::costoEnlace(char nodo)
{
    map<char,int>::iterator ite=rutas.begin();

    while(ite!=rutas.end()){

        if(ite->first==nodo)return ite->second;

        ite++;
    }

}

bool Enrutador::buscarKey(char nodo)
{
    bool banKey=false;
    map<char,int>::iterator ite=rutas.begin();
    while(ite!=rutas.end()){
        if(ite->first==nodo)banKey=true;
        ite++;
    }
    return banKey;
}

void Enrutador::impresionRutas()
{
    map<char,int>::iterator ite=rutas.begin();
    cout << "Tabla de enrutamiento del nodo "<< this->nombreNodo <<endl;
    while(ite!=rutas.end()){
        cout<< "nodo: "<< ite->first << " valor enlace: "<< ite->second<<endl;
        ite++;
    }
}

bool Enrutador::conexion(char nodo)
{
    map<char,int>::iterator ite=rutas.begin(); bool conec=false;

    while(ite!=rutas.end()){

        if(ite->first==nodo & costoEnlace(ite->first)!=0)return conec=true;

        ite++;
    }

    return conec;

}
