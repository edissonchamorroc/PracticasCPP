#include "ficheros.h"


ficheros::ficheros()
{

}

void ficheros::lecturaFichero(string nombreFichero, QGraphicsScene *scene,QList<muroEstatico*> &murosEstaticos,QList<MuroDinamico*> &murosDinamicos)
{
    ifstream lector;
    lector.open(nombreFichero);
    string leido;
    int posicion[4],contador=0;

    if(!lector.fail()){

        while(!lector.eof()){

            lector>>leido;
            posicion[contador]=utilidades::conversionStr2Int(leido);
            contador++;

            if(contador==4){

                if(nombreFichero=="murosEstaticos.txt"){
                    murosEstaticos.append(new muroEstatico(posicion[0],posicion[1],posicion[2],posicion[3]));
                    scene->addItem(murosEstaticos.back());
                    posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                    contador=0;
                }

                else if(nombreFichero=="murosDinamicos.txt"){
                    murosDinamicos.append(new MuroDinamico(posicion[0],posicion[1],posicion[2],posicion[3]));
                    scene->addItem(murosDinamicos.back());
                    posicion[0]=0;posicion[1]=0;posicion[2]=0;posicion[3]=0;
                    contador=0;
                }

            }

        }
    }
    lector.close();
}


