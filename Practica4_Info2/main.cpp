#include <iostream>
#include<list>
#include<string>
#include<enrutador.h>
#include<red.h>
#include<ficheros.h>
using namespace std;

void ejecucion(int , red &,ficheros &);

void modificacion(red &s);

int main()
{
    red Redes;ficheros fichero;

    int opcion;

    string continuar="si";

    while(continuar=="si"){
        cout << "Que desea realizar" << endl;

        cout << "1: Modelar red desde consola." << endl;

        cout << "2: Modelar red desde archivo." << endl;

        cout << "3: Costo de envio con enrutador de origen y enrutador de destino." << endl;

        cout << "4: Camino mas eficiente en la red." << endl;

        cout << "5. Modificar la red actual. " << endl;

        cout << "Ingrese opcion : "  ;

        cin>> opcion;

        ejecucion(opcion,Redes,fichero);

        cout << " Desea continuar?: " ;cin>>continuar;

        system("pause");

        system("cls");

    }

}

void ejecucion(int opcion, red &Redes, ficheros &fichero){

    switch (opcion) {
    case 1:{

        string nodos,modificar;int cantidadEnlaces;

        Redes.reset();

        cout << "Ingrese el nombre de todos los nodos a usar en la red: " ;

        cin>>nodos;

        Redes.setListEnrutadores(nodos);

        Redes.crecionRed();

        cout << "Ingrese la cantidad de enlaces que habra en la red: " ;

        cin>>cantidadEnlaces;

        Redes.enlazarRed(cantidadEnlaces);

        Redes.imprimirRed();

        break;

    }
    case 2:{
        string nombreArchivo;

        Redes.reset();

        cout << "Ingrese el nombre del archivo: " ;cin>>nombreArchivo;

        fichero.setNombreFichero(nombreArchivo);

        fichero.lecturaEnrutadores();

        Redes.setListEnrutadores(fichero.getLectura());

        Redes.crecionRed();

        fichero.modificarRelacion(Redes);

        break;
    }
    case 3:{
        char nodoOrigen,nodoDestino;string ruta="";int valor=0;

        cout << "Ingrese el nodo de origen: " ;cin>>nodoOrigen;

        cout << "Ingrese el nodo de destino: " ;cin>>nodoDestino;

        Redes.costoenvio(nodoOrigen,nodoDestino,ruta,valor);

        cout << "La ruta para enlazar "<< nodoOrigen << " con " << nodoDestino << " es: " << ruta << " y tiene un costo de: "<< valor << endl;


        break;

    }
    case 4:{

        break;
    }
    case 5:{

        modificacion(Redes);

        break;

    }
    default:{

        cout<< "La opcion no es valida. " << endl;
        break;

    }

    }

}

void modificacion(red &Redes){
    int opcion =0;

    cout << "1. Agregar enrutador."<< endl;

    cout << "2. Eliminar enrutador."<< endl;

    cout << "3. Cambiar costo de enlace existente." <<endl;

    cout << "4. Imprimir tabla de enrutamiento" << endl;

    cout << "5. Imprimir red" << endl;

    cout << "Ingrese opcion : "  ;

    cin>>opcion;

    switch(opcion){
    case 1:{
        char nodoAdicional;int enlaces;

        cout << "Ingrese nodo Adicional : "  ;cin>>nodoAdicional;

        cout<< "Cuantos enlaces tendra el nodo adicional? : " ; cin>> enlaces;

        if(!Redes.buscarEnrutador(nodoAdicional))  Redes.agregarEnrutador(nodoAdicional,enlaces);

        else cout << "El nodo ya existe" << endl;

        break;

    } case 2:{
        char nodoEliminar;

        cout << "Ingrese nodo a eliminar: "  ;cin>> nodoEliminar;

        Redes.eliminarEnrutador(nodoEliminar);

        break;

    } case 3:{
        char nodoPrincipal,nodoSecundario;int costoEnlace;

        cout << "Ingrese nodo principal: "  ;cin>>nodoPrincipal;

        cout << "Ingrese nodo enlazado: "  ;cin>>nodoSecundario;

        cout<< "Cuanto es costo del nuevo enlace: " ; cin>> costoEnlace;

        if(Redes.buscarEnrutador(nodoPrincipal)){

            if(Redes.buscarEnrutador(nodoSecundario)){

                Redes.modificarEnlaces(nodoPrincipal,nodoSecundario,costoEnlace);
                Redes.modificarEnlaces(nodoSecundario,nodoPrincipal,costoEnlace);

            }

            else cout << "El nodo a enlazar no existe" << endl;

        }

        else cout << "El nodo principal existe" << endl;


        break;

    }
    case 4:{

        char nodo;

        cout << "Ingrese el nodo el cual desea imprir su tabla: " ;cin>>nodo;

        Redes.imprimirEnrutador(nodo);

        break;
    }
    case 5:{

        Redes.imprimirRed();

        break;
    }
    default:{
        cout << "opcion no valida." << endl;

        break;
    }
    }
}
