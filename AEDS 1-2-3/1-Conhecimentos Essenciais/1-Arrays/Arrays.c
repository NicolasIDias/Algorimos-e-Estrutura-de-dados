#include <stdio.h>

int main()
{

    // Declaração de um array A de tamanho fixo e nao inicializado
    int A[5];
    // Atribuição de valores ao array A
    A[0] = 0, A[1] = 1, A[2] = 2, A[3] = 3, A[4] = 4;

    // Declaração de um array B ja inicializado e com tamanho fixo
    int B[5] = {0, 1, 2, 3};
    // B[4] é automaticamente inicializado com valor 0, mesmo sem estar explicitamente declarado
    printf("%d\n", B[4]);

    for (int i = 0; i < (sizeof(A) / sizeof(A[0])); i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (int i = 0; i < (sizeof(B) / sizeof(A[0])); i++)
    {
        printf("%d ", B[i]);
    }

    return 0;
}