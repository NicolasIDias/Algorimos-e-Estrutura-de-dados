#include <stdio.h>
#include "array.h"
#include "../../0-shared/bool.h"

int main()
{

    array_t arr = new_array(10);
    array_t arr2 = new_array(10);

    for (int i = 0; i < 5; i++)
    {
        append(&arr, i);
    }

    for (int i = 5; i >= 0; i--)
    {
        append(&arr2, i);
    }

    print_array(&arr);
    append(&arr, 100);
    insert_at(&arr, 5000, 6);
    print_array(&arr);
    remove_at(&arr, 4);
    remove_at(&arr, 9);
    print_array(&arr);

    bool num_found = linear_search(&arr, 100);
    if (num_found)
        printf("Number %d was found\n", 100);
    else
        printf("Number %d was not found\n", 100);

    print_array(&arr2);
    bool num_found2 = binary_search(&arr2, 100);
    if (num_found2)
        printf("Number %d was found\n", 100);
    else
        printf("Number %d was not found\n", 100);

    printf("%d\n", min(&arr));
    printf("%d\n", max(&arr));
    printf("%.2f\n", avg(&arr));

    array_t merge1 = new_array(10);
    array_t merge2 = new_array(10);

    for (int i = 0; i < 5; i++)
    {
        append(&merge1, i);
    }

    for (int i = 5; i >= 0; i--)
    {
        append(&merge2, i);
    }

    //print_array(&merge1);
    //print_array(&merge2);

    array_t merged12 = merge(&merge1, &merge2);
    print_array(&merged12);


    delete_array(&merged12);
    delete_array(&merge1);
    delete_array(&merge2);
    delete_array(&arr);
    delete_array(&arr2);
    return 0;
}