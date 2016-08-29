/* tamanho da matriz */
#define LIN 10
#define COL 10

/*  inicialização dos valores da matriz
*/
typedef enum{
	MAR,
	VAZIO,
	NAVIO
}tipoP;

//criação das matrizes do jogador 
int matrizP[LIN][COL];
int matrizPTiros[LIN][COL];
// inicia matriz do jogador com valor 0, e variavel utilizada na struc que se encontra no jogar.c
void iniciaMatrizP();
// printa matriz ou de tiro ou de barcos
void imprimeMatrizP(int x);
// sorteia barco manualmente
void enviaTamanhoP();
void sortPosP(int quantidade,int tamanho);
// sorteia barco aleatoriamente
void enviaTamanhoPAleatorio();
void sortPosPAleatorio(int quantidade,int tamanho);
// atira na matriz da ia
int atiraP();
// função utilizada para tranformar char em inteiro
int valor(char c);
//posiciona o navio e os pontos ao seu redor
void colocaNavioP(int lin, int col, int value,int z);
