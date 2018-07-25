#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleados.h"
#include "validaciones.h"

    char archivo1[15]="data.csv";
    char archivo2[15]="out.csv";

eEmpleados* new_Empleados()
{
    eEmpleados* EmpleadosAux;

    EmpleadosAux = (eEmpleados*) malloc(sizeof(eEmpleados));

    return EmpleadosAux;
}


int set_sueldo(eEmpleados* this, float sueldo)
{
    int index=-1;

    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        index=0;
    }
    return index;
}

float get_sueldo(eEmpleados* this)
{
    float index=-1;

    if(this != NULL)
    {
        index= this->sueldo;
    }
    return index;
}


int set_id(eEmpleados* this, int id)
{
    int index=-1;

    if(this != NULL && id >= 0)
    {
        this->id = id;
        index=0;
    }
    return index;
}

int get_id(eEmpleados* this)
{
    int index=-1;

    if(this != NULL)
    {
        index= this->id;
    }
    return index;
}


int set_edad(eEmpleados* this, int edad)
{
    int index=-1;

    if(this != NULL && edad >= 0)
    {
        this->edad = edad;
        index=0;
    }
    return index;
}

int get_edad(eEmpleados* this)
{
    int index=-1;

    if(this != NULL)
    {
        index= this->edad;
    }
    return index;
}


int set_nombre(eEmpleados* this, char* nombre )
{
    int index=-1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        index=0;
    }
    return index;
}

char* get_nombre (eEmpleados* this)
{
    char* nombre=NULL;

    if(this != NULL)
    {
        nombre = this->nombre;
    }
    return nombre;
}


int set_profesion(eEmpleados* this, char* profesion )
{
    int index=-1;

    if(this != NULL && profesion != NULL)
    {
        strcpy(this->profesion,profesion);
        index=0;
    }
    return index;
}


char* get_profesion(eEmpleados* this)
{
    char* profesion=NULL;

    if(this != NULL)
    {
        profesion = this->profesion;
    }
    return profesion;
}



int mostrar_Empleadoss(eEmpleados* this)
{
    int index=-1;

    if(this != NULL)
    {
        printf(" ID: %d ---- NOMBRE: %s ---- EDAD: %d ---- PROFESION: %s ---- SUELDO: $%.2f\n", get_id(this), get_nombre(this), get_edad(this), get_profesion(this), get_sueldo(this));
        index=0;
    }
    return index;
}



int comparar_Empleadoss(void* EmpleadosA, void* EmpleadosB)
{
    eEmpleados* Empleados1;
    eEmpleados* Empleados2;

    Empleados1= (eEmpleados*) EmpleadosA;
    Empleados2= (eEmpleados*) EmpleadosB;

    return strcmp(Empleados1->nombre, Empleados2->nombre);
}



int mostrar_lista_Empleadoss(ArrayList* listado)
{
    int index=-1;
    int i;
    int len;
    eEmpleados* EmpleadosActual;

    if(listado != NULL)
    {
        len = listado->len(listado);
        for(i=0; i<len; i++)
        {
            EmpleadosActual= (eEmpleados*) listado->get(listado, i);
            printf("%d.",i+1);
            mostrar_Empleadoss(EmpleadosActual);
        }
        index=0;
    }
    return index;
}



int cargar_Archivo(FILE* archivo ,ArrayList* listaEmpleados, eEmpleados* empleado, int id, char* nombre, int edad, char* profesion, float sueldo)
{
    int index=-1;
    char linea[100];
    char auxlinea[10];

    if(listaEmpleados!= NULL && empleado != NULL)
    {
        memset(linea, '\0',100);
        archivo= fopen("data.csv","r");
        if(archivo!= NULL)
        {
            fgets(linea, 100, archivo);

            while(!feof(archivo))
            {
                empleado=new_Empleados();

                strcpy(auxlinea,strtok(linea,","));
                id = atoi(auxlinea);
                strcpy(nombre,strtok(NULL,","));
                strcpy(auxlinea,strtok(NULL,","));
                edad = atoi(auxlinea);
                strcpy(profesion,strtok(NULL,","));
                strcpy(auxlinea,strtok(NULL,"\n"));
                sueldo= (float) atoi(auxlinea);

                set_nombre(empleado, nombre);
                set_edad(empleado, edad);
                set_profesion(empleado,profesion);
                set_sueldo(empleado,sueldo);
                set_id(empleado,(id));

                listaEmpleados->add(listaEmpleados,empleado);

                memset(linea, '\0',100);
                fgets(linea, 100, archivo);
            }

            fclose(archivo);
            index=0;
        }
    }
    return index;
}



