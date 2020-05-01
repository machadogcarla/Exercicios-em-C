#include <stdio.h>

int main() {
	
	//Declaração de Variáveis
	int r, nc, nci, re, nv, ndez, nCinco, nd, n1;
	int q, n100, n50, n20, n10, n5, n2;
	
	printf("Informe o valor em Reais: ");
	//scanf("%d", &r);
	scanf("%d", &q);
	
/*	nc = r / 100;
	
	nci = re / 50;
	re = re % 50;
	
	nv = re / 20;
	re = re % 20;
	
	ndez = re / 10;
	re = re % 10;
	
	nCinco = re / 5;
	re = re % 5 ;
	
	nd = re / 2;
	re = re % 2;	
	
	 n1 =  re / 1;
	 re = re % 1;
	 
	printf("%d notas de 100, %d notas de 50, %d notas de 20, %d notas de 10, %d notas de 5, %d notas de 2, %d notas de 1 ",
	 nc, nci, nv, ndez, nCinco, nd, n1 );	 
	 */
	 
	 if (q >= 100){
	 	n100 = q /100;
	 	r = q % 100; //pegando o valor do resto
	 	printf(" %d Notas de 100 ", n100);
	 	
	 	 }	
		  			   
		if(r >= 50){
			n50 = r /50;
		
				printf(", %d Notas de 50 ", n50);
				
		}else{
			
			if(r >= 20){
			n20 = r / 20;
		
				printf(", %d Notas de 20 ", n20);
			
		}// fim do if 
				else{
			
			if(r >= 10){
			n10 = r / 10;
			//r = q % 10 ; //pegando o valor do resto
				printf(", %d Notas de 10 ", n10);
		}
		 else {
		
		 if(r >= 5){
			n5 = r / 5;
		//	r = q % 5; //pegando o valor do resto
				printf(", %d Notas de 5 ", n5);
		} else{
			
			if(r >= 2){
				
			n2 = r / 1;
			
		printf(", %d Notas de 2 ", n2);
				
			} else{
				
				printf(", %d Moeda de 1 ", n1);	
			} 
	
			
		}	
		 }

	}
}

	
}//fim do main
