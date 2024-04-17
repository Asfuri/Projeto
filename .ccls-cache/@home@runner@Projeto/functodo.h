/*#Descrição:

    Esse arquivo é uma biblioteca de funções, structs, 
    variáveis e outros componenetes que são dependencia do main.c, 
    o principal arquivo do PROJETO CPROGRAME,
    essa biblioteca é responsável por:
      PARA TRATAR DE TO-DO-LIST e TASKS
    por gentileza, não deixe de incluir esse arquivo na execução  
*/

/*#Bibliotecas*/
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*#Tipos, struct, union, enum*/

//definição de tipo para Tasks com nome e status
typedef struct{
  char *nometask; //nome da task 
  int concluido; // ==1 concluido == 0 não concluido
} Task;


/*#FUNCOES*/

//função para adicionar tasks no to-do-list
void addtasks(FILE *arquivo){

  char *addtask;
  printf("Digite qual tarefa deseja adicionar:\n");
  scanf("%m[^\n]", &addtask);
  getchar();
  fprintf(arquivo, "%s\n", addtask);

}

//função para remover tasks do to-do-list
void removtask(FILE *arquivo){
  char *removtask;
  printf("Digite qual tarefa deseja remover:\n");
  scanf("%m[^\n]", &removtask);
  getchar();
  int tam = strlen(removtask);
  for (int i=0; i<tam; i++) {
    if (strcmp (removtask, Task.nometask[i] == 0)){
      
    }
  }
  
}