int cargar_Empleados(ArrayList* listaEmpleados , eEmpleados* actualEmpleado, int id, char* nombre, int edad, char* profesion, float sueldo)
{
    int index=-1;


    if(listaEmpleados != NULL && actualEmpleado != NULL && nombre != NULL && profesion != NULL)
    {
        actualEmpleado=new_Empleados();


        set_nombre(actualEmpleado, nombre);
        set_edad(actualEmpleado, edad);
        set_profesion(actualEmpleado,profesion);
        set_sueldo(actualEmpleado,sueldo);
        set_id(actualEmpleado,id);

        listaEmpleados->add(listaEmpleados,actualEmpleado);
    }

    return index;
}



int crear_pagina(FILE* archivoEmpleados ,char* nombreDeArchivo ,ArrayList* listaEmpleados)
{
    eEmpleados* ActualEmpleado;
    int index=-1;
    int len=listaEmpleados->len(listaEmpleados);
    int i;

    if(listaEmpleados != NULL && nombreDeArchivo!= NULL )
    {
        archivoEmpleados=fopen(nombreDeArchivo,"w");
        if(archivoEmpleados!= NULL)
        {
            for(i=0; i<len;i++)
            {
                ActualEmpleado= new_Empleados();

                if(ActualEmpleado != NULL)
                {
                    ActualEmpleado= (eEmpleados*) listaEmpleados->get(listaEmpleados,i);

                    fprintf(archivoEmpleados,"%d,",get_id(ActualEmpleado));
                    fprintf(archivoEmpleados,"%s,",get_nombre(ActualEmpleado));
                    fprintf(archivoEmpleados,"%d,",get_edad(ActualEmpleado));
                    fprintf(archivoEmpleados,"%s,",get_profesion(ActualEmpleado));
                    fprintf(archivoEmpleados,"%.2f\n",get_sueldo(ActualEmpleado));
                }
            }
            fclose(archivoEmpleados);
            index=0;
        }
    }
    return index;
}



int agregar_empleados(FILE* archivo  ,ArrayList* listaEmpleados , eEmpleados* empleados , int id , char* nombre , int edad , char* profesion , float sueldo)
{
    int index=-1;
    int len;
    int aux;

    if(listaEmpleados != NULL && empleados != NULL && nombre != NULL && profesion != NULL)
    {
        if((len = listaEmpleados->len(listaEmpleados))==0)
            {
                 cargar_Archivo(archivo,listaEmpleados,empleados,id,nombre,edad,profesion,sueldo);
            }

            printf(" ingrese id:\n ");
            id=validarNumero(id);

            fflush(stdin);
            printf(" ingrese nombre:\n ");
            nombre[20]=validarnombre(nombre);

            printf(" ingrese edad:\n ");
            edad=validarNumero(edad);
            fflush(stdin);

            do
            {
                printf(" ingrese profesion:\n ");
                printf(" 1: analista \t 2: programador \t 3: tester \n ");
                scanf("%d", &aux);
                switch(aux)
                {
                    case 1:
                        strcpy(profesion,"analista");
                        sueldo= 20000;
                        break;
                    case 2:
                        strcpy(profesion,"programador");
                        sueldo= 25000;
                        break;
                    case 3:
                        strcpy(profesion,"tester");
                        sueldo=18000;
                        break;
                    default:
                        printf("no hay una opcion con ese numero, reingrese \n");
                }
            }while(aux < 1 || aux > 3);


             cargar_Empleados(listaEmpleados,empleados,id,nombre,edad,profesion,sueldo);
             crear_pagina(archivo, archivo1,listaEmpleados);
             mostrar_lista_Empleadoss(listaEmpleados);

             index=0;
    }
    return index;
}



