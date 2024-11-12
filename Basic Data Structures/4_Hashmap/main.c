#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char key[50];
    char value[50];
    struct node* next;
} node;

typedef struct  {
    int capacity;
    char *ptr;
} array;

#define RR_Interval 2 // round-robin interval
int rr_ctr = 0; // tracks round-robin cycles

// max = array capacity
// unimplemented
int doRoundRobin(int current, int max){
    return (current + 1 + RR_Interval) % max;
}




node* initLL(node *ll, char* key, char* value){
    ll->next = NULL;
    strcpy(ll->key, key);
    strcpy(ll->value, value);
    return ll;
}

void initArray(array *arr, int capacity){
    arr->capacity = capacity;
    arr->ptr = (int *)malloc(capacity * sizeof(node));
    for(int i = 0; i < capacity; i++){
        arr->ptr[i] = -128;
    }
}

/*
 * addLLElem: adds a new node to the end of the Linked List
 * @param {node} ll - the linked list to be extended
 * @param {char*} key - the key identifier to the value
 * @param {char*} value - the value that is identifiable from the key
 *  
 * addLLElem will create a new linked list node and add it to the end
 *  of the linked list with the key-value pair supplied
*/
char* addLLElem(node *ll, char* key, char* value) {
    node *current = NULL;
    node *nextNode = malloc(sizeof(node));
    nextNode->next = NULL;
    strcpy(nextNode->key, key);
    strcpy(nextNode->value, value);

    if(ll == NULL){ // if linked list is empty
        ll = nextNode;
        return;
    }
    else { // otherwise get to the end
        while(current->next != NULL){ // iterate to the last element
            current = current->next;
        }
        current = nextNode;
        return &current;
    }    
}

/*
 * addArrayElem
 * @param (*array) arr - array to add the element unto
 * @param (char*) key - the key for the key-value pair
 * @param (char*) value - the value for the key
 * 
 * A limited array implementation designed to
 * hash keys, so index is not required as a param in the function
 * the indexing will be handled by this function (if a key already exists, then we stack ontop of that key)
*/
void addArrayElem(array *arr, char* key, char* value){
    int randomIndex = (rand()%(arr->capacity+1))-1;

    if(arr->ptr[randomIndex] == NULL){
        node ll;
        node *newLL = initLL(&ll, &key, &value);

        arr->ptr[randomIndex] = newLL;
        return; // there's no linked list
    }
    else {
        node *current = arr->ptr;
        addLLElem(&current, &key, &value);
    }
    
}

void freeLL(node *ll){
    node *current = ll;
    node *next;

    while(current->next != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

void freeHashMap(array *arr){
    int capacity = arr->capacity;

    for(int i = 0; i < capacity; i++){
        if(arr->ptr[i] == NULL){
            // do nothing
        }
        else {
            node *current = arr->ptr[i];
            freeLL(&current);
        }
    }
    free(arr);
}

/*
 * valuesForKey - prints out the values for a key in the hashmap
 * (array*) arr - array which the data nodes belong to
 * (char*) key - key which the values belong to
*/
void valuesForKey(array *arr, char *key){
    char* values[10];
    int valuesCtr = 0;
    for(int i = 0; i < arr->capacity; i++){
        if(arr->ptr[i] == NULL){
        } // do nothing
        else { // if theres a hit
            node *current = arr->ptr;
            node *next;
            while(arr->ptr[i] != NULL){
                if(strcmp(current->key, key)){
                    strcpy(values[valuesCtr], current->value);
                    valuesCtr++;
                }
            }
        }
    }
    // print out the values
    printf("For key %s. These are the values:\n", key);
    for(int i = 0; i <= valuesCtr; i++){
        printf("index: %d, value: %s\n", i, values[i]);
    }
}

int main(){

    array arr;
    initArray(&arr, 10);

    addArrayElem(&arr, "apple", "red");
    addArrayElem(&arr, "orange", "orange");
    addArrayElem(&arr, "grape", "purple");
    addArrayElem(&arr, "apple", "green");
    
    valuesForKey(&arr, "apple");

    freeHashMap(&arr);
    return 0;
}