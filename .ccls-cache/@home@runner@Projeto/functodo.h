/*#Descrição:

    Esse arquivo é uma biblioteca de funções, structs, 
    variáveis e outros componenetes que são dependencia do main.c, 
    o principal arquivo do PROJETO CPROGRAME,
    essa biblioteca é responsável por:
      PARA TRATAR DE TO-DO-LIST e TASKS
    por gentileza, não deixe de incluir esse arquivo na execução  
*/

/*#Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*#Tipos, struct, union, enum*/

//definição de tipo para Tasks com nome e status
typedef struct{
  char *nometask; //nome da task 
  int concluido; // == 1 concluido == 0 não concluido
} Task;

void listarTasks(Task *ArrayTasks, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d - ", i+1);
        if(ArrayTasks[i].concluido == 0)
            printf("[ ] ");
        else
            printf("[x] ");
        printf("%s\n", ArrayTasks[i].nometask);
    }
}
void alterarStatus(int indice, Task *ArrayTasks, int tamanho, FILE *arquivo) {
    // Alterar o status da tarefa no array
    if(ArrayTasks[indice].concluido == 0)
        ArrayTasks[indice].concluido = 1;
    else
        ArrayTasks[indice].concluido = 0;

    // Reescrever todas as tarefas no arquivo
    fseek(arquivo, 0, SEEK_SET);
    for(int i = 0; i < tamanho; i++) {
        if(ArrayTasks[i].concluido == 0)
            fprintf(arquivo, "\n- [ ] %s", ArrayTasks[i].nometask);
        else
            fprintf(arquivo, "\n- [x] %s", ArrayTasks[i].nometask);
    }
}

/*#FUNCOES*/

//função para adicionar tasks no to-do-list
void addTask(FILE *arquivo, Task **ArrayTasks, int *ultimo){
  printf("Digite qual tarefa deseja adicionar:\n");
  getchar();
  fflush(stdin);
  
  // Alocar memoria para Tarefa
  Task *newTask = (Task*) malloc(sizeof(Task));
  
  // Alocar memória para o nome da tarefa
  newTask->nometask = (char*) malloc(100 * sizeof(char));
  
  // Ler o nome da tarefa
  scanf("%m[^\n]", &(newTask->nometask));
  getchar();

  // Colocar a tarefa como não concluída
  newTask->concluido = 0;

  // Adicionar a tarefa ao array
  ArrayTasks[*ultimo] = newTask;

  // Colocar a tarefa no arquivo
  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "\n- [ ] %s", ArrayTasks[*ultimo]->nometask);

  // Aumentar a contagem de tarefas
  (*ultimo)++;
}

//função para remover tasks do to-do-list
void removerTask(int indice, Task **ArrayTasks, int *tamanho, FILE *arquivo) {
  // Remover a tarefa do array
  free(ArrayTasks[indice]);
  for (int i = indice; i < *tamanho - 1; i++) {
    ArrayTasks[i] = ArrayTasks[i + 1];
  }

  // Diminuir o número de tarefas
  (*tamanho)--;

  // Reescrever todas as tarefas no arquivo
  fseek(arquivo, 0, SEEK_SET);
  for(int i = 0; i < *tamanho; i++) {
    if(ArrayTasks[i]->concluido == 0)
      fprintf(arquivo, "\n- [ ] %s", ArrayTasks[i]->nometask);
    else
      fprintf(arquivo, "\n- [x] %s", ArrayTasks[i]->nometask);
  }
}

