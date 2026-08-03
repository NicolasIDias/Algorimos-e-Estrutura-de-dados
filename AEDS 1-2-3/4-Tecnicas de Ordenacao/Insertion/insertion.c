#include "../utils/array.h"

void swap(array_t *arr, int i, int j)
{
    int tmp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = tmp;
}

void insertion_sort(array_t *arr)
{
    for(int i=0;i<arr->length-1;i++){
        for(int j=i+1;j<arr->length;j++){
            if(arr->A[i] > arr->A[j]){
                swap(arr, i, j);
                //print_array(arr);
            } 
        }
    }
}