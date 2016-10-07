#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"



/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

int esNumerico(char str[])
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

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
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


/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Muestra un menu y solicita un  num�ro al usuario valida que sea entre X e Y
 * \return devuelve el numero ingresado
 */
int menu()
{
char ingreso[5];
int opc=-1;

printf("1- Alta de abonado\n");
printf("2- Modificar datos de abonado\n");
printf("3- Baja de abonado\n");
printf("4- Nueva llamada\n");
printf("5- Fin de llamada\n");
printf("6- Informes\n");
printf("7- Salir \n\n");


if(!getStringNumeros("Seleccione una opcion: ",ingreso))
    {
    printf("\nEl valor ingresado es incorrecto.\n");
    fflush(stdin);
    system("pause");
    system("cls");
    }else
        {
        (opc=atoi(ingreso));
        }



return opc;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }



}



void inicializarArrayAbonado(eAbonado abonado[],int largo,int valor)
{
int i;
for (i=0;i<largo;i++)
{
    abonado[i].estado = valor;
}
}

int obtenerEspacioLibre (eAbonado abonado[],int cant, int valor)
{
int i;
int retorno=-1;
    for(i=0;i<cant;i++)
    {
        if(abonado[i].estado == valor)
        {
        retorno=i;
        break;
        }
    }
return retorno;
}

void inicializarArrayLlamada(eLlamada llamada[],int largo,int valor,int valor2)
{
int i;
for (i=0;i<largo;i++)
{
    llamada[i].estado = valor;
    llamada[i].contador = valor2;
}
}

int obtenerEspacioLibreLlamada (eLlamada llamada[],int cant, int valor)
{
int i;
int retorno=-1;
    for(i=0;i<cant;i++)
    {
        if(llamada[i].estado == valor)
        {
        retorno=i;
        break;
        }
    }
return retorno;
}


void agregarAbonado (eAbonado abonado[],int espacioLibre,int id)
{
system("cls");
int aux;
int flag2=1;
while (flag2!=0)

{if(!getStringLetras("\nIngrese nombre: ",abonado[espacioLibre].nombre))
    {
    printf("Nombre ingresado no valido, no se guarda alta\n");
    fflush(stdin);
    system("pause");
    break;
    }
    fflush(stdin);
if(!getStringLetras("\nIngrese Apellido: ",abonado[espacioLibre].apellido))
    {
    printf("Apellido ingresado no valido, no se guarda alta\n");
    fflush(stdin);
    system("pause");
    break;
    }
    fflush(stdin);
    printf("\nIngrese Numero desde 1 a 99: ");
    scanf("%d",&aux);
    fflush(stdin);
    if(aux<1 || aux >99)
    {
    printf("Edad no valida, no se guarda alta\n");
    system("pause");
    fflush(stdin);
    break;
    }else
    {abonado[espacioLibre].numero=aux;
    }
fflush(stdin);
abonado[espacioLibre].id=id;
abonado[espacioLibre].estado=1;
flag2=0;
printf("El abonado se guardo correctamente.");
system("pause");
}

}

void motivo()
{
    printf("\n1-FALLA 3G \n2-FALLA LTE \n3-FALLA EQUIPO \n");
}

void estado()
{
    printf("\n1-EN CURSO \n2-SOLUCIONADO \n3-NO SOLUCIONADO \n");
}


int mostrar(eAbonado abonado[],eLlamada llamada[], int cant)
{
    int i;
        motivo();
        estado();
    for(i=0;i<cant;i++)
    {

        if(abonado[i].estado==1)
        {
        printf("\nNombre: %s",abonado[i].nombre);
        printf("\nApellido: %s",abonado[i].apellido);
        printf("\nNumero: %d",abonado[i].numero);
        printf("\nEstado: %d",abonado[i].estado);
        printf("\nID: %d\n",abonado[i].id);
        }

        if(llamada[i].estado==1)
        {
        printf("\nID: %d",llamada[i].abonadoId);
        printf("\nMotivo: %d",llamada[i].motivo);
        printf("\nID de llamada: %d",llamada[i].idLlamada);
        printf("\nEstado de llamada: %d",llamada[i].estadoLlamada);
        printf("\nSe registro/aron %d llamada/s con este ID \n",llamada[i].contador);
        }
    }
    return 1;
}

