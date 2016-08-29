#include "play1.h"
#include "ia.h"
#include "jogar.h"



/**
 * Inicia o vetor que evita repetiï¿½ï¿½es de tiros da IA
 */
void iniciavetor(){
	int i;
	for(i=0;i<100;i++){
		vetor[i]=i;
	}
}
/**
 * Funï¿½ï¿½o que dinamisa as rodadas.\n
 * a cada rodada ï¿½ somado 1 ï¿½ variï¿½vel V que ï¿½ responsï¿½vel por determinar quem vai jogar baseado no resto de divisï¿½o por 2.
 */
void rodadas(){
	int v=1;
	int x,opc = 1;
	
	while(pontos_geral[0]<20 && pontos_geral[1]<20){
		system("cls");
		imprimeMatrizIa(2);
		imprimeMatrizP(2);
		if(v%2 == 0){
			x = atiraIa();
			if(x==1){
				pontos_geral[0]++;
			}else
				v=1;
		}else{
			do{
				if(opc<1 || opc>3){
					system("cls");
					printf("opcao errada, tente novamente\n");
				}
				printf("1- Atirar\n"
		        		"2- Salvar\n"
						"3- Menu\n");
				scanf("\n%i",&opc);			
			}while(opc<1 || opc>3);
			system("cls");
			if(opc==1){
				imprimeMatrizIa(2);
				imprimeMatrizP(2);
				printf("Vez do Player\n");
				x = atiraP();
				if(x==1){
					pontos_geral[1]++;
				}else{
					printf("\n- ERRO DESGRACADO! -\n");
					v=2;
				}
			}else if(opc==2){
				salvar();
				break;
			}else{
				break;
		}		
			system("pause");
		}
	}
	system("cls");
	if(pontos_geral[0]==20){
		printf("\n#========================#\n"
			     "#  LOSER LOSER LOSER     #\n"
			     "#   LOSER LOSER LOSER    #\n"
		         "#      HAHA OTARIO       #\n"
			     "#========================#\n");
	}else if(pontos_geral[1]==20){
		printf("\n#========================#\n"
			     "#                        #\n"
			     "#       Voce ganhou      #\n"
		         "#   Obrigado por jogar   #\n"
		         "#                        #\n"
			     "#========================#\n");
	}
	system("pause");
}

/**
 * funï¿½ï¿½o uzada para testar se o barco foi destuido ou acertado.
 */
int verificaUm(int x, int y, barco *p){	
	int acertou = 0;
	int i = p->x, j = p->y;
	while(1){
		if(p->v == 0) break;
		if( x == i && y == j ){
			acertou = 1;
			p->v--;
			if(p->v == 0){ 
				printf("\n*******************\n"
					   "# NAVIO DESTRUIDO #\n"
					   "*******************\n");
			}else{
				printf("\n* VOCE ACERTOU!!! *\n");
				break;
			}
		}
		
		if(p->z == 0){
			j++;
			if(j == p->y+p->cont) break;
		}else{
			i++;
			if(i == p->x+p->cont) break;
		}
	}
	return acertou;
}
int testaTodoMundo(int x, int y, barco * c){
	int acertou = 0;
	int i = 0;
	for(; i < 10 && !acertou; i++){
		acertou = verificaUm(x, y, &c[i]);
	}
	return acertou;
}
/**
 * Imprime o menu e pede ao player a opï¿½ï¿½o desejada.
 */
void menu(){
	int x;
	x=1;
	while(1){
	do{
		system("cls");
		if(x<1 || x>3)
		printf("Opcao errada, tente novamente!\n");
		printf(" ----------BATALHA NAVAL------------\n"
		       "|               Menu                |\n"
			   "| 1- Novo jogo                      |\n"
			   "| 2- Continuar                      |\n"
			   "| 3- Sair                           |\n"
			   " -----------------------------------\n");
		printf("Escolha a opcao: ");
		scanf("\n%i",&x);
	  }while(x <1 || x>3);
		switch(x){
			case 1:
				tam_vetor= 100;
				pontos_geral[0]=0;
				pontos_geral[1]=0;
				iniciaMatrizP();
				iniciaMatrizIa();
				enviaTamanhoIa();
				iniciavetor();
				do{
					system("cls");
					if(x<1 || x>2)
						printf("Opcao errada, tente novamente!\n");
						printf("1- Sorteia navios aleatoriamente\n"
					       		"2- Posicionar navios manualmente\n");
						scanf("\n%i",&x);
				}while(x<1 || x>2);
				if(x==1){
					enviaTamanhoPAleatorio();
				}else{
					enviaTamanhoP();
				}
				rodadas();
			break;
			case 2:
				carregar();
				rodadas();
			break;
			case 3:
				exit(0);
			break;		
		}
	}
}
/**
 * Funï¿½ï¿½o responsï¿½vel por salvar os dados da partida dentro de um arquivo que pode ser lido posteriormente.
 */
