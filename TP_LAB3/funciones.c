#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menu()
{
        int opc;
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        scanf("%d",&opc);
        return opc;

}

void altas(ePeli peli, FILE *pArchive)
{




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

char aux[100];
float auxn;

printf("Ingrese el Titulo de la pelicula: ");
fflush(stdin);
gets(aux);
valtam(aux,20);
valtitulo(aux,peli,pArchive);
strcpy(peli.titulo,aux);

printf("Ingrese el genero: ");
fflush(stdin);
gets(aux);
valtam(aux,20);
strcpy(peli.genero,aux);

printf("Ingrese la duracion en minutos: ");
scanf("%f",&auxn);
auxn=(int)valnum(auxn,0,180);
peli.duracion=auxn;

printf("Ingrese la descripcion: ");
fflush(stdin);
gets(aux);
valtam(aux,50);
strcpy(peli.descripcion,aux);
printf("Ingrese el puntaje (1/10): ");
scanf("%f",&auxn);
auxn=valnum(auxn,0,10);
peli.puntaje=auxn;

printf("Ingrese el link de la imagen: ");
fflush(stdin);
gets(aux);
valtam(aux,1000);
strcpy(peli.link,aux);

peli.estado=1;

fseek(pArchive,0L,SEEK_END);
fwrite(&peli,sizeof(ePeli),1,pArchive);

fclose(pArchive);

return;
}

void modificar(ePeli peli, FILE *pArchive)
{
char dato[20];
char aux[100];
float auxn;

printf("Ingrese pelicula a modificar: ");
fflush(stdin);
gets(dato);
rewind(pArchive);

while(!feof(pArchive))
{
    fread(&peli,sizeof(ePeli),1,pArchive);
    if(strcmp(dato, peli.titulo)==0)
    {
        printf("Ingrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(aux);
        valtam(aux,20);
        valtitulo(aux,peli,pArchive);
        strcpy(peli.titulo,aux);

        printf("Ingrese el genero: ");
        fflush(stdin);
        gets(aux);
        valtam(aux,20);
        strcpy(peli.genero,aux);

        printf("Ingrese la duracion en minutos: ");
        scanf("%f",&auxn);
        auxn=(int)valnum(auxn,0,180);
        peli.duracion=auxn;

        printf("Ingrese la descripcion: ");
        fflush(stdin);
        gets(aux);
        valtam(aux,50);
        strcpy(peli.descripcion,aux);

        printf("Ingrese el puntaje (1/10): ");
        scanf("%f",&auxn);
        auxn=valnum(auxn,0,10);
        peli.puntaje=auxn;

        printf("Ingrese el link de la imagen: ");
        fflush(stdin);
        gets(aux);
        valtam(aux,1000);
        strcpy(peli.link,aux);

        peli.estado=1;

        fseek(pArchive,(-1)*sizeof(ePeli),SEEK_CUR);
        fwrite(&peli,sizeof(ePeli),1,pArchive);
        break;
    }
}
return;
}

void eliminar(ePeli peli, FILE *pArchive)
{
char dato[20];

printf("Ingrese pelicula a eliminar: ");
fflush(stdin);
gets(dato);

rewind(pArchive);
while(!feof(pArchive))
{
    fread(&peli,sizeof(ePeli),1,pArchive);
    if(stricmp(dato, peli.titulo)==0)
    {
        strcpy(peli.titulo,"\0");
        peli.estado=0;

        fseek(pArchive,(-1)*sizeof(ePeli),SEEK_CUR);
        fwrite(&peli,sizeof(ePeli),1,pArchive);
        break;
    }
}
return;
}


float valnum(float cant, int min, int max)
{
while(cant<=min||cant>max)
{
    printf("Ingrese una cantidad desde %d hasta %d: ",min,max);
    scanf("%f",&cant);
}
return cant;
}


void valtitulo(char x[], ePeli peli, FILE *pArchive)
{
rewind(pArchive);
while(!feof(pArchive))
{
    fread(&peli,sizeof(ePeli),1,pArchive);
    while(stricmp(x, peli.titulo)==0)
    {
        printf("Esta pelicula ya fue ingresada, Por favor, ingresar un nuevo titulo: ");
        fflush(stdin);
        gets(x);
        valtam(x,20);
    }
}
}

void valtam(char x[], int tam)
{
while(strlen(x)>tam-1)
{
    printf("Reingrese una cadena que no exeda %d caracteres: ", tam-1);
    fflush(stdin);
    gets(x);
}
}



void generarPagina(ePeli peli,FILE *pArchive)
{

FILE *pHtml;

char bloque1[]="<!DOCTYPE html><html><head><title>Tp3</title></head><body><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
char bloque2[]="alt=''></a><h3><a href='#'>";
char bloque3[]="</h3><ul><li>Género:";
char bloque4[]="</li><li>Puntaje:";
char bloque5[]="</li><li>Duración:";
char bloque6[]="</li></ul><p>";
char bloque7[]="</p></article></html></body>";

pHtml = fopen("Peliculas_Web.html", "w");

fprintf(pHtml, "%s\n", bloque1);

rewind(pArchive);
while(!feof(pArchive))
{
    fread(&peli,sizeof(ePeli),1,pArchive);
    if(peli.estado==1)
        fprintf(pHtml, "%s%s%s%s%s%s%.02f%s%d%s%s%s\n", peli.link, bloque2, peli.titulo, bloque3, peli.genero, bloque4, peli.puntaje,bloque5,peli.duracion,bloque6,peli.descripcion,bloque7);
}

fprintf(pHtml, "%s", bloque7);

fclose(pArchive);

}
