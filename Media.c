/* Aloque dinamicamente espaço e receba ‘números’ digitados
pelo usuário. O usuário poderá entrar com novos ‘números’, até
que este escolha a opção N (Deseja continuar? (S/N)). Em
seguida, determine a média e aloque espaço para os números
menores e maiores que a média. Mostre na tela. Utilizar função
para alocação dinâmica */

#include <stdio.h>
#include <stdlib.h>

void aloca (int **p, int tam);
void leitura (int p);
void mostra (int p, int tam);
int maior_media (int p, int tam, int pM);

int main ()

{
    int ptr = NULL, cont=0,pmaior = NULL, qmaior;
    char op;

    do
    {
        aloca(&ptr, cont+1);
        leitura(ptr + cont);
        cont++;
        printf("Deseja continuar? <S/N>: ");
        scanf("%c", &op);


    } while (op== 's' || op== 'S');

    mostra(ptr, cont);
    qmaior = maior_media(ptr, cont, &pmaior);

    return 0;

}

void aloca (int **p, int tam)
{
    if((*p=(int)realloc(*p, tam*sizeof(int)))==NULL)
    exit(1);
}

void leitura (int p)
{
    printf("/n Digite um numero: ");
    scanf("%i", p);

}

void mostra (int p, int tam)
{
    for( int i=0; i < tam; i++, p++)
        printf("\n%i", p);
    printf("\n\n\n");
    system("pause");
}

int maior_media (int p, int tam, int pM)
{
   int i;
  float m=0;
  for(i=0; i<tam; i++)
  m+=(p+i);

    m/=tam;
    printf("\n A media = %.2f ", m);

    for(i=0;i<tam;i++,p++)
    {
        if (*p>m)
        {
            aloca(pM,qM+1);
            (pM+qM)=p;
            qM++;
        }
    }
}


