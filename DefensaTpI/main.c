#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "pacientes.h"
#define TAM 10

int main()
{
    int opcion;
    int salir=0;
    int TurnoPacienteUrgente = 0;
    int TurnoPacienteRegular = 0;
    char dni[10];

    ArrayList* listaUrgente;
    ArrayList* listaRegular;

    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;

    listaUrgente = al_newArrayList();
    listaRegular = al_newArrayList();
    atendidosUrgentes = al_newArrayList();
    atendidosRegulares = al_newArrayList();


    do{
        printf(" 1.TURNO URGENTE \n");
        printf(" 2.TURNO REGULAR\n");
        printf(" 3.PROXIMO CLIENTE\n");
        printf(" 4.LISTADO\n");
        printf(" 5.INFORMAR ATENDIDOS\n");
        printf(" 6.SALIR\n");
        printf("\n OPCION: ");

        opcion=validarNumero(opcion);

        switch(opcion)
        {
        case 1:
            TurnoPacienteUrgente ++;
            printf("\n\tINGRESE DNI: ");
            fflush(stdin);
            gets(dni);
            cargar_paciente(listaUrgente,TurnoPacienteUrgente,dni);
            break;
        case 2:
            TurnoPacienteRegular ++;
            printf("\n\tINGRESE DNI: ");
            fflush(stdin);
            gets(dni);
            cargar_paciente(listaRegular,TurnoPacienteRegular,dni);
            break;
        case 3:
            if(!listaUrgente->isEmpty(listaUrgente))
                {
                    printf("\n\tCLIENTE A SER ATENDIDO [URGENTE]: \n");
                    lista_pacientes_atendidos(listaUrgente,atendidosUrgentes);
                }
                else
                {
                    if(!listaRegular->isEmpty(listaRegular))
                    {
                        printf("\n\tCLIENTE A SER ATENDIDO [REGULAR]: \n");
                        lista_pacientes_atendidos(listaRegular,atendidosRegulares);
                    }
                    {
                        printf("\n\tNO HAY CLIENTES POR ATENDER!\n");
                    }
                }
            break;
        case 4:
            if(!listaUrgente->isEmpty(listaUrgente))
                {
                    printf("\n\tTRAMITES URGENTES\n");
                    mostrar_lista_pacientes(listaUrgente);
                }
                else if(listaUrgente->isEmpty(listaUrgente))
                {
                    printf("\n\tNO HAY CLIENTES POR ATENDER!\n");
                }
                else if(!listaRegular->isEmpty(listaRegular))
                {
                    printf("\n\tTRAMITES REGULARES\n");
                    mostrar_lista_pacientes(listaRegular);
                }
                else
                {
                    printf("\n\tNO HAY CLIENTES POR ATENDER!\n");
                }
            break;
        case 5:
            if(!atendidosUrgentes->isEmpty(atendidosUrgentes))
                {
                    atendidosUrgentes->sort(atendidosUrgentes,comparar_pacientes,0);
                    printf("\n\tTRAMITES URGENTES\n");
                    mostrar_lista_pacientes(atendidosUrgentes);
                }

                if(!atendidosRegulares->isEmpty(atendidosRegulares))
                {
                    atendidosRegulares->sort(atendidosRegulares,comparar_pacientes,0);
                    printf("\n\tTRAMITES REGULARES\n");
                    mostrar_lista_pacientes(atendidosRegulares);
                }
            break;
        case 6:
            salir=1;
            break;
        default:
            printf("\n No se ha accedido a ninguna opcion del Sistema. Por favor, intente de nuevo.\n\n");
            break;
        }

    }while(salir==0);


return 0;
}
