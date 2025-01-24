#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* arr;
    size_t length;
    size_t element_size;
} Array;

/*
 * Needed methods:
 * append
 * insert
 * pop
 * remove
 * clear
 * index
 * count
 * sort
 * reverse
 * copy
 *
 * list.append(x)
 * Add an item to the end of the list. Equivalent to a[len(a):] = [x].
 *
 * list.extend(iterable)
 * Extend the list by appending all the items from the iterable. Equivalent to
 * a[len(a):] = iterable.
 *
 * list.insert(i, x)
 * Insert an item at a given position. The first argument is the index of the
 * element before which to insert, so a.insert(0, x) inserts at the front of 
 * the list, and a.insert(len(a), x) is equivalent to a.append(x).
 *
 * list.remove(x)
 * Remove the first item from the list whose value is equal to x. It raises 
 * a ValueError if there is no such item.
 *
 * list.pop([i])
 * Remove the item at the given position in the list, and return it. If no 
 * index is specified, a.pop() removes and returns the last item in the list. 
 * It raises an IndexError if the list is empty or the index is outside the 
 * list range.
 *
 * list.clear()
 * Remove all items from the list. Equivalent to del a[:].
 *
 * list.index(x[, start[, end]])
 * Return zero-based index in the list of the first item whose value is equal 
 * to x. Raises a ValueError if there is no such item.
 *
 * The optional arguments start and end are interpreted as in the slice 
 * notation and are used to limit the search to a particular subsequence of 
 * the list. The returned index is computed relative to the beginning of the 
 * full sequence rather than the start argument.
 *
 * list.count(x)
 * Return the number of times x appears in the list.
 *
 * list.sort(*, key=None, reverse=False)
 * Sort the items of the list in place (the arguments can be used for sort 
 * customization, see sorted() for their explanation).
 *
 * list.reverse()
 * Reverse the elements of the list in place.
 *
 * list.copy()
 * Return a shallow copy of the list. Equivalent to a[:].
 * */

Array* new_array(size_t element_size, size_t length){
    if (!element_size || !length) return NULL;
    
    Array* array = (Array*) malloc(sizeof(Array));
    if (!array) return NULL;

    array->arr = malloc(element_size * length);
    if (!array->arr){
        free(array);
        return NULL;
    }
    (*array).length = length;
    (*array).element_size = element_size;
    return array;
}

void* at(Array* array, size_t position){
    if (position >= (*array).length) return NULL;
    return array->arr + position * (*array).element_size;
}

int new_array(Array* array){
    if (!array) return -1;
    if (!array->arr) free(array->arr);
    free(array);
    return 0;
}

int main(){
    int init[] = {3, 2 ,345, 1, 3, 4, 2, 3};
    Array* array = make_array(sizeof(int), 4);
    int i = 0, success = -1;
    int* element_addr = NULL;
    for (i = 0; i < (*array).length; i++){
        element_addr = (int*) at(array, i);
        if (element_addr) *element_addr = init[i];
    }

    element_addr = (int*) at(array, i);
    if (element_addr) *element_addr = init[i];
    else 
        printf(
            "ERROR: index %d out of bounds for array of length %d\n", i, (int) (*array).length
        );

    for (i = 0; i < (*array).length; i++){
        printf("array %d = %d\n", i, *(int*) at(array, i));
    }
    success = !free_array(array);
    printf("Did it work? %d\n", success);
    return 0;
}

