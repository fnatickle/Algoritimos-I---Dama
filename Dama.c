#include <stdio.h>
#include <stdlib.h>
#define N 8


//Imprime tabuleiro

void tabuleiro(char **Matriz){
     int i, j;
     printf("  0  1  2  3  4  5  6  7\n");
	 for(i=0;i<N;i++){
	 	printf("%d",i);
     	for(j=0;j<N;j++){
     		printf("[%c]",Matriz[i][j]);
     	}
     	printf("\n");

     }
}

//Aloca espaços de memória para o tabuleiro
char **initialize(){
	char **Matriz;
	int i, j;
	Matriz = (char **)calloc(N, sizeof(char *));
	for(i=0;i<N;i++)
		Matriz[i] = (char *)calloc(N, sizeof(char));

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			Matriz[i][j] = ' ';

    return Matriz;
}

//Função que aloca as peças Pretas e brancas 

void BlackOrWhite(char **Matriz){
	int i, j;
for(i=0; i<3; i++){
	if(i%2==0)
		j=1;
	else
		j=0;
	while(j<N){
		Matriz[i][j]='P';
		j+=2;
		}
	}
for (i=5; i<8; i++){
	if(i%2==1)
		j=0;
	else
		j=1;
	while(j<N){
		Matriz[i][j]='B';
		j+=2;
		}
	}
}
//Verifica se a peça selecionada é valida
int stepshow (char **Matriz, int lin, int col, char gamer){
    if(lin < 0 || lin >= N ||
       col < 0 || col >= N ||
       Matriz[lin][col] != gamer)
        return 0; 
}
//Verifica se o espaço aonde a peça vai ser enviada é valida
int stepshowshow(char **Matriz, int lin, int col, char gamer){
    if(lin < 0 || lin >= N ||
       col < 0 || col >= N ||
       (Matriz[lin][col] == 'B') || (Matriz[lin][col] == 'P'))
        return 0; 
}
int stepshowDama(char **Matriz, int lin, int col, char gamer){
	if(Matriz[lin][col]=='B' || Matriz[lin][col]=='X')
		if(Matriz[lin][col]=='P' || Matriz[lin][col]=='O')
		return 0;
}
// Verifica o status do jogo
int flawesvictory(char **Matriz, char Juego, char JuegoD){
	int i, j;
 for(i=0;i<N;i++)
        if(Matriz[i][0]==Juego || Matriz[i][0]==JuegoD ||
           Matriz[i][1]==Juego || Matriz[i][1]==JuegoD ||
           Matriz[i][2]==Juego || Matriz[i][2]==JuegoD ||
           Matriz[i][3]==Juego || Matriz[i][3]==JuegoD ||
           Matriz[i][4]==Juego || Matriz[i][4]==JuegoD ||
           Matriz[i][5]==Juego || Matriz[i][5]==JuegoD ||
           Matriz[i][6]==Juego || Matriz[i][6]==JuegoD ||
           Matriz[i][7]==Juego || Matriz[i][7]==JuegoD)//Verifica todas as casas do tabuleiro para ver se tem peças
        		return 1;//Jogo continua
}
//Verifica se o ganhador são as peças B ou P(X e O são as peças que virariam dama)
int statusofgame(char **Matriz){
if (flawesvictory(Matriz, 'B', 'X'))
	return -1;//Continua o jogo
else
	return 0;//Pretas ganham

if(flawesvictory(Matriz, 'P', 'O'))
	return -1;//COntinua o jogo
else
    return 1;//Brancas ganham

}
//Move é o destino da peça e select e a peça que eu havia selecionado anteriormente

int movepecaB(char **Matriz, int linselect, int colselect, int linmove, int colmove, char jogador){//move as peças brancas
	if((linmove == (linselect -1)) && 
	  ((colmove == (colselect+1))|| 
	  	colmove ==(colselect-1)))
	  	return 0;
	  	else if((linmove == (linselect -2)) && 
	           ((colmove == (colselect+2))|| 
	  	         colmove ==(colselect-2)))
	  		     return 0;
	}

