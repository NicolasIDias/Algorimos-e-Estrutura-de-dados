#include <stdio.h>


int fibRec(int prev, int curr, int counter, int target){
    if(counter == target) return curr;
    else{
        return fibRec(curr, curr+prev, counter+1, target);
    } 
}


int main(){
    
    int prev = 0, curr = 1, counter = 1, target = 64;

    int fib = fibRec(prev, curr, counter, target);
    printf("%d", fib);

    return 0;
}