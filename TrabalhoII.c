/*FAETERJ-Rio
  Algoritmos e Linguagens de Programação I - 2016/1
  Professor Leonardo Vianna - Turma A
  Aluno: Filipe Rodrigues Cardoso da Silva
  Trabalho II - Vetores e Funções
*/

//Importação de bibliotecas
#include <stdio.h>

//Declaração de constantes
#define CAP 100  //podem alterar quando necessário para poderem proceder com os testes
#define TRUE 1	 //representa o valor lógico verdadeiro, retornado quando algumas operações conseguirem ser executadas
#define FALSE 0  //representa o valor lógico falso, retornado quando algumas operações não conseguirem ser executadas

//Declaração dos prtótipos das funções
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

//Implementação da main
int main ()
{
	//Declaração de variáveis
	int v[CAP+1];			//o vetor que armazenará os elementos
							//A última posição deverá guardar a quantidade de elementos do vetor. Logo, o programa não pode armazenar outros valores nessa posição!
	int numero1, numero2; 	//numeros fornecidos pelo usuário
	int pos1, pos2;			//armazenarão posições dos vetores
	int erro;				//armazena se houve erro no retorno da função buscaPosicao
	int quant;				//guardará a quantidade de elementos para a função subvetor
	int opcao;				//opcao do menu escolhida pelo usuário
	
	//comandos da main			
	inicializarVetor (v, CAP);

	do
	{
		opcao = menu();
		
		switch (opcao)
		{
			//inserção
			case 1: printf ("Entre com o elemento a ser inserido: ");
					scanf ("%d", &numero1);
					
					if (inserir (v, CAP, numero1) == TRUE)
					{
						printf ("Inserção realizada com sucesso!\n");
					}
					else
					{
						printf ("Erro: inserção não realizada!\n");
					}
					
					break;
					
			//remoção
			case 2: printf ("Entre com o elemento a ser removido: ");
					scanf ("%d", &numero1);
					
					if (remover (v, CAP, numero1) == TRUE)
					{
						printf ("Remoção realizada com sucesso!\n");
					}
					else
					{
						printf ("Erro: remoção não realizada!\n");
					}
					
					break;
					
			//alteração
			case 3: printf ("Entre com o elemento a ser alterado: ");
					scanf ("%d", &numero1);
					
					printf ("Entre com o novo elemento: ");
					scanf ("%d", &numero2);
					
					if (alterar (v, CAP, numero1, numero2) == TRUE)
					{
						printf ("Alteração realizada com sucesso!\n");
					}
					else
					{
						printf ("Erro: alteração não realizada!\n");
					}
					
					break;
					
			//busca por valor
			case 4: printf ("Entre com o elemento a ser buscado: ");
					scanf ("%d", &numero1);										
					
					pos1 = buscar (v, CAP, 0, numero1);
					
					if (pos1 >= 0)
					{
						printf ("O elemento %d foi encontrado na posição %d!\n", numero1, pos1);
					}
					else
					{
						printf ("Erro: elemento não encontra-se no vetor!\n");
					}
					
					break;
					
			//busca por posicao
			case 5: printf ("Entre com a posição a ser consultada: ");
					scanf ("%d", &pos1);										
					
					erro = buscarPosicao (v, CAP, pos1, &numero1);
					
					if (erro == FALSE)
					{
						printf ("Na posição %d foi encontrado o elemento %d!\n", pos1, numero1);
					}
					else
					{
						printf ("Erro: posição inválida!\n");
					}
					
					break;
			
			//troca de posições
			case 6: printf ("Entre com a primeira posição: ");
					scanf ("%d", &pos1);
					
					printf ("Entre com a segunda posição: ");
					scanf ("%d", &pos2);										
					
					if (trocar (v, CAP, pos1, pos2) == TRUE)
					{
						printf ("Elementos trocados com sucesso!\n");
					}
					else
					{
						printf ("Erro: troca não realizada!\n");
					}
					
					break;
					
			//inverter vetor
			case 7: inverter (v, CAP);
					printf ("Inversão realizada com sucesso!\n");
					exibir (v,CAP);					
					
					break;
					
			//exibir subvetor
			case 8: printf ("Entre com a posição inicial do subvetor: ");
					scanf ("%d", &pos1);
					
					printf ("Entre com a quantidade de elementos do subvetor: ");
					scanf ("%d", &quant);
					
					exibirSubvetor (v, CAP, quant, pos1);
					
					break;
					
			//exibir vetor
			case 9: exibir (v, CAP);
					break;
					
			//Quantidade de elementos no vetor
			case 10:printf ("Há %d elementos no vetor!\n", quantidade (v, CAP));
					break;
				
			//Saída	
			case 0: printf ("Fim do programa!\n");
		}		
	}
	while (opcao != 0);  //a repetição só terminará quando o usuário escolher a opção 0 do menu, que representa a saída da aplicação	
}

