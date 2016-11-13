#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
char seguir='s';
FILE *pArchive;
ePeli peli;

pArchive=fopen("datos.dat", "rb+");
if(pArchive==NULL)
{
    pArchive=fopen("datos.dat", "wb+");
    if(pArchive==NULL)
    {
        printf("Error! No se puede abrir archivo");
        exit(1);
    }
}
while(seguir=='s')
{

    switch(menu())
    {
        case 1:
            altas(peli, pArchive);
            break;
        case 2:
            modificar(peli, pArchive);
            break;
        case 3:
            eliminar(peli, pArchive);
            break;
        case 4:
            generarPagina(peli,pArchive);
            break;
        case 5:
            seguir = 'n';
            break;
    }
}
fclose(pArchive);
return 1;
}
