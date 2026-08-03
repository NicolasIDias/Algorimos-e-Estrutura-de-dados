#include <stdio.h>

int fun(int n){
    if(n > 0){
        return n + fun(n-1);
    }else{
        return 0;
    }
}

int main(){

    printf("%d", fun(2));

    return 0;
}