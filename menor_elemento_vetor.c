/*
Faça um algoritmo que leia um vetor N[20]. A seguir, encontre o menor elemento do vetor N e 
a sua posição dentro do vetor, mostrando: “O menor elemento de N é”, M, “e sua posição dentro do vetor é:”,P.*/

#include <stdio.h>
#define TAM 5

void preenche (int v[], int tam);
int buscaMenorElemento(int v[], int tam, int *menor);
	
	int main()
	{
		int N[TAM]; //criação do vetor
		int resp;
		
		preenche(N, TAM);
		
		int menor = N[0]; //atribuo menor n[0]
		
		//printf("%d", menor);
		
		resp = buscaMenorElemento(N, TAM, &menor);
		
		printf("\nO menor elemento de N é %d e sua posição dentro do vetor é: %d \n\n", menor, resp);
		
	}
	
		void preenche (int v[], int tam){
			
			int i;
			for( i = 0; i < tam; i++)
			{
				printf("%d elemento: " , i+1);
				scanf("%d", &v[i]);
			}
		}
		
		
		int buscaMenorElemento(int v[], int tam, int *menor)
		{
			
			int i, posicao; //atribuo a variavel menor o primeiro valor
		
			for(i = 0; i < tam ; i++)
			{
				if(*menor >= v[i])
				{
					*menor = v[i];
					posicao = i;
				}
			}
		return posicao;
		}
