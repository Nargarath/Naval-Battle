#include "ia.h"
#include "play1.h"
#include "jogar.h"

int barcos_ia_cont = 0;
/**
 * Inicia as Matrizes de tiros e a do tabuleiro secreto com 0. \n
 * A matrizIa � a matriz que ter� o jogo da inteligencia artificial que nao poder� ser visualizado pelo player. \n
 * A matrizIaTiros � a matriz que recebera os tiros do player e ser� usada futuramente para comprarar com a matriz do tabuleiro secreto(matrizIa).
 */
void iniciaMatrizIa(){
	int i,j;
	barcos_ia_cont = 0;
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			matrizIa[i][j] = MAR_IA;
			matrizIaTiros[i][j] = MAR_IA;
		}
	}
}
/**
 * A Ia gera duas posi��es aleat�rias para atirar na matriz do player.\n 
 * O tiro ser� testado de acordo com a matriz do tabuleiro do jogador.\n
 * retorna 1 se acertou e 0 se 	errou.
 */
int atiraIa(){
		int x,y,z,w;
		w = rand() % tam_vetor;
		x = vetor[w] / 10;
		y = vetor[w] % 10;		
		vetor[w]= vetor[tam_vetor-1];
		tam_vetor--;
		if(matrizIaTiros[x][y]==MAR_IA && testaTodoMundo(x, y,BARCOS_P)){
			matrizIaTiros[x][y]=NAVIO_IA;
		}else if(matrizIaTiros[x][y]==MAR_IA && matrizP[x][y]!=NAVIO){
			matrizIaTiros[x][y]=VAZIO_IA;
		}	
		if(matrizIaTiros[x][y]==NAVIO_IA){
			return 1;
		}else{
			return 0;
		}
}




/**
 *  fun��o para imprimir a matriz dos barcos da IA
 */
void imprimeMatrizIa(int x){
	printf("Matriz IA\n");
	int i,j;
	if(x==1){
		printf("    ");
		for(i=65;i<75;i++){
			printf("%c ",i);
		}
		printf("\n");
		for(i=0;i<LIN_IA;i++){
			if(i==9){
				printf("%i  ",i+1);	
			}else{
				printf("%i   ",i+1);
			}
			for(j=0;j<COL_IA;j++){
				if(matrizIa[i][j]==MAR_IA){
					printf("~ ");
				}
				else if(matrizIa[i][j]==VAZIO_IA){
					printf(". ");
				}
				else if(matrizIa[i][j]==NAVIO_IA){
					printf("X ");
				}
			}
			printf("\n");
		}
	}else {
		printf("    ");
		for(i=65;i<75;i++){
			printf("%c ",i);
		}
		printf("\n");
		for(i=0;i<LIN_IA;i++){
			if(i==9){
			printf("%i  ",i+1);	
			}else{
				printf("%i   ",i+1);
			}
			for(j=0;j<COL_IA;j++){
				if(matrizIaTiros[i][j]==MAR_IA){
					printf("~ ");
				}
				else if(matrizIaTiros[i][j]==VAZIO_IA){
					printf(". ");
				}
				else if(matrizIaTiros[i][j]==NAVIO_IA){
					printf("X ");
				}
			}
	
		printf("\n");
		}
	}
}

/**  
 * fun��o que envia tamanho e quantidade de navios para ia sortear a posi��o do navio
 */
void enviaTamanhoIa(){
	int i,j;
	i=1;
	j=5;
	while(i<j){
		sortPosIa(i,j-i);
		i++;
	}
}

/**  
 * Fun��o que sorteia a posi��o do navio
 */
