#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
typedef struct {
  char *nometask;
  int concluido;
} Task;

void lerTam(FILE *arquivo, int *tam, Task **ArrayTasks) {
  char linha[256];
  int numTarefas = 0;
  int encontrouLinhaHorizontal = 0;

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    if (!encontrouLinhaHorizontal) {
      if (strcmp(linha, "***\n") == 0) {
        encontrouLinhaHorizontal = 1;
      }
      continue;
    }

    if (strncmp(linha, "- [ ]", 5) == 0 || strncmp(linha, "- [x]", 5) == 0) {
      char *nome = strdup(linha + 5);
      nome[strcspn(nome, "\n")] = '\0';

      *ArrayTasks = (Task *)realloc(*ArrayTasks, (numTarefas + 1) * sizeof(Task));
      if (*ArrayTasks == NULL) {
        printf("Erro ao realocar memória\n");
        exit(1);
      }

      (*ArrayTasks)[numTarefas].nometask = nome;
      (*ArrayTasks)[numTarefas].concluido = (linha[3] == 'x');

      numTarefas++;
    }
  }
  *tam = numTarefas;
}

void novoTodo(FILE *toDo, int *tam, Task **ArrayTasks) {
  if (toDo == NULL) {
    char *titulo, *subTitulo, *descricaoToDo;
    printf("Inicializando arquivo!\n");
    toDo = fopen("tasks.md", "w+");
    printf("Digite o título: ");
    scanf("%m[^\n]", &titulo);
    printf("Digite o subtitulo: ");
    limparBuffer();
    scanf("%m[^\n]", &subTitulo);
    limparBuffer();
    printf("PARA QUEBRA DE LINHA: \"<br>\"\n");
    printf("Digite a descrição ('.' para parar): \n");
    scanf("%m[^.]", &descricaoToDo);
    limparBuffer();

    fprintf(toDo, "# %s\n## %s\n%s\n***", titulo, subTitulo, descricaoToDo);
    fflush(toDo); // Libera as alterações no arquivo
    fclose(toDo);
    toDo = fopen("tasks.md", "r+"); // Reabre o arquivo aqui
  } else {
    fclose(toDo); // Fecha o arquivo antes de reabri-lo
    toDo = fopen("tasks.md", "r+");
  }
  lerTam(toDo, tam, ArrayTasks);
  int numTarefas = *(tam);
  printf("Quantidade de tarefas: %d\n", numTarefas);
  for (int i = 0; i < numTarefas; i++) {
    printf("Tarefa %d: %s (%s)\n", i + 1, (*ArrayTasks)[i].nometask, (*ArrayTasks)[i].concluido ? "Concluída" : "Não concluída");
  }
}

void addTask(FILE *arquivo, Task **ArrayTasks, int *quantTasks) {
  printf("Digite qual tarefa deseja adicionar:\n");
  char nomeTarefa[256];
  scanf(" %[^\n]", nomeTarefa);

  *ArrayTasks = (Task *)realloc(*ArrayTasks, (*quantTasks + 1) * sizeof(Task));
  if (*ArrayTasks == NULL) {
    printf("Erro ao realocar memória\n");
    exit(1);
  }

  (*ArrayTasks)[*quantTasks].nometask = strdup(nomeTarefa);
  (*ArrayTasks)[*quantTasks].concluido = 0;

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "\n- [ ] %s", (*ArrayTasks)[*quantTasks].nometask);
  fflush(arquivo);
  (*quantTasks)++;
}

void listarTasks(Task *ArrayTasks, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("%d - ", i + 1);
    if (ArrayTasks[i].concluido == 0)
      printf("[ ] ");
    else
      printf("[x] ");
    printf("%s\n", ArrayTasks[i].nometask);
  }
}

