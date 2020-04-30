/*FAETERJ-Rio
  Algoritmos e Linguagens de Programação I - 2016/1
  Professor Leonardo Vianna - Turma Manhã A
  Alunos: FILIPE RODRIGUES CARDOSO DA SILVA e NATHALIE MOREIRA DOS SANTOS CORREA
  Trabalho III - Batalha Naval
*/

#include <stdio.h>
#include <stdlib.h>

//Declaração de #define
#define C 15
#define L 15
#define JOG1 1
#define JOG2 2 
#define TOTAL 23

//Declaração de Prototipo das Funções
void zeramapa(char m[L][C]);
void quatidade(char tipo, int *quant);
void mapa(char m[L][C], int jogador);
int valPos(char m[L][C], char tipo, int orientacao, int posL, int posC, int quant);
void preenche(char m[L][C], int posL, int posC, int quant, char tipo, int orientacao);
void atira(char m[L][C], int posL, int posC, int *acertos, int *erro);
void exibir (char m[L][C]);

int main()
{
	int vez = JOG1, acertos1 = 0, acertos2 = 0, erro = 0, lintiro, coltiro;
	char mapa1[L][C];
	char mapa2[L][C];
	char continua = 's';
	
	do
	{
		system("cls");
		zeramapa(mapa1);
		zeramapa(mapa2);
		mapa(mapa1,JOG1);
		printf ("\n\n");
		system("pause");
		system("cls");
		mapa(mapa2,JOG2);
		printf ("\n\n");
		system("pause");
		system("cls");
		
		while(acertos1 < TOTAL && acertos2 < TOTAL)
		{
			printf("\n\n\tJogador %d informe onde deseja atirar!",vez);
			
			printf("\n\n\tInforme a LINHA onde deseja atirar:");
			scanf("%d",&lintiro);
			do{
				printf("\n\tInforme a COLUNA onde deseja atirar:");
				scanf("%d",&coltiro);
			}while(coltiro>=15);
			if(vez==1){
				atira(mapa2,lintiro,coltiro,&acertos1,&erro);
				if(erro==1){
					vez=2;
				}
			}
			else
			{
				atira(mapa1,lintiro,coltiro,&acertos2,&erro);
				if(erro==1){
					vez=1;
				}
			}
		}
		if(acertos1 == TOTAL)
		{
			printf ("\n\n\t\t#################\n\n");
			printf ("\n\n\t\tJogador 1 venceu!\n\n");
			printf ("\n\n\t\t#################\n\n");
		}
		else
		{
			printf ("\n\n\t\t#################\n\n");
			printf ("\n\n\t\tJogador 2 venceu!\n\n");
			printf ("\n\n\t\t#################\n\n");
		}
		printf ("\n\n");
		system("pause");
		printf("\n\n\tDeseja jogar novamente?\n\t\t[s] ou [n]: ");
		continua = getch();
	}while(continua == 's');
}

//Funções 
void zeramapa(char m[L][C])
{
	int i, j;
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			m[i][j] = 'a';

		}
	}
}

void quatidade(char tipo, int *quant)
{
	switch(tipo) 
	{
		case 'P': 
			*quant = 5;
			break;
		case 'C':
			*quant = 4;
			break;
		case 'T': 
			*quant = 3;
			break;
		case 'R': 
			*quant = 2;
			break;
		case 'S': 
			*quant = 1;
			break;
	}
}


