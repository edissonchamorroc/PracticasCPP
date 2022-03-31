/* Autor: John Edisson Chamorro Coral
 * Cargo: Estudiante Ingenieri­a Electronica
 * Entidad: Universidad de Antioquia
 * Funcion: Este programa realiza manejo de ficheros y con base en ello se aplica generando 3 programas que consisten en:
 * 1.Codificacion de textos basado en dos metodos planteados por el docente
 * 2.Decodificacion de textos que previamente fueron codificados con alguno de los dos metodos anteriores
 * 3.simulacion de un cajero con la diferencia que en este hay un usuario administrador, que puede realizar cambios si ingresa la
 * contrasena correcta(previamente codificada), y se encarga de ingresa o eliminar usuarios, o cambiar simplemente su contrasena.
 * Para el usuario normal solo se puede verificar y retirar su saldo. En cada accion de usuario normal se descontara 1000 unidades
 * de su moneda local por lo que se mostrara¡ en pantalla su saldo actualizado*/

#include <iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include<math.h>
using namespace std;
string char2bin(string);
void codificacion1(string ,string &,int );
void codificacion2(string ,string &codificado,int semilla);
void decodificacion1(string binario,string &codificado,int semilla);
void decodificacion2(string textoleido,string &codificado,int semilla);
long int char2int(string arreglo);
long int multiplo(string arreglo);
void int2char(string &arreglo,long int numero);


