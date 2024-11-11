#include <stdio.h>

#define INT_UNALLOC -128 // manually set the size of unallocated values (for some reason windows is using 8bit signed integers)

typedef struct {
    int capacity; // total capacity of array
    int size; // current # of element inside array
    char* ptr; // pointer to array (block of contiguous memory)
} intArray;

void initArray(intArray *arr, int capacity){
    // the cast ensures that the block of memory is separated by integers, and that integer values will be there
    // default value is void (any type can be casted). It is not necessary to cast in C
    arr->ptr = (int *)malloc(capacity * sizeof(int)); // create the block of contiguous memory
    arr->capacity = capacity;
    for(int i = 0; i < capacity; i++){ // initialize values to max int size
        arr->ptr[i] = INT_UNALLOC;
    }
}

void addElement(intArray *arr, int index, int value){
    printf("adding element %d value %d\n", index, value);
    if(arr->size >= arr->capacity){ // if arr full condition
        printf("Array is full. Failed to add element.\n");
        return;
    }
    if(index > arr->capacity){
        printf("Index out of Bound. Failed to add element.\n");
        return;
    }
    arr->ptr[index] = value; // add value to the first free block of memory
    arr->size++; // increment the size (keeping track)
}

void removeElement(intArray *arr, int index){
    printf("remove element %d \n", index);
    if(index > arr->capacity){
        printf("Index out of Bound. Failed to add element.\n");
        return;
    }
    int max = INT_UNALLOC;
    arr->ptr[index] = max;
    arr->size--; // decrement the size
}

void printArray(intArray *arr){
    for(int i = 0; i < arr->capacity; i++){
        printf("Array index %d, value: %d\n", i, arr->ptr[i]);
    }
}
// Clean up allocated memory
void freeArray(intArray *arr) {
    free(arr->ptr);
}

int main()
{
    intArray array;
    initArray(&array, 5);

    addElement(&array, 0, 10);
    addElement(&array, 2, 5);
    addElement(&array, 4, 2);
    addElement(&array, 3, 1);

    removeElement(&array, 3);

    printArray(&array);

    freeArray(&array);

    return(0);
}