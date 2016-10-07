#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANT 10
#define VACIO -1
#define BAJA 0
#define OCUPADO 1

int main()
{
    char cerrar='s';
    int id=1;
    int idLlamada=1;
    eAbonado abonado[CANT];
    eLlamada llamada[CANT];
    inicializarArrayAbonado(abonado,CANT,VACIO);
    inicializarArrayLlamada(llamada,CANT,VACIO,BAJA);
    while(cerrar=='s')
    {
        int espacioLibre=obtenerEspacioLibre (abonado,CANT,VACIO);
        int espacioLibreLlamada=obtenerEspacioLibreLlamada (llamada,CANT,VACIO);

        switch(menu())
        {
        case 1:
            if(espacioLibre!=-1)
            {agregarAbonado (abonado,espacioLibre,id);
            id++;
            system("CLS");
            }else
                {system("CLS");
                printf("Usted no dispone de espacio disponible para realizar una nueva ALTA* \n");
                }
        break;

        case 2:
            modificar (abonado,CANT);
        break;

        case 3:
            baja (abonado,CANT);
        break;

        case 4:
            if(espacioLibreLlamada!=-1)
            {nuevaLlamada(abonado,llamada,espacioLibreLlamada,CANT,idLlamada);
            idLlamada++;
            system("CLS");
            }else
                {system("CLS");
                printf("Usted no dispone de espacio disponible para realizar una nueva Llamada* \n");
                }

        break;

        case 5:
            finLlamada(llamada,CANT);
        break;

        case 6:
            system("cls");
            mostrar(abonado,llamada,CANT);
            system("pause");
            system("cls");
        break;

        case 7:
            cerrar='n';
        break;


        }
    }

    return 1;

}
