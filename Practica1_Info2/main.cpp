/*Este programa soluciona los problemas de la practica 1 de laboratio de informatica 2.
 *  Este desplegaa un menu en donde el usuario ingresara un numero el cual determina el problema resolver
 * Autor: John Edisson Chamorro
 * Cargo: Estudiante Ingenieri­a Electronica
 * fecha: Diciembre 9,2021
 * Universidad de Antioquia
 */

#include<iostream>
using namespace std;


int main(){//funcion principal
    int numeroingresado=1;

    //8-11
    while(numeroingresado!=0){
        cout<<" Eliga la opcion: "<<endl;
        cout<<"1: Determina si el caracter ingresado es vocal/consonante/o ninguno de los anterioes"<<endl;
        cout<<"2: Minima combinacion de billetes"<<endl;
        cout<<"4: Conversion de numero a formato de hora"<<endl;
        cout<<"5: Patron rombo en pantalla"<<endl;
        cout<<"7: Serie Fibonacci"<<endl;
        cout<<"8: Suma los multiplos de a y b menores que c, siendo a,b y c numeros"<<endl;
        cout<<"9: Suma de todos los digitos elevados a si mismos"<<endl;
        cout<<"11: Calcula el mcm de todos los numeros entre 1 y el numero ingresado"<<endl;
        cout<<"12: Maximo factor primo"<<endl;
        cout<<"14: Numero palindromo"<<endl;
        cout<<"15: suma de diagonal"<<endl;
        cout<<"17: Secuencia de numeros triangulares"<<endl;
        cout<<"\nIngrese numero para la solucion de alguno de ellos,\n si requiere salir del programa ingrese el numero cero:";
        cin>>numeroingresado;
        cout<<endl;

        switch(numeroingresado){
        case 1:{
            cout<<"\nEste programa determina si el caracter ingresado es vocal, consonante o ninguno de los dos\n";
            cout<<" Ingres el cararcter: ";
            char caracter;
            cin>>caracter;
            if(caracter==65 || caracter==69 || caracter==73 || caracter==79 || caracter==85 || caracter==97 || caracter==101 || caracter==105 || caracter==111 || caracter==117){
                cout<<"\nEs vocal "<<endl;
            }
            else if((caracter>=65 & caracter<=90) || (caracter>=97 & caracter<=122)){
                cout<<"\nEs consonante"<<endl;
            }
            else{
                cout<<"\nNo es vocal, ni consonante"<<endl;
            }
            break;}
        case 2:{
            cout<<"Este programa determina la minima combinacion de billetes y monedas \n para una cantidad de dinero determinada\n ingrese cantidad de dinero a determinar: ";
            int dineroingresado;
            int k50,k20, k10, k5, k2,k1;
            int m500,m200,m100,m50;
            cin>>dineroingresado;
            k50=dineroingresado/50000;
            dineroingresado-=50000*k50;
            k20=dineroingresado/20000;
            dineroingresado-=20000*k20;
            k10=dineroingresado/10000;
            dineroingresado-=10000*k10;
            k5=dineroingresado/5000;
            dineroingresado-=5000*k5;
            k2=dineroingresado/2000;
            dineroingresado-=2000*k2;
            k1=dineroingresado/1000;
            dineroingresado-=1000*k1;
            m500=dineroingresado/500;
            dineroingresado-=500*m500;
            m200=dineroingresado/200;
            dineroingresado-=200*m200;
            m100=dineroingresado/100;
            dineroingresado-=100*m100;
            m50=dineroingresado/50;
            dineroingresado-=50*m50;

            cout<<"\n";
            cout<<"50000: "<<k50<<"\n";
            cout<<"20000: "<<k20<<"\n";
            cout<<"10000: "<<k10<<"\n";
            cout<<"5000: "<<k5<<"\n";
            cout<<"2000: "<<k2<<"\n";
            cout<<"1000: "<<k1<<"\n";
            cout<<"500: "<<m500<<"\n";
            cout<<"200: "<<m200<<"\n";
            cout<<"100: "<<m100<<"\n";
            cout<<"50: "<<m50<<"\n";
            cout<<"Faltante: "<<dineroingresado<<"\n";
            break;
        }
        case 4:{
            int hora1=0,hora2=0,hora1_1=0,hora2_2=0,min1=0,min2=0,dia=0;
            cout<<" Ingres el primer numero de 4 digitos maximo: ";
            cin>>hora1;
            cout<<" Ingres el segundo numero de 4 digitos maximo: ";
            cin>>hora2;

            min1=hora1%100; //extrer los numeros correspondientes a minutos
            hora1_1=(hora1-min1)/100;//extrar la hora
            cout<<"\n Hora 1 ingresada: "<<hora1_1<<":"<<min1<<endl;

            min2=hora2%100;
            hora2_2=(hora2-min2)/100;
            cout<<"\n Hora 2 ingresada: "<<hora2_2<<":"<<min2<<endl;
            if(hora1_1< 24 & hora2_2<24 & min1<60 & min2<60){
                hora1_1+=hora2_2;
                min1+=min2;
                if(min1 >=60){
                    hora1_1++;
                    min1-=60;
                }
                if(hora1_1>=24){
                    dia+=1;
                    hora1_1-=24;
                }
                cout<<"\n Hora final: "<<dia<<" dia(s) "<<hora1_1<<":"<<min1<<endl;
            }

            else{
                cout<<" El numero ingresado no corresponde a una hora valida"<<endl;
            }

            break;
        }
        case 5:{
            cout<<"\nEste programa grafica un rombo hecho con asteriscos\n ingrese el tamano de la figura con un numero impar:";
            int tamanodelrombo=0;
            cin>>tamanodelrombo;
            if(tamanodelrombo>0)
            {
                if(tamanodelrombo%2==0){tamanodelrombo++;}//determino si es par

                char *rombo=new char();//arreglo char dinamico

                for(int i=0;i<tamanodelrombo;i++){//ciclo para llenar de espacios el arreglo
                    rombo[i]=' ';
                }
                int i=0;
                while(i<=tamanodelrombo/2){
                    rombo[(tamanodelrombo/2)+i]='*';//de la mitad hacia extremos
                    rombo[(tamanodelrombo/2)-i]='*';
                    for(int j=0;j<tamanodelrombo;j++){//para imprimir el arreglo en cada cambio que se realice
                        cout<<rombo[j];
                    }
                    cout<<"\n";
                    i++;
                }
                for(int j=0;j<tamanodelrombo;j++){
                    rombo[j]=' ';
                    rombo[(tamanodelrombo-1)-j]=' ';//de extremos a centro
                    for(int k=0;k<tamanodelrombo;k++){//para imprimir el arreglo en cada cambio que se realice
                        cout<<rombo[k];}
                    cout<<"\n";}
            }
            else{cout<<"\nEl numero ingresado no es valido";}


            break;    }
        case 7:{
            int fini=0,fseg=1, limite, suma=0;
            cout<<"\nCalcula la suma de todos los numeros pares de la serie de fibonacci\n ingrese el limite de la serie:";
            cin>>limite;
            for(int i=0;i<limite;i++){
                cout<<fini<<", ";
                fseg+=fini;
                fini=fseg-fini;
                if(fini%2==0 && fini<limite){
                    suma+=fini;
                }
            }
            cout<<"\n el resultado de la suma es: "<<suma<<"\n";
            break;
        }
        case 8:{
            int a=0,b=0,c=0;
            cout<<"\nIngrese el numero a:";cin>>a;
            cout<<"\nIngrese el numero b:";cin>>b;
            cout<<"\nIngrese el numero c:";cin>>c;
            int *multiplosA = new int();
            int *multiplosB = new int();
            bool banderaA=true;
            bool banderaB=true,banderaDiferentes=true;
            int *i = new int{1};
            int *j= new int{1};
            int *contadorA=new int{0};
            int *contadorB=new int{0};
            int *suma = new int{0};

            while(banderaA){

                if(*i*a<c){

                    *(multiplosA+(*i-1))=*i*a;
                    *contadorA+=1;
                }if(*i*a>=c){
                    banderaA=false;
                }
                   *i+=1;
            }

            while(banderaB){

                if(*j*b<c){
                    for(int i=0;i<*contadorA;i++){
                        if(*(multiplosA+i)==*j*b){
                            banderaDiferentes=false;
                        }
                    }

                    if(banderaDiferentes){
                        *(multiplosB+(*j-1))=*j*b;
                        *contadorB+=1;

                    }
                    banderaDiferentes=true;

                }
                if(*j*b>=c){
                    banderaB=false;
                }
                *j+=1;
            }

            for(int i=0;i<*contadorA;i++){
                *suma+=*(multiplosA+i);
                cout<<*(multiplosA+i)<<" + ";
            }

            for(int i=0;i<*contadorB;i++){
                *suma+=*(multiplosB+i);
                cout<<*(multiplosB+i)<<" + ";
            }


            cout<< "= " << *suma<<endl;
            delete multiplosA;
            delete multiplosB;
            delete i;delete j;delete suma;delete contadorA; delete contadorB;
            break;
        }
        case 9:{
            int numero=0,contador=0,divisor=1,sumacadadigito=1,sumatotal=0;
            bool band=true;
            cout<<"\nEste programa calcula la suma de los digitos elevados por si mismos\ningrese numero: ";
            cin>>numero;
            while(band==true){//ciclo para determinar numero de digitos
                if(numero/divisor !=0){contador++;divisor*=10;}
                else{band=false;}
            }
            int vectorn[contador];
            divisor=10;
            for(int j=0;j<contador;j++){//ciclo para guardar numeros en arreglo desde la ultima posicion hacia arriba
                vectorn[contador-1-j]=numero%divisor;
                divisor*=10;
            }
            divisor=1;
            for(int j=0;j<contador-1;j++){divisor*=10;}//ciclo para inicializar el ciclo desde la cantidad requeridad para dividir primer digito del vector
            for(int j=0;j<contador-1;j++){//ciclo para volver unidades los numeros del vector
                vectorn[j]=(vectorn[j]-vectorn[j+1])/divisor;
                divisor/=10;
            }
            for(int j=0;j<contador;j++){
                int contador2=vectorn[j];
                for(int i=0;i<contador2;i++){
                    sumacadadigito*=vectorn[j];
                }
                sumatotal+=sumacadadigito;
                sumacadadigito=1;
            }

            cout<<"El resultado de la suma es: "<<sumatotal<<"\n";
            break;
        }
        case 11:{
            break;
        }
        case 12:{

            int NumMFP=0,i=2,j=0;
            cout<<"\nEste programa calcula el maximo factor primo \n Ingrese numero a= ";
            cin>>NumMFP    ;
            int *MFP= new int[10];

            for(int i=0;i<sizeof (MFP);i++){//inicializo en ceros arreglo
                *(MFP+i)=0;
            }

            for(;;i++)//Determinar Factor Comun
            {
                if(i==2 || i%2!=0){//solo numeros primos
                    if(NumMFP==1){//final del factor comun?
                        break;
                    }
                    if(NumMFP%i==0){//factor comun
                        NumMFP/=i;
                        *(MFP+j)=i;
                        i=2;
                        j++;
                    }
                }
            }
            NumMFP=*MFP;
            for(int i=0;i<sizeof(MFP)-1;i++){
                int b=*(MFP+i);
                if(NumMFP<b){
                    NumMFP=*(MFP+i);
                }

            }
            delete [] MFP;
            cout<<"\nEl maximo Factor primo es: "<<NumMFP<<endl;
            break;
        }
        case 14:{
            cout<<"Programa que encuentra el palindromo mas grande de multiplicar de 3 digitos"<<endl;
            int Producto, revproducto, Reversa, Max, actuI, actuJ;
            Max = 0;
            for(int i=100; i<1000; i++){
                for(int j=100; j<1000; j++){
                    Producto = i * j;
                    revproducto = Producto;
                    Reversa = 0;
                    while (revproducto > 0) {
                        Reversa = (Reversa * 10) + (revproducto % 10);
                        revproducto = revproducto / 10;
                    }
                    if((Reversa == Producto) && (Producto > Max)){
                        Max = Producto;
                        actuI = i;
                        actuJ = j;
                    }
                }
            }
            cout << actuI << " * " << actuJ << " = " << Max << endl ;
            break;

        }
        case 15:{
            int tamM=0,sumM=0,pos1=0,pos2=0;
            cout<<"\nEste programa calcula la suma de la diagonal \n Ingrese el tamano de la matriz= ";
            cin>>tamM;
            int *Matriz=new int[tamM*tamM];

            for(int i=0;i<tamM*tamM;i++){//inicializo arreglo
                *(Matriz+i)=i+1;
            }

            for(int i=0;;i+=2){//diagonal 1
                pos1+=i;
                if(pos1<tamM*tamM){
                    sumM+=*(Matriz+pos1);

                }
                else{break;}

            }

            for(int i=4;;i+=4){//diagonal 2

                if(pos2<tamM*tamM-1){
                    sumM+=*(Matriz+i+pos2);
                    pos2+=i;
                    sumM+=*(Matriz+i+pos2);

                }
                else{break;}
                pos2+=i;
            }


            delete [] Matriz;
            cout<<"\nLa suma de la diagonal es: "<<sumM<<endl;

            break;
        }
        case 17:{int ntriangular=0,kdivisores=0,posicion=1,cont=0;
            cout<<"\nEste programa calcula el numero triangular k\n que tiene mas de k divisores\nIngrese numero k: ";
            cin>>kdivisores;
            bool ban=true;

            while(ban==true)
            {   cont=0;
                ntriangular+=posicion;
                if(ntriangular!=1)
                {

                    for(int i=1;i<=ntriangular;i++)
                    {
                        if(ntriangular%i==0){cont++;}
                    }

                }
                posicion++;
                if(cont>kdivisores){ban=false;}

            }
            cout<<"El numero es: "<< ntriangular<<" que tiene "<< cont<<" divisores\n";
            break;
        }
        default:{cout<<"\n El numero ingresado no corresponde al \n grupo de problemas que se asignaron para resolver";
            break;
        }}
        system("pause");
        system("CLS");

    }




    ;


    return 0;

}
