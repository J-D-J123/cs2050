// practice 
// Author:    J-D-J123
// Date:      2/23/2025

// #include "lab3.h"

Spaceship** load_fleet(const char* filename) {

    // basic NULL test cases 
    if(filename == NULL) {
        return (Spaceship**)NULL;
    }

    int lengths[NUMBER_OF_SHIPS] = {0}; 

    // read file using file pointer 
    FILE * fp; 
    fp = fopen(filename, "r"); 

    if(fp == NULL) {

        return NULL; 
    }

    // read the top line    
    fscanf(fp, "%d %d %d %d %d", &lengths[0], &lengths[1], &lengths[2], &lengths[3], &lengths[4]);

    // testing ONLY
    // for(int i = 0; i < NUMBER_OF_SHIPS; i++) {
    //     printf("[%d] ", lengths[i]);
    // }
    // printf("\n");

    // allocate enough storage to point to the rows 
    // amountOfShips * sizeof(Spaceship) + sizeof(int) 
    Spaceship ** ships = malloc(NUMBER_OF_SHIPS*sizeof(Spaceship*) + sizeof(int));

    // store the total size of the array 
    *(int*)ships = NUMBER_OF_SHIPS;

    // plus plus the pointer 
    ships = (Spaceship**)(((int*)ships) + 1); 

    // make the rows now point to another set of rows 
    for(int i = 0; i < NUMBER_OF_SHIPS; i ++) {

        // testing ONLY
        // printf("%d * %d + %d\n", lengths[i], sizeof(Spaceship), sizeof(int)); 

        Spaceship * rows = malloc(lengths[i] * sizeof(Spaceship) + sizeof(int));    
        *(int*)rows = lengths[i]; 
        rows = (Spaceship*)(((int*)rows) + 1); 

        // re do the code so that each row is E C M D V in that order 
        for(int j = 0; j < lengths[i]; j++) {

            // read names first name and last as well as type and speed from file
            fscanf(fp, "%49s %49s %c %f", rows[j].name, rows[j].lastName, &rows[j].type, &rows[j].speed);

        }

        ships[i] = rows; 
    }
    fclose(fp); 
    return ships; 
}

void freeJaggedArray(Spaceship ** ships) {

    if(ships == NULL) {
        return; 
    }

    int size = *(((int*)ships) - 1); 

    for(int i = 0; i < size; i++) {

        if(ships[i] != NULL) {
            // free each row 
            free(((int*)ships[i]) - 1);
        } 
    }

    // now free the main pointer 
    free(((int*)ships) - 1); 
}

int getRowSize(Spaceship ** ships) {

    if(ships == NULL) {

        return 1; 
    }

    return *(((int*)ships) - 1);

}

int getColSize(Spaceship ** ships, int row) {

    if(ships == NULL) {

        return 1; 
    }

    return *(((int*)ships[row]) - 1);
}