int main()
{   int semilla=0,eleccionusuario=0,metodocodificacion=0;
    char *tituloarchivo=new char(),*tituloaguardar=new char();
    string banderaf="no";

    while(banderaf=="no")
    {   cout<<"Que desea realizar? \n1.Codificacion\n2.Decodificacion\n3.Simulador Cajero."<<endl;
        cin>>eleccionusuario;
        switch (eleccionusuario){
        case 1:
        {
            char caracter;ofstream escritor;ifstream lector;string textoleido,codificado,binario;
            cout<<"\nIngrese metodo de codificacion (1 o 2): ";
            cin>>metodocodificacion;
            cout<<"\nIngrese semilla para codificar o con la cual codifico: ";
            cin>>semilla;
            cout<<"\nIngrese el titulo del archivo a codificar - 'titulo.txt': ";
            cin>>tituloarchivo;
            lector.open(tituloarchivo);
            if(!lector.fail())
            {
                while(!lector.eof())//guardo caracter a caracter del todo el fichero
                {
                    lector.get(caracter);
                    if(caracter!=0)textoleido+=caracter;
                    caracter={0};//limpio variable
                }
                binario=char2bin(textoleido);//utilizo funcion char2bin
                //escritor.close();
                lector.close();
                cout<<"\nTexto obtenido: \n";
                cout<<textoleido<<endl;
                cout<<"Texto en formato binario:\n";
                cout<<binario<<endl;
                switch (metodocodificacion) {
                case 1:{

                    cout<<"Codificacion:\n ";
                    codificacion1(binario,codificado,semilla);
                    cout<<codificado<<endl;
                    cout<<"Ingre el nombre del archivo donde guardara la codificacion -'titulo.txt': ";
                    cin>>tituloaguardar;
                    escritor.open(tituloaguardar,ios::app);
                    escritor<<codificado;
                    escritor.close();
                    break;
                }
                case 2:
                {
                    cout<<"Codificacion:\n ";
                    codificacion2(binario,codificado,semilla);
                    cout<<codificado<<endl;
                    cout<<"Ingre el nombre del archivo donde guardara la codificacion -'titulo.txt': ";
                    cin>>tituloaguardar;
                    escritor.open(tituloaguardar,ios::app);
                    escritor<<codificado;
                    escritor.close();
                    break;
                }
                default:{cout<<"\nNo existe esa categoria de codificacion"<<endl;break;}}}
            else
            {
                cout<<"Error, no existe ese fichero"<<endl;
            }
            break;
        }
        case 2:
        {
            int cualmetodo=0,cualsemilla=0;char deseo[2],caracter;string textoleido,codificado,binario;
            ifstream lectordeco;ofstream escritodeco;
            cout<<"\n Ingrese el titulo del texto a decodificar  (titulo.txt): ";
            cin>>tituloarchivo;
            cout<<"\n Que metodo se uso?: ";
            cin>>cualmetodo;
            cout<<"\n Que semilla se uso?: ";
            cin>>cualsemilla;
            lectordeco.open(tituloarchivo);
            if(!lectordeco.fail())
            {
                while(!lectordeco.eof())//guardo caracter a caracter del todo el fichero
                {
                    lectordeco.get(caracter);
                    if(caracter!=0)textoleido+=caracter;
                    caracter={0};//limpio variable
                }
                lectordeco.close();
                cout<<"\nTexto obtenido: \n";
                cout<<textoleido<<endl;
                if(cualmetodo==1){ decodificacion1(textoleido,codificado,cualsemilla);}
                else{decodificacion2(textoleido,codificado,cualsemilla);}
                cout<<"\nDecodificacion: ";
                cout<<codificado<<endl;
                cout<<"\nDesear guardar lo decodificado?(si/no): ";
                cin>>deseo;
                if(deseo[0]=='s'){
                    char *decodificacion=new char();
                    ofstream escrito;
                    cout<<"\nIngrese el nombre del archivo donde va a guardar lo decodificado-titulo.txt: ";
                    cin>>decodificacion;
                    escrito.open(decodificacion);
                    escrito<<codificado;
                    escrito.close();
                    delete decodificacion;
                }
            }
            else
            {
                cout<<"Error, no existe ese fichero"<<endl;
            }


            break;
        }
        case 3:
        {   //contrasena SUDO: 17860,semilla=4,metodo=2
            int tipodeusuario,opnormal=0,opadmin=0,semilla=0,metodo=0;ifstream lectoradm,lectorusu;ofstream escritoradm,escritorusu;char *contrasena=new char();
            string cedula,clave,saldo,textoleido,textocompleto,ingresodatos="si";char carat;
            //---------------------------- decodificacion de datos de usuarios
            textocompleto.clear();
            textoleido.clear();
            lectoradm.open("usuarios.txt");//aqui inicio la decodificacion del documento usuarios
            escritoradm.open("temp.txt");
            while(!lectoradm.eof())//guardo caracter a caracter del todo el fichero
            {
                lectoradm.get(carat);
                if(carat!=0)textoleido+=carat;
                carat={0};//limpio variable
            }
            decodificacion1(textoleido,textocompleto,6);
            escritoradm<<textocompleto;
            textocompleto.clear();
            textoleido.clear();
            lectoradm.close();
            escritoradm.close();
            remove("usuarios.txt");
            rename("temp.txt","usuarios.txt");
            //-------------------------------------------------------------------------
            cout<<"\nIngrese 1.Usuario Administrador. 2.Usuario normal: ";
            cin>>tipodeusuario;
            if(tipodeusuario==1)
            {
                cout<<"\nIngrese contrasena de administrador: ";
                cin>>contrasena;
                cout<<"\nIngrese metodo de codificacion: ";
                cin>>metodo;
                cout<<"\nIngrese semilla de codificacion: ";
                cin>>semilla;
                lectoradm.open("SUDO.txt");
                lectoradm>>textoleido;
                if(metodo==1){decodificacion1(textoleido,clave,semilla);}
                else {decodificacion2(textoleido,clave,semilla);}
                if(clave==contrasena)
                {
                    lectoradm.close();
                    while(opadmin!=4)
                    {
                        cout<<"Que desea hacer?\n1.Ingresar nuevo usuario.\n2.Eliminar Usuario.\n3.Cambiar contrasena.\n4.Salir: ";
                        cin>>opadmin;
                        if(opadmin==1)
                        {
                            bool bandera=true;
                            escritoradm.open("usuarios.txt",ios::app);
                            while(ingresodatos=="si")
                            {
                                cout<<"\nIngrese cedula: ";
                                cin>>cedula;
                                lectoradm.open("usuarios.txt");

                                while(!lectoradm.eof())
                                {
                                    lectoradm>>textoleido;
                                    if(textoleido==cedula){cout<<"\nCedula existente";bandera=false;}
                                    lectoradm>>textoleido>>textoleido;
                                }
                                if(bandera==true){
                                    lectoradm.close();
                                    escritoradm<<endl;
                                    cout<<"\nIngrese contrasena: ";
                                    cin>>clave;
                                    cout<<"\nIngrese Saldo: ";
                                    cin>>saldo;
                                    escritoradm<<cedula<<" "<<clave<<" "<<saldo;
                                    escritoradm<<endl;
                                    cout<<"\nDesea ingresar mas usuarios?:(si/no): ";
                                    cin>>ingresodatos;
                                }
                                lectoradm.close();
                                bandera=true;
                            }
                            escritoradm.close();
                            break;
                        }
                        //------------------------------------------------------------------
                        else if(opadmin==2) {//Inicio de la opcion 2 eliminar usuario
                            bool bandera=true;
                            lectoradm.open("usuarios.txt");
                            escritoradm.open("temp.txt",ios::app);
                            cout<<"\nIngrese Cedula de usuario a eliminar: ";
                            cin>>cedula;
                            while(!lectoradm.eof())
                            {
                                lectoradm>>textoleido;//lectura de cedula
                                if(textoleido==cedula)
                                {
                                    cout<<"\nCedula:"<<textoleido;
                                    lectoradm>>textoleido;//clave
                                    cout<<"\nClave: "<<textoleido;
                                    lectoradm>>textoleido;//saldo
                                    cout<<"\nSaldo: "<<textoleido;
                                    cout<<"\nUsuario eliminado"<<endl;
                                    textoleido.clear();
                                    bandera=false;
                                }
                                else
                                {   if(textoleido!="")
                                    {
                                        escritoradm<<textoleido;//escribo cedula
                                        lectoradm>>textoleido;
                                        escritoradm<<" "<<textoleido;//escribo clave
                                        lectoradm>>textoleido;
                                        escritoradm<<" "<<textoleido;//saldo
                                        escritoradm<<endl;
                                    }
                                }

                            }
                            if(bandera==true){
                                cout<<"\nUsuario no existe"<<endl;
                            }
                            lectoradm.close();
                            escritoradm.close();
                            remove("usuarios.txt");
                            rename("temp.txt","usuarios.txt");
                            break;
                        }
                        //-----------------------------------------------------------------------
                        else if(opadmin==3) {//inicio opcion 3 cambio de clave
                            bool bandera=true;
                            lectoradm.open("usuarios.txt");
                            escritoradm.open("temp.txt",ios::app);
                            cout<<"\nIngrese Cedula de usuario para cambiar clave: ";
                            cin>>cedula;
                            while(!lectoradm.eof())
                            {
                                lectoradm>>textoleido;//lectura de cedula
                                if(textoleido==cedula)
                                {
                                    cout<<"\nCedula:"<<textoleido;
                                    escritoradm<<textoleido<<" ";
                                    lectoradm>>textoleido;//clave
                                    cout<<"\nClave actual: "<<textoleido;
                                    cout<<"\nIngrese clave nueva:";cin>>textoleido;
                                    escritoradm<<textoleido;
                                    lectoradm>>textoleido;//saldo
                                    escritoradm<<" "<<textoleido<<endl;
                                    textoleido.clear();
                                    bandera=false;
                                }
                                else
                                {   if(textoleido!="")
                                    {
                                        escritoradm<<textoleido;//escribo cedula
                                        lectoradm>>textoleido;
                                        escritoradm<<" "<<textoleido;//escribo clave
                                        lectoradm>>textoleido;
                                        escritoradm<<" "<<textoleido<<endl;//saldo
                                        textoleido.clear();
                                    }
                                }

                            }
                            if(bandera==true){
                                cout<<"\nUsuario no existe"<<endl;
                            }
                            lectoradm.close();
                            escritoradm.close();
                            remove("usuarios.txt");
                            rename("temp.txt","usuarios.txt");
                            break;
                        }
                    }

                }
                else{cout<<"\nContrasena invalida"<<endl;}

            }

            else//codigo para cuando el usuario ingresa como normal
            {

                while(opnormal!=3)
                {
                    cout<<"\n1.Consultar Saldo.\n2.Retirar saldo.\n3.Salir: ";
                    cin>>opnormal;

                    if(opnormal==1)//si solo requiere consulta de saldo
                    {
                        int long sald=0;bool bandera=true;
                        cout<<"Ingrese su cedula: ";cin>>cedula;
                        cout<<"Ingrese su clave: ";cin>>clave;
                        lectorusu.open("usuarios.txt");
                        escritorusu.open("temp.txt");
                        while(!lectorusu.eof())
                        {
                            lectorusu>>textoleido;//lectura de cedula
                            if(textoleido==cedula)
                            {
                                escritorusu<<textoleido<<" ";
                                lectorusu>>textoleido;//leo clave
                                if(textoleido==clave)
                                {
                                escritorusu<<textoleido<<" ";
                                lectorusu>>textoleido;//saldo
                                sald=char2int(textoleido);
                                sald-=1000;
                                int2char(textoleido,sald);
                                cout<<"\nSaldo: "<<textoleido;
                                escritorusu<<textoleido<<endl;
                                textoleido.clear();
                                bandera=false;
                                }
                                else
                                {
                                    cout<<"\nClave Invalida"<<endl;
                                    escritorusu<<textoleido<<" ";
                                    lectorusu>>textoleido;//leo clave
                                    escritorusu<<textoleido<<" ";
                                    lectorusu>>textoleido;//leo saldo
                                    escritorusu<<textoleido<<endl;
                                    textoleido.clear();
                                    bandera=false;
                                }
                            }
                            else
                            {   if(textoleido!="")
                                {
                                    escritorusu<<textoleido;//escribo cedula
                                    lectorusu>>textoleido;
                                    escritorusu<<" "<<textoleido;//escribo clave
                                    lectorusu>>textoleido;
                                    escritorusu<<" "<<textoleido<<endl;//saldo
                                    textoleido.clear();
                                }
                            }

                        }
                        if(bandera==true)
                        {
                            cout<<"\nUsuario no existe"<<endl;
                        }
                        lectorusu.close();
                        escritorusu.close();
                        remove("usuarios.txt");
                        rename("temp.txt","usuarios.txt");
                    }
                    else if(opnormal==2)//cuando usuario elige retirar saldo
                    {
                        int long sald=1000,retiro=0;bool bandera=true;
                        cout<<"Ingrese su cedula: ";cin>>cedula;
                        cout<<"Ingrese su clave: ";cin>>clave;
                        lectorusu.open("usuarios.txt");
                        escritorusu.open("temp.txt");
                        while(!lectorusu.eof())
                        {
                            lectorusu>>textoleido;//lectura de cedula
                            if(textoleido==cedula)
                            {
                                escritorusu<<textoleido<<" ";
                                lectorusu>>textoleido;//leo clave
                                if(textoleido==clave)
                                {
                                escritorusu<<textoleido<<" ";
                                lectorusu>>textoleido;//saldo
                                cout<<"\nCuanto desea retirar?: ";cin>>retiro;
                                retiro+=sald;
                                sald=char2int(textoleido);
                                if(sald>=retiro)
                                {
                                    sald-=retiro;
                                    int2char(textoleido,sald);
                                    cout<<"\nSaldo: "<<textoleido;
                                    escritorusu<<textoleido<<endl;
                                    textoleido.clear();
                                    bandera=false;
                                }
                                else{cout<<"\nNo tiene esa cantidad"<<endl;escritorusu<<textoleido;textoleido.clear();bandera=false;}
                                }
                                else
                                {
                                    cout<<"\nClave Invalida"<<endl;
                                    escritorusu<<textoleido<<" ";
                                    lectorusu>>textoleido;//leo clave
                                    escritorusu<<textoleido<<" ";
                                    lectorusu>>textoleido;//leo saldo
                                    escritorusu<<textoleido<<endl;
                                    textoleido.clear();
                                    bandera=false;
                                }

                            }
                            else
                            {   if(textoleido!="")
                                {
                                    escritorusu<<textoleido;//escribo cedula
                                    lectorusu>>textoleido;
                                    escritorusu<<" "<<textoleido;//escribo clave
                                    lectorusu>>textoleido;
                                    escritorusu<<" "<<textoleido<<endl;//saldo
                                    textoleido.clear();
                                }
                            }

                        }
                        if(bandera==true)
                        {
                            cout<<"\nUsuario no existe"<<endl;
                        }
                        lectorusu.close();
                        escritorusu.close();
                        remove("usuarios.txt");
                        rename("temp.txt","usuarios.txt");

                    }

                }
            }
            //---------------------------- codificacion de datos de usuarios
            textocompleto.clear();
            textoleido.clear();
            lectoradm.open("usuarios.txt");//aqui inicio la decodificacion del documento usuarios
            escritoradm.open("temp.txt");
            while(!lectoradm.eof())//guardo caracter a caracter del todo el fichero
            {
                lectoradm.get(carat);
                if(carat!=0)textoleido+=carat;
                carat={0};//limpio variable
            }
            textocompleto=char2bin(textoleido);
            textoleido.clear();
            textoleido=textocompleto;
            textocompleto.clear();
            codificacion1(textoleido,textocompleto,6);
            escritoradm<<textocompleto;
            textocompleto.clear();
            textoleido.clear();
            lectoradm.close();
            escritoradm.close();
            remove("usuarios.txt");
            rename("temp.txt","usuarios.txt");
            //-------------------------------------------------------------------------
            break;
        }
        default:
            cout<<"\nOpcion no valida, Por favor Ingrese una valida"<<endl;
            break;
        }

        cout<<"Si desea salir (si/no): ";
        cin>>banderaf;
        system("pause");
        system("CLS");
    }
    delete tituloaguardar;
    delete tituloarchivo;
    return 0;
}
//------------------------------ conversor de caracter a binario--------------------------------------
string char2bin(string textoleido){//funcion correcta conversion a binario
    char bin[8];int salto=0;
    string binario;
    for(int j=0;j<textoleido.size();j++)//ciclo en todo el texto leido
    {
        for(int i=0;i<8;i++)//conversion a bit del caracter
        {
            bin[7-i]=(textoleido[j]%2)?'1':'0';
            textoleido[j]/=2;
        }
        for(int i=0;i<8;i++)//guardo lo convertido en el string binario
        {
            binario+=bin[i];
        }
        salto+=8;//salto para el otro caracter
    }
    return binario;
}
//------------------------------primer metodo de codificaciÃ³n--------------------------------------

