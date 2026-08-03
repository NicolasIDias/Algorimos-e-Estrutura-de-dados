#include <stdio.h>


void head(int n){
    if(n>0){
        head(n-1);
        printf("%d",n);
    }
}

void headLoop(int n){
    for(int i=1;i<=n;i++) printf("%d", i);
}

int main(){
    head(5);
    headLoop(5);
    return 0;
}