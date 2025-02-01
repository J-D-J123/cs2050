#include "lab1.h"
/**
* Student:      (J-D-J123 on GitHub 🙏 (we praying on this one))
* Class:        cs2050 
* File:         lab1.c
* Date:         1/31/2025
* Desc:         In this lab, you will cover pass by reference and using error codes. Each function has an associated error
*                   code, and one or more possible error conditions. You should consider when errors might occur that make
*                   completion of your function’s goal impossible and return the specified error code when they occur.
*                   Consider that parameters passed into your functions may be wrong or illegal (what if I pass in NULL) –
*                   you should respond properly to these situations. 
*
*                   - int getMedian(int array[], int size, int *result)
*                   - int sumNegative(int array[], int size, int *result)
*                   - int sumEven(int array[], int size, int *result)
*/

/**
* The getMedian function checks to see if the
*
*/
int getMedian(int array[], int size, int *result) {

    // check for NULL values 
    if(array <= 0 || size <= 0 || result <= 0) {return 1;}
    

    // make getMedian
    for(int i = 0; i < size-1; i++) {
        // printf("In median - going through array\n"); 
        // printf("checking array[%d]=%d to %d\n", i, array[i], *result); 
        if(i == (size)/2 ) {

            // printf("storing *result\n");
            // printf("doint %d + %d = %d / 2\n", array[i], array[i+1], array[i] + array[i+1]);

            *result = (array[i] + array[i+1]) / 2; 
            break; 
        }
    }
    return 0;  
}

/**
*
*
*/
int sumNegative(int array[], int size, int *result) {

    // check for NULL values 
    if(array <= 0 || size <= 0 || result <= 0) {return 1;}

    int count = 0; 

    for(int i = 0; i < size; i++) {

        if(array[i] < 0) {
            *result += array[i];
            count++; 
        }
    }
    if (count > 0) {
        return 0;
    } else {
        return 1; 
    }
}

int sumEven(int array[], int size, int *result) {

    // check for NULL values 
    if(array <= 0 || size <= 0 || result <= 0) {return 1;}

    int count = 0; 
    int sum = 0;

    for(int i = 0; i < size; i++) {

        if(array[i] % 2 == 0) {
            sum += array[i];
            count++; 
        }
    }
    *result = sum; 

        if (count > 0) {
            return 0;
        } else {
            return 1; 
        }
}
