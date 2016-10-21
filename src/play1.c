#include "../lib/play1.h"
#include "../lib/ia.h"
#include "../lib/jogar.h"
// contador de navios destruidos
int barcos_p_cont = 0;

/**
 * Inicia as Matrizes de tiros e a do tabuleiro secreto com 0. \n
 * A matrizP � a matriz que ter� o jogo do player que nao poder� ser visualizado pela inteligencia artificial. \n
 * A matrizPTiros � a matriz que recebera os tiros dq IQ e ser� usada futuramente para comprarar com a matriz do tabuleiro secreto(matrizP).
 */
 void iniciaMatrizP(){
 	int i,j;
 	barcos_p_cont = 0;
 	for(i=0;i<LIN;i++){
 		for(j=0;j<COL;j++){
 			matrizP[i][j] = MAR;
 			matrizPTiros[i][j] = MAR;
 		}
 	}
 }

/**
 * a fun��o pede as coordenadas que o usu�rio quer atirar no tabuleiro da IA
 */
 int atiraP(){
 	int x,y;
 	char z;		
 	printf("\ndigite a localizacao que deseja atirar no campo inimigo.");
 	do{
 		printf("\nDigite a linha\n");
 		scanf("%i",&x);
 		x--;
 	}while(x<0 || x>9);
 	
 	do{
 		printf("\ndigite a coluna\n");
 		scanf("\n%c",&z);
 		y = valor(z);
 	}while(y<0 || y>9);
 	
 	if(matrizPTiros[x][y]==MAR && testaTodoMundo(x,y,BARCOS_IA)){
 		matrizPTiros[x][y]=NAVIO;
 	}else if(matrizPTiros[x][y]==MAR && matrizIa[x][y]!=NAVIO_IA){
 		matrizPTiros[x][y]=VAZIO;
 	}else{
 		while(matrizPTiros[x][y] != MAR){
 			printf("\nEsse lugar ja foi atirado, escolha outro lugar!");
 			do{
 				printf("\nDigite a linha\n");
 				scanf("%i",&x);
 				x--;
 			}while(x<0 || x>9);
 			
 			do{
 				printf("\ndigite a coluna\n");
 				scanf("\n%i",&y);
 				y = valor(y);
 			}while(y<0 || y>9);
 		}
 		if(matrizIa[x][y]==MAR_IA){
 			matrizPTiros[x][y]=VAZIO;
 		}else if(matrizIa[x][y]==VAZIO_IA){
 			matrizPTiros[x][y]=VAZIO;
 		}else{
 			testaTodoMundo(x,y,BARCOS_IA);
 			matrizPTiros[x][y]=NAVIO;
 		}
 	}	
 	if(matrizPTiros[x][y]==NAVIO){
 		return 1;
 	}else{
 		return 0;
 	}		
 }

/**
 * Imprime a matriz do player na tela
 */
 void imprimeMatrizP(int x){
 	printf("Matriz P\n");
 	int i,j;
 	if(x==1){
 		printf("    ");
 		for(i=65;i<75;i++){
 			printf("%c ",i);
 		}
 		printf("\n");
 		for(i=0;i<LIN;i++){
 			if(i==9){
 				printf("%i  ",i+1);	
 			}else {
 				printf("%i   ",i+1);
 			}
 			for(j=0;j<COL_IA;j++){
 				if(matrizP[i][j]==MAR){
 					printf("~ ");
 				}
 				else if(matrizP[i][j]==VAZIO){
 					printf(". ");
 				}
 				else if(matrizP[i][j]==NAVIO){
 					printf("X ");
 				}
 			}
 			printf("\n");
 		}
 	}else{
 		printf("    ");
 		for(i=65;i<75;i++){
 			printf("%c ",i);
 		}
 		printf("\n");
 		for(i=0;i<LIN;i++){
 			if(i==9){
 				printf("%i  ",i+1);	
 			}else {
 				printf("%i   ",i+1);
 			}
 			for(j=0;j<COL_IA;j++){
 				if(matrizPTiros[i][j]==MAR){
 					printf("~ ");
 				}
 				else if(matrizPTiros[i][j]==VAZIO){
 					printf(". ");
 				}
 				else if(matrizPTiros[i][j]==NAVIO){
 					printf("X ");
 				}
 			}
 			printf("\n");
 		}
 	}
 }
/**
 * Envia o tamanho e a posi��o que o barco ser� alocado
 */
 void enviaTamanhoP(){
 	int i=1,j=5;
 	while(i<j){
 		sortPosP(i,j-i);
 		i++;
 	}
 }
