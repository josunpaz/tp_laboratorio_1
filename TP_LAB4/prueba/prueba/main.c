#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

int main()
{
char seguir='s';
eEmpleado* empleado = empleado_add();

while(seguir=='s')
{

    switch(menu())
    {
        case 1:
        cargarEmpleadoAux(empleado);
        break;
        case 2:
        printf("Esto funciona de maravillas 2");
        break;
        case 3:
        printf("Esto funciona de maravillas 3");
        break;
        case 4:
        printf("Esto funciona de maravillas 4");
        break;
        case 5:
        seguir='n';
        break;

    }

}
   return 1;

}
