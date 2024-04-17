/*#Bibliotecas*/
#include "funcagenda.h"
#include "functodo.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#Constantes e Variaveis de controle de escopo geral*/

/*#Funcoes de menu/interface*/

//     Função de imprimir na tela as opcões do To-do
//     Deve ser chamada dentro de um escopo pós-bifucacao de fluxo
void printToDoOptions() {
  printf("\n\n");
  printf("1. Adicionar tasks\n");
  printf("2. Concluir task\n");
  printf("3. Editar tasks\n");
  printf("4. Remover tasks\n");
  printf("5. Listar tasks\n");
}

//     Função de imprimir na tela as opcões da Agenda
//     Deve ser chamada dentro de um escopo pos-bifucacao de fluxo
void printAgendaOptions() {
  printf("\n\n");
  printf("1. Criar Agenda\n");
  printf("2. Adicionar eventos\n");
  printf("3. Remover eventos\n");
  printf("4. Remover eventos\n");
}

/*vai printar tudo em arquivo, "r+"
switch case para o usuario escolher entre o
to-do-list e a agenda semanal
CÓDIGO ESTÁ APENAS O ESQUELETO!!*/

FILE *todo;
FILE *Agenda;
int main() {

  int opcao;
  do {
    //  opção para escolher entre to-do-list e agenda semanal
    //  Condição de acorodo com opção para desvio de fluxo do programa
    printf("Qual função deseja acessar?\n1. Acessar To-Do-List\n2. Acessar Agenda\n3. Para sair do programa\n");
    scanf("%d", &opcao);
    // opcao para escolher entre to-do ou agenda

    switch (opcao) {
    case 1:
      // to do list
      todo = fopen("tasks.md", "r+");
      printf("Rodou pai\n");
      if (todo == NULL) {
        // se o ARQUIVO for NULO, ele cria um novo arquivo!
        printf("Inicializando arquivo!\n");
        todo = fopen("tasks.md", "w+");
      }
      break;
    case 2:
      // fluxo para agenda
      printf("Rodou pai 2\n");
      break;

    default:
      printf("Encerrando programa...");
      exit(1);
      break;
    }
  } while (opcao == 1 || opcao == 2);
}
/*if (opcao == 1) { // Fluxo do To-do

  FILE *todo;
  todo = fopen("tasks.md", "r+");
  if(todo == NULL){
    todo = fopen("tasks.md", "w+");
  }

} else if (opcao == 2) { // Fluxo da Agenda

} else {
  printf("Opção Inválida\nEncerrando o programa...");
  exit(1);
}
}*/