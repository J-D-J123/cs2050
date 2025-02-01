/**
* Name:     J-D-J123
* Date:     1/23/2024
* File:     preLab0.c
* Desc:     For this prelab you are tasked to implement a function that will be 
*               passed an array of integers; an integer giving
*               the size of the array; and a query integer to be 
*               searched for in the array. The function will return a nonnegative
*               number representing the number of occurrences of integers in the 
*               array that are greater than or equal to the query integer. There 
*               is no prototype specified for the function, so you're free to choose 
*               the name of the function and the order in which the parameters are passed.
*     
*/

#include <stdio.h>

int function(int *numArray, int size, int query); 

int main(void) {


    int numArray[] = {1, 1, 2, 2, 3, 3, 4, 4, 
                    5, 5, 6, 7, 7, 8, 8, 76, 31,
                    9, 9, 10, 10, 0, 1, 100,
                    20, 21, 23, 35, 64, 43, 33};

    int size = sizeof(numArray)/sizeof(numArray[0]); 
    int query = 2; 

    // for testing 
    // printf("%d\n", size);

    int found = function(numArray, size, query);

    if (found>=0) {
        printf("query is: %d, it was found: %d times.\n", query, found); 
    } else {
        printf("query is: %d, and was not found in array\n", query);

        // error return 1
        return 1; 
    }

}

/**
* this function returns the total amount of times it
*   finds the type query in the numArray 
* @param numArray is the name of the array looped through 
* @param size is the size of the numArray
* @param query is a int of what your trying to find
*/
int function(int *numArray, int size, int query) {

    int count = 0;

    for(int i = 0; i < size; i++) {
        if (*(numArray+i) >= query) {
            count++; 
        }
    }

    // return count
    return count;
}
