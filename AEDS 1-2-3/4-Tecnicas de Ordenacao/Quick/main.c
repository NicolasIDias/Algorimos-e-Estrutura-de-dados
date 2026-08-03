#include "quick.h"
#include "../utils/array.h"
#include <stdio.h>

int main()
{

    array_t arr = new_array(10);
    for (int i = arr.size; i > 0; i--)
    {
        append(&arr, i);
    }
    partition(&arr);
    print_array(&arr);
    //printf("%d\n", arr.length);

    return 0;
}