void codificacion1(string binario,string &codificado,int semilla){
    int count1=0,count0=0,ini=0,incremento=0;
    //int tamanotexto=binario.size();
    codificado=binario;

    for(int i=0;i<semilla;i++)//cambio en el primer bloque
    {
        if(binario[i]=='0')codificado[i]='1';
        else codificado[i]='0';
    }

    for(int j=0;j<binario.size()-semilla;j+=semilla)
    {
        for(int i=0+j;i<semilla+j;i++)//conteo de binarios en el bloque anterior
        {
            if(binario[i]=='0')count0++;
            else count1++;
        }

        if(count0==count1)
        {
            ini=0; incremento=1;
        }
        else if(count0>count1)
        {
            ini=1; incremento=2;
        }
        else
        {
            ini=2; incremento=3;
        }

        for(int k=ini+j+semilla;k<semilla*2+j;k+=incremento)//cambios segun conteo
        {
            if(codificado[k]=='0')codificado[k]='1';
            else codificado[k]='0';
        }
        count0=0;
        count1=0;
    }

}

//------------------------------segundo metodo de codificacion--------------------------------------
void codificacion2(string binario,string &codificado,int semilla){
    codificado=binario;
    if(binario.size()%semilla !=0)
    {
        for(int i=0;i<binario.size() ;i+=semilla)//salto por bloques
        {
            if(i < binario.size() - 2)
            {
                codificado[i]=binario[semilla+i-1];//ultimo a primero
                for(int j=0;j<semilla-1;j++)//recorro bits
                {
                    codificado[j+i+1]=binario[j+i];
                }
            }
            else
            {
                codificado[i]=binario[i+1];
                codificado[i+1]=binario[i];
            }
        }
    }
    else
    {
        for(int i=0;i<binario.size() ;i+=semilla)//salto por bloques
        {

            codificado[i]=binario[semilla+i-1];
            for(int j=0;j<semilla-1;j++)//recorro bits
            {
                codificado[j+i+1]=binario[j+i];
            }

        }
    }
}

