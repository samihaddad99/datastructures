#include <stdio.h>

#define UNALLOC -128 // unallocation value
#define FALSE 0
#define TRUE 1

typedef struct{
   int size;
   int capacity;
   char* ptr; 
} set;


void initSet(set *set, int capacity){
    set->size = 0;
    set->capacity = capacity;
    set->ptr = (int *)malloc(sizeof(int) * capacity);
    for(int i = 0; i<capacity;i++){
        set->ptr[i] = UNALLOC;
    }
}

// false = not a duplicate value = 0
// true = duplicate value = 1
// it's important to check dupes within (current) size, because the unallocated values will be duplicates
int checkDupes(set *set, int value){
    for(int i = 0; i < set->size; i++){
        if(set->ptr[i] == value)
            return TRUE;
    }
    return FALSE;
}

// add element at the first available free space (size)
//   and increment the size by 1
//   must also check that the element is not duplicated
void addElem(set *set, int value){
    if(set->size >= set->capacity){
        printf("Set is full\n");
        return;
    }
    if(checkDupes(set, value)){
        printf("The value %d already exists in the set. No duplicates are allowed.\n", value);
        return;
    }
    set->ptr[set->size] = value;
    set->size++;
}

void remElem(set *set){
    if(set->size <= 0){
        printf("There are no elements to remove\n");
    }
    set->ptr[set->size-1] = UNALLOC; // index is size-1
    set->size--;
    return;
}

void printSet(set *set){
    for(int i = 0; i < set->size; i++){
        int elem = set->ptr[i];
        printf("Element at index: %d, value: %d\n", i, elem);
    }
    return;
}

void freeSet(set *set){
    free(set->ptr);
}

int main(){

    set mySet;
    initSet(&mySet, 5);

    addElem(&mySet, 1);
    addElem(&mySet, 2);
    addElem(&mySet, 3);
    addElem(&mySet, 4);

    remElem(&mySet);

    printSet(&mySet);

    return 0;
}