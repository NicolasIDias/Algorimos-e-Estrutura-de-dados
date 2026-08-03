#include <stdio.h>

typedef struct String
{
    char s[200];
} String;

typedef struct Pessoa
{
    String nome;
    int idade;
} Pessoa;

int main()
{
    Pessoa p;
    scanf("%s", &p.nome);
    printf("%s", p.nome);
    return 0;
}