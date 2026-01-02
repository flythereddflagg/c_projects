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

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define INIT_ARR_LENGTH 1024

typedef struct {
    char *arr;
    int length; // the end of the user space for the array
    // int end; // the end of the memory space for the array
    int element_size; // size in bytes of each element
} Array;

Array* Array_on_stack(Array *self, char* arr, int element_size, int length){
    check(self && arr && element_size > 0 && length > 0, "Invalid inputs");
    self->arr = arr;
    self->length = length;
    self->element_size = element_size;
    return self;
error:
    printf(
        "PM: Array *self:%p, char* arr:%p, int element_size:%d, int length:%d\n", 
        self, arr, element_size, length
    );
    exit(2);
}

Array* Array_on_heap(int element_size, int length){
    Array *array = NULL;
    check(element_size > 0 && length > 0, "Invalid inputs");
    array = (Array*) malloc(sizeof(Array));
    check_mem(array);

    array->arr = malloc(length*element_size);
    check_mem(array->arr);
    array->length = length;
    array->element_size = element_size;

error:
    return array;
}

void Array_heap_free(Array* self){
    check(self, "Cannot free NULL pointer");
    if (self->arr) 
        free(self->arr);
    free(self);
error:
    ;
}

void* Array_at(Array* self, int position){
    check(self, "invalid array object: %p", self);
    check(self->arr, "invalid array attrbute: %p", self->arr);
    check(position >= 0 && position < self->length, 
        "Array out of bounds. Len: %d, pos: %d", self->length, position
    );
    return self->arr + position * self->element_size;

error:
    return NULL;
}

int main(){
    Array array_d;
    const int len = 12;
    int arr1[len];
    int *element;
    Array *array = Array_on_stack(
        &array_d, 
        (char*)&(arr1[0]), 
        sizeof(int), 
        len
    );

    Array *heap_array = Array_on_heap(
        sizeof(int),
        len
    );
    check(heap_array, "Heap array did not initalize correctly.");
    for (int i = 0; i < array->length; i++){
        element = (int*) Array_at(array, i);
        check(element, "NULL pointer returned from array");
        *(element) = i+1;
        printf("%d @ %llu; ", *(element), (long long unsigned)element);
        // heap array down here
        element = (int*) Array_at(heap_array, i);
        check(element, "NULL pointer returned from array");
        *(element) = i+1;
        printf("HEAP %d @ %llu \n", *(element), (long long unsigned)element);
    }

error:
    Array_heap_free(heap_array);
    return 0;
}

