#include "ficheros.h"

ficheros::ficheros()
{

}

ficheros::ficheros(string nombreFichero)
{
    this->nombreFichero=nombreFichero;

}

void ficheros::setNombreFichero(string nombrefichero)
{
    nombreFichero=nombrefichero;
    nombreFichero+=".txt";
}

void ficheros::lecturaEnrutadores()
{

   lector.open(nombreFichero);

    bool final=false;

    string leido;

    if(!lector.fail()){

        while(!final){
            lector>>lectura;
            if(lectura!="-"){
                leido+=lectura;
            }
            else    final=true;

        }
    }
    else{
        cout << "El archivo no existe" << endl;
    }

    lectura=leido;

    lector.close();
}

void ficheros::modificarRelacion(red &Redes)
{

    escrituraEnlaces();

    lector.open("enlaces.txt");

    char nodo1, nodo2;string valorEnlace; int valor=0;

    if(!lector.fail())
    {
       while(!lector.eof())//ciclo definir relacion de enrutadores
         {
         lector>>nodo1;
         lector>>nodo2;
         lector>>valorEnlace;
         valor=converChr2Int(valorEnlace);
         Redes.modificarEnlaces(nodo1,nodo2,valor);//aqui se genera la sobrecarga
         }
    }
    else{
        cout << "El archivo no existe" << endl;
    }

    lector.close();
    remove("enlaces.txt");

}

void ficheros::escrituraEnlaces()
{
    lector.open(nombreFichero); escritor.open("enlaces.txt",ios::app);

    bool final=false; string lec;

    if(!lector.fail())
    {
        while(!final){
            lector>>lec;
            if(lec=="-"){
                while(!lector.eof())
                {
                    lector>>lec;
                    escritor<<lec;
                    lector>>lec;
                    escritor<<lec;
                    lector>>lec;
                    escritor<<lec<<"\n";

                }
                final=true;
            }

        }
    }
    else{
        cout << "El archivo no existe" << endl;
    }

    lector.close();
    escritor.close();

}

int ficheros::converChr2Int(string numero)
{
    int multi=1,char2int=0;
    for(int i=0;i<numero.size()-1;++i)
    {
        multi*=10;
    }
    for(int i=0;i<numero.size();++i){
       char2int+=(numero.at(i)-48)*multi;
       multi/=10;
    }
    return char2int;

}

string ficheros::getLectura()
{
 return lectura;
}
