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

#define INIT_ARR_LENGTH 1024

typedef struct {
    char *arr;
    int length; // the end of the user space for the array
    int end; // the end of the memory space for the array
    int element_size; // size in bytes of each element
} Array;

Array* Array_on_stack(Array *self, char* arr, int element_size, int length){
    if (!element_size || !length) return NULL;
    int end = INIT_ARR_LENGTH;
    while (end < (length * element_size))
        end *= 2;
    self->arr = arr;
    self->end = end;
    self->length = length;
    self->element_size = element_size;
    return self;
}

Array* Array_on_heap(int element_size, int length){
    if (!element_size || !length) return NULL;
    int end = INIT_ARR_LENGTH;
    while (end < (length * element_size))
        end *= 2;
    Array* array = (Array*) malloc(sizeof(Array));
    if (!array) return NULL;

    array->arr = malloc(end);
    if (!array->arr){
        free(array);
        return NULL;
    }
    array->end = end;
    array->length = length;
    array->element_size = element_size;
    return array;
}

int Array_heap_free(Array* self){
    if (!self) 
        return -1;
    if (self->arr) 
        free(self->arr);
    free(self);
    return 0;
}

void* Array_at(Array* self, int position){
    if (position < 0 || position >= self->length) 
        return NULL;
    return self->arr + position * self->element_size;
}

int main(){
    Array array_d;
    const int len = 12;
    int arr1[len];
    int* element;
    Array* array = Array_on_stack(&array_d, (char*) &(arr1[0]), sizeof(int), len);
    int test[INIT_ARR_LENGTH] = {1,2,3,4,5};
    for (int i = 0; i < len; i++){
        element = (int*) Array_at(array, i);
        if (!element){
            printf("ERROR element %d is wrong", i);
            continue;
        }
        *(element) = test[i];
        element = (int*)Array_at(array, i);
        printf("%d ", *(element));
    }
    return 0;
}

