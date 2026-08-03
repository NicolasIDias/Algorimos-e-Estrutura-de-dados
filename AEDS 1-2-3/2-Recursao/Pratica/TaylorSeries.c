#include <stdio.h>

int power(int n1, int n2){
    if(n1 == 0) return 0;
    else if(n2 == 1) return n1;
    else if(n2 == 0) return 1;
    else{
        return n1 * power(n1, n2-1);
    }
}
int sum(int n){
    if(n > 0){
        return n + fun(n-1);
    }else{
        return 0;
    }
}
int factorial(int n){
    if(n == 0) return 0;
    else if(n == 1){
        return 1;
    }else{
        return n*fact(n-1);
    }

}

int taylor(int n){

}

int main(){
    printf("%d", taylor(4));
    return 0;
}