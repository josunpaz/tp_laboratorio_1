#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {
char nombre[50];
int edad;
int estado;
int dni;
}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre (EPersona persona[],int cant, int valor);

/**
 * Inicializa el array en vacio.
 * @param lista el array se pasa como parametro.
 */
void inicializarArrayPersona(EPersona persona[],int largo,int valor);

void grafico(int hasta18,int de19a35,int mayorDe35);
void agregarPersona (EPersona persona[],int espacioLibre);
void listarPersonas(EPersona persona[],int cant);

int borrar (EPersona persona[],int cant);
int listar (EPersona persona[],int cant);
int contarPorEdad (EPersona persona[],int cant,int* menor18,int* de18a35,int* mayor35);
int menu();

#endif // FUNCIONES_H_INCLUDED
