#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
                char titulo[20];
                char genero[20];
                char descripcion[50];
                int duracion;
                float puntaje;
                char link[1000];
                int estado;
              }ePeli;
/**
 * \brief Printea un menu y devuelve numero seleccionado
 * \param
 * \return El numero seleccionado
 */
int menu();

/**
 * \brief Agrega una pelicula al archivo binario
 * \param Estructura tipo ePeli
 * \param puntero a archivo
 * \return funcion void, sin retorno
 */
void altas(ePeli peli, FILE *pArchive);

/**
 * \brief Modifica una pelicula del archivo binario
 * \param Estructura tipo ePeli
 * \param puntero a archivo
 * \return funcion void, sin retorno
 */
void modificar(ePeli peli, FILE *pArchive);

/**
 * \brief Elimina una pelicula del archivo binario
 * \param Estructura tipo ePeli
 * \param puntero a archivo
 * \return funcion void, sin retorno
 */
 void eliminar(ePeli peli, FILE *pArchive);

/**
 * \brief Genera un archivo .html
 * \param Estructura tipo ePeli
 * \param puntero a archivo
 * \return funcion void, sin retorno
 */
void generarPagina(ePeli peli,FILE *pArchive);

/**
 * \brief Valida tamaño
  */
void valtam(char x[], int tam);
/**
 * \brief Valida numero max min
  */
float valnum(float, int, int);
/**
 * \brief Valida titulo ePeli
  */
void valtitulo(char x[], ePeli peli, FILE *pArchive);




#endif // FUNCIONES_H_INCLUDED

