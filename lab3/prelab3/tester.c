#include "lab3.h"
#include "lab3.c"

int main() {

    Spaceship** fleet = load_fleet("ships.txt");
    if (fleet == NULL) {
        printf("Failed to load fleet.\n");
        return 1;
    }
    printf("Size of Fleet aka Rows: %d\n", *(((int*)fleet) - 1));

    // Print loaded ships -- testing only 
    // for (int i = 0; i < *(((int*)fleet) - 1); i++) { 

    //     // printf("Size of Col: %d\n", *(((int*)fleet[i]) - 1)); 

    // }

    int row = 0; 

    printf("Total Amount of Rows: %d\n", getRowSize(fleet)); 
    printf("Total Amount of Cols: %d on Row #%d\n", getColSize(fleet, row), row); 

    printf("Trying to free Fleet!\n");
    freeJaggedArray(fleet); 
    printf("Fleet was freed!!!\n");

    return 0;
}