int movepecaP(char **Matriz, int linselect, int colselect, int linmove, int colmove, char jogador){//move as peças pretas
	if((linmove == (linselect +1)) && 
	  ((colmove == (colselect+1))|| 
	  	colmove ==(colselect-1)))
	  	return 0;
	  else if((linmove == (linselect +2)) && //Come as peças(Na funçao game, o algoritmo verifica se esse movimento é possivel)
	  ((colmove == (colselect+2))|| 
	  	colmove ==(colselect-2)))
	  	return 0;
	}

char transformerdamaB(char **Matriz){//Transforma as peças brancas em X(DAMA)
	
	if(Matriz[0][0] == 'B')
		Matriz[0][0] = 'X';
	else if(Matriz[0][1] == 'B')
		Matriz[0][1] = 'X';
	else if(Matriz[0][2] == 'B')
		Matriz[0][2] = 'X';
	else if(Matriz[0][3] == 'B')
		Matriz[0][3] = 'X';
	else if(Matriz[0][4] == 'B')
		Matriz[0][4] = 'X';
	else if(Matriz[0][5] == 'B')
		Matriz[0][5] = 'X';
	else if(Matriz[0][6] == 'B')
		Matriz[0][6] = 'X';
	else if(Matriz[0][7] == 'B')
		Matriz[0][7] = 'X';
}


char transformerdamaP(char **Matriz){//Transforma as peças pretas em O(DAMA)

	if(Matriz[7][0] == 'P')
		Matriz[7][0] = 'O';
	else if(Matriz[7][1] == 'P')
		Matriz[7][1] = 'O';
	else if(Matriz[7][2] == 'P')
		Matriz[7][2] = 'O';
	else if(Matriz[7][3] == 'P')
		Matriz[7][3] = 'O';
	else if(Matriz[7][4] == 'P')
		Matriz[7][4] = 'O';
	else if(Matriz[7][5] == 'P')
		Matriz[7][5] = 'O';
	else if(Matriz[7][6] == 'P')
		Matriz[7][6] = 'O';
	else if(Matriz[7][7] == 'P')
		Matriz[7][7] = 'O';		
}


int DamaCE(int LinB, int ColB, char **Matriz, int Def1, char Player){//Especifica como a dama deve agir caso ela tenha que se mover na Diagonal CIMA/ESQUERDA
	for(LinB; LinB>=Def1; LinB++)
		for(ColB; ColB>=Def1; ColB++)
	if(Matriz[LinB][ColB]==' ')
		return 0;
	else if(Matriz[LinB][ColB]==Player)
		return 1;
	else
		return 1;
}

int DamaCD(int LinB, int ColB, char **Matriz, int Def1, char Player){////Especifica como a dama deve agir caso ela tenha que se mover na Diagonal CIMA/DIREITA
	for(LinB; LinB>=Def1; LinB++)
		for(ColB; ColB>=Def1; ColB--)
	if(Matriz[LinB][ColB]==' ')
		return 0;
	else if(Matriz[LinB][ColB]==Player)
		return 1;
	else
		return 1;
}

int DamaBE(int LinB, int ColB, char **Matriz, int Def1, char Player){//Especifica como a dama deve agir caso ela tenha que se mover na Diagonal BAIXO/ESQUERDA
	Def1 = Def1 * -1;
	for(LinB; LinB>=Def1; LinB--)
		for(ColB; ColB>=Def1; ColB++)
	if(Matriz[LinB][ColB]==' ')
		return 0;
	else if(Matriz[LinB][ColB]==Player)
		return 1;
	else
		return 1;
}

int DamaBD(int LinB, int ColB, char **Matriz, int Def1, char Player){//Especifica como a dama deve agir caso ela tenha que se mover na Diagonal BAIXO/DIREITA
	Def1 = Def1 * -1;
	for(LinB; LinB>=Def1; LinB--)
		for(ColB; ColB>=Def1; ColB--)
	if(Matriz[LinB][ColB]==' ')
		return 0;
	else if(Matriz[LinB][ColB]==Player)
		return 1;
	else
		return 1;
}

