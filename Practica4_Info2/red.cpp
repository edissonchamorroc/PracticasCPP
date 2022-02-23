#include "red.h"


red::red()
{

}

red::red(string enrutadores)
{
    this->enrutadores=enrutadores;
}

void red::crecionRed()
{
    for(int i=0;i<enrutadores.size();i++){

        if(!buscarEnrutador(enrutadores.at(i))) Red.push_back(Enrutador(enrutadores.at(i)));

    }

    list<Enrutador>::iterator ite=Red.begin();

    while(ite!=Red.end()){

       ite->crearRuta(enrutadores);

       ite++;
    }

}

bool red::buscarEnrutador(char nodo)
{
    list<Enrutador>::iterator ite=Red.begin();

    bool find=false;

    while(ite!=Red.end()){

        if(ite->getNombreNodo()==nodo) find=true;

        ite++;
    }

    return find;
}

void red::enlazarRed(int cantidadEnlaces)
{
    char nodo,enlace; int valor;

    for(int i=0;i<cantidadEnlaces;){
        cout << "Ingrese el nodo base: ";cin>>nodo;
        cout << "Ingrese el nodo con el que se va a enlaza: ";cin>>enlace;
        cout << "Ingrese el costo del enlace: ";cin>>valor;
        modificarEnlaces(nodo,enlace,valor);
        i++;

        /*cout << "Ingrese el nodo base: ";cin>>nodo;
        list<Enrutador>::iterator ite=Red.begin();
        list<Enrutador>::iterator ite2=Red.begin();
        while(ite!=Red.end()){
           if(ite->getNombreNodo()==nodo){
                cout << "Ingrese el nodo con el que se va a enlaza: ";cin>>enlace;
               if(buscarEnrutador(enlace)){
                    cout << "Ingrese el costo del enlace: ";cin>>valor;
                    ite->modificarRuta(enlace,valor);
                    i++;
                      while(ite2!=Red.end()){
                          if(ite2->getNombreNodo()==enlace){
                              if(ite2->buscarKey(nodo)){
                                    ite2->modificarRuta(nodo,valor);
                              }
                            }
                          ite2++;
                        }
                    }
                }
            ite++;
        }*/
    }
}

void red::eliminarEnrutador(char nodo)
{
      eliminarEnrutadorString(nodo);

      if(buscarEnrutador(nodo)){

        list<Enrutador>::iterator ite=Red.begin();

        while(ite!=Red.end()){

            if(ite->getNombreNodo()==nodo) {
                Red.erase(ite); break;}

            ite++;
        }
        eliminarRutas(nodo);
    }
    else{
        cout << " El nodo ingresado no existe." <<endl;
      }
}

void red::eliminarEnrutadorString(char nodo)
{
    string copiaEnrutador;
    for(int i=0;i<enrutadores.size();i++){
        if(enrutadores.at(i)!=nodo)copiaEnrutador+=enrutadores.at(i);
    }
    enrutadores.clear(); enrutadores=copiaEnrutador;
}

void red::eliminarRutas(char nodo)
{
    list<Enrutador>::iterator ite=Red.begin();

    while(ite!=Red.end()){

        ite->eliminarRuta(nodo);

        ite++;
    }
}

void red::modificarEnlaces(char nodo1, char nodo2, int costoEnlace)
{
    list<Enrutador>::iterator ite=Red.begin();

    list<Enrutador>::iterator ite2=Red.begin();

    while(ite!=Red.end()){

        if(ite->getNombreNodo()==nodo1){

            ite->modificarRuta(nodo2,costoEnlace);

            while(ite2!=Red.end()){

                if(ite2->getNombreNodo()==nodo2){

                     ite2->modificarRuta(nodo1,costoEnlace);

                  }
                ite2++;
              }
        }

        ite++;
    }
}

void red::agregarEnrutador(char nodoAdicional,int enlaces){

    enrutadores+=nodoAdicional;

    crecionRed();

    enlazarRed(enlaces);
}

void red::reset()
{
    list<Enrutador>::iterator ite=Red.begin();

    while(ite!=Red.end()){

        Red.erase(ite);
        ite++;

    }
}

void red::imprimirRed()
{
    list<Enrutador>::iterator ite=Red.begin();

    while(ite!=Red.end()){

        ite->impresionRutas();

        ite++;
    }
}

void red::imprimirEnrutador(char nodo)
{
    list<Enrutador>::iterator ite=Red.begin();

    while(ite!=Red.end()){

        if(ite->getNombreNodo()==nodo)ite->impresionRutas();

        ite++;
    }
}

void red::setListEnrutadores(string enrutadores)
{
    this->enrutadores=enrutadores;
}

void red::costoenvio(char nodoOrigen, char nodoDestino, string &ruta,int &valor)
{
    ruta+=nodoOrigen;

    list<Enrutador>::iterator ite=Red.begin();

    while(ite!=Red.end()){
        list<Enrutador>::iterator ite2=Red.begin();
        if(ite->getNombreNodo()==nodoOrigen){
            while(ite2!=Red.end()){
                if(ite2->conexion(ite->getNombreNodo())){
                    if(ite2->getNombreNodo()==nodoDestino){
                        ruta+=nodoDestino;
                        valor+=ite->costoEnlace(ite2->getNombreNodo());
                        break;
                    }
                    else if(!repetido(ite2->getNombreNodo(),ruta)){
                        ruta+=ite2->getNombreNodo();
                        nodoOrigen=ite2->getNombreNodo();
                        valor+=ite->costoEnlace(ite2->getNombreNodo());
                        break;
                    }
                }
                ite2++;
            }
        }
        ite++;
    }
}

bool red::repetido(char nodo ,string ruta)
{
    bool repetido=false;
    for(int i=0;i<ruta.size();i++){
        if(ruta.at(i)==nodo) repetido=true;
    }

    return repetido;
}

