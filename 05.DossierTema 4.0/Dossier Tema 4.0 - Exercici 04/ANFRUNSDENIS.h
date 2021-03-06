#ifndef ANFRUNSDENIS_H_INCLUDED
#define ANFRUNSDENIS_H_INCLUDED

// S� que no est� bien incluir todas las librer�as siempre pero por si acaso para el examen tengo una plantilla preparada con todas ellas.
#include <rlutil.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int demanarNum();
int maxNumV(int v[],int qttE);
int demanarEntreMinMax(int minim, int maxim);
int posV(int v[], int qttE, int num);
void imprimirV(int v[], int qttE);
void imprimir2V(int v1[], int v2[], int qttE);
void cerca(int v[],int qttE,int num);
void randomIn(int v[], int num, int maxim);
void marcaV(int v[], int qttE);
float avgV(int v[], int qttE);

/// Estos dos prototipos son para poder reiniciar el programa.
void program();
void resetPrograma();

/// Pide al usuario un n�mero.
int demanarNum(){
    int n;
    scanf("%d",&n);
    return n;
}

/// Devuelve el n�mero m�ximo de un vector.
int maxNumV(int v[],int qttE){
    int i, maxim;
    maxim=v[0];
    for(i=1;i<qttE;i++){
        if(v[i]>maxim) maxim=v[i];
    }
    return maxim;
}

/// scanf() Devuelve entre un valor m�nimo y m�ximo. demanarEntreMinMax(valorMin, valorMax).
int demanarEntreMinMax(int minim,int maxim){
    int n;
    do {
        printf("Introduce un n�mero entre %d y %d: ", minim, maxim);
        setColor(2);
        scanf("%d",&n);
        setColor(7);
    } while (n<minim || n>maxim);

    return n;
}

/// Encuentra la posici�n de un valor en el vector. posicioVector(nombreVector, cantidadElementos, numeroEncontrar).
int posV(int v[], int qttE, int num) {
    int i=0;
    int pos=-1;

    while (i<qttE && pos==-1){
        if (v[i]==num){
            pos=i;
        } else
            i++;
    }
    return pos;
}

/// Marcar Vector con -1. marcaVector(nombreVector, cantidadElementos).
void marcaV(int v[], int qttE){
    int i=0;
    for (;i<qttE;i++){
        v[i]=-1;
    }
}

/// printf() Imprime posici�n y valor de 1 vector. imprimirVector(nombreVector, cantidadElementos).
void imprimirV(int v[], int qttE){
    int i=0;
    for (;i<qttE;i++){
        if (v[i]!=-1){
            printf("\n[%d]: %d",i,v[i]);
        }
    }
}

/// printf() Imprime posici�n y valor de 2 vectores. imprimir2Vectors(nombreVector, contadorPosicion, cantidadElementos).
void imprimir2V(int v1[], int v2[], int qttE){
    int i=0;
    if (qttE==0){
        printf("\nNo se ha introducido ning�n valor v�lido.");
    }else{
        for (;i<qttE;i++){
            printf("\nEl n�mero %d se ha introducido %d veces.",v1[i],v2[i]);
        }
    }
}

/// Encontrar n�mero en un vector.
void cerca(int v[],int qttE,int num){
    int i;
    bool trobat = false;
    for(i=0;i<qttE;i++){
        if (v[i] == num){
            printf("El numero %d s'ha trobat!",num);
            trobat = true;
        }
    }
    if (trobat == false){
        printf("El numero %d no s'ha trobat!",num);
    }
}

/// Rellenar un vector con n�meors aleatorios. randomIn(nombreVector, cantidad de valores a introducir, valor maximo a introducir).
void randomIn(int v[], int num, int maxim){
    int i=0;
    for(;i<num;i++){
        v[i]=rand()%maxim;
    }
}

/// Calcula el promedio entre la cantidad de elementos introducidos por el usuario.
float avgV(int v[],int num){
    float acum=0;
    int i=0;
    for (;i<num;i++){
        acum=acum+v[i];
    }
    printf("\n\nSuma de valors: %.f - Quantitat de valors: %d",acum,num);
    if (num==0){
        return num;
    }else{
        return acum/num;
    }
}

/// Reset del programa.
void resetPrograma(){

    char optionPr='X';      // Variable para controlar la salida/repetici�n del programa.
    int finalCountdown=1;   // I'ts a final countdown!

    // RESET.
    fflush(stdin);
    setColor(7); printf("\n\nAra vols [");
    setColor(12); printf("R");
    setColor(7); printf("]einiciar el sistema o vols [");
    setColor(12); printf("S");
    setColor(7); printf("]ortir? ");
    scanf("%c",&optionPr);
    fflush(stdin);

    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')) {
        setColor(RED); printf("�Error!");
        setColor(7); printf(" Vols [");
        setColor(12); printf("R");
        setColor(7); printf("]einiciar el sistema o vols [");
        setColor(12); printf("S");
        setColor(7); printf("]ortir? ");
        scanf("%c",&optionPr);
        fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r') {
        cls();
        program();
    } else {
        setColor(6);
        printf("\nCurs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        setColor(7);

        // Cuenta atr�s.
        printf("\n\nEl programa es tancara en: ");
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--) {
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(500);
        exit(0);
    }
}

#endif // ANFRUNSDENIS_H_INCLUDED
