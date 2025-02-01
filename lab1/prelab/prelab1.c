#include <stdio.h> // dont really need but nice to have


int getArrayInfo(int * array, int n, int * smallest, int * largest) {

    // if n is NULL or less than or equal to 0 return 0 
    if(n <= 0 || array <= 0 || smallest <= 0 || largest <= 0) {

        return 0; 
    }

    // local variables 
    int count = 0;
    int isDistinct = 0;

    *smallest = array[0]; 
    *largest  = array[0];

    // find smallest and largest values in the array 
    for(int i = 0; i < n; i++) {

        if(array[i] < *smallest) {
            *smallest = array[i]; 
        } 

        if(array[i] > *largest) {
            *largest  = array[i];
        }

        // now count the non-duplicate values and then return that int value
        isDistinct = 1; 

        for(int a = 0; a < n; a++) {
            if(i != a && array[i] == array[a]) {

                // change value when finds duplicate value 
                isDistinct = 0; 
                break;
            } 
        }

        // only count if it appears once -- when isDistinct is true (is 1)
        if(isDistinct) {
            count++; 
        }
    }
    
    // printf("smallest: %d, largest: %d\n", *smallest, *largest); 
    return count;
}
