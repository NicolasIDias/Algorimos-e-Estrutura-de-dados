#include <stdio.h>
#include <stdlib.h>

int* new_array(int size){
    int *p = NULL;
    p = (int *) malloc(size*sizeof(int));
    if(p == NULL){
        exit(1);
    }
    return p;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int sum(int a, int b){
    if(b == 0) return a;
    else if(a == 0) return b;
    else return sum(a+1, b-1);
}

int main(){
    int w=10, b=500;
    int soma = sum(w,b);

    int x = 4, y = 7;
    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);

    int *a = new_array(5);

    printf("%d\n", a[0]);

    printf("%d\n", soma);

    free(a);
}