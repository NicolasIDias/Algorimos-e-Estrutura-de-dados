#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "../../0-shared/bool.h"

array_t new_array(int size)
{
    array_t arr;
    arr.size = size;
    arr.A = malloc(sizeof(int) * size);
    arr.length = 0;
    return arr;
}

void append(array_t *arr, int n)
{
    if (arr->length == arr->size)
    {
        resize(arr);
    }
    arr->A[arr->length++] = n;
}

void insert_at(array_t *arr, int n, int index)
{
    if (index < 0 || index > arr->length)
    {
        printf("[Erro]: Index fora dos limites. O limite atual e: %d\n", arr->length);
        return;
    }
    if (arr->length == arr->size)
        resize(arr);
    for (int i = arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = n;
    arr->length++;
}

void remove_at(array_t *arr, int index)
{
    if (index >= arr->length || index < 0)
    {
        printf("[Erro]: Index fora dos limites do array\n");
        return;
    }
    else
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

void resize(array_t *arr)
{
    int size = arr->size * 2;
    int *tmp = realloc(arr->A, sizeof(int) * size);
    if (tmp != NULL)
    {
        arr->A = tmp;
        arr->size = size;
    }
    else
    {
        printf("[Erro]: Memoria insuficiente para dar resize\n");
    }
}

void delete_array(array_t *arr)
{
    if (arr != NULL)
    {
        free(arr->A);
        arr->A = NULL;
    }
    arr->length = 0;
    arr->size = 0;
}

void print_array(array_t *arr)
{
    printf("[");
    for (int i = 0; i < arr->length; i++)
    {
        if (i == arr->length - 1)
        {
            printf("%d", arr->A[i]);
        }
        else
        {
            printf("%d, ", arr->A[i]);
        }
    }
    printf("]");
    printf("\n");
}

bool linear_search(array_t *arr, int target)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == target)
            return true;
    }
    return false;
}

bool binary_search(array_t *arr, int target)
{
    if (arr->length == 0)
        return false;
    bool isSorted = is_sorted(arr);
    if (isSorted)
    {
        int low = 0;
        int high = arr->length - 1;
        while (low <= high)
        {
            int curr = (low + high) / 2;
            if (arr->A[curr] == target)
                return true;
            else if (target > arr->A[curr])
                low = curr + 1;
            else
                high = curr - 1;
        }
        return false;
    }
    else
    {
        printf("[Error]: Array nao ordenado\n");
        return false;
    }
    return false;
}

bool search(array_t *arr, int target)
{
    bool isSorted = is_sorted(arr);
    if (isSorted)
        return binary_search(arr, target);
    else
        return linear_search(arr, target);
}

bool is_sorted(array_t *arr)
{
    if (arr->length < 2)
        return true;
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] > arr->A[i + 1])
            return false;
    }
    return true;
}

int max(array_t *arr)
{
    if (arr == NULL)
    {
        printf("[Error]: Array Nulo");
        return -1;
    }
    else
    {
        int max = arr->A[0];
        for (int i = 0; i < arr->length; i++)
        {
            if (max < arr->A[i])
                max = arr->A[i];
        }
        return max;
    }
}

int min(array_t *arr)
{
    if (arr == NULL)
    {
        printf("[Error]: Array Nulo");
        return -1;
    }
    else
    {
        int min = arr->A[0];
        for (int i = 0; i < arr->length; i++)
        {
            if (min > arr->A[i])
                min = arr->A[i];
        }
        return min;
    }
}

float avg(array_t *arr)
{
    if (arr == NULL)
    {
        printf("[Error]: Array Nulo");
        return -1;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < arr->length; i++)
            sum += arr->A[i];
        return sum / arr->length;
    }
}

array_t merge(array_t *arr1, array_t *arr2)
{
    int size = arr1->size + arr2->size;
    array_t arr = new_array(size);

    print_array(arr1);
    print_array(arr2);

    int i = 0, j = 0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            append(&arr, arr1->A[i]);
            i++;
        }
        else
        {
            append(&arr, arr2->A[j]);
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        append(&arr, arr1->A[i]);
    }
    for (; j < arr2->length; j++)
    {
        append(&arr, arr2->A[j]);
    }

    return arr;
}