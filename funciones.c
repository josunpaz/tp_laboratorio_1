
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


/**
*\brief suma dos numeros
*\param a y b son los valores ingresado por el usuario
*\return el resultado de la suma
*
*/


float funSuma(float a, float b)
{
    float fin;
    fin= a + b;
    return fin;
}

float funResta( float a, float b)
{
    float fin;
    fin= a-b;
    return fin;
}

float funMult(float a, float b)
{
    float fin;
    fin= a*b;
    return fin;

}

float fundiv(float a, float b)
{
    float fin;
    fin=a/b;
    return fin;
}

double factorial(float numeroUno)
{
       double respuesta;

        if(numeroUno==0 || numeroUno==1)
            return 1;

       respuesta= (double)numeroUno * factorial (numeroUno - 1);

    return respuesta;
}
void validar_factorial(float numeroUno)
{
    double fact;

    if(numeroUno < 0)
    {
       printf("Error. No se puede calcular el factorial de un numero negativo.Reingrese el numero\n");
    }
    else if(numeroUno > 170)
    {
        printf("El resultado es INFINITO\n");
    }
    else if(floor(numeroUno) != numeroUno)
    {
        printf("ERROR. Debe ingresar un numero entero para calcular el factorial\n");
    }
    else{

        fact= factorial(numeroUno);
        printf("El factorial de %.0f es %.0f\n", numeroUno, fact);
    }


}



/*int menu (int opc)
{
    char texto[300];
    texto= "1- Ingresar 1er operando (A=x)\n2- Ingresar 2do operando (B=y)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operacione\n9- Salir\n";
    printf ("%s",texto);
    scanf("%d",&opc);
    return opc;
}*/


