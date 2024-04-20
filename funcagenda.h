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

//		Função de criar a agenda
// 	Pode ser chamada de outras funções(agendaExiste) 
//		(min = 0, max = 0)
// 	Logo, trata
void criarAgenda(FILE *Agenda, int min, int max){
  if(min == 0 && max == 0){
    printf("Digite a hora inicial(0 a 24): ");
    scanf("%d", &min);
    printf("Digite a hora final(%d a 24): ", min);
    scanf("%d", &max);
    if(!(min < max) || (!(min > 0 && min < 24) || !(max < 24))){
      printf("Voce digitou horas invalidas!\n");
      return;
     }
  }
  Agenda = fopen("agenda.md", "w"); // imprimir esqueleto da agenda
  fprintf(Agenda, "Hora | Domingo | Segunda | Terça | Quarta | Quinta | Sexta | Sábado\n");
  fprintf(Agenda, "---|---|---|---|---|---|---|--- \n");
  for(int i = min; i <= max; i++){
    fprintf(Agenda, "%dh |  |  |  |  |  |  | \n", i);
  }
  fclose(Agenda);
}

// 	Essa função sera apenas de backstage
// 	Deve ser chamada antes das demais funções
// 	Excluindo apenas a criarAgenda()
void agendaExiste(FILE *agenda){
  agenda = fopen("agenda.md", "r+");
  if(agenda == NULL){
    printf("A agenda não existe, criando agenda...\n");
    fclose(agenda);
    criarAgenda(agenda, 0, 0);
  } else {
    return;
  }
}

//		Função de adicionar evento
// void adicionarEvento(FILE *Agenda, int dia, char horaFormatada[4], int hora){
//   Agenda = fopen("agenda.md", "r+");
  // Evento evento;
  // evento.dia = dia;
  // evento.hora = hora;
  // printf("Digite o evento: ");
  // fflush(stdin);
  // scanf("%m[^\n]", &evento.evento);
  // getchar();
  // fflush(stdin);
  // char linha[200];
  // int quantlinhas = 0;
  // char strBusca[3];
  // char pipes;
  // int countPipes = 0;
  // fseek(Agenda, 0, SEEK_CUR);
  // while(fscanf(Agenda, "%[^\n]", linha) != EOF){
  // 	strcpy(strBusca, strstr(linha, " "));
  // 	quantlinhas++;
  // 	if(strcmp(strBusca, horaFormatada) == 0){
  // 		while((pipes = fgetc(Agenda)) == 1){
  // 			if(pipes == '|')
  // 				countPipes++;
  // 			if(countPipes == dia){
  // 				fprintf(Agenda, "%s|", evento.evento);
  // 			}
  // 			if(countPipes > 7)
  // 				printf("algo deu errado nos pipes");
  // 		}
  // 	}
  // }
//   printf("Algo deu errado!\n");
//   fclose(Agenda);
// }