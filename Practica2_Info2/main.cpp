/*Este programa soluciona 10 problemas de la
 * practica 2 de laboratio de informatica 2.
 *  Este desplegara un menu en donde el usuario
 *  ingresara un numero el cual determina el problema
 *  resolver
 * Autor: John Edisson Chamorro
 * Cargo: Estudiante Ingenieria Electronica
 * fecha: Enero 6,2022
 * Universidad de Antioquia
 */

#include<iostream>
using namespace std;

void imprimirCadena(char *);
//-------------------------------------------
void descomposiciondinero(int );
//------------------------------------------
char * generaarreglo();
void contarCaracteresEnArray(char []);
//-----------------------------------------
int tamanodearreglochar(char *);
long int multiplo(int );
long int char2int(char *,long int ,int );
int conversionChar2Int(char *ptr);
char * seperarCaracteresAlpha(char *);
char * seperarCaracteresNumericos(char *);
//--------------------------------------------
int counterDigits(int );
int * splitNumber(int , int );
string convertNumber2String(int * ,int );
//--------------------------------------------
void minusculas2MAYUSCULAS(char *);
//-------------------------------------------
void eliminarcaracter(int ,char *);
//--------------------------------------------
void fraccionararreglo(char *, int );
//--------------------------------------------------
void determinarmatrizmagica(int ,int **);
void llenarmatriz(int , int ** );
void imprimirmatriz(int,int , int **);
//---------------------------------------------------
unsigned long long int factorial(int );
//---------------------------------------------------
bool comparition(char *,char *);
//---------------------------------------------------
void rom2arb(char *);
//---------------------------------------------------
void starts(int **);
//---------------------------------------------------
bool verificarCaracteresNumericos(char *);
int sumaCaracteresEnBloque(char * , int );
void agregarCerosACadena(char * );
char ** crearMatrizCine();
void imprimirMatrizChar(char ** );
bool disponibilidadAsiento(int fila, int columna, char **matriz);
void reservaCancelaAsientoCine(int fila,int columna,char **matriz);
int filaLetra2Numero(char );
int * generarRectangulo();
bool intercepcionRectangulosEjeX(int *rectangulo1,int *rectangulo2);
int * generarItercepcion(int * rectangulo1,int * rectangulo2);

