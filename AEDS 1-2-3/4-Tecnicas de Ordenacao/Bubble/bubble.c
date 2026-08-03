#include "../utils/array.h"

void swap(array_t *arr, int i, int j){
    int tmp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = tmp;
}

void bubble_sort(array_t *arr){
    for(int i=0;i<arr->length;i++){
        for(int j=0;j<arr->length-1;j++){
            if(arr->A[j] > arr->A[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}