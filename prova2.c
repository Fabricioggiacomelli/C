#include<stdio.h>
#include<stdlib.h>

void aloca(int **p, int tam);
void leitura (int *p);
void par (int *p, int tam, int **pp, int *qp);
void mostra (int *p, int tam);

int main()
{
	int *ptr=NULL, *ppar=NULL;
	int cont=0, qpar=0;
	char op;
	
	do
	{
		aloca (&ptr, cont+1);
		leitura(ptr+cont);
		cont++;
		
		printf("\nDeseja continuar? <S/N> ");
		scanf(" %c", &op);
		fflush(stdin);
	} while (op=='S' || op=='s');
	
	printf("\nNumeros Digitados\n");
	mostra (ptr, cont);
	
	par(ptr, cont, &ppar, &qpar);
	printf("\n");
	
	printf("\nResultado das subtracoes\n");
	mostra(ppar, qpar);
	
	printf("\n\n");
	system("pause");
	return 0;
}

void aloca(int **p, int tam)
{
	if ((*p=(int)realloc(*p, (tam)*sizeof(int))) == NULL)
	{
		printf("\nErro na alocacao\n");
		exit(1);
	}
}

void leitura (int *p)
{
	printf("\nEndereco %u - Numero: ", p);
	scanf("%i", p);
	fflush(stdin);
}

void par (int *p, int tam, int **pp, int *qp)
{
	int i, sub;
	for (i=0; i<tam-1;i+=2)
	{
		sub = *(p+i+1) - *(p+i);
		
		if (sub%2 == 0)
		{
			aloca (pp, (*qp)+1);
			*(*pp + *qp) = sub;
			(*qp)++;
		}
	}
	
	if (tam%2 != 0)
	{
		if (*(p+tam-1) % 2 == 0)
		{
			aloca (pp, (*qp)+1);
			*(*pp + *qp) = sub;
			(*qp)++;
		}
	}
}

void mostra(int *p, int tam)
{
	int i;
	for (i=0; i<tam; i++)
	{
		printf("\n%i", *(p+i));
	}
}