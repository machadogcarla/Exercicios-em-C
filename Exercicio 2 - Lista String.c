#include <stdio.h>
#include <stdlib.h>

//Declara��o de #define
#define TAM 20
//Declara��o de Prototipo das Fun��es
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

//Fun��es 
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
