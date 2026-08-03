#include "../utils/array.h"
#include "selection.h"

int main(){

    array_t arr = new_array(10);
    for(int i=arr.size;i>0;i--){
        append(&arr, i);
    }
    print_array(&arr);
    selection_sort(&arr);
    print_array(&arr);

}