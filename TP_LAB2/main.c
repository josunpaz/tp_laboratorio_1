#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define VACIO -1
#define BAJA 0
#define OCUPADO 1
#define CANT 20
#include <string.h>


int main()
{
char seguir='s';
int opc=0;
int flag=0;
int menor18=0;
int de18a35=0;
int mayor35=0;

EPersona persona[CANT];
inicializarArrayPersona(persona,CANT,VACIO);

while(seguir=='s')
{opc=menu();

int espacioLibre=obtenerEspacioLibre (persona,CANT,VACIO);

    switch(opc)
    {
        case 1:
            if(espacioLibre!=-1)
            {   flag=1;
                agregarPersona (persona,espacioLibre);
                system("CLS");
            }else
                {system("CLS");
                printf("Usted no dispone de espacio disponible para realizar una nueva ALTA* \n");}
            break;

        case 2:
            if(flag!=0){
            listar (persona,CANT);
            borrar (persona,CANT);
            }else
            {
                system("CLS");
                printf("Aun no ingreso ningun dato*\n");
            }
            break;
        case 3:
            listarPersonas(persona,CANT);
            break;
        case 4:
            system("cls");
            contarPorEdad(persona,CANT,&menor18,&de18a35,&mayor35);
            grafico(menor18,de18a35,mayor35);
            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            break;
    }
}
return 0;
}
