#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
// #include <time.h>

/// Dossier 2020-21-ME-UF1. Tema 3.1 Exercici 06 (TotesTaulesMultiplicar)

// Fer un programa que ens mostri les taules de multiplicar des de l�1 fins al 10, utilitzant el procediment de l�exercici 5.

/// Prototipos Procedimientos: 1ro los Void-Array. 2do Void-Void. 3ro Void-int/char.
void argumento(char []);    // para imprimir texto
void resetPrograma(void);   // reset o cierre programa
void TotesTaulesMultiplicar(int);  /// EXERCICI
/// Prototipos Funciones: 4to int/char-Void. 5to int/char-int/char.
int retornValor(void);      // para pedir valores
//int pregunta(void);


/// Variables globales.
char miCadena[50];
int espera=10;
int xDir=1, yDir=2;

int main()
{
    SetConsoleTitle("Dossier Tema 3.1 Exercici 06. (TotesTaulesMultiplicar) Denis Anfruns.");

    system("MODE CON: COLS=111 LINES=20");
    /// Tildes y s�mbolos alien�genas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int numTablaMult=1;

    // numTablaMult=pregunta();
    TotesTaulesMultiplicar(numTablaMult);

    resetPrograma();
    return 0;
}

/// Funci�n de petici�n al usuario
//int pregunta(){
//    int num;
//     setColor(7); argumento(strcpy(miCadena,"\n >> Introdueix una taula de multiplicar (valors de 1 a 10): "));
//     num=retornValor();
//    while (num<0 || num>10){
//        setColor(RED); argumento(strcpy(miCadena," ��Valor erroni!!"));
//        setColor(7); argumento(strcpy(miCadena,"\n >> Tens que introduir un valor de 1 a 10): "));
//        num=retornValor();
//    }
//    return num;
//}

void TotesTaulesMultiplicar(tabla){
    int i=0;
    for (;tabla<=10;tabla++){
        for (;i<=10;i++){
            msleep(espera);
            gotoxy(xDir,yDir);
            printf(" %2dx%2d=%3d",tabla, i, tabla*i);
            yDir+=1;
        }
        gotoxy(xDir+=11,yDir=2);
        i=0;
    }
    tabla=0;
}

/// Procedimiento del recorrido del string
void argumento(char miCadena[])
{
    int pos=0;
    while (miCadena[pos] != '\0')
    {
        msleep(espera);
        printf("%c",miCadena[pos]);
        pos++;
    }
}

/// Funci�n para escanear valor.
int retornValor()
{
    int num=0;
    scanf("%d",&num);

    return num;
}

/// Funci�n reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetici�n del programa.
    int finalCountdown=2; // I'ts a final countdown!

    /// RESET.

    gotoxy(xDir,yDir+=10);
    fflush(stdin);
    setColor(7); argumento(strcpy(miCadena,"\n\n >> Ara vols ["));
    setColor(RED); argumento(strcpy(miCadena,"R"));
    setColor(7); argumento(strcpy(miCadena,"]einiciar el programa o vols ["));
    setColor(RED); argumento(strcpy(miCadena,"S"));
    setColor(7); argumento(strcpy(miCadena,"]ortir? "));
    scanf("%c",&optionPr);
    fflush(stdin);

    /// Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')){
		printf(">> Vols ["); setColor(12); printf("R"); setColor(15); printf("]einiciar el sistema o vols ["); setColor(12); printf("S"); setColor(15); printf("]ortir? ");
		scanf("%c",&optionPr);
		fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r'){
        cls();
        main();
    } else {
        espera=0;
        setColor(6); argumento(strcpy(miCadena,"\n >> Dossier Tema 3.1 Exercici 06 (TotesTaulesMultiplicar)"));
        argumento(strcpy(miCadena,"\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers."));
        setColor(15);

        /// Cuenta atr�s.
        espera=10;
        argumento(strcpy(miCadena,"\n\n Tancant programa..."));
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--){
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(500);
        getchar();
        exit(0);
    }
}
