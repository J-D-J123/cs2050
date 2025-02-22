#include <stdio.h>
#include "main.c"

int main() {

    int lengths[5] = {2, 3, 4, 5, 6};
    int rows = 5; 

    void ** jaggedArray = allocate2DArray(sizeof(int), rows, lengths); 

    printf("rows = %d\n", getRowCount(jaggedArray));

    printf("Cols = %d\n", getColCount(jaggedArray, 4));


    free2DArray(jaggedArray); 

    
}