void mapa(char m[L][C], int jogador)
{
	int quant = 0, opcao, linha, coluna, orientacao, valido, pa = 0, c = 0, ct = 0, r = 0, s = 0;
	
	do
	{
		//exibir(m);
		
		printf("\n\tJogador %d Informe qual a embarcacao que deseja inserir: \n\n",jogador);
		printf("\n\t\t[1] - %d Porta-Aviao",1-pa);
		printf("\n\t\t[2] - %d Cruzador",1-c);
		printf("\n\t\t[3] - %d Contra-torpedeiros",2-ct);
		printf("\n\t\t[4] - %d Rebocadores",2-r);
		printf("\n\t\t[5] - %d Submarinos\n\t\t",4-s);	
		scanf("%d",&opcao);
		switch (opcao)
		{
			case 1: 
				if(pa == 1){
					printf("\n### Erro: Embarcacao ja foi inserida! ###\n\n");
				}
				while(pa < 1)
				{
					printf("\n\tInforme em qual linha deseja inserir: ");
					scanf("%d",&linha);
					printf("\n\tInforme em qual coluna deseja inserir: ");
					scanf("%d",&coluna);
					printf("\n\tInforme: \n\t[1] Para por na vertical.\n\t[2] Para por na horizontal.\n\t\t");
					scanf("%d",&orientacao);
					quatidade('P',&quant);
					valido = valPos(m,'P',orientacao, linha, coluna, quant);
					
					if(valido < 0)
					{
						printf("\n### Erro: Posicao invalida! ###\n\n");
					}
					else
					{
						preenche(m, linha, coluna, quant, 'P', orientacao);
						printf("\n\tInserido com sucesso na posicao %d, %d!\n\n",linha,coluna);
						pa++;
					}
				}
				break;
	
			case 2:	
				if(c == 1){
					printf("\n### Erro: Embarcacao ja foi inserida! ###\n\n");
				}
				while (c < 1)
				{
					printf("\n\tInforme em qual linha deseja inserir: ");
					scanf("%d",&linha);
					printf("\n\tInforme em qual coluna deseja inserir: ");
					scanf("%d",&coluna);
					printf("\n\tInforme: \n\t[1] Para por na vertical.\n\t[2] Para por na horizontal.\n\t\t");
					scanf("%d",&orientacao);
					quatidade('C',&quant);
					valido = valPos(m,'C',orientacao, linha, coluna, quant);
					
					if(valido < 0)
					{
						printf("\n### Erro: Posicao invalida! ###\n\n");
					}
					else
					{
						preenche(m, linha, coluna, quant, 'C',orientacao);
						printf("\n\tInserido com sucesso na posicao %d, %d!\n\n",linha,coluna);
						c++;
					}				
				}
				break;
					
			case 3:
				if(ct == 2){
					printf("\n### Erro: Embarcacao ja foi inserida! ###\n\n");
				}
				while (ct < 2)
				{
					printf("\n\tInforme em qual linha deseja inserir o %do: ",ct+1);
					scanf("%d",&linha);
					printf("\n\tInforme em qual coluna deseja inserir o %do: ",ct+1);
					scanf("%d",&coluna);
					printf("\n\tInforme: \n\t[1] Para por na vertical.\n\t[2] Para por na horizontal.\n\t\t");
					scanf("%d",&orientacao);
					quatidade('T',&quant);
					valido = valPos(m,'T',orientacao, linha, coluna, quant);
					
					if(valido < 0)
					{
						printf("\n### Erro: Posicao invalida! ###\n\n");
					}
					else
					{
						preenche(m, linha, coluna, quant,'T',orientacao);
						printf("\n\tInserido com sucesso na posicao %d, %d!\n\n",linha,coluna);
						ct++;
					}				
				}
					
				break;
			case 4:
				if(r == 2){
					printf("\n### Erro: Embarcacao ja foi inserida! ###\n\n");
				}	
				while (r < 2)
				{
					printf("\n\tInforme em qual linha deseja inserir o %do: ",r+1);
					scanf("%d",&linha);
					printf("\n\tInforme em qual coluna deseja inserir o %do: ",r+1);
					scanf("%d",&coluna);
					printf("\n\tInforme: \n\t[1] Para por na vertical.\n\t[2] Para por na horizontal.\n\t\t");
					scanf("%d",&orientacao);
					quatidade('R',&quant);
					valido = valPos(m,'R',orientacao, linha, coluna, quant);
					if(valido < 0)
					{
						printf("\n### Erro: Posicao invalida! ###\n\n");
					}
					else
					{
						preenche(m, linha, coluna, quant, 'R',orientacao);
						printf("\n\tInserido com sucesso na posicao %d, %d!\n\n",linha,coluna);
						r++;
					}				
				}
				
				break;
			case 5:
				if(s == 4){
					printf("\n### Erro: Embarcacao ja foi inserida! ###\n\n");
				}	
				while (s < 4)
				{
					printf("\n\tInforme em qual linha deseja inserir o %do: ",s+1);
					scanf("%d",&linha);
					printf("\n\tInforme em qual coluna deseja inserir o %do: ",s+1);
					scanf("%d",&coluna);
					quatidade('S',&quant);
					valido = valPos(m,'S', 0, linha, coluna, quant);
					if(valido < 0)
					{
						printf("\n### Erro: Posicao invalida! ###\n\n");
					}
					else
					{
						preenche(m, linha, coluna, quant,'S', 0);
						printf("\n\tInserido com sucesso na posicao %d, %d!\n\n",linha,coluna);
						s++;
					}				
				}
				
				break;
				
		}
		printf ("\n\n");
		system("pause");
	}while(pa+c+ct+r+s <= 6);
	printf("\n\t++ Todas as embarcacoes foram inseridas com sucesso! ++\n\n");
}

