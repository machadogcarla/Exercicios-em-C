/*Escreva um algoritmo que leia dois vetores de 10 posições e faça a
 multiplicação dos elementos de mesmo índice, colocando o resultado em um terceiro vetor. Mostre o vetor resultante.*/
 
 #include <stdio.h>
 #define TAMA 5
  #define TAMB 5
   #define TAMC 5
 void preenche (int v[], int tam);
void mult (int v1[], int v2[],int v3[],int tamA, int tamB,int tamC);
 void exibe(int v[], int tam);
 
 int main()
 
 { 	
 	printf("Preenchendo Vetor 1:\n");
	 int v1[TAMA];
 	preenche (v1, TAMA);
 	exibe (v1, TAMA);
 	printf("\n\n");
 	
	printf("Preenchendo Vetor 2:\n");
	int v2[TAMB];
 	preenche (v2, TAMB);
 	exibe (v2, TAMB);
 	printf("\n\n");
  	
	  printf("Preenchendo Vetor 3 Com a mult. de v1 * v2:\n");
  	int v3[TAMC];
   	mult (v1, v2,v3, TAMA,TAMB, TAMC);
   	
	exibe (v3, TAMC);
 	
 }
 
 	void preenche (int v[], int tam){
			
			int i;
			
			for( i = 0; i < tam; i++)
			{
				printf("%d elemento: " , i+1);
				scanf("%d", &v[i]);
			}
		}
		
		
		void mult (int v1[], int v2[],int v3[],int tamA, int tamB,int tamC){
		
			int i;
		
			for( i = 0; i < tamA; i++)
			{
				v3[i] = v1[i] * v2[i];
			}
		}
		
		void exibe(int v[], int tam){
			
				int i;
		
			for( i = 0; i < tam; i++)
			{
				printf("%d ", v[i]);
			}
		}	
		
