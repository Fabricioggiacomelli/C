#include<stdio.h>
#include<stdlib.h>

void aloca(int**num, int cont)
{
    num = (int) realloc(*num, (cont+1)*sizeof(int));
    if(num == NULL)
    {
        printf("aloc fail");
    }
}
void leitura(int* num, int cont)
{
    printf("numero:");
    scanf("%i", &num[cont]);
    fflush(stdin);
}
void opcao(char* op)
{
    printf("deseja continuar <s/n>");
    scanf(" %c", op);
    fflush(stdin);
}
void subtrair(int*num, int cont, int*sub, int* impar, int* cont_i)
{
    int temp = 0;
    printf("os numeros apos a subtracao:\n");
    for(int i=0; i<cont/2; i++)
    {
        sub = (int) realloc(sub, (i+1) sizeof(int));
        if(*sub == NULL)
        {
            printf("aloc fail");
        }
        (*sub)[i] = num[temp] - num[temp + 1 ];
        temp += 2;
        printf("%i ", (*sub)[i]);
        if((*sub)[i] %2 != 0)
        {
            impar = (int) realloc(*impar, (*cont_i+1)*sizeof(int));
            if(*impar == NULL)
            {
                printf("aloc fail");
            }

             (*impar)[*cont_i] = (*sub)[i];
            (*cont_i)++;
        }
    }  
}
void imprime( int*impar, int cont_i)
{
    printf("\n os numeros impares sao:\n");
    for(int i= 0; i < cont_i; i++ )
    {
        printf("%i ", impar[i]);
    }
}
int main()
{
    int* num = NULL;
    int cont = 0;
    char op;
    int* sub = NULL; 
    int* impar = NULL;
    int cont_i = 0;

    do
    {
        aloca(&num, cont);
        leitura(num, cont);
        opcao(&op);
        cont++;

    } while (op == 's' || op == 's');

    subtrair(num, cont, &sub, &impar, &cont_i);
    imprime(impar, cont_i);
    free(num);
    free(sub);
    free(impar);
    
}