int baja (eAbonado abonado[],int cant)
{
int i;
int idIngresado;
printf("\nIngrese id del abonado: ");
scanf("%d",&idIngresado);
for(i=0;i<cant;i++)
{
        if(idIngresado==abonado[i].id)
        {

        abonado[i].estado=0;
        printf("Valores modificados correctamente\n");
        system("pause");
        system("CLS");
        break;
        }
        else if (i+1==cant)
        {
        printf("\nEl ID ingresado no coincide con ningun ID existente.\n");
        system("pause");
        system("CLS");
        fflush(stdin);
        break;
        }

}
return -1;
}


int modificar (eAbonado abonado[],int cant)
{
int i;
int idIngresado;
printf("\nIngrese id del abonado: ");
scanf("%d",&idIngresado);
char auxNombre[15];
char auxApellido[15];
int aux;


for(i=0;i<cant;i++)
{
        if(idIngresado==abonado[i].id)
        {
            if(!getStringLetras("\nIngrese nombre: ",auxNombre))
            {
            printf("Nombre ingresado no valido, no se modificacion alta\n");
            fflush(stdin);
            system("pause");
            system("cls");
            break;
            }
            fflush(stdin);
            if(!getStringLetras("\nIngrese Apellido: ",auxApellido))
            {
            printf("Apellido ingresado no valido, no se guarda modificacion\n");
            fflush(stdin);
            system("pause");
            system("cls");
            break;
            }
            fflush(stdin);
            printf("\nIngrese Numero desde 1 a 99: ");
            scanf("%d",&aux);
            fflush(stdin);
            if(aux<1 || aux >99)
            {
            printf("Edad no valida, no se guarda Modificacione\n");
            system("pause");
            system("cls");
            fflush(stdin);
            break;
            }else
            {abonado[i].numero=aux;
            strcpy(abonado[i].nombre, auxNombre);
            strcpy(abonado[i].apellido, auxApellido);
            printf("\n*Los valores fueron modificados correctamente");
            system("pause");
            system("cls");
            }
        break;
        }
        else if (i+1==cant)
        {
        printf("\nEl ID ingresado no coincide con ningun ID existente.\n");
        system("pause");
        system("CLS");
        fflush(stdin);
        break;
        }

}
return -1;
}



int nuevaLlamada(eAbonado abonado[],eLlamada llamada[],int espacioLibre,int cant,int idLlamada)
{
    int i;
    int idIngresado;
    int opc;

    printf("Ingrese el ID del abonado que realiza la llamada: ");
    scanf("%d",&idIngresado);

    for(i=0;i<cant;i++)
    {
        if(idIngresado==abonado[i].id && abonado[i].estado==1)
        {
            motivo();
            opc=getValidInt("Ingrese motivo de llamada: ","\nValor Incorrecto",1,3);
            llamada[espacioLibre].motivo=opc;
            llamada[espacioLibre].estadoLlamada=1;


            llamada[espacioLibre].idLlamada=idLlamada;
            llamada[espacioLibre].abonadoId=abonado[i].id;
            llamada[espacioLibre].estado=1;

            llamada[espacioLibre].contador=llamada[espacioLibre].contador+1;

            printf("Se cargo valor correctamente, El ID de su llamada es: %d \n",idLlamada);

            system("pause");
            system("cls");

            break;
        }
    }
 return 1;
}



int finLlamada(eLlamada llamada[], int cant )
{
    int i;
    int opc;
    for(i=0;i<cant;i++)
    {
        opc=getValidInt("Ingrese ID de llamada: ","\nValor Incorrecto",1,cant);
        if(opc==llamada[i].idLlamada)
        {
        opc=getValidInt("\n2-SOLUCIONADO \n3-NO SOLUCIONADO \nIngrese Nuevo estado de llamada: ","\nValor Incorrecto",2,3);
        llamada[i].estadoLlamada=opc;
        printf("\nEl nuevo estado se cargo correctamente\n");
        system("pause");
        system("cls");

        break;
        }
    }
return 1;
}









