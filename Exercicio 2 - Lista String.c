#include <stdio.h>
#include <stdlib.h>

//Declaração de #define
#define TAM 20
//Declaração de Prototipo das Funções
void inverte(char S[]);

int main()
{
	char S[TAM];
		
	printf("\n\tInforme a frase: ");
	gets(S);
	inverte(S);
	printf("\n\t");
	puts(S);
}

//Funções 
void inverte(char S[])
{
	int i, j, total;
	char aux;
	for(i=0,j=1;S[j]!='\0'&&S[i]!='\0';i+=2,j+=2)
	{
		aux = S[i];
		S[i] = S[j];
		S[j] = aux;
	}
}
