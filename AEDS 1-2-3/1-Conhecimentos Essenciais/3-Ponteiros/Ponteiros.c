#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 100; // Ocupa 2 bytes

    int *p = NULL;
    p = &numero; // Ponteiro p armazena o endereço de memória da variável numero

    printf("%d\n", numero);
    printf("%d\n", *p);

    *p = 10; // Altera o valor armazenado no endereço de memória armazenado em p
    printf("%d\n", numero);

    // Alocação dinâmica de memória

    int *ponteiro = NULL;
    ponteiro = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        // *(ponteiro+i) = i;
        // printf("%d,", *(ponteiro+i));
        ponteiro[i] = i;
        printf("%d", ponteiro[i]);
    }
    printf("\n");

    int col = 5, row = 19;
    int *matriz = NULL;

    matriz = (int *)malloc(col * row * sizeof(int));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matriz[i*col+j] = 2*9+j-i;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d,", matriz[i*col+j]);
        }
        printf("\n");
    }

    free(ponteiro);
    free(matriz);
    return 0;
}