#include <stdio.h>
#include <stdlib.h>

// Funções
void aloca(float **p, int tam);
void receber_num(float *p, int tam);
void imprime(float *p, int tam);
void soma(float *p, int tam);

int main()
{
    float *ptr = NULL;
    int x;
    aloca(&ptr, 10);
    receber_num(ptr, 10);
    printf("Valores originais:\n");
    imprime(ptr, 10);
    soma(ptr, 10);
    printf("Valores após soma:\n");
    imprime(ptr, 10);
    free(ptr);
    return 0;
}

void aloca(float **p, int tam)
{
    *p = (float *)realloc(*p, tam * sizeof(float));
    if (*p == NULL)
    {
        printf("Erro na alocação!");
        exit(1);
    }
    printf("Memória alocada com sucesso.\n");
}

void receber_num(float *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite um numero %d: ", i + 1);
        scanf("%f", &p[i]);
    }
}

void imprime(float *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Valor: %.2f - Endereço: %u\n", p[i], (void *)&p[i]);
    }
}

void soma(float *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        p[i] += 30;
    }
}
