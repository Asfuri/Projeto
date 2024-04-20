/*#Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "functodo.h"
#include "funcagenda.h"

/*#Constantes e Variaveis de controle de escopo geral*/
/*#Funcoes de menu/interface*/

//     Função de imprimir na tela as opcões do To-do
//     Deve ser chamada dentro de um escopo pós-bifucacao de fluxo
void printToDoOptions() {
  printf("\n\n");
  printf("1. Adicionar tasks\n");
  printf("2. Concluir task\n");
  printf("3. Remover conclusão da task\n");
  printf("4. Editar task\n");
  printf("5. Remover task\n");
  printf("6. Listar tasks\n");
}

//     Função de imprimir na tela as opcões da Agenda
//     Deve ser chamada dentro de um escopo pos-bifucacao de fluxo
void printAgendaOptions() {
  printf("\n1. Criar Agenda\n");
  printf("2. Adicionar evento\n");
  printf("3. Remover evento\n");
  printf("4. Editar evento\n");
  printf("Escolha uma opção: ");
}

/*vai printar tudo em arquivo, "r+"
switch case para o usuario escolher entre o
to-do-list e a agenda semanal
CÓDIGO ESTÁ APENAS O ESQUELETO!!*/

Task *tarefas;
FILE *toDo;
FILE *Agenda;
// tarefas = (Task *)malloc(sizeof(Task));

int main() {

  int resp;
  int opcaoEmAgenda;
  int min, max, diaAlterar, horaAlterar;
  char horaFormatada[4];
  do {
    //  opção para escolher entre to-do-list e agenda semanal
    //  Condição de acorodo com opção para desvio de fluxo do programa
    printf("Qual função deseja acessar?\n1. Acessar To-Do-List\n2. Acessar Agenda\n3. Para sair do programa\n");
    scanf("%d", &resp);
    // opcao para escolher entre to-do ou agenda

    switch (resp) {

    case 1:
      // to do list

      toDo = fopen("tasks.md", "r+");
      if (toDo == NULL) {
        char *titulo;
        char *subTitulo;
        char *descricaoToDo;
        //   se o ptr ARQUIVO for NULO, ele cria um novo arquivo!
        //   logo, está sem titulo, subtitulo e descrição
        printf("Inicializando arquivo!\n");
        toDo = fopen("tasks.md", "w+");
        //Usuário digita o título
        getchar();
        fflush(stdin);
        printf("Digite o título: ");
        scanf("%m[^\n]", &titulo);
        getchar();
        //Usuário digita o subtitulo
        printf("Digite o subtitulo: ");
        scanf("%m[^\n]", &subTitulo);
        getchar();
        //Usuário digita a descrição
        // + instruções
        printf("PARA QUEBRA DE LINHA: \"<br>\"\n");
        printf("Digite a descrição ('.' para parar): \n");
        scanf("%m[^.]", &descricaoToDo);
        getchar();
        // Imprime no tasks.md as informações
        fprintf(toDo, "# %s\n## %s\n%s\n***", titulo, subTitulo, descricaoToDo);
        fclose(toDo);
        //   Depois abre com r+ para começar as operações com a lista
        toDo = fopen("tasks.md", "r+");
      }
      int remover;
      int opcaoEmToDo;
      printToDoOptions();
      scanf("%d", &opcaoEmToDo);
      switch (opcaoEmToDo){
        case 1: // adicionar task
          // addTask(toDo);
          break;
        case 2: //remover task
          printf("Digite qual número da task que deseja remover:\n");
          scanf("%d", &remover);
          // removtask(remover);
          break;
        case 3: //marcar task como concluida
          printf("Deseja marcar qual task como concluida?\n");
          // listasTasks();
          //função listar task com os indices
          // marcarConcluido(tarefas[i]);
          printf("Task marcada como concluída com sucesso!\n");
          break;
        case 4: //listar tasks ja cadastradas
        break; 
      }
    break; 
    case 2:
      // fluxo para agenda
      printAgendaOptions();
      scanf("%d", &opcaoEmAgenda);
      switch (opcaoEmAgenda){
        case 1: // Criar Agenda
          printf("\nAviso! Se houver agenda, sera sobrescrita!\n");
          printf("Digite a hora inicial(0 a 24): ");
          scanf("%d", &min);
          printf("Digite a hora final(%d a 24): ", min);
          scanf("%d", &max);
          // testa se o usuario digitou horas validas
          // Se não, ele vai para a proxima iteracao (menu inicial)
          if(!(min < max) || (!(min > 0 && min < 24) || !(max < 24))){
            printf("Voce digitou horas invalidas!\n");
            continue;
          }
          criarAgenda(Agenda, min, max);
        break;
        case 2: // Adicionar evento
          printf("1 - Domingo \t 2 - Segunda \t 3 - Terça \n4 - Quarta \t 5 - Quinta \t 6 - Sexta \t 7 - Sábado\n");
          printf("Digite o dia em que voce quer criar o evento: ");
          scanf("%d", &diaAlterar);
          printf("Digite a hora em que voce quer criar o evento: ");
          scanf("%d", &horaAlterar);
          // testa se o usuario digitou horas validas
          if(diaAlterar >= 1 && diaAlterar <= 7 && horaAlterar > min){
            // pode ocorrer de min e max nao terem valores, pois a agenda foi criada a partir de um erro de falta de agenda
            sprintf(horaFormatada, "%dh", horaAlterar); 
            // adicionarEvento(Agenda, diaAlterar, horaFormatada, horaAlterar);
          }else
            printf("Voce digitou algo inválido!\n");
          continue;
        break;
        case 3:
          // removerEvento();
        break;
        case 4:
          // editarEvento();
        break;
      }
      break;

    default:
      printf("Encerrando programa...");
      exit(1);
      break;
    }
  } while (resp != 3);
}