int valPos(char m[L][C], char tipo, int orientacao, int posL, int posC, int quant)
{
	int i, j, maxL, maxC;

	if(orientacao == 1)
	{
		maxL = posL + quant;
		maxC = posC;
	}
	else
	{
		if(orientacao == 2)
		{
			maxL = posL;
			maxC = posC + quant;	
		}
		else
		{
			maxL = posL;
			maxC = posC;
		}
	}
	if(maxL>=15 || maxC>=15)
	{
		return -1;
	}
	for(i=posL;i<=maxL;i++)
	{
		for(j=posC;j<=maxC;j++)
		{
			if(m[i][j]!='a')
			{
				return -1;
			}
		}
	}
	return 1;
}

void preenche(char m[L][C], int posL, int posC, int quant, char tipo, int orientacao)
{
	int i, j, maxL, maxC;
	
	if(orientacao == 1)
	{
		maxL = posL + quant;
		maxC = posC + 1;
	}
	else
	{
		if(orientacao == 2)
		{
			maxL = posL + 1;
			maxC = posC + quant;	
		}
		else
		{
			maxL = posL + 1;
			maxC = posC + 1;
		}
	}
	for(i=posL;i<maxL;i++)
	{
		for(j=posC;j<maxC;j++)
		{
			m[i][j] = tipo;
		}
	}
}

void exibir (char m[L][C])
{
	
	int i, j;
	for(i=0;i<L;i++)
	{
		printf(" [%d]",i);
	}
	printf("\n\n");
	for(i=0;i<L;i++)
	{
		
		for(j=0;j<C;j++)
		{
			if(j>10)
			{
				printf(" ");
			}
			printf(" [%c]",m[i][j]);
		}
		printf(" [%d]\n",i);
	}
}

void atira(char m[L][C], int posL, int posC, int *acertos, int *erro)
{
	int ac = *acertos;
	*erro = 0;
	
	switch(m[posL][posC])
	{
		case 'a':
			printf("\n\n\t### Voce acertou um tiro na agua! ###\n");
			*erro = 1;
			break;
		case 'I':
			printf("\n\n\t### A posicao informada ja foi acertada! ###\n");
			break;
		case 'P':
			printf("\n\n\t+ Voce acertou o Porta-Aviao! +\n");
			ac = ac + 1;//Mudar para atribuição em variavel
			m[posL][posC] = 'I';
			break;
		case 'C':
			printf("\n\n\t+ Voce acertou o Cruzador! +\n");
			ac = ac + 1;//Mudar para atribuição em variavel			
			m[posL][posC] = 'I';
			break;
		case 'T':
			printf("\n\n\t+ Voce acertou o Contra-torpedeiro! +\n");
			ac = ac + 1;//Mudar para atribuição em variavel	
			m[posL][posC] = 'I';
			break;
		case 'R':
			printf("\n\n\t+ Voce acertou o Rebocador! +\n");
			ac = ac + 1;//Mudar para atribuição em variavel
			m[posL][posC] = 'I';
			break;
		case 'S':
			printf("\n\n\t+ Voce acertou o Submarino! +\n");
			ac = ac + 1;	//Mudar para atribuição em variavel
			m[posL][posC] = 'I';
			break;	
	}
	*acertos = ac;
}