int main(){
    int problema=1;
    while(problema!=0){
        //puntos 1-2-3-5-6-7-10-12-13-16
        //faltan 15
        cout<<"\nSolucion de practica de laboratorio N2 de Informatica "
              "2\n*******************************************************************************\n";
        cout<<"\nIngrese nuemero del ejercicio que quiera resolver:"
              "\n1:Descompone cantidad de dinero en denominacion de dinero colombiano"
              "\n2:Genera un arreglo de letras mayusculas y determina cuantas veces se repite cada letra"
              "\n3:Determinar si las cadenas son iguales"
              "\n4:Recibe una cadena de caracteres numericos y lo convierte a tipo entero"
              "\n5:Recibe un numero tipo entero y convierte el numero a representacion string"
              "\n6:Programa que convierte letras minusculas en mayusculas"
              "\n7:Programa que elimina caracteres repetidos"
              "\n8:Programa que separar caracteres numericos de los otros caracteres:"
              "\n9: Divide cadena de caracteres numericos y lo suma en bloques"
              "\n10: Conversion de numero Romano a Arabico"
              "\n11: Simulador de asientos de sala cine"
              "\n12:Programa que determina un cuadrado magico"
              "\n13: Determina cuantas estrellas hay en una matriz"
              "\n15: Interseccion entre rectangulos"
              "\n16: Programa que determinar cuantos caminos posibles hay"
              "\n\nSi requiere salir del programa ingrese el numero cero:\n";
        cin>>problema;

        switch(problema){
        case 1:{
            cout<<"\nIngrese el dinero a descomponer: ";
            int dinero;
            cin>>dinero;
            descomposiciondinero(dinero);
            break;
        }
        case 2:{
            cout<<"\nProcesando..."<<endl;
            char *arreglo= new char();
            arreglo=generaarreglo();
            contarCaracteresEnArray(arreglo);

            break;
        }
        case 3:{
            char *cadena1=new char(),*cadena2=new char();
            cout<<"\nIngrese 1era cadena de caracteres:"<<endl;
            cin>>cadena1;
            cout<<"\nIngrese 2da cadena de caracteres:"<<endl;
            cin>>cadena2;

            if(comparition(cadena1,cadena2))
            {
                cout<<"\nlas cadenas ingresadas son iguales"<<endl;
            }
            else cout<<"\nlas cadenas ingresadas no son iguales"<<endl;
            delete cadena1;delete cadena2;
            break;
        }
        case 4:{
            char *cadenaCaracteres= new char();
            cout<<"\nIngrese la cadena de caracteres numericos para convertir a tipo entero: ";
            cin>>cadenaCaracteres;
            cout<< "La cadena de caracteres ingresada fue: ";
            imprimirCadena(cadenaCaracteres) ;
            cout << " y fue convertida el entero: " <<conversionChar2Int(cadenaCaracteres) <<endl;
            break;
        }
        case 5:{
            int numeroEntero=0;
            cout<<"\nIngrese el numero entero para convertir a tipo string: ";
            cin>>numeroEntero;
            int digits=counterDigits(numeroEntero);
            cout<<convertNumber2String(splitNumber(numeroEntero,digits), digits)<<endl;

            break;
        }
        case 6:{
            cout<<"\nIngrese palabra: ";
            char *palabra;
            palabra=new char();
            cin>>palabra;
            minusculas2MAYUSCULAS(palabra);
            delete palabra;
            break;
        }
        case 7:{
            cout<<"\nIngrese cadena de caracteres:";
            char *cadena;
            cadena=new char();
            cin>>cadena;

            int tamacad;
            tamacad=tamanodearreglochar(cadena);
            eliminarcaracter(tamacad,cadena);
            delete cadena;
            break;
        }
        case 8:{
            char * cadena= new char();

            cout<<"\nIngrese la cadena de caracteres: ";
            cin>>cadena;

            cout << "Original: ";
            imprimirCadena(cadena);
            cout<< endl;
            cout << "Texto: ";
            imprimirCadena(seperarCaracteresAlpha(cadena));
            cout<< endl;
            cout << "Numeros: ";
            imprimirCadena(seperarCaracteresNumericos(cadena));

            break;
        }
        case 9:{
            char *cadena=new char();
            int suma=0,bloque=0;
            cout<<"\nIngrese la cadena de caracteres numericos: ";
            cin>>cadena;
            cout<<"\nIngrese el bloque: ";
            cin>>bloque;
            if(verificarCaracteresNumericos(cadena)){
                suma=sumaCaracteresEnBloque(cadena,bloque);
            }
            cout << "Original: "; imprimirCadena(cadena);
            cout << "\nSuma: " << suma;
            break;
        }
        case 10:{
            char *romano=new char();
            cout<<"\nIngrese el numero romano:";
            cin>>romano;
            rom2arb(romano);
            break;
        }
        case 11:{
            char ** matriz=crearMatrizCine();
            bool continuar=true;char yesNo;
            int columna;char fila;
            imprimirMatrizChar(matriz);
            while(continuar){

                cout<< "Ingrese la fila (A-O): ";
                cin>>fila;
                cout<< "\nIngrese el asiento (1-30): ";
                cin>>columna;
                reservaCancelaAsientoCine(filaLetra2Numero(fila),columna,matriz);
                imprimirMatrizChar(matriz);
                cout<< "Desea continuar con el simulador? y/n: ";
                cin>>yesNo;
                if(yesNo=='n' || yesNo=='N')continuar=false;
            }
            break;
        }
        case 12:{
            cout<<"\nIngrese el tamano del cuadro magico (NxN): ";
            int dimensionmatriz;
            int **matriz;

            cin>>dimensionmatriz;
            matriz=new int*[dimensionmatriz];
            llenarmatriz(dimensionmatriz,matriz);
            determinarmatrizmagica(dimensionmatriz,matriz);
            delete matriz;
            break;
        }
        case 13:{
            int matriz[6][8]={{0,3,4,0,0,0,6,8},{5,13,6,0,0,0,2,3},{2,6,2,7,3,0,10,0},{0,0,4,15,4,1,6,0},{0,0,7,12,6,9,10,4},{5,0,6,10,6,4,8,0}};
            int *pf=matriz[0];
            int **pM=&pf;
            cout<<"\n Matriz"<<endl;
            for(int i=0;i<40;i+=8)
            {
                for(int j=0;j<6;j++)
                {
                    if(*((*pM+i)+j)>9) cout<<*((*pM+i)+j)<<" ";
                    else cout<<*((*pM+i)+j)<<"  ";
                }
                cout<<endl;
            }
            starts(pM);

            break;
        }
        case 15:{
            int *rectangulo1= new int[4];
            int *rectangulo2= new int[4];
            break;
        }
        case 16:{
            cout<<"\nIngrese el tamano de la matriz a determinar el numero de caminos: ";
            int tamanomatriz;
            unsigned long long int ncaminos=0,nx2=0,n2=0;
            cin>>tamanomatriz;
            nx2=factorial(tamanomatriz*2);
            n2=factorial(tamanomatriz);
            ncaminos=nx2/(n2*n2);
            cout<<"\n"<<ncaminos<<"\n";
            break;
        }
        default:{
            cout<<"\n El numero ingresado no corresponde al \n grupo de problemas que se asignaron para resolver\n";
            problema=0;
            break;
        }
        }
        system("pause");
        system("CLS");

    }
    return 0;
}

