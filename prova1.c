#include<stdio.h>
#include<stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p);
void imprimepar(int *p, int tam);


int main() {
	char resp;
	int *ptr=NULL, cont=0, qtdp;
	
	do {
		aloca(&ptr, cont+1);
		leitura(ptr+cont);
		cont++;
		printf("Deseja continuar? (S/N) ");
		scanf(" %c", &resp);
	} while(resp != 'n' && resp != 'N');
	
	
	printf("Numeros pares a partir da subtracao:\n");
	imprimepar(ptr,cont);
	
}

void aloca(int **p, int tam) {
	if((*p=(int *)realloc(*p,tam*sizeof(int))) == NULL)
		exit(1);
}

void leitura(int *p) {
	printf("Endereço %i - Valor: ", p);
	scanf("%i", p);
}

void imprimepar(int *p, int tam) {
	
	int j = 1;
	
	if(tam == 0) 
	{
		printf("Voce digitou apenas um numero!");
	}
	else if (tam % 2 == 0)
	{
		
		for(int i=0; i<tam; i += 2, j += 2)
		{
			if((*(p+i) - *(p+j)) % 2 == 0)
			{
				printf("%i\n", *(p+i) - *(p+j));
			}
		}
	}
	else if (tam % 2 == 1)
	{
		for(int i=0; i<tam-1; i += 2, j += 2)
		{
			if((*(p+i) - *(p+j)) % 2 == 0)
			{
				printf("%i\n", *(p+i) - *(p+j));
			}
		}
		if(*(p+tam-1) % 2 == 0)
			printf("%i\n", *(p+tam-1));
	}
}