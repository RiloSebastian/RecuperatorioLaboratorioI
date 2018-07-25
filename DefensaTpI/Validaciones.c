#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "validaciones.h"
#define TAM 10

int validarNumero(int numero){
int num;
int i;
int j=0;
int retorno;
char numAux[30];

do{
 fflush(stdin);

 gets(numAux);

 i=strlen(numAux);

 while(j<i){

  if((numAux[j]> 47 && numAux[j]<58) || (numAux[j]>43 && numAux[j]<47)){
   retorno= 0;
   j++;
  }
  else{
   retorno= 1;
   break;
  }
 }
 if(retorno!=0){
  printf("Error: debe ingresar datos enteros\n vuelva a ingresar: ");
  }
}while(retorno!=0);

num=atoi(numAux);
numero=num;
return numero;
}
