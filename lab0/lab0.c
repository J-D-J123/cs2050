/**
* Name:     (J-D-J123 on github)
* Class:    cs2050
* Date:     1/24/2025
* File:     prelab-1.c
* Desc:     in this lab you will cover the basics of 
*               getting started (submit code, and interact)
*               using header files, as well as  implement 
*               countOcurrences(int size, int array[], int query) method
*
* WARNING:  this lab0.c is to only test the ability of submiting and using 
*               hellbender, this will allow for diff cases to be compared
*               such as doubles, chars, floats, and even longs. 
*               --- THIS MIGHT CRASH THE PROGRAM ---
*/

#include "lab0.h"
#include <stdio.h>

/**
* the countOccurrences() method
*   counts how many times the number happens to be in the array
* @param size is the size of the array
* @param array is the array we are searching for the query 
* @param query is the number we are looking for in the array
*/
int countOccurrences(int size, int array[], int query) {

    int counter = 0;

    if(sizeof(array) == sizeof(NULL)) {
        printf("Input is NULL, no array, returning 0\n");
        return counter;
    }

    for(int i = 0; i < size; i++) {
        if(array[i] == query) {
            counter++; 
        }
    }
    return counter; 
} // end of lab0.c
