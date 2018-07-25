#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "empleados.h"
#include "validaciones.h"

int main()
{
    FILE* empleados;
    FILE* filtrados;
    char archivo1[15]="data.csv";
    char archivo2[15]="out.csv";

    eEmpleados* empleado;
    ArrayList* arrrayEmpleados;
    arrrayEmpleados=al_newArrayList();
    ArrayList* empleadosFiltrados;


    int opcion;
    int index=-1;
    char nombre[20]="-";
    char profesion[20]="-";
    int edad=0;
    float sueldo=0;
    int id=1;

    do
    {
        printf(" 1.AGREGAR EMPLEADO\n");
        printf(" 2.ELIMINAR EMPLEADO\n");
        printf(" 3.LISTAR\n");
        printf(" 4.FILTRAR\n");
        printf(" 5.SALIR\n");

        printf("\n opcion: ");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            index= agregar_empleados(empleados,arrrayEmpleados,empleado,id,nombre,edad,profesion,sueldo);
            if(index==0)
            {
                printf(" Empleado agregado! \n");
            }
            break;
        case 2:
            index=borrar_Empleados(empleados,arrrayEmpleados,empleado,id,nombre,edad,profesion,sueldo);
             if(index==0)
            {
                printf(" Empleado eliminado! \n");
                index=mostrar_lista_Empleadoss(arrrayEmpleados);
            }

            break;
        case 3:
            leer_Archivo(empleados, archivo1);
            printf("\n");
            leer_Archivo(filtrados, archivo2);
            break;
        case 4:
            index= filtrar_Empleados(empleados,filtrados,arrrayEmpleados,empleadosFiltrados,empleado,id,nombre,edad,profesion,sueldo);
             if(index==0)
            {
                printf(" Empleados Filtrados! \n");
            }
            break;
        case 5:
            break;
        default:
            printf("\n No se ha accedido a ninguna opcion del Sistema. Por favor, intente de nuevo.\n\n");
            break;
        }

    }
    while(opcion!=5);

    return 0;
}
