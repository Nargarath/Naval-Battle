
// estruct para guardar posi��o dos barcos, dire��o , vida e tamanho

typedef struct{
	int x , y, z, cont, v;
}barco;

int vetor[100];  // vetor utilizado para IA sempre sortear algo valido, porem sem repeti��es
int pontos_geral[2];	// contador de pontos de ambos jogadores
int tam_vetor;		// utilizado para auxiliar vetor[100]
barco BARCOS_IA[10];		//struct barco IA
barco BARCOS_P[10];			//struct barco P
// fun��o que deixa o jogo em loop
void rodadas();
// fun��o uzada para testar se o barco foi destuido ou acertado e decrementa a vida total do barco
int testaTodoMundo(int x, int y, barco *c);
int verificaUm(int x, int y, barco *p);
// salva estado do jogo
void salvar();
// carrega estado do jogo
void carregar();
// carrega os valores que a ia pode sortear
void iniciavetor();
//determina qual limpesa de tela deve usar, se windows ou linux.
void limparTela();