void imprimirCadena(char *cadena){
       for(int i=0;i<tamanodearreglochar(cadena);i++){
           cout<< *(cadena+i);
    }
}
//********************** funcion para el problema 1******************
void descomposiciondinero(int dinero)
{
    int  denominaciondinero[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    int *ptrdinero=denominaciondinero;
    int r=0;

    for(int i=0;i<10;i++)
    {
        r=dinero/(*ptrdinero);
        dinero-=(*ptrdinero)*r;
        cout<<*ptrdinero<<":"<<r<<"\n";
        ptrdinero++;
    }
    cout<<"Sobrante: "<<dinero<<"\n";
    delete ptrdinero;

}
//********************** funciones para el problema 2******************
char * generaarreglo(){

    char * arregloCaracteresMayusula= new char();

    for(int i=0;i<200;i++){
        int valor = rand() % 26;
            *(arregloCaracteresMayusula+i)=valor+65;
    }

    return arregloCaracteresMayusula;

}

void contarCaracteresEnArray(char arreglo[]){

    int  contadores[26] = {0};
    for(int i=0;i<200;i++){
      *(contadores +(*(arreglo+i)-65))+=1;
    }
    for(int j=0;j<26;j++){
        char letra=j+65;
        cout<< letra << " : "<<*(contadores+j)<<endl;
    }

}
//********************** funciones para el problema 3******************

int tamanodearreglochar(char *ptr){
    int bandera=0,tamano=0;
    while(bandera==0)
    {
        if(*ptr!=0 ){
            tamano++;
            ptr++;
        }
        else bandera++;
    }
    return tamano;
}
bool comparition(char *cadena1,char* cadena2){
    bool isEqual=true;
    if(tamanodearreglochar(cadena1)==tamanodearreglochar(cadena2))
    {
        for(int i=0;i<tamanodearreglochar(cadena1);i++)
        {
            if(*(cadena1 + i)!=*(cadena2 + i))
            {
                isEqual=false;
            }

        }
    }
    else isEqual=false;
    return isEqual;
}
//********************** funciones para el problema 4******************
int conversionChar2Int (char * ptr){
    int numero=0,i=0;
    int multiplo =1;
    int tamano =tamanodearreglochar(ptr);
    for(int i=0;i<tamano-1;i++){
        multiplo*=10;
    }
    while(multiplo>0)
    {
        numero+=(*(ptr+i) - 48)*multiplo;
        multiplo/=10;
        i++;
    }
    return numero;
}
//********************** funciones para el problema 5******************
int counterDigits(int number){
    int digits=0;

    while(number>0){
        number/=10;
        digits++;
    }
    return digits;
}

int * splitNumber(int number, int digits){

    int * listNumbers = new int[digits];
    int modulo=1;
    for(int i=0;i<digits-1;i++){
        modulo*=10;
    }
    for(int i=0;i<digits;i++){

        int digit=(number-(number%modulo))/modulo;
        number-=digit*modulo;
        *(listNumbers+i)=digit;
        modulo/=10;

    }

    return listNumbers;
}
string convertNumber2String(int * numbers,int digits){

    string caracter="";

    for(int i=0;i<digits;i++){
        caracter+=48+(*(numbers+i));
    }

    return  caracter;
}
//********************** funcion para el problema 6******************
void minusculas2MAYUSCULAS(char *ptr){

    int limit=tamanodearreglochar(ptr);

    for(int i=0;i<limit;i++){
        int ptr2=*ptr;
        if(ptr2>=97 & ptr2<=122)
        {
            *ptr-=32;
        }
        cout<<char(*ptr);
        ptr++;
    }cout<<"\n";}
//********************** funcion para el problema 7******************
void eliminarcaracter(int tamanocadena,char *cadena){

    for(int i=0;i<tamanocadena;i++)
    {
        for(int j=i+1;j<tamanocadena;j++)
        {
            if(*(cadena+i)==*(cadena+j))
            {
                *(cadena+j)=' ';
            }
        }
    }

    for(int i=0;i<tamanocadena;i++){
        if(*(cadena+i)!=' ')
        {
            cout<<*(cadena+i);
        }
    }
    cout<<"\n"<<endl;
}
//********************** funcion para el problema 8******************
char * seperarCaracteresNumericos(char *cadena){
    char * cadenaNumerica = new char();
    int j=0;
    for(int i=0;i<tamanodearreglochar(cadena);i++){
        if(*(cadena+i)>=48 && *(cadena+i)<=57){
            *(cadenaNumerica+j)=*(cadena+i);
            j++;
        }
    }
    return cadenaNumerica;
}
char * seperarCaracteresAlpha(char *cadena){
    char * cadenaCaracteres = new char();
    int j=0;
    for(int i=0;i<tamanodearreglochar(cadena);i++){
        if((*(cadena+i)>=65 && *(cadena+i)<=90)||(*(cadena+i)>=97 && *(cadena+i)<=122)){
            *(cadenaCaracteres+j)=*(cadena+i);
            j++;
        }
    }
    return cadenaCaracteres;
}
//*************************** funcion para el problema 9******************
bool verificarCaracteresNumericos(char *cadena){
    bool isSoloNumerico = true;
    for(int i=0;i<tamanodearreglochar(cadena);i++){
        if(!(*(cadena+i)>=48 && *(cadena+i)<=57)){
          isSoloNumerico=false;
        }
    }
    return isSoloNumerico;
}
int sumaCaracteresEnBloque(char * cadena, int bloque){
    int suma=0,idex=bloque-1,j=0;
    char numeroSeparado[bloque];

    for(int i=tamanodearreglochar(cadena)-1;i>=0;i--){

        if(j<bloque){
            *(numeroSeparado+ idex)= *(cadena + i);
            j++;
            idex--;
        }
        if(j==bloque){
            suma+=conversionChar2Int(numeroSeparado);
            j=0;
            idex=bloque-1;
            agregarCerosACadena(numeroSeparado);
        }

    }

    return suma;
}
void agregarCerosACadena(char * cadena){

    for(int i=0;i<tamanodearreglochar(cadena);i++){
        *(cadena + i)='0';
    }

}

//*************************** funcion para el problema 10******************
void rom2arb(char *numR){
    cout<<"\nEl numero ingresado fue: "<<endl;
    minusculas2MAYUSCULAS(numR);
    int *arb=new int();
    int suma=0;
    for(int i=0;i<tamanodearreglochar(numR);i++)
    {
        if(*(numR + i)=='M')
        {
            *(arb+i)=1000;
        }
        else if(*(numR + i)=='D')
        {
            *(arb+i)=500;
        }
        else if(*(numR + i)=='C')
        {
            *(arb+i)=100;
        }
        else if(*(numR + i)=='L')
        {
            *(arb+i)=50;
        }
        else if(*(numR + i)=='X')
        {
            *(arb+i)=10;
        }
        else if(*(numR + i)=='V')
        {
            *(arb+i)=5;
        }
        else if(*(numR + i)=='I')
        {
            *(arb+i)=1;
        }
        else
        {
            cout<<"\nNumero romano no valido."<<endl;
            break;
        }
    }
    for(int i=0;i<tamanodearreglochar(numR)-1;i+=2)
    {
        if(*(arb+i)>*(arb+i+1) || *(arb+i)==*(arb+i+1))
        {
            suma=suma + ( *(arb+i) + *(arb+i+1));
        }
        else
        {
            suma=suma + ( *(arb+i+1) - *(arb+i));
        }
    }
    cout<<"\nEl numero en arabicos es: ";
    cout<<suma<<endl;
    delete arb;
}
//********************** funciones para el problema 11**************
void reservaCancelaAsientoCine(int fila,int columna,char **matriz){
    int opcion=0;
    cout<<"\n1. Reservar\n2. Cancelar\nIngrese la opcion deseada:";
    cin>>opcion;
    switch (opcion) {
    case 1:{
        if(disponibilidadAsiento(fila,columna,matriz)){
            *(*(matriz+fila)+columna-1)='+';
            cout<<"\nReserva exitosa!!!"<<endl;
        }
        else{
            cout<<"\nLa ubicacion ya esta reservada!!!"<<endl;
        }
        break;
    }
    case 2:{
        if(!disponibilidadAsiento(fila,columna,matriz)){
            *(*(matriz+fila)+columna-1)='-';
            cout<<"\nCancelacion exitosa!!!"<<endl;
        }
        else{
            cout<<"\nLa ubicacion no esta reservada!!!"<<endl;
        }
        break;
    }
    default:{
        cout<<"\nLa opcion ingresada no es valida"<<endl;
        break;
    }
    }

}
bool disponibilidadAsiento(int fila, int columna, char **matriz){
    bool esDisponible = false;
    if(*(*(matriz+fila)+columna-1)=='-') esDisponible=true;

    return esDisponible;
}
char ** crearMatrizCine(){
    char ** matriz= new char*[15];

    for(int fila=0;fila<15;fila++){
        matriz[fila]=new char[20];
        for(int colum=0;colum<20;colum++){
            *(*(matriz+fila)+colum)='-';
        }
    }

    return matriz;
}
void imprimirMatrizChar(char ** matriz){

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<20;j++)
        {
            cout<<matriz[i][j]<<"|";
        }
        cout<<"\n";
    }

}
int filaLetra2Numero(char fila ){
    int f=0;
    if(fila>=65 && fila<=79){
        f=fila-65;
    }
    if(fila>=97 && fila<=111){
        f=fila-97;
    }
    return f;
}