//---------------------------------------
void decodificacion1(string binario,string &codificado,int semilla){
    int count1=0,count0=0,ini=0,incremento=0,potencia=128;
    int decodificado=0;string deco;
    codificado=binario;

        for(int i=0;i<semilla;i++)//cambio en el primer bloque
        {
            if(binario[i]=='0')codificado[i]='1';
            else codificado[i]='0';
        }

        for(int j=0;j<binario.size()-semilla;j+=semilla)
        {
            for(int i=0+j;i<semilla+j;i++)//conteo de binarios en el bloque anterior
            {
                if(codificado[i]=='0')count0++;
                else count1++;
            }
            if(count0==count1)
            {
                ini=0; incremento=1;
            }
            else if(count0>count1)
            {

                ini=1; incremento=2;
            }
            else
            {
                ini=2; incremento=3;
            }

            for(int k=ini+j+semilla;k<semilla*2+j;k+=incremento)//cambios segun conteo
            {
                if(codificado[k]=='0')codificado[k]='1';
                else if(codificado[k]=='1') codificado[k]='0';
            }
            count0=0;
            count1=0;
        }


        for(int i=0;i<codificado.size()-1;i+=8)
        {
            for(int j=0;j<8;j++)
            {
                decodificado+=(codificado[j+i]-48)*(potencia);
                potencia/=2;
            }
            deco+=decodificado;
            decodificado=0;
            potencia=128;
        }
        codificado=deco;
    }

