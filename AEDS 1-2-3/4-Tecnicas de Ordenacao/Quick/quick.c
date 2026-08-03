#include "../utils/array.h"
#include "../utils/bool.h"

void sort(array_t *arr, int low, int high);

void swap(array_t *arr, int i, int j)
{
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
    temp = 0;
}

int mediana(array_t *arr)
{
    int index = arr->length - 1;
    int n1 = arr->A[0];
    int n2 = arr->A[index];
    int n3 = arr->A[index / 2];
    return (n1 + n2 + n3) / 3;
}

int partition(array_t *arr)
{
    int pivot = mediana(arr);
    int n = arr->length;

    int i = -1, j = n;
    while (true)
    {
        do  
        {
            i++;
        } while (arr->A[i] < pivot);
        do
        {
            j--;
        } while (arr->A[j] > pivot);

        if (i > j)
            break;
        swap(arr, i, j);
    }
    return pivot;
}

void sort(array_t *arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr);

        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

void quick_sort(array_t *arr)
{
    int low = 0;
    int high = arr->length - 1;
    sort(arr, low, high);
}