#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

typedef struct{
int Dni;
int Turno;
}ePaciente;

ePaciente* new_paciente();

int set_id(ePaciente* this , int id );

int get_id (ePaciente* this);

int set_dni(ePaciente* , char* );

char* get_dni (ePaciente* );

int mostrar_pacientes (ePaciente* this);

int comparar_pacientes(void* pacienteA,void* pacienteB);

int mostrar_lista_pacientes (ArrayList* listado);

int cargar_paciente(ArrayList* listado, int turno, char* dni);

int lista_pacientes_atendidos (ArrayList* ListaPendientes, ArrayList* listaAtendidos);

#endif // PACIENTES_H_INCLUDED
