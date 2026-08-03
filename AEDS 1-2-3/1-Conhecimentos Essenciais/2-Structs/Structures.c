#include <stdio.h>

typedef struct Carta{
    // 0: Espadas - 1: Paus - 2: Ouros - 3: Copas
    int naipe;
    // 0: Preto - 1: Vermelho
    int cor;
    // 0,1,2 ... 10,11,12 -> A,2,3 ... J,Q,K
    int val;
} Carta;

typedef struct Deck{
    Carta cartas[52];
} Deck;

typedef struct Node{
    int val;
    Node *next;
} Node;

typedef struct Student{
    char nome[50];
    int idade;
    long matricula;
    char endereco[50];
    char curso[25];

} Student;

typedef struct NumeroComplexo{
    int real;
    int imagiario;
} Complex;

typedef struct Retangulo{
    float altura;
    float comprimento;
} Rect;

int main(){
    // Declaração sem inicialização
    Rect r1;
    // Atruibuição de valores à r1
    r1.altura = 10.2, r1.comprimento = 40.5;
    // Declaração com inicialização
    Rect r2 = {10.2, 40.5};

}
