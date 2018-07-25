#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Validaciones.h"
#include "pacientes.h"

ePaciente* new_paciente()
{
    ePaciente* pacienteAux;

    pacienteAux = (ePaciente*) malloc(sizeof(ePaciente));

return pacienteAux;
}


int set_id(ePaciente* this , int turno)
{
int index=-1;

    if(this != NULL && turno > 0)
    {
     this->Turno = turno;
     index=0;
    }
return index;
}


int get_id (ePaciente* this)
{
int index=-1;

    if(this != NULL)
    {
        index= this->Turno;
    }
return index;
}



int set_dni(ePaciente* this, char* dni )
{
int index=-1;

    if(this != NULL && dni != NULL)
    {
        this->Dni = dni;
        index=0;
    }
return index;
}


char* get_dni (ePaciente* this)
{
char* dni=NULL;

    if(this != NULL)
    {
        dni = this->Dni;
    }
return dni;
}

int mostrar_pacientes (ePaciente* this)
{
int index=-1;

    if(this != NULL)
    {
        printf(" TURNO: %d ---- DNI: %s \n", get_id(this), get_dni(this));
        index=0;
    }
return index;
}


int comparar_pacientes(void* pacienteA,void* pacienteB)
{
ePaciente* paciente1;
ePaciente* paciente2;

paciente1= (ePaciente*) pacienteA;
paciente2= (ePaciente*) pacienteB;

return strcmp(paciente1->Dni, paciente2->Dni);
}


int mostrar_lista_pacientes (ArrayList* listado)
{
int index=-1;
int i;
int len;
ePaciente* pacienteActual;

    if(listado != NULL)
    {
        len = listado->len(listado);
        for(i=0; i<len;i++)
        {
            pacienteActual= (ePaciente*) listado->get(listado, i);
            mostrar_pacientes(pacienteActual);
        }
    index=0;
    }
return index;
}


int cargar_paciente(ArrayList* listado, int turno, char* dni)
{
int index=-1;
ePaciente* pacienteActual;

    if(listado != NULL && turno>0 && dni != NULL)
    {
        pacienteActual = new_paciente();

        set_id(pacienteActual, turno);
        set_dni(pacienteActual, dni);

        listado->add(listado, pacienteActual);
        index=0;
    }
return index;
}

int lista_pacientes_atendidos (ArrayList* ListaPendientes, ArrayList* listaAtendidos)
{
int index=-1;
ePaciente* pacienteActual;

    if(ListaPendientes != NULL && listaAtendidos != NULL)
    {
        pacienteActual= (ePaciente*) ListaPendientes->pop(ListaPendientes,0);
        listaAtendidos->add(listaAtendidos, pacienteActual);

        index=0;
    }
return index;
}
