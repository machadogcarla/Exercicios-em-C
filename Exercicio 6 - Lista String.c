#include <stdio.h>
#include <stdlib.h>

//Declaração de #define
#define TAM 32

//Declaração de Prototipo das Funções
void criptografa(char S[], int quant);


int main()
{
	int i;
	char string[TAM];
	
	printf("\n\tInforme a frase: ");
	gets(string);
	
	criptografa(string,TAM);	
}

//Funções 
void criptografa(char S[], int quant)
{
	int i;

	for(i=0;S[i] != '\0';i++)
	{
		if(S[i]=='z'||S[i]=='Z')
		{
			S[i] -= 25;
			//S[i] = 'a';
		}
		else
		{
			S[i] += 1;
		}

	}
	printf("\n\t%s",S);
}