void sortPosIa(int quantidade,int tamanho){	
	int x ,y,z,cont;
	while(quantidade>0){
		z= rand() %2;
		cont=0;
		if(z==0){
			x = rand() %LIN_IA;
			y = rand() %(COL_IA-tamanho+1);
			while(cont<tamanho){		
				if(matrizIa[x][y+cont]!=MAR_IA){
					cont=0;
					x = rand() % LIN_IA;
					y = 	rand() % (COL_IA-tamanho+1);
				}else{
					cont++;
				}
			}
		} else {
			x = rand() % (LIN_IA-tamanho+1);
			y = rand() %COL_IA;
				while(cont<tamanho){
					if(matrizIa[x+cont][y]!=MAR_IA){
						cont=0;
						x = rand() % (LIN_IA-tamanho+1);
						y = rand() % COL_IA;
					}else{
						cont++;
					}
				}
			
		}
		BARCOS_IA[barcos_ia_cont].x = x;
		BARCOS_IA[barcos_ia_cont].y = y;
		BARCOS_IA[barcos_ia_cont].z = z;
		BARCOS_IA[barcos_ia_cont].cont = tamanho;
		BARCOS_IA[barcos_ia_cont].v = tamanho;
		
		barcos_ia_cont++;
		colocaNavioIa(x,y,tamanho,z);
		quantidade--;
	}
}

/**  
 * Fun��o que ir� posicionar o navio na posi��o que fo sorteada
 */
void colocaNavioIa(int x, int y, int tamanho,int z) {
	int i;
	//colocando pontos
	if(z==0){
		if(x>0){
			if(y>0 && y<9){
				for(i=0;i<tamanho+2;i++){
					matrizIa[x-1][y+i-1]=VAZIO_IA;
				}	
			}
		else if(y==0){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x-1][y+i]=VAZIO_IA;
			}		
		}
		else if(y==9){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x-1][y+i-1]=VAZIO_IA;
			}		
		}
		}
		
		if(y>0 && y<9){
			for(i=0;i<tamanho+2;i++){
					matrizIa[x][y+i-1]=VAZIO_IA;
			}	
		}
		if(y==0){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x][y+i]=VAZIO_IA;
			}		
		}
		if(y==9){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x][y+i-1]=VAZIO_IA;
			}		
		}
		
		if(x<9){
			if(y>0 && y<9){
				for(i=0;i<tamanho+2;i++){
					matrizIa[x+1][y+i-1]=VAZIO_IA;
				}	
			}
			if(y==0){
				for(i=0;i<tamanho+1;i++){
					matrizIa[x+1][y+i]=VAZIO_IA;
				}		
			}
			if(y==9){
				for(i=0;i<tamanho+1;i++){
					matrizIa[x+1][y+i-1]=VAZIO_IA;
				}		
			}
		}
		
		
	//colocando navio	
		for(i=0;i<tamanho;i++){
				matrizIa[x][y+i]=NAVIO_IA;
		}
		
	}else{
	//colocando pontos
		if(y>0){
			if(x>0 && x<9){
			for(i=0;i<tamanho+2;i++){
				matrizIa[x-1+i][y-1]=VAZIO_IA;
				}	
			}
		else if(x==0){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x+i][y-1]=VAZIO_IA;
				}		
			}
		else if(x==9){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x-1+i][y-1]=VAZIO_IA;
			}		
		}
		}
		
		if(x>0 && x<9){
			for(i=0;i<tamanho+2;i++){
				matrizIa[x+i-1][y]=VAZIO_IA;
				}	
			}
		if(x==0){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x+i][y]=VAZIO_IA;
				}		
			}
		if(x==9){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x+i-1][y]=VAZIO_IA;
			}		
		}
		
		if(y<9){
			if(x>0 && x<9){
			for(i=0;i<tamanho+2;i++){
				matrizIa[x+i-1][y+1]=VAZIO_IA;
				}	
			}
		if(x==0){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x+i][y+1]=VAZIO_IA;
				}		
			}
		if(x==9){
			for(i=0;i<tamanho+1;i++){
				matrizIa[x+i-1][y+1]=VAZIO_IA;
			}		
		}
		}
		
		
		
		
		
		
	//colocando navio
		for(i=0;i<tamanho;i++){
			matrizIa[x+i][y]=NAVIO_IA;
		}
	}
}
	

