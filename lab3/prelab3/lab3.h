#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define NUMBER_OF_SHIPS 5

typedef struct {

    char type; 
    char name[50]; // gives it more of a personality 
    char lastName[50]; // idk why i added a lastName
    float speed; // Speed in light - years per hour
} Spaceship; 