/**
 * Envia o tamanho e a posi��o que o barco ser� alocado aleatoriamente
 */
 void enviaTamanhoPAleatorio(){
 	int i=1,j=5;
 	while(i<j){
 		sortPosPAleatorio(i,j-i);
 		i++;
 	}
 }
/**
 *	pede que o jogador digite o lugar que o barco ser� colocado.
 */
 void sortPosP(int quantidade,int tamanho){
 	int x ,y,z,cont,w,c;
 	char d;
 	while(quantidade>0){
 		do{
 			printf("Escolha a direcao para o navio de tamanho %i\n"
 				"Digite 0 para posicionar o navio de na horizontal.\n"
 				"Digite 1 para posicionar o navio na vertical.\n"
 				,tamanho);
 			fflush(stdin);
 			scanf("%i",&z);
 			if(z<0 || z>1 ){
 				printf("digite a porra certa!\n");
 			}
 		}while(z<0 || z>1);
 		cont=0;
 		if(z==0){
 			printf("Escolha a Linha : de 1 a 10\n"
 				"Escolha a Coluna: de A a J\n");
 			do{
 				printf("Digite o numero referente a linha:  \n");
 				fflush(stdin);
 				scanf("%i",&c);
 				x = c-1;
 			}while(x<0 || x>9);
 			
 			do{
 				printf("Digite o numero referente a coluna:  \n");
 				fflush(stdin);
 				scanf("%c",&d);
 				y = valor(d);
 			}while(y<0 || y>(COL-tamanho+1) );
 			
 			while(cont<tamanho){		
 				if(matrizP[x][y+cont]!=MAR){
 					cont=0;
 					do{
 						printf("Digite o numero referente a linha:  \n");
 						fflush(stdin);
 						scanf("%i",&c);
 						x = c-1;
 					}while(x<0 || x>9);
 					do{
 						printf("Digite o numero referente a coluna:  \n");
 						fflush(stdin);
 						scanf("%c",&d);
 						y = valor(d);
 					}while(y<0 || y>(COL-tamanho+1) );
 				}else{
 					cont++;
 				}
 			}
 		} else {
 			do{
 				printf("Digite o numero referente a linha:  \n");
 				fflush(stdin);
 				scanf("%i",&c);
 				x = c-1;
 			}while(x<0 || x>(LIN-tamanho+1));
 			
 			do{
 				printf("Digite o numero referente a coluna:  \n");
 				fflush(stdin);
 				scanf("%c",&d);
 				y = valor(d);
 			}while( y<0 || y>9 );
 			
 			while(cont<tamanho){
 				if(matrizP[x+cont][y]!=MAR){
 					cont=0;
 					do{
 						printf("Digite o numero referente a linha:  \n");
 						fflush(stdin);
 						scanf("%i",&c);
 						x = c-1;
 					}while(x<0 || x>(LIN-tamanho+1));
 					
 					do{
 						printf("Digite o numero referente a coluna:  \n");
 						fflush(stdin);
 						scanf("%c",&d);
 						y = valor(d);
 					}while( y<0 || y>9 );		
 				}else{
 					cont++;
 				}
 			}	
 		}
 		BARCOS_P[barcos_p_cont].x = x;
 		BARCOS_P[barcos_p_cont].y = y;
 		BARCOS_P[barcos_p_cont].z = z;
 		BARCOS_P[barcos_p_cont].cont = tamanho;
 		BARCOS_P[barcos_p_cont].v = tamanho;
 		barcos_p_cont++;
 		colocaNavioP(x,y,tamanho,z);
 		quantidade--;
 		limparTela();
 		imprimeMatrizP(1);
 		imprimeMatrizP(2);
 	}
 }
/**
 * Transforma char em inteiro
 */
 int valor(char c){
 	int y;	
 	if(c >= 'A' && c <= 'J' ) {
 		y = c - 'A';
 	}else if(c >= 'a' || c <= 'j' ) {
 		y = c - 'a';
 	}else{
 		y = 10;
 	}
 	return y;
 }

