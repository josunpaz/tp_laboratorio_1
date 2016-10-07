

typedef struct{

    int id;
    int numero;
    char nombre[20];
    char apellido[15];
    int estado;

    }eAbonado;

typedef struct{

    int abonadoId;
    int motivo;
    int estado;
    int estadoLlamada;
    int idLlamada;
    int contador;


    }eLlamada;



int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int menu();
int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void agregarAbonado (eAbonado abonado[],int espacioLibre,int id);
void inicializarArrayAbonado(eAbonado abonado[],int largo,int valor);
void getString(char mensaje[],char input[]);

int obtenerEspacioLibre (eAbonado abonado[],int cant, int valor);

int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);

int mostrar(eAbonado abonado[],eLlamada llamada [],int cant);



int baja (eAbonado abonado[],int cant);
int modificar (eAbonado abonado[],int cant);



void inicializarArrayLlamada(eLlamada llamada[],int largo,int valor,int valor2);
int obtenerEspacioLibreLlamada (eLlamada llamada[],int cant, int valor);
int nuevaLlamada(eAbonado abonado[],eLlamada llamada[],int espacioLibre, int cant,int idLlamada);
int finLlamada(eLlamada llamada[], int cant );