//********************** funcion para el problema 12******************
void llenarmatriz(int tamanomatriz, int **matriz){
    int dato;
    for(int i=0;i<tamanomatriz;i++)
    {//i representa las filas
        matriz[i]=new int[tamanomatriz];
        for(int j=0;j<tamanomatriz;j++)
        {//j representa las columnas
            cout << "Ingrese elemento:["<< i+1 <<"]["<< j+1<<"]=";
            cin>>dato;
            *(*(matriz+i)+j)=dato;
        }
    }
    imprimirmatriz(tamanomatriz,tamanomatriz,matriz);
}
void determinarmatrizmagica(int tamanomatriz,int **matriz){
    int sumac=0,sumaf=0,sumad=0,i=0,bandera=0;
    while(bandera==0)
    {
        for(int j=0;j<tamanomatriz;j++){
            sumaf+=matriz[i][j];
            sumac+=matriz[j][i];
            sumad+=matriz[j][j];
        }
        if(sumaf==sumac & sumac==sumad){

            bandera=1;
            cout<<"Es cuadrado magico\n";break;
            break;
        }
        else
        {
            cout<<"No es cuadrado magico\n";break;
        }
    }
    if(bandera==0)cout<<"Si es cuadrado magico\n";
}
void imprimirmatriz(int f,int c,int **matriz){
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(matriz[i][j]>10){cout<<matriz[i][j]<<" ";}
            else{cout<<matriz[i][j]<<"  ";}
        }
        cout<<"\n";
    }

}

