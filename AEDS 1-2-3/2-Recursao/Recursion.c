#include <stdio.h>

int fun1(int n){
    static int x = 0;
    if(n>0){
        x++;
        return fun1(n-1)+x;
    }
    return n;
}

int fun2(int n){
    if(n>0){
        return fun2(n-1)+n;
    }
    return 0;
}

void rec(int n, int counter){

    if(n>0){
        printf("Switching On - ");
        printf("Going to next room\n");
        rec(n-1, counter+1);
        if(counter > 1)printf("Going back to room: %d\n", counter-1);
        else printf("Im in the starting room: %d\n", counter);

    }

}

int main(){

    int n = fun1(5);
    printf("%d\n", n);

    int n2 = fun2(5);
    printf("%d\n", n2);
    return 0;
}