int borrar_Empleados(FILE* archivo ,ArrayList* listaEmpleados, eEmpleados* empleado, int id, char* nombre, int edad, char* profesion, float sueldo)
{
    eEmpleados* aux;
    int indice=0;
    int index=-1;
    int i;
    int len = listaEmpleados->len(listaEmpleados);

    if(listaEmpleados!= NULL && empleado != NULL && nombre !=NULL && profesion !=NULL)
    {
        if(len == 0)
        {
            cargar_Archivo(archivo,listaEmpleados,empleado,id,nombre,edad,profesion,sueldo);
        }
        mostrar_lista_Empleadoss(listaEmpleados);

        printf("ingrese indice: ");
        indice= validarNumero(indice);
        len=listaEmpleados->len(listaEmpleados);

        if(indice<=len)
        {
            listaEmpleados->remove(listaEmpleados,(indice-1));
            archivo= fopen("data.csv","w");
            len=listaEmpleados->len(listaEmpleados);
            if(archivo!= NULL)
            {
                for(i=0; i<len;i++)
                {
                    aux= new_Empleados();

                    aux = (eEmpleados*) listaEmpleados->get(listaEmpleados,i);
                    if(aux != NULL)
                    {
                        fprintf(archivo,"%d,",get_id(aux));
                        fprintf(archivo,"%s,",get_nombre(aux));
                        fprintf(archivo,"%d,",get_edad(aux));
                        fprintf(archivo,"%s,",get_profesion(aux));
                        fprintf(archivo,"%.2f\n",get_sueldo(aux));
                    }
                }
                fclose(archivo);
                index=0;
            }

        }
    }

    return index;
}



int leer_Archivo(FILE* archivo, char* nombredeArchivo)
{
    int index=-1;
    char nombre[20];
    char profesion[20];
    int edad;
    float sueldo;
    int id;
    char linea[60];
    char auxlinea[10];
    int i=1;

    memset(linea, '\0',60);
    if(nombredeArchivo != NULL)
    {
        archivo= fopen(nombredeArchivo,"r");
        if(archivo!= NULL)
        {
            fgets(linea, 60, archivo);

            while(!feof(archivo))
            {

                strcpy(auxlinea,strtok(linea,","));
                id = atoi(auxlinea);
                strcpy(nombre,strtok(NULL,","));
                strcpy(auxlinea,strtok(NULL,","));
                edad = atoi(auxlinea);
                strcpy(profesion,strtok(NULL,","));
                strcpy(auxlinea,strtok(NULL,"\n"));
                sueldo= (float) atoi(auxlinea);

                printf("%d. ID: %d ---- NOMBRE: %s ---- EDAD: %d ---- PROFESION: %s ---- SUELDO: $%.2f\n", i ,id, nombre,edad,profesion,sueldo);
                i++;
                memset(linea, '\0',60);
                fgets(linea, 60, archivo);

            }
            index=0;
            fclose(archivo);
        }
    }

    return index;
}


int funcionFilter(void* item)
{
    int index=0;
    eEmpleados* empleado1;

    empleado1= (eEmpleados*) item;

    if(empleado1->edad >= 30 && strcmp(empleado1->profesion, "programador")==0)
    {
        index=1;
    }

    return index;
}


int filtrar_Empleados(FILE* archivo ,FILE* archivoFiltrados ,ArrayList* listaEmpleados ,ArrayList* empleadosFiltrados , eEmpleados* empleados , int id , char* nombre , int edad , char* profesion , float sueldo)
{
    int index=-1;

    if(listaEmpleados!= NULL && empleadosFiltrados!= NULL && empleados != NULL && nombre !=NULL && profesion !=NULL)
    {
        empleadosFiltrados= listaEmpleados->filter(listaEmpleados, funcionFilter);
        crear_pagina(archivoFiltrados, archivo2 ,empleadosFiltrados);
        index=0;
    }

    return index;
}
