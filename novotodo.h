#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void novoTodo(FILE *toDo) {
  if (toDo == NULL) {
    char *titulo;
    char *subTitulo;
    char *descricaoToDo;
    //   se o ptr ARQUIVO for NULO, ele cria um novo arquivo!
    //   logo, está sem titulo, subtitulo e descrição
    printf("Inicializando arquivo!\n");
    toDo = fopen("tasks.md", "w+");
    // Usuário digita o título
    getchar();
    fflush(stdin);
    printf("Digite o título: ");
    scanf("%m[^\n]", &titulo);
    getchar();
    // Usuário digita o subtitulo
    printf("Digite o subtitulo: ");
    scanf("%m[^\n]", &subTitulo);
    getchar();
    // Usuário digita a descrição
    //  + instruções
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
}