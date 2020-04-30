#include <stdio.h>
#include <stdlib.h>

//Declaração de #define
#define TAM 20

//Declaração de Prototipo das Funções
void criaS1(char S[], int quant);


int main()
{
	int i;
	char string[TAM];
	
	printf("\n\tInforme a frase: ");
	gets(string);
	
	criaS1(string,TAM);
	
}

//Funções 
void criaS1(char S[], int quant)
{
	int i, j;
	char S1[quant];
	
	for(i=0,j=0;S[i]!='\0';i++)
	{
		if (S[i]==tolower(S[i])&&S[i]!=' ')
		{
			S1[j] = S[i];
			j++;
		}
	}
	for(i=0;S[i]!='\0';i++)
	{
		if (S[i]==toupper(S[i])&&S[i]!=' ')
		{
			S1[j] = S[i];
			j++;
		}
	}
	S1[j] = '\0';
	printf("\n\t%s",S1);
}
