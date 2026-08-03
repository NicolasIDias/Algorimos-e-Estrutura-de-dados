#include <stdio.h>
#include <stdlib.h>

typedef struct Teste
{
    int A[5];
    int n;
} Teste;

typedef struct Retangulo
{
    float comprimento;
    float altura;
} Rect;

Rect *criar_rect(float altura, float comprimento){
    Rect *r = NULL;
    r = (Rect *) malloc(sizeof(Rect));
    r->altura = altura;
    r->comprimento = comprimento;
    return r;
}

float calculate_area(Rect r1)
{
    return r1.altura * r1.comprimento;
}

void mudar_comprimento(Rect *r, float n)
{
    r->comprimento = n;
}
void mudar_altura(Rect *r, float n)
{
    r->altura = n;
}

// TESTE
void mudar_primeiro(Teste *t)
{
    t->A[0] = 100;
}

int main()
{

    Rect r1 = {10, 5};
    float area = calculate_area(r1);
    printf("%.2f\n", area);

    Rect *r2 = (Rect *)malloc(sizeof(Rect));

    r2->altura = 100;
    r2->comprimento = 200;

    float area2 = calculate_area(*r2);
    printf("%.2f\n", area2);
    

    Rect *r3 = criar_rect(10, 20);
    float area3 = calculate_area(*r3);
    printf("%.2f\n", area3);


    Teste t1 = {{1, 2, 3, 4, 5}, 5};
    printf("%d\n", t1.A[0]);
    mudar_primeiro(&t1);
    printf("%d\n", t1.A[0]);

    free(r2);
    return 0;
}