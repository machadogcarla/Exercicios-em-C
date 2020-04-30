/*FAETERJ-Rio
  Algoritmos e Linguagens de Programa��o I - 2016/1
  Professor Leonardo Vianna - Turma A
  Aluno: Filipe Rodrigues Cardoso da Silva
  Trabalho II - Vetores e Fun��es
*/

//Importa��o de bibliotecas
#include <stdio.h>

//Declara��o de constantes
#define CAP 100  //podem alterar quando necess�rio para poderem proceder com os testes
#define TRUE 1	 //representa o valor l�gico verdadeiro, retornado quando algumas opera��es conseguirem ser executadas
#define FALSE 0  //representa o valor l�gico falso, retornado quando algumas opera��es n�o conseguirem ser executadas

//Declara��o dos prt�tipos das fun��es
int menu();
void inicializarVetor (int v[], int capacidade);
int inserir (int v[], int capacidade, int valor);
int remover (int v[], int capacidade, int valor);
int alterar (int v[], int capacidade, int velho, int novo);
int buscar (int v[], int capacidade, int posInicial, int valor);
int buscarPosicao (int v[], int capacidade, int pos, int *valor);
int trocar (int v[], int capacidade, int pos1, int pos2);
void inverter (int v[], int capacidade);
void exibirSubvetor (int v[], int capacidade, int quantidade, int pos);
void exibir (int v[], int capacidade);
int quantidade (int v[], int capacidade);

//Implementa��o da main
int main ()
{
	//Declara��o de vari�veis
	int v[CAP+1];			//o vetor que armazenar� os elementos
							//A �ltima posi��o dever� guardar a quantidade de elementos do vetor. Logo, o programa n�o pode armazenar outros valores nessa posi��o!
	int numero1, numero2; 	//numeros fornecidos pelo usu�rio
	int pos1, pos2;			//armazenar�o posi��es dos vetores
	int erro;				//armazena se houve erro no retorno da fun��o buscaPosicao
	int quant;				//guardar� a quantidade de elementos para a fun��o subvetor
	int opcao;				//opcao do menu escolhida pelo usu�rio
	
	//comandos da main			
	inicializarVetor (v, CAP);

	do
	{
		opcao = menu();
		
		switch (opcao)
		{
			//inser��o
			case 1: printf ("Entre com o elemento a ser inserido: ");
					scanf ("%d", &numero1);
					
					if (inserir (v, CAP, numero1) == TRUE)
					{
						printf ("Inser��o realizada com sucesso!\n");
					}
					else
					{
						printf ("Erro: inser��o n�o realizada!\n");
					}
					
					break;
					
			//remo��o
			case 2: printf ("Entre com o elemento a ser removido: ");
					scanf ("%d", &numero1);
					
					if (remover (v, CAP, numero1) == TRUE)
					{
						printf ("Remo��o realizada com sucesso!\n");
					}
					else
					{
						printf ("Erro: remo��o n�o realizada!\n");
					}
					
					break;
					
			//altera��o
			case 3: printf ("Entre com o elemento a ser alterado: ");
					scanf ("%d", &numero1);
					
					printf ("Entre com o novo elemento: ");
					scanf ("%d", &numero2);
					
					if (alterar (v, CAP, numero1, numero2) == TRUE)
					{
						printf ("Altera��o realizada com sucesso!\n");
					}
					else
					{
						printf ("Erro: altera��o n�o realizada!\n");
					}
					
					break;
					
			//busca por valor
			case 4: printf ("Entre com o elemento a ser buscado: ");
					scanf ("%d", &numero1);										
					
					pos1 = buscar (v, CAP, 0, numero1);
					
					if (pos1 >= 0)
					{
						printf ("O elemento %d foi encontrado na posi��o %d!\n", numero1, pos1);
					}
					else
					{
						printf ("Erro: elemento n�o encontra-se no vetor!\n");
					}
					
					break;
					
			//busca por posicao
			case 5: printf ("Entre com a posi��o a ser consultada: ");
					scanf ("%d", &pos1);										
					
					erro = buscarPosicao (v, CAP, pos1, &numero1);
					
					if (erro == FALSE)
					{
						printf ("Na posi��o %d foi encontrado o elemento %d!\n", pos1, numero1);
					}
					else
					{
						printf ("Erro: posi��o inv�lida!\n");
					}
					
					break;
			
			//troca de posi��es
			case 6: printf ("Entre com a primeira posi��o: ");
					scanf ("%d", &pos1);
					
					printf ("Entre com a segunda posi��o: ");
					scanf ("%d", &pos2);										
					
					if (trocar (v, CAP, pos1, pos2) == TRUE)
					{
						printf ("Elementos trocados com sucesso!\n");
					}
					else
					{
						printf ("Erro: troca n�o realizada!\n");
					}
					
					break;
					
			//inverter vetor
			case 7: inverter (v, CAP);
					printf ("Invers�o realizada com sucesso!\n");
					exibir (v,CAP);					
					
					break;
					
			//exibir subvetor
			case 8: printf ("Entre com a posi��o inicial do subvetor: ");
					scanf ("%d", &pos1);
					
					printf ("Entre com a quantidade de elementos do subvetor: ");
					scanf ("%d", &quant);
					
					exibirSubvetor (v, CAP, quant, pos1);
					
					break;
					
			//exibir vetor
			case 9: exibir (v, CAP);
					break;
					
			//Quantidade de elementos no vetor
			case 10:printf ("H� %d elementos no vetor!\n", quantidade (v, CAP));
					break;
				
			//Sa�da	
			case 0: printf ("Fim do programa!\n");
		}		
	}
	while (opcao != 0);  //a repeti��o s� terminar� quando o usu�rio escolher a op��o 0 do menu, que representa a sa�da da aplica��o	
}

