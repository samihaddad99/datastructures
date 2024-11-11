#include <stdio.h>
#define NUMBER_ARR_SIZE 3
int main()
{
    char str[] = "hello there";

    int nums[4] = {4,5,6};

    for(int i = 0; i < NUMBER_ARR_SIZE; i++){
        printf("index: %d, value: %d\n", i, nums[i]);
    }
    

    return(0);
}