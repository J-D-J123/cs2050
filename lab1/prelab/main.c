#include "prelab.h"

int main(void) {

    int smallest = 0; 
    int largest  = 0; 

    int array[] = {0, 1, 6, 6, 6, 7, 8, 9, 7, 0, 0 ,0 ,100000, 100, 10, -100, 0, 4, 76, 29, 19, 90000};

    int size = (sizeof(array)/sizeof(array[0]));

    int info = getArrayInfo(array, size, &smallest, &largest);

    printf("non-dupliate Values: = %d, smallest: %d largest: %d\n", info, smallest, largest);

    // no error so return 0 
    return 0; 
}
