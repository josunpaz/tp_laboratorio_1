#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float numeroUno= 0;
    float numeroDos= 0;
    int total;
    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
system("cls");
system("color 2");
printf("1- Ingresar 1er operando (A=%.2f)\n",numeroUno);
        printf("2- Ingresar 2do operando (B=%.2f)\n",numeroDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");

        printf("Ingrese la opcion deseada:");
        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                printf("Ingrese el 1er operando: ");
                scanf("%f",&numeroUno);
                break;
            case 2:
                printf("Ingrese el 2do operando: ");
                scanf("%f",&numeroDos);
                break;
            case 3:
                printf("\nLa suma de los operandos es: %.2f\n",funSuma(numeroUno,numeroDos));
                system("pause");
                break;
            case 4:
                printf("\n La resta de los operandos es: %.2f\n",funResta(numeroUno,numeroDos));
                system("pause");
                break;
            case 5:
                printf("\n La division de los operandos es: %.2f\n",fundiv(numeroUno,numeroDos));
                system("pause");
                break;
            case 6:
                printf("\n la multiplicacion de los operandos es: %.2f \n",funMult(numeroUno,numeroDos));
                 system("pause");
                break;
            case 7:
                validar_factorial(numeroUno);
                system("pause");
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