//Implementação das funções

//Mostra um menu de opções ao usuário e é retornada a opção selecionada
int menu()
{
	int opcao;
	int erro;
	
	do
	{
		printf ("-----Menu de Opções-----\n\n");
		printf ("1) Inserir\n2) Remover\n3) Alterar\n4) Buscar por valor\n");
		printf ("5) Buscar por posicao\n6) Trocar\n7) Inverter vetor\n8) Exibir subvetor\n");
		printf ("9) Exibir vetor\n10) Quantidade\n0) Sair\n\n");
		
		printf ("Opção: ");
		scanf ("%d", &opcao);
		
		if ((opcao < 0) || (opcao > 10))
		{
			erro = TRUE;
			
			printf ("\nErro: opção inválida! Tente novamente!\n\n");
		}
		else
		{
			erro = FALSE;
		}
	} while (erro == TRUE);
}

//Inicializa o vetor, armazenando na última posição a quantidade de elementos no vetor 
void inicializarVetor (int v[], int capacidade)
{
	v[capacidade] = 0;   		   //inicialmente o vetor está vazio
}

//Caso exista espaço disponível, insere 'valor' no vetor 'v'
//A função retorna TRUE ou FALSE dependendo se conseguiu ou não realizar a inserção
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

//Caso 'valor' exista no vetor, são removidas todas as suas ocorrências. 
//A função retorna TRUE ou FALSE dependendo se conseguiu ou não realizar a remoção
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

//Caso 'velho' exista no vetor, todas as suas ocorrências são alteradas por 'novo'. 
//A função retorna TRUE ou FALSE dependendo se conseguiu ou não realizar a alteração
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

//busca 'valor' no vetor a partir da posicao 'posInicial'. Caso seja encontrado, é retornada
//a posição de sua primeira ocorrência. Caso contrário, é retornado -1
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

//dada uma posição 'pos', é retornado em 'valor' o elemento que encontra-se nesta posição.
//A função retorna TRUE ou FALSE, dependendo se 'pos' é ou não uma posição válida 
int buscarPosicao (int v[], int capacidade, int pos, int *valor)
{
	if (pos>=(v[capacidade])||pos<0)
	{
		return TRUE;
	}
	*valor = v[pos];
	return FALSE;
	
}

//caso possível, troca os conteúdos das duas posições do vetor definidas como parâmetros.
//retorna TRUE ou FALSE informando se a operação foi ou não realizada
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
//Caso pos ultrapasse os limites do vetor, uma mensagem deve ser apresentada ao usuário
//informando que não há elementos a exibir. Caso não existam 'quantidade' elementos a partir
//de 'pos', devem ser exibidos todos os elementos de 'v' da posição 'pos' até o final do vetor. 
void exibirSubvetor (int v[], int capacidade, int quantidade, int pos)
{
	int i, limite;
	
	limite = pos+quantidade;
	
	printf("\n");
	if(pos>=v[capacidade] || pos<0)
	{
		printf("Não existem elementos no subvetor!\n\n");
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
