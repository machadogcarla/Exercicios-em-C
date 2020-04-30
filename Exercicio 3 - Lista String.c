#include <stdio.h>
#include <stdlib.h>

//Declaração de #define
#define TAM 10

//Declaração de Prototipo das Funções
void tiraSpace(char S[], int quant);


int main()
{
	int i;
	char string[TAM];
	
	printf("\n\tInforme a frase: ");
	gets(string);
	
	tiraSpace(string,TAM);
	
	printf("\n\t%s...",string);
	
}

//Funções 
void tiraSpace(char S[], int quant)
{
	int i;
	for(i=0;S[i] != '\0';i++);
	i--;
	while(S[i] == ' ')
	{
		S[i] = '\0';
		i--;
	}
}

