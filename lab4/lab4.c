#include <stdio.h>
#include <stdlib.h>

void ** allocate2DArray(int elementSize, int rows, int Lenghts[]) {

    // basic NULL test cases 
    if(elementSize <= 0 || rows <= 0 || Lenghts == NULL) {

        return NULL; 
    }

    // create the jagged array first of rows then fill in the rows with data
    void ** jaggedArray = malloc(rows * sizeof(void *) + sizeof(int)); 

    // store the size of rows 
    *(int*)jaggedArray = rows; 

    // increase the pointer
    jaggedArray = (void**)(((int*)jaggedArray) + 1); 

    // loop through the rows and make data for each row 
    for(int i = 0; i < rows; i++) {

        // make a new row for the pointer to point too 
        void * row = malloc(Lenghts[i] * elementSize + sizeof(int)); 

        // store size 
        *((int*)row) = Lenghts[i]; 

        // increase ptr
        row = ((int*)row) +1;  

        jaggedArray[i] = row; 
    }

    return jaggedArray; 
}


/**
* get size of rows 
*/
int getRowCount(void ** jaggedArray) {

    if (jaggedArray == NULL) {

        return 1; 
    }

    return *(((int*)jaggedArray) - 1);
}

/*
* get total number of Colums per row 
*/
int getColCount(void ** jaggedArray, int row) {

    if(jaggedArray == NULL || row < 0) {
        return 1; 
    }

    return *(((int*)jaggedArray[row]) - 1); 
}

/**
* free the jagged array 
*/
void free2DArray(void ** jaggedArray) {

    if(jaggedArray == NULL) {
        return; 
    }

    // get each row and free it then free the main pointer 
    for(int i = 0; i < *(((int*)jaggedArray) - 1 ); i++) {

        free(((int*)jaggedArray[i]) - 1);
    } 

    // free the main pointer too it as well
    free(((int*)jaggedArray) - 1); 
} // end of lab4.c
