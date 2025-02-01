#include <stdio.h> 
#include "lab1.h"

// ERRORS WILL COME IN AS 1 NOT 0

int main(void) {

    int array[] = {-3, -2, -1, 0, 1, 2, 3};
    int size = (sizeof(array)/sizeof(array[0]));

    int result;

    // int medianWorking = getMedian(array, size, &result);
    int medianWorking = sumEven(array, size, &result);

    if(medianWorking == 0) {
        printf("median = %d\n", result);
    } else {
        printf("median failed, try again\n");
    }

    printf("median = %d\n", result);


    // no errors occur in the main so return 0 
    return 0; 
}
