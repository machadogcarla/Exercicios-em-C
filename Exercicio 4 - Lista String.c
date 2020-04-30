#include <stdio.h>
#include <stdlib.h>

//Declaração de #define
#define TAM 10

//Declaração de Prototipo das Funções
void buscaLetra(char letra, int num);


int main()
{
	int N;
	char ch;
	
	printf("\n\tInforme a letra: ");
	scanf("%c",&ch);
	printf("\n\tInforme o numero: ");
	scanf("%d",&N);
	
	buscaLetra(ch,N);
	
}

//Funções
void buscaLetra(char letra, int num)
{
	int i;
	char strNomes[num][TAM];
	
	for(i=0;i<num;i++)
	{
		printf("\n\tInforme o nome: ");
		do
		{
			gets(strNomes[i]);
		}while(strNomes[i][0]=='\0');
	}
	for(i=0;i<num;i++)
	{
		if (tolower(strNomes[i][0]) == tolower(letra))
		{
			printf("\n\t%s",strNomes[i]);
		}
	}

}



