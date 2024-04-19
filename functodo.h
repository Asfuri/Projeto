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
  int concluido = 0; // ==1 concluido == 0 não concluido
} Task;

void marcarConcluido(Task *task){
  char resp;
  if(task->concluido == 0){
    task->concluido = 1;
    //printf("Task marcada com sucesso\n");
  }
  //else{
    //printf("Task já está como concluida\n");
    //printf("Deseja desmarcar?\n");
    //scanf(" %c", &resp);
  //}
    //if(resp == 's'){
      //task->concluido = 0;
    //}
    //else{
      //printf("Ok, não foi desmarcado\n");
    //}
    
}
void listarTask(Task *)
/*3 - 4 - 6
  -> LISTAR()
  -> Digite o numero da tarefa
  -> concluida 
  -> C -> XXXX
  -> I -> C
  -> inconcluda
  -> C -> I
  -> I -> XXXX
*/
// void alternarConcluir(Task *task){
//   if(task->concluido == 1)
//     task->concluido = 0;
//   else 
//     task->concluido = 1;
// }

void desmarcarConcluido(Task *task){
  if(task->concluido == 1){
    task->concluido = 0;
  }
}
/*while(){
  if(Task.concluido != 0){
    Printf("Tasks Concluidas: %s", Task.nometask[i][]);
  }
  1. - 
  2. - 
  3. - 
printf("Qual task quer mudar:")
  for(int i=0; i< N;i++ ){
    if(Task.nome[i+1] == Task.nome[N]){
      marcarcomoconluida(Task.nome[i];)
    }
  }
}*/
/*#FUNCOES*/

//função para adicionar tasks no to-do-list
void addTask(FILE *arquivo){
  char *addtask;
  printf("Digite qual tarefa deseja adicionar:\n");
  scanf("%m[^\n]", &addtask);
  getchar();
  
  fprintf(arquivo, "%s\n", addtask);

}

//função para remover tasks do to-do-list
void removtask(Task *task[], int *tamanho){
  int n; //indice a ser removido
  printf("Qual número da task deseja remover?\n");
  //função de imprimir opções
  scanf("%i", &n);
  if(n<1 || n>*tamanho){
    printf("Índice inválido\n");
    return 1;
  }
  n--;//ajustar o indice para o vetor
  int indiceremover = task[n].concluido;
  //deslocar as strings para preencher o espaço
  for(int i=n, i < *tamanho-1; i++){
    task[i] = task[i+1];
  }

  (*tamanho)--;
  printf("Tarefa removida com sucesso!\n");
 
}

