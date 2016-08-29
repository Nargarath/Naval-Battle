// declaração de bibliotecas geral do projeto
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* tamanho da matriz */
#define LIN_IA 10
#define COL_IA 10



/*  definição dos valores da matriz
*/
typedef enum{
	MAR_IA,
	VAZIO_IA,
	NAVIO_IA
}tipoIa;


// matrizes da IA
int matrizIa[LIN_IA][COL_IA];		
int matrizIaTiros[LIN_IA][COL_IA];
// função menu com opções novo jogo, carregar e sair
void menu();

//função para iniciar valores de ambas matrizes da IA com 0, e da variavel usada na struct dos barcos que se encontra no jogar.c
void iniciaMatrizIa();
// função para imprimir a matriz dos barcos da IA
void imprimeMatrizIa(int x);
// funções usadas para colocar sortear , e colocar barco e pontos
void enviaTamanhoIa();
void sortPosIa(int quantidade,int tamanho);
void colocaNavioIa(int lin, int col, int value,int z);
//função que atira na matriz inimiga
int atiraIa();

