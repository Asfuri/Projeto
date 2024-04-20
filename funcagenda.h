/*#Descrição:

    Esse arquivo é uma biblioteca de funções, structs, 
    variáveis e outros componenetes que são dependencia do main.c, 
    o principal arquivo do PROJETO CPROGRAME,
    essa biblioteca é responsável por:
      PARA TRATAR DE AGENDA e EVENTOS
    por gentileza, não deixe de incluir esse arquivo na execução  
*/

/*#Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Constantes e variáveis de controle*/
#define DOMINGO 1
#define SEGUNDA 2
#define TERCA   3
#define QUARTA  4
#define QUINTA  5
#define SABADO  6

/*#Tipos, struct, union, enum*/

//definição de tipo para Eventos
typedef struct{
  char *evento;
  int hora; //apenas horários fechados
  int dia;
} Evento;

/*#FUNCOES*/