//********************** funcion para el problema 13******************
void starts(int **pM)
{

    int estrellas=0;double suma=0.0;

    for(int f=0;f<40;f+=8)
    {
        for(int c=0;c<8;c++)
        {
            if(f!=0 & f!=40 & c!=0 & c!=7)
            {
                int aij=*((*pM + f)+ c);
                int aij_1=*((*pM + f)+ c - 1);
                int aijp1=*((*pM + f)+ c + 1);
                int ai_1j=*((*pM + f - 8)+ c);
                int aip1j=*((*pM + f + 8)+ c);
                suma=(aij+aij_1+aijp1+ai_1j+aip1j)/5.0;
                if(suma >6)
                {
                    estrellas++;
                }
            }
        }


    }
    cout<<"\n Estrellas en la matriz: "<<estrellas<<endl;
}
//********************* funciones para el problema 15****************
int * generarRectangulo(){
    int rectangulo[4];
    int posx,posy,ancho,alto;
    cout<<"Ingrese la posicion x del rectangulo: ";
    cin>>posx;rectangulo[0]=posx;
    cout<<"Ingrese la posicion y del rectangulo: ";
    cin>>posy; rectangulo[1]=posy;
    cout<<"Ingrese el ancho del rectangulo: ";
    cin>>ancho; rectangulo[2]=ancho;
    cout<<"Ingrese la altura del rectangulo: ";
    cin>>alto;rectangulo[3]=alto;

    return rectangulo;
}
bool intercepcionRectangulosEjeX(int *rectangulo1,int *rectangulo2){
    bool esInterceptado=false;
    if(*(rectangulo2+0)>=*(rectangulo1+0) && *(rectangulo2+0)<=(*(rectangulo1+0) + *(rectangulo1+3))){//Derecha
        esInterceptado=true;
    }
    if((*(rectangulo2+0) + *(rectangulo2+3))>=*(rectangulo1+0) && (*(rectangulo2+0) + *(rectangulo2+3))<=(*(rectangulo1+0) + *(rectangulo1+3))){//Izquierda
         esInterceptado=true;
    }
    return esInterceptado;
}
bool intercepcionRectangulosEjeY(int *rectangulo1,int *rectangulo2){
    bool esInterceptado=false;
    if(*(rectangulo2+1)>=(*(rectangulo1+1) + *(rectangulo1+2)) && *(rectangulo2+1)<=*(rectangulo1+0)){//Abajo
        esInterceptado=true;
    }
    if((*(rectangulo2+1) + *(rectangulo2+2))<=*(rectangulo1+0) && (*(rectangulo2+1) + *(rectangulo2+2))<=(*(rectangulo1+1) + *(rectangulo1+2))){//Izquierda
         esInterceptado=true;
    }
    return esInterceptado;
}
int * generarItercepcion(int * rectangulo1,int * rectangulo2){
    int * intercepcion = new int[4];
    intercepcion={0};
    if(intercepcionRectangulosEjeX(rectangulo1,rectangulo2) && intercepcionRectangulosEjeY(rectangulo1,rectangulo2)){
        cout<< "Hay intercepcion";
    }else{
        cout<< "No Hay intercepcion";
    }
    return intercepcion;
}
//********************** funcion para el problema 16******************
unsigned long long int factorial(int tamanomatriz){
    unsigned long long int nfac=1;
    if(tamanomatriz==0)
    {
        nfac=1;
    }
    else
    {
        for(int i=1;i<tamanomatriz;i++){
            nfac*=i;
        }
    }
    return nfac;
}