/**
 * Aloca aleatoriamente o lugar que o barco estar�
 */
 void sortPosPAleatorio(int quantidade,int tamanho){
 	int x ,y,z,cont,i;
 	i=0;
 	while(quantidade>0){
 		z= rand() %2;
 		cont=0;
 		if(z==0){
 			x = rand() %LIN;
 			y = rand() %(COL-tamanho+1);
 			while(cont<tamanho){		
 				if(matrizP[x][y+cont]!=MAR){
 					cont=0;
 					x = rand() % LIN;
 					y = rand() % (COL-tamanho+1);
 				}else{
 					cont++;
 				}
 			}
 		} else {
 			x = rand() % (LIN-tamanho+1);
 			y = rand() %COL;
 			while(cont<tamanho){
 				if(matrizP[x+cont][y]!=MAR){
 					cont=0;
 					x = rand() % (LIN-tamanho+1);
 					y = rand() % COL;
 				}else{
 					cont++;
 				}
 			}
 		}
 		BARCOS_P[barcos_p_cont].x = x;
 		BARCOS_P[barcos_p_cont].y = y;
 		BARCOS_P[barcos_p_cont].z = z;
 		BARCOS_P[barcos_p_cont].cont = tamanho;
 		BARCOS_P[barcos_p_cont].v = tamanho;
 		barcos_p_cont++;
 		colocaNavioP(x,y,tamanho,z);
 		quantidade--;
 	}
 }
/**
 * Fun��o respons�vel por substituir na matriz a aloca��o do barco(essa fun��o foi usada na anterior).
 */
 void colocaNavioP(int x, int y, int tamanho,int z) {
 	int i;
	//colocando pontos
 	if(z==0){
 		if(x>0){
 			if(y>0 && y<9){
 				for(i=0;i<tamanho+2;i++){
 					matrizP[x-1][y+i-1]=VAZIO;
 				}	
 			}
 			else if(y==0){
 				for(i=0;i<tamanho+1;i++){
 					matrizP[x-1][y+i]=VAZIO;
 				}		
 			}
 			else if(y==9){
 				for(i=0;i<tamanho+1;i++){
 					matrizP[x-1][y+i-1]=VAZIO;
 				}			
 			}
 		}
 		
 		if(y>0 && y<9){
 			for(i=0;i<tamanho+2;i++){
 				matrizP[x][y+i-1]=VAZIO;
 			}	
 		}
 		if(y==0){
 			for(i=0;i<tamanho+1;i++){
 				matrizP[x][y+i]=VAZIO;
 			}		
 		}
 		if(y==9){
 			for(i=0;i<tamanho+1;i++){
 				matrizP[x][y+i-1]=VAZIO;
 			}		
 		}
 		
 		if(x<9){
 			if(y>0 && y<9){
 				for(i=0;i<tamanho+2;i++){
 					matrizP[x+1][y+i-1]=VAZIO;
 				}	
 			}
 			if(y==0){
 				for(i=0;i<tamanho+1;i++){
 					matrizP[x+1][y+i]=VAZIO;
 				}		
 			}
 			if(y==9){
 				for(i=0;i<tamanho+1;i++){
 					matrizP[x+1][y+i-1]=VAZIO;
 				}		
 			}
 		}
 		
 		
	//colocando navio	
 		for(i=0;i<tamanho;i++){
 			matrizP[x][y+i]=NAVIO;
 		}
 		
 	}else{
	//colocando pontos
 		if(y>0){
 			if(x>0 && x<9){
 				for(i=0;i<tamanho+2;i++){
 					matrizP[x-1+i][y-1]=VAZIO;
 				}	
 			}
 			else if(x==0){
 				for(i=0;i<tamanho+1;i++){
 					matrizP[x+i][y-1]=VAZIO;
 				}		
 			}
 			else if(x==9){
 				for(i=0;i<tamanho+1;i++){
 					matrizP[x-1+i][y-1]=VAZIO;
 				}		
 			}
 		}
 		
 		if(x>0 && x<9){
 			for(i=0;i<tamanho+2;i++){
 				matrizP[x+i-1][y]=VAZIO;
 			}	
 		}
 		if(x==0){
 			for(i=0;i<tamanho+1;i++){
 				matrizP[x+i][y]=VAZIO;
 			}		
 		}
 		if(x==9){
 			for(i=0;i<tamanho+1;i++){
 				matrizP[x+i-1][y]=VAZIO;
 			}		
 		}
 		
 		if(y<9){
 			if(x>0 && x<9){
 				for(i=0;i<tamanho+2;i++){
 					matrizP[x+i-1][y+1]=VAZIO;
 				}	
 			}
 			if(x==0){
 				for(i=0;i<tamanho+1;i++){
 					matrizP[x+i][y+1]=VAZIO;
 				}		
 			}
 			if(x==9){
 				for(i=0;i<tamanho+1;i++){
 					matrizP[x+i-1][y+1]=VAZIO;
 				}		
 			}
 		}	
		for(i=0;i<tamanho;i++){			//colocando navio
			matrizP[x+i][y]=NAVIO;
		}
	}
}


