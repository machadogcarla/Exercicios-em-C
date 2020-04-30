#include <stdio.h>
#include <stdlib.h>

//Declaração de #define
#define TAM 20

//Declaração de Prototipo das Funções
int ocorrenciasCh(char S[], char letra);

int main()
{
	
	char S[TAM];
	char ch;
	
	printf("\n\tInforme a frase: ");
	gets(S);
	printf("\n\tInforme a letra: ");
	scanf("%c",&ch);
	printf("\n\n\t%d ocorrencias foram encontradas com a letra '%c' na frase.\n",ocorrenciasCh(S,ch),ch);
	
}

//Funções 
int ocorrenciasCh(char S[], char letra)
{
	int i = 0, cont = 0;
	while(S[i]!='\0')
	{
		if(tolower(S[i])==tolower(letra))
		{
			cont++;
		}
		i++;
	}
	return cont;
}

