#include <stdio.h>
#define linha 4
#define coluna 4
void preencher(float M[linha][coluna]);
void exibir(float M[linha][coluna]);
void inverterColunas(float M[linha][coluna]);
void inverterLinhas(float M[linha][coluna]);

int main ()
{
float matriz[linha][coluna];

preencher(matriz);		
exibir(matriz);
inverterColunas(matriz);
inverterLinhas(matriz);
exibir(matriz);

}
void preencher(float M[linha][coluna])
{
	int i,j,k=0;
	for(i=0;i<linha;i++)
	{
		for(j=0;j<coluna;j++)
		{
			k++;
			M[i][j]=k;
		}
	}
}


void exibir(float M[linha][coluna])
{
	int i,j;
	for(i=0;i<linha;i++)
	{
		for(j=0;j<coluna;j++)
		{
			printf("%.1f\t ",M[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void inverterColunas(float M[linha][coluna])
{

	int i,j,aux;
	
	for(j=0;j<coluna;j++)
	{
		
		for(i=0;i<linha/2;i++)
		{
		aux=M[i][j];
		M[i][j]=M[linha-i-1][j];
		M[linha-i-1][j]=aux;
		}
	}
	
}
void inverterLinhas(float M[linha][coluna])
{

	int i,j,aux;
	
	for(i=0;i<linha;i++)
	{
		
		for(j=0;j<linha/2;j++)
		{
		aux=M[i][j];
		M[i][j]=M[i][coluna-j-1];
		M[i][coluna-j-1]=aux;
		}
	}
	
}

/*
void invertecoluna(int m[Q][Y])
		{
	
		int i,j;
		int aux;

		for (i=0; i < Q ; i++)
		{
			for(j=0; j < Y/2 ; j++)
			{
				aux = m[i][j];
				m[i][j] = m[i][Y - 1 - j];
				m[i][Y - 1 - j] = aux;
			}
		}
		
		
		}

		void invertelinha (int m[Q][Y])
		{
			int i, j;
			int aux[Y];
			
			for (i=0; i < Q/2; i++)
			{
				for(j=0; j < Y; j++)
				{
					aux[j] = m[i][j];
					m[i][j] = m[Q - 1 - i][j];
					m[Q - 1 -i][j] = aux[j];
				}
			}
		}

*/