//Implementa��o das fun��es

//Mostra um menu de op��es ao usu�rio e � retornada a op��o selecionada
int menu()
{
	int opcao;
	int erro;
	
	do
	{
		printf ("-----Menu de Op��es-----\n\n");
		printf ("1) Inserir\n2) Remover\n3) Alterar\n4) Buscar por valor\n");
		printf ("5) Buscar por posicao\n6) Trocar\n7) Inverter vetor\n8) Exibir subvetor\n");
		printf ("9) Exibir vetor\n10) Quantidade\n0) Sair\n\n");
		
		printf ("Op��o: ");
		scanf ("%d", &opcao);
		
		if ((opcao < 0) || (opcao > 10))
		{
			erro = TRUE;
			
			printf ("\nErro: op��o inv�lida! Tente novamente!\n\n");
		}
		else
		{
			erro = FALSE;
		}
	} while (erro == TRUE);
}

//Inicializa o vetor, armazenando na �ltima posi��o a quantidade de elementos no vetor 
void inicializarVetor (int v[], int capacidade)
{
	v[capacidade] = 0;   		   //inicialmente o vetor est� vazio
}

//Caso exista espa�o dispon�vel, insere 'valor' no vetor 'v'
//A fun��o retorna TRUE ou FALSE dependendo se conseguiu ou n�o realizar a inser��o
int inserir (int v[], int capacidade, int valor)
{
	if (v[capacidade]>=capacidade)
	{
		return FALSE;
	}
	v[(v[capacidade])] = valor;
	v[capacidade]++;
	return TRUE;
}

//Caso 'valor' exista no vetor, s�o removidas todas as suas ocorr�ncias. 
//A fun��o retorna TRUE ou FALSE dependendo se conseguiu ou n�o realizar a remo��o
int remover (int v[], int capacidade, int valor)
{
	int i = 0, resp = FALSE;
	while(i<v[capacidade])
	{
		if(v[i] == valor)
		{
			v[i] = v[(v[capacidade] - 1)];
			v[capacidade] = v[capacidade] - 1;
			resp = TRUE;
		}
		else
		{
			i++;
		}
	}
	return resp;
}

//Caso 'velho' exista no vetor, todas as suas ocorr�ncias s�o alteradas por 'novo'. 
//A fun��o retorna TRUE ou FALSE dependendo se conseguiu ou n�o realizar a altera��o
int alterar (int v[], int capacidade, int velho, int novo)
{
	int i, resp = FALSE;
	for(i=0;i<v[capacidade];i++)
	{
		if(v[i] == velho)
		{
			v[i] = novo;
			resp = TRUE;
		}
	}
	return resp;
}

//busca 'valor' no vetor a partir da posicao 'posInicial'. Caso seja encontrado, � retornada
//a posi��o de sua primeira ocorr�ncia. Caso contr�rio, � retornado -1
int buscar (int v[], int capacidade, int posInicial, int valor)
{
	int i;
	for(i=posInicial;i<=capacidade && valor!=v[i];i++);
	if (i==capacidade)
	{
		return -1;
	}
	return i;
}

//dada uma posi��o 'pos', � retornado em 'valor' o elemento que encontra-se nesta posi��o.
//A fun��o retorna TRUE ou FALSE, dependendo se 'pos' � ou n�o uma posi��o v�lida 
int buscarPosicao (int v[], int capacidade, int pos, int *valor)
{
	if (pos>=(v[capacidade])||pos<0)
	{
		return TRUE;
	}
	*valor = v[pos];
	return FALSE;
	
}

//caso poss�vel, troca os conte�dos das duas posi��es do vetor definidas como par�metros.
//retorna TRUE ou FALSE informando se a opera��o foi ou n�o realizada
int trocar (int v[], int capacidade, int pos1, int pos2)
{
	int aux;
	if ((pos1>=v[capacidade] || pos1<0)||(pos2>=v[capacidade] || pos2<0))
	{
		return FALSE;
	}
	aux = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = aux;
	return TRUE;
}

//inverte os elementos do vetor
void inverter (int v[], int capacidade)
{
	int i, j, aux;
	for(i=0,j=(v[capacidade]);i<j;i++,j--)
	{
		aux = v[j-1];
		v[j-1] = v[i];
		v[i] = aux;
	}
}

//exibe o subvetor de 'v', iniciado na posicao 'pos' e que contenha 'quantidade' elementos
//Caso pos ultrapasse os limites do vetor, uma mensagem deve ser apresentada ao usu�rio
//informando que n�o h� elementos a exibir. Caso n�o existam 'quantidade' elementos a partir
//de 'pos', devem ser exibidos todos os elementos de 'v' da posi��o 'pos' at� o final do vetor. 
void exibirSubvetor (int v[], int capacidade, int quantidade, int pos)
{
	int i, limite;
	
	limite = pos+quantidade;
	
	printf("\n");
	if(pos>=v[capacidade] || pos<0)
	{
		printf("N�o existem elementos no subvetor!\n\n");
	}
	else
	{
		if(limite>v[capacidade])
		{
			limite = v[capacidade];
		}
		for(i=pos;i<limite;i++)
		{
			printf("[%d] ",v[i]);
		}
		printf("\n");
	}	
}

//Exibe todos os elementos do vetor
void exibir (int v[], int capacidade)
{
	int i;
	printf("\n");
	for (i=0;i<v[capacidade];i++)
	{
		printf("[%d] ",v[i]);
	}
	printf("\n");
}

//Retorna a quantidade de elementos no vetor
int quantidade (int v[], int capacidade)
{
	return v[capacidade];
}
