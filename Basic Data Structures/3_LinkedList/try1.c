#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char p_h;
    int start_adr;
    int end_adr;
    char *next_ptr;
} linked_list;

traverse_linked_list(linked_list *ll){
    linked_list *ptr = ll;
    int elem = 0;
    do{
        if(ptr == NULL){
            printf("End of Linked List\n");
            return 1;
        }
        else{
            char p_h = ptr->p_h;
            int start_adr = ptr->start_adr;
            int end_adr = ptr->end_adr;
            char *nextPtr = ptr->next_ptr;
            ptr = ptr->next_ptr; // set ptr to next
            printf("elem: %d start_adr: %d end_adr: %d\n",elem, start_adr, end_adr);
            elem++;
        }
    } while(ptr != NULL);
}

int main() {
    
    linked_list lm1 = {
        p_h:'p',
        start_adr:1,
        end_adr:5,
        next_ptr:NULL
    };

    linked_list lm2 = {
        p_h:'h',
        start_adr:5,
        end_adr:8,
        next_ptr:&lm1
    };
    char *ptr = &lm2;
    traverse_linked_list(ptr);
    
    return 0;
}