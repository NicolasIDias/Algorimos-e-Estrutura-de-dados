#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno
{
    char nome[20];
    int idade;
} Aluno;        

int main()
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    strcpy(aluno->nome, "Nicolas");
    aluno->idade = 19;
    printf("%s, %d", aluno->nome, aluno->idade);

    int nTurmas = 3, alunosPorTurma = 5;
    Aluno *buffer = (Aluno *)malloc(nTurmas * alunosPorTurma * sizeof(Aluno));

    for (int i = 0; i < nTurmas; i++)
    {
        for (int j = 0; j < alunosPorTurma; j++)
        {
            strcpy((buffer + i * alunosPorTurma + j)->nome, "Nicolas");
            (buffer + i * alunosPorTurma + j)->idade = 19;
        }
    }

    printf("\n");

    for (int i = 0; i < nTurmas; i++)
    {
        printf("[");
        for (int j = 0; j < alunosPorTurma; j++)
        {
            printf("%s, %d-", (buffer+i*alunosPorTurma+j)->nome,(buffer+i*alunosPorTurma+j)->idade);
        }
        printf("]");
        printf("\n");
    }

    free(aluno);
    free(buffer);


    printf("\n");
    return 0;
}