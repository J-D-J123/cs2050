#include "lab2.h"
#include <stdlib.h> 

/**
 * Student:     J-D-J123
 * Class:       cs2050
 * File:        lab2.c
 * Date:        2/7/2025
 * Desc:        In this lab, you will cover memory allocation, as well as freeing allocated memory. Remember that when-
 *                  ever you allocate memory, you must always check that it is not NULL. Make sure to pay attention to the
 *                  specified return values. Also, consider that you MUST error-check to make sure any parameters passed
 *                  into your function are valid. For example, will your code respond properly if my test application passes in
 *                  NULL for the first parameter? Finally, this lab is not about “enhanced” or “smart” arrays – notice that the
 *                  size parameter is passed into all of the functions that need it.
 * 
 *                  - int makeArray(int **array, int size)
 *                  - int initArray(int *array, int size)
 *                  - int multiplyOdd(int *array, int size, int multiplicand) 
 */

/**
 * makeArray() method takes pointer array, as well as the size of the new array
 *  it will create a new array with the given size, and place the address of the 
 *  newly created array in the provided pointer. will return 0 if creating the array
 *  was successful or 1 otherwise. 
 * 
 *  - return 0 if successful 
 *  - return 1 otherwise 
 * 
 *  - place the address of the new created array in the provided pointer 
 * @param array - input array 
 * @param size  - size of the new @param array
 */
int makeArray(int **array, int size) {

    // simple NULL fix - only for size becuase **array can be NULL
    if(size <= 0 || array == NULL) {
        return 1; 
    } 

    *array = (int *)malloc(size * sizeof(int));
    if(*array == NULL) {
        return 1; 
    }

    for(int i = 0; i < size; i++) {

        (*array)[i] = i + 1;         
    }

    return 0; 

}

/**
 * The initArray() takes an integer array as well as the size of the array
 *  initalizes each index in the array to 0
 *  --- DOES NOT RETURN ANYTHING (void *)0 ---
 * @param array - the array that is getting changed 
 * @param size  - the size of the @param array 
 */
void initArray(int *array, int size) {
    if (array == NULL || size <= 0) {
        return; 
    }

    for(int i = 0; i < size; i++) {
        array[i] = 0; 
    }
}

/**
 * the multiplyOdd() function takes the integer array as well as size and the 
 *  integer multiplicand which is used for this method 
 * @param array         - array we are going through 
 * @param size          - size of the array 
 * @param multiplicand  - the integer that is multiplied by any element of the array
 *      which is ODD by the value of the multiplicand, stores the result in the same
 *      index in the array. 
 *
 * - Returns the number of elementes which were multiplied 
 * - Note: that 0 is considered to be an even number
 */
int multiplyOdd(int *array, int size, int multiplicand) {

    int count = 0; 

    // array cannot be NULL 
    // size cannot be less than or equal to 0 
    // multiplicand cannot be NULL
    if(array == NULL || size <=0) {
        return count;   
    }

    for(int i = 0; i < size; i++) {
        if(array[i] % 2 != 0) {
            array[i] = array[i] * multiplicand; 
            count++; 
        }
    }

    return count; 
}

/**
 * when you make the array you should always free the array by using freeArray()
 *  to free up the storage and the memory. 
 *  @param array is the pointer to int array pointer, frees all memory allocated to 
 *      that array. after freeing, also sets original pointer to NULL
 */
void freeArray(int **array) {

    // if array input is null free
    if(array != NULL) {
        free(array);
        return; 
    } else {
        // if is NULL do not do anyting just return 
        return; 
    }

} // end of lab2.c
