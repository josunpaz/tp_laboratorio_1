#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inicializarArrayPersona(EPersona persona[],int largo,int valor)
{
int i;
for (i=0;i<largo;i++)
{
    persona[i].estado = valor;

}
}

int obtenerEspacioLibre (EPersona persona[],int cant, int valor)
{
int i;
int retorno=-1;
    for(i=0;i<cant;i++)
    {
        if(persona[i].estado == valor)
        {
        retorno=i;
        break;
        }
    }
return retorno;
}



int listar (EPersona persona[],int cant)
{
system("CLS");
int i;
for (i=0;i<cant;i++)
{
    if(persona[i].estado==1)
    {
    printf(" Nombre: %s",persona[i].nombre);
    printf("\n Edad: %d",persona[i].edad);
    printf("\n DNI: %d \n\n",persona[i].dni);
    }

}



return -1;
}

int borrar (EPersona persona[],int cant)
{
int i;
int dniIngresado;
printf("\nIngrese DNI de la persona que desea modificar: ");
scanf("%d",&dniIngresado);
for(i=0;i<cant;i++)
{
        if(dniIngresado==persona[i].dni)
        {

        persona[i].estado=0;
        printf("Valores modificados correctamente\n");
        system("pause");
        system("CLS");
        break;
        }
        else if (i+1==cant)
        {
        printf("\nEl DNI ingresado no coincide con ningun DNI existente.\n");
        system("pause");
        system("CLS");
        break;
        }

}
return -1;
}

int numeros (char str[])
{
int i=0;
while(str[i] != '\0')
{
   if(str[i] < '0' || str[i] > '9')
       return 0;
   i++;
}
return 1;
}

int letras (char str[])
{
int i=0;
while(str[i] != '\0')
{
   if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       return 0;
   i++;
}
return 1;
}

void getString(char mensaje[],char input[])
{
printf("%s",mensaje);
scanf ("%s", input);
}

int getStringNumeros(char mensaje[],char input[])
{
char aux[256];
getString(mensaje,aux);
if(numeros(aux))
{
    strcpy(input,aux);
    return 1;
}
return 0;
}


int getStringLetras(char mensaje[],char input[])
{
char aux[256];
getString(mensaje,aux);
if(letras(aux))
{
    strcpy(input,aux);
    return 1;
}
return 0;
}
void agregarPersona (EPersona persona[],int espacioLibre)
{
system("cls");
int aux;
int flag2=1;
while (flag2!=0)

{if(!getStringLetras("\nIngrese nombre: ",persona[espacioLibre].nombre))
    {
    printf("Nombre ingresado no valido\n");
    system("pause");
    break;
    }

    printf("\nIngrese Edad: ");
    scanf("%d",&aux);
    if(aux<1 || aux >99)
    {
    printf("Edad no valida\n");
    system("pause");
    break;
    }else
    {persona[espacioLibre].edad=aux;
    }

    printf("\nIngrese DNI: ");
    scanf("%d",&aux);
    if(aux<1 || aux >99999999)
    {
    printf("DNI no valido\n");
    system("pause");
    break;
    }else
    {persona[espacioLibre].dni=aux;
    }
persona[espacioLibre].estado=1;
flag2=0;
}
}

void listarPersonas(EPersona persona[],int cant)
{
int i=0;
int j=0;
EPersona personaAux;
printf("DNI            |EDAD\t| ESTADO| NOMBRE\n");
for(i=0;i<cant-1;i++)
{
    if(persona[i].estado==1)
    {
    for(j=i+1;j<cant;j++)
        {
        if(persona[j].estado==1)
            {
            if (strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                personaAux=persona[i];
                persona[i]=persona[j];
                persona[j]=personaAux;
                }
            }
        }
    }
}
for(i=0;i<cant;i++)
{
    if(persona[i].estado==1)
    {
       printf("%d      | %d\t| %d\t | %s\n",persona[i].dni,persona[i].edad,persona[i].estado,persona[i].nombre);
    }

}
system("pause");
system("cls");
}



int menu()
{
char ingreso[50];
int opc;

printf("1- Agregar persona\n");
printf("2- Borrar persona\n");
printf("3- Imprimir lista ordenada por  nombre\n");
printf("4- Imprimir grafico de edades\n\n");
printf("5- Salir\n");

if(getStringNumeros("Seleccione una opcion: ",ingreso))
{
opc=atoi(ingreso);
}else
    {
    printf("\nEl valor ingresado es incorrecto.\n");
    opc=-1;
    system("pause");
    system("cls");
    }

return opc;
}


int contarPorEdad (EPersona persona[],int cant,int* menor18,int* de18a35,int* mayor35)
{
int i;
for (i=0;i<cant;i++)
{
    if(persona[i].estado==1 && persona[i].edad<18)
    {
        *menor18= *menor18+1;
    }
    else if (persona[i].estado==1 && persona[i].edad>35)
    {
        *mayor35=*mayor35+1;
    }
    else if (persona[i].estado==1 && persona[i].edad>=18 && persona[i].edad<=35)
    {
        *de18a35=*de18a35+1;
    }
}

return 0;
}

void grafico(int hasta18,int de19a35,int mayorDe35)
{
int cero=0;
int i=0;
if(hasta18>=mayorDe35 && hasta18>=de19a35)
{
    cero=hasta18;
}
else if(mayorDe35>=hasta18 && mayorDe35>=de19a35)
{
    cero=mayorDe35;
}
else if(de19a35>=hasta18 && de19a35>=mayorDe35)
{
    cero=de19a35;
}
for(i=cero; i>cero; i--)
{
    printf("%d|",i);
    int flag=0;
    if(i<10){
        printf("%02d|",i);
    }
    else
        printf("%02d|",i);

    if(i<= hasta18){
        printf("*");
    }
    if(i<= de19a35){
        flag=1;
        printf("\t*");
    }
    if(i<= mayorDe35){
        if(flag==0)
            printf("\t\t*");
        if(flag==1)
            printf("\t*");

    }
    //Bajo una linea luego de cada iteracion
    printf("\n");
    }
printf("--+-----------------");
printf("\n  |<18\t19-35\t>35");
printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);


}
