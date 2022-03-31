#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream escritor;string textoleido,tituloaguardar;
    tituloaguardar="murosDinamicos.txt";
    escritor.open(tituloaguardar,ios::app);
   /* for(int i=74;i<1110;i+=74){

        textoleido="-"+to_string(i)+" -370 37 37";
        escritor<<textoleido;
        escritor<<endl;
    }*/
    for(int j=74;j<444;j+=37){
        for(int i=37;i<1110;i+=37){

            textoleido="-"+to_string(i)+" -"+to_string(j)+" 37 37";
            escritor<<textoleido;
            escritor<<endl;
        }

    }

    escritor.close();
}
//i=0 i<1110 -i 0 37 37 arriba
//i=37 i<=444 0 -i 37 37 izq
//i=37 i<1110 -i -444 37 37 abajo
//i=37 i<=444 -1110 -i 37 37 der
//i=74 i<1110 -i -74 37 37 intermedias primera fila
