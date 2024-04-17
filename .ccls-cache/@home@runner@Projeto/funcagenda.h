/*#Descrição:

    Esse arquivo é uma biblioteca de funções, structs, 
    variáveis e outros componenetes que são dependencia do main.c, 
    o principal arquivo do PROJETO CPROGRAME,
    essa biblioteca é responsável por:
      PARA TRATAR DE AGENDA e EVENTOS
    por gentileza, não deixe de incluir esse arquivo na execução  
*/

/*#Bibliotecas*/
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*#Tipos, struct, union, enum*/

//definição de tipo para Eventos
typedef struct{
  char *evento;
  int hora; //apenas horários fechados
  int dia;
} Evento;

/*#FUNCOES*/

