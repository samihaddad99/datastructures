#include <stdio.h>
#include <stdlib.h>

#define VALSIZE 5

typedef struct node {
    int value;
    struct node* next;
} node;

// initialize linked list (head starts as NULL)
void initLL(node **ll) {
    *ll = NULL;  // Start with an empty list (head is NULL)
}

// add elements to the linked list
void addElems(node **linkedL, int values[], int size) {
    node *current = NULL;

    for (int i = 0; i < size; i++) {
        node *nextNode = malloc(sizeof(node));  // allocate a new node
        nextNode->value = values[i];             // assign the value
        nextNode->next = NULL;                   // set the next pointer to NULL

        if (*linkedL == NULL) {
            // if the list is empty, nextNode becomes the head
            *linkedL = nextNode;
        } else {
            // otherwise, add the node at the end of the list
            current = *linkedL;
            while (current->next != NULL) {
                current = current->next;  // traverse to the last node
            }
            current->next = nextNode;  // link the new node at the end
        }
    }
}

void printLL(node *ll) {
    node *current = ll;  // Start from the head

    while (current != NULL) {
        printf("Value is: %d\n", current->value);
        current = current->next;
    }
}

void freeLL(node *ll) {
    node *current = ll;
    node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    node *linkedL;  // declare pointer to head of the linked list
    initLL(&linkedL);  // initialize the linked list (head should be NULL)

    int values[VALSIZE] = {1, 2, 3, 4, 5};
    addElems(&linkedL, values, VALSIZE);

    printLL(linkedL);

    freeLL(linkedL);

    return 0;
}