//---------------------------------------------------------------
void decodificacion2(string textoleido,string &codificado,int semilla){
    string deco;
    char decodificado={};int potencia=128;
    for(int j=0;j<semilla-1;j++)
    {
        codificacion2(textoleido,codificado,semilla);
        textoleido=codificado;
    }
    for(int i=0;i<textoleido.size();i+=8)
    {
        for(int j=0;j<8;j++)
        {
            decodificado+=(textoleido[j+i]-48)*(potencia);
            potencia/=2;
        }
        deco+=decodificado;
        decodificado=0;
        potencia=128;
    }
    codificado=deco;
}
//--------------------------------------------------------------------------
long int char2int(string arreglo){
    long int chartoint=0,multip=multiplo(arreglo);
    for(int i=0;i<arreglo.size();++i){
        chartoint+=(arreglo[i]-48)*multip;
        multip/=10;

    }
    return chartoint;
}
long int multiplo(string arreglo){
    long int multi=1;
    for(int i=0;i<arreglo.size()-1;++i)
    {
        multi*=10;
    }
    return multi;
}
//-------------------------------------------------------------------------
void int2char(string &arreglo,long int numero){
    long int multi=multiplo(arreglo),num=0;
    for(int i=0;i<arreglo.size();i++)
    {
        num=numero/multi;
        numero=numero-(num*multi);
        arreglo[i]=num+48;
        multi/=10;
    }
}