int damaisthelaw(char **Matriz, int linhaA, int linhaB, int colunaA, int colunaB, char Player){//Chama as funções da Dama de acordo com as situações linA-liB || colA-ColB
	int Def1, Def2;
	Def1 = linhaA - linhaB;
	Def2 = colunaA - colunaB;
	if(Def1>0 && Def2>0)
		DamaCE(linhaB, colunaB, Matriz, Def1, Player);
	else if((Def1>0 && Def2<0) && (Def1==(Def2*(-1))))
		DamaCD(linhaB, colunaB, Matriz, Def1, Player);
	else if((Def1<0 && Def2>0) && (Def2==(Def1*(-1))))
		DamaBE(linhaB, colunaB, Matriz, Def1, Player);
	else if((Def1<0 && Def2<0) && (Def1==(Def2*(-1))))
		DamaBD(linhaB, colunaB, Matriz, Def1, Player);		
}



//Executar todas as funções do programa
void game(){
	printf("Bem vindo a dama!\nAs brancas começam, dê as coordenadas:\n");
	printf("Importante: Primeiro indicar o número da linha e depois o número da coluna\n");
	char **Matriz;
	char Player = 'B';
	int Jogook = -1;
	Matriz = initialize();
	BlackOrWhite(Matriz);
	int linhaA, colunaA, linhaB, colunaB, j;
	
	while(Jogook==-1){
		tabuleiro(Matriz);
		printf("Caro jogador [%c], digite a linha e coluna para selecionar a peça que deseja movimentar:", Player);
		scanf("%d",&linhaA);
		scanf("%d",&colunaA);
		//SE a jogada não for possivel
		if( !stepshow(Matriz, linhaA, colunaA, Player) ){
			printf("\nJogada invalida!\n");
		    continue;

	}
	    printf("\nDigite a linha e a coluna na qual você deseja colocar a peça %c:\n", Player);
	    scanf("%d",&linhaB);
		scanf("%d",&colunaB);

		if( !stepshowshow(Matriz, linhaB, colunaB, Player)){//Verifica se a jogada é valida
			printf("\nJogada invalida!\n");
			continue;
		}
		if((Player == 'B') && movepecaB(Matriz, linhaA, colunaA, linhaB, colunaB, Player)){//Movimenta Pça B
				printf("\nJogada invalida!\n");
				continue;
			}else if((Player == 'P') && movepecaP(Matriz, linhaA, colunaA, linhaB, colunaB, Player)){//Movimenta Pça P
				printf("\nJogada invalida!\n");
				continue;
			}
			transformerdamaP(Matriz);//Caso a peça tenha que vira dama, esta função transforma
			transformerdamaB(Matriz);//Caso a peça tenha que vira dama, esta função transforma		
			stepshowDama(Matriz, linhaA, colunaA, Player);

		    Matriz[linhaB][colunaB] = Player;//Esses algoritmos esvaziam as casas anteriores que antes estavam ocupadas, além de fazer as peças adversárias serem comidas
	        Matriz[linhaA][colunaA] = ' ';
	        if(Matriz[linhaB+1][colunaB-1] == 'P') 
	        	Matriz[linhaB +1][colunaB-1] = ' ';
	        	else if(Matriz[linhaB+1][colunaB+1] == 'P')
	        		Matriz[linhaB+1][linhaB+1] = ' ';
	        	else if(Matriz[linhaB-1][colunaB-1] == 'B') 
	        	Matriz[linhaB -1][colunaB-1] = ' ';
	            else if(Matriz[linhaB-1][colunaB+1] == 'B') 
	        	Matriz[linhaB -1][colunaB+1] = ' ';		

		Jogook = statusofgame(Matriz);//Verifica o status do GAme

		if( Player == 'B')//Alterna jogador
            Player = 'P';
        else
            Player = 'B';
    }
	 
	if(Jogook = 0)
		printf("\nPretas Wins!\n");//DEfine o vencedor
	if(Jogook = 1)
		printf("\nBrancas Wins!\n");

}
void main(){
	game();
}