void alterarStatus(int indice, Task *ArrayTasks, int tamanho, FILE *arquivo) {
  if (indice < 0 || indice >= tamanho) {
    printf("Índice inválido\n");
    return;
  }

  if (ArrayTasks[indice].concluido == 0)
    ArrayTasks[indice].concluido = 1;
  else
    ArrayTasks[indice].concluido = 0;

  // Armazenar o conteúdo antes das tarefas
  char linha[256];
  char conteudoAntesDasTarefas[1024] = "";
  int encontrouLinhaHorizontal = 0;
  fseek(arquivo, 0, SEEK_SET);
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    if (!encontrouLinhaHorizontal) {
      strcat(conteudoAntesDasTarefas, linha);
      if (strcmp(linha, "***\n") == 0) {
        encontrouLinhaHorizontal = 1;
      }
    } else {
      break;
    }
  }

  // Reescrever o arquivo
  fseek(arquivo, 0, SEEK_SET);
  fprintf(arquivo, "%s", conteudoAntesDasTarefas);
  for (int i = 0; i < tamanho; i++) {
    if (i != 0) {
      fprintf(arquivo, "\n");
    }
    if (ArrayTasks[i].concluido == 0)
      fprintf(arquivo, "- [ ] %s", ArrayTasks[i].nometask);
    else
      fprintf(arquivo, "- [x] %s", ArrayTasks[i].nometask);
  }
  fflush(arquivo);
}

void removerTarefa(int indice, Task *ArrayTasks, int *tamanho, FILE *arquivo) {
  if (indice < 0 || indice >= *tamanho) {
    printf("Índice inválido\n");
    return;
  }

  free(ArrayTasks[indice].nometask);
  for (int i = indice; i < *tamanho - 1; i++) {
    ArrayTasks[i] = ArrayTasks[i + 1];
  }

  (*tamanho)--;
  fseek(arquivo, 0, SEEK_SET);
  for (int i = 0; i < *tamanho; i++) {
    if (ArrayTasks[i].concluido == 0)
      fprintf(arquivo, "\n- [ ] %s", ArrayTasks[i].nometask);
    else
      fprintf(arquivo, "\n- [x] %s", ArrayTasks[i].nometask);
  }
  fflush(arquivo);
}

void printToDoOptions() {
  printf("\n\n");
  printf("1. Adicionar task\n");
  printf("2. Mudar status da task\n");
  printf("3. Remover task\n");
  printf("4. Listar tasks\n");
  printf("5. Sair\n");
}

int main() {
  FILE *toDo = NULL;
  int resp;
  int quantTasks = 0;
  Task *ArrayTasks = NULL;
  toDo = fopen("tasks.md", "r+");
  int opcaoEmToDo;
  novoTodo(toDo, &quantTasks, &ArrayTasks);
  do {
    printf("Qual função deseja acessar?\n1. Acessar To-Do List\n2. Sair\n");
    scanf("%d", &resp);
    switch (resp) {
    case 1:
      printToDoOptions();
      scanf("%d", &opcaoEmToDo);
      switch (opcaoEmToDo) {
      case 1:
        addTask(toDo, &ArrayTasks, &quantTasks);
        fflush(toDo);
        break;
      case 2:
        printf("Digite o índice da task que deseja alterar o status: ");
        int indiceStatus;
        scanf("%d", &indiceStatus);
        alterarStatus(indiceStatus - 1, ArrayTasks, quantTasks, toDo);
        break;
      case 3:
        printf("Digite o índice da task que deseja remover: ");
        int indiceRemover;
        scanf("%d", &indiceRemover);
        removerTarefa(indiceRemover - 1, ArrayTasks, &quantTasks, toDo);
        break;
      case 4:
        listarTasks(ArrayTasks, quantTasks);
        break;
      case 5:
        break;
      default:
        printf("Opção inválida\n");
      }
      break;
    case 2:
      printf("Encerrando programa...\n");
      break;
    default:
      printf("Opção inválida\n");
    }
  } while (resp != 2);

  fclose(toDo);
  return 0;
}
