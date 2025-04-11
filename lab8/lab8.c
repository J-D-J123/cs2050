/**
* Name:         J-D-J123 
* Clas:         cs2050
* Date:         4/04/2025
* File:         lab8.c
* Desc:         Recusion and Makefiles practice, 
*                   mypow(int base, int power)
*                   then printing and sorting the base ball players
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "lab8.h"

/**
* the mpow() function takes a base and raises that base to a power
* then it returns that result.
* The power may not be fractional (Must be an integer)
*/
double mypow(int base, int power)
{
    if(power == 0) {
        return 1; 
    }

    // if power is negative then have it in the demonator divided by 1.0
    if(power < 0) {

        return 1.0 / mypow(base, -power); 
    }

    // else then its postive 
    return base * mypow(base, power - 1); 
}

/**
* the PrintBaseBallPlayers functin takes in a player and 
* the length of the PBaseBallPlayer list then prints out their 
* stats
* Used: 
*   Next(players) // returns the next pointer to the list of the current player
*   PrintBaseBallPlayer(players) // returns the stats of the player
*/
void PrintBaseBallPlayers(PBaseBallPlayer players, int length)
{
    // NULL cases + stop when length is equal to 0 
    if(players == NULL || length <= 0) {
        return; 
    }

    // prints the stats of the player per player 
    PrintBaseBallPlayer(players); 

    // calls the function with the next players pointer 
    PrintBaseBallPlayers(Next(players), length - 1);
}

PBaseBallPlayer FindHighestAvg(PBaseBallPlayer players, int length)
{
    PBaseBallPlayer player = NULL; 

    return player; 
}

void SortBaseBallPlayers(PBaseBallPlayer players, int length)
{
}