void salvar(){
	int i,j;
	FILE *arq;
	arq = fopen("dados.txt","w");
	printf("Salvando...");
	sleep(3);
	printf("\t[OK]\n");
	sleep(1);	
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			fprintf(arq,"%i ",matrizIa[i][j]);
		}
		fprintf(arq,"\n");
	}
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			fprintf(arq,"%i ",matrizIaTiros[i][j]);
		}
		fprintf(arq,"\n");
	}
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			fprintf(arq,"%i ",matrizP[i][j]);
		}
		fprintf(arq,"\n");
	}
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			fprintf(arq,"%i ",matrizPTiros[i][j]);
		}
		fprintf(arq,"\n");
	}
	for(i=0;i<2;i++){
		fprintf(arq,"%i ",pontos_geral[i]);
	}
	fprintf(arq,"\n");
	for(i=0;i<LIN_IA;i++){
		fprintf(arq,"%i %i %i %i %i\n",BARCOS_IA[i].x,BARCOS_IA[i].y,BARCOS_IA[i].z,BARCOS_IA[i].cont,BARCOS_IA[i].v);
	}
	for(i=0;i<LIN_IA;i++){
		fprintf(arq,"%i %i %i %i %i\n",BARCOS_P[i].x,BARCOS_P[i].y,BARCOS_P[i].z,BARCOS_P[i].cont,BARCOS_P[i].v);
	}
	fprintf(arq,"%i\n",tam_vetor);
	for(i=0;i<tam_vetor;i++){
		fprintf(arq,"%i ",vetor[i]);
	}
	
	fclose(arq);
	
}
/**
 * Carrega um jogo anteriormente salvo.
 */
void carregar(){
	int i,j;
	FILE *arq;
	arq = fopen("dados.txt","r");
	printf("Carregando.....");
	sleep(3);
	printf("\t[OK]\n");
	sleep(1);
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			fscanf(arq,"%i ",&matrizIa[i][j]);
		}
	}
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			fscanf(arq,"%i ",&matrizIaTiros[i][j]);
		}
	}
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			fscanf(arq,"%i ",&matrizP[i][j]);
		}
	}
	for(i=0;i<LIN_IA;i++){
		for(j=0;j<COL_IA;j++){
			fscanf(arq,"%i ",&matrizPTiros[i][j]);
		}
	}
	for(i=0;i<2;i++){
		fscanf(arq,"%i ",&pontos_geral[i]);
	}
	for(i=0;i<LIN_IA;i++){
		fscanf(arq,"%i %i %i %i %i",&BARCOS_IA[i].x,&BARCOS_IA[i].y,&BARCOS_IA[i].z,&BARCOS_IA[i].cont,&BARCOS_IA[i].v);
	}
	for(i=0;i<LIN_IA;i++){
		fscanf(arq,"%i %i %i %i %i",&BARCOS_P[i].x,&BARCOS_P[i].y,&BARCOS_P[i].z,&BARCOS_P[i].cont,&BARCOS_P[i].v);
	}
	fscanf(arq,"%i",&tam_vetor);
	for(i=0;i<tam_vetor;i++){
		fscanf(arq,"%i ",&vetor[i]);
	}
	fclose(arq);
}
/**
*Essa função determina em tempo de compilação se o sistema é windows ou linux e define qual operação deve executar para limpar a tela do usuário.
*/
void limparTela(){
#ifdef _WIN32
system("cls");	
#else
system("clear");
#endif
}
