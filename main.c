#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int numeroUno;
    int numeroDos;
    float total;

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        /*
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");

        printf("Ingrese la opcion deseada:");
        scanf("%d",&opcion);
        */


        switch(opcion)
        {
            case 1:
                printf("Ingrese el 1er operando");
                scanf("%d",&numeroUno);
                break;
            case 2:
                printf("Ingrese el 2do operando");
                scanf("%d",&numeroDos);
                break;
            case 3:
                int funSuma (numeroUno,numeroDos);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
