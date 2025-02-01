/**
* Name:     (J-D-J123 on github)
* Class:    cs2050
* Date:     1/24/2025 
* File:     main.c
* Desc:     testing file for lab0.c 
*
* WARNING:  this lab0.c is to only test the ability of submiting and using 
*               hellbender, this will allow for diff cases to be compared
*               such as doubles, chars, floats, and even longs. 
*               --- THIS MIGHT CRASH THE PROGRAM ---
*/

#include <stdio.h> 
#include "lab0.h"

int main(void) {

    int intArray[] = {1, 1, 2, 2, 3, 3, 4, 4, 
                    5, 5, 6, 7, 7, 8, 8, 76, 31,
                    9, 9, 10, 10, 0, 1, 100,
                    20, 21, 23, 35, 64, 43, 33};


    int size = (sizeof(intArray)/sizeof(intArray[0])); 
    printf("size %d\n", size);

    int query = 2; // number to search for (change this to your liking)

    int occurrences = countOccurrences(size, intArray, query);

    printf("occurrences = %d\n", occurrences);

    occurrences = countOccurrences(size, NULL, query);

    printf("occurrences = %d\n", occurrences);

} // end of main.c
