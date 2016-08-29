// declara��o de bibliotecas geral do projeto
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* tamanho da matriz */
#define LIN_IA 10
#define COL_IA 10



/*  defini��o dos valores da matriz
*/
typedef enum{
	MAR_IA,
	VAZIO_IA,
	NAVIO_IA
}tipoIa;


// matrizes da IA
int matrizIa[LIN_IA][COL_IA];		
int matrizIaTiros[LIN_IA][COL_IA];
// fun��o menu com op��es novo jogo, carregar e sair
void menu();

//fun��o para iniciar valores de ambas matrizes da IA com 0, e da variavel usada na struct dos barcos que se encontra no jogar.c
void iniciaMatrizIa();
// fun��o para imprimir a matriz dos barcos da IA
void imprimeMatrizIa(int x);
// fun��es usadas para colocar sortear , e colocar barco e pontos
void enviaTamanhoIa();
void sortPosIa(int quantidade,int tamanho);
void colocaNavioIa(int lin, int col, int value,int z);
//fun��o que atira na matriz inimiga
int atiraIa();

