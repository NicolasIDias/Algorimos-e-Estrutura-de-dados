#include <stdio.h>


typedef struct Date {

    int dia;
    int mes;
    int ano;

} Date;

int main(){
    Date hoje = {20, 10, 2025};
    printf("%d/%d/%d", hoje.dia, hoje.mes, hoje.ano);
}


