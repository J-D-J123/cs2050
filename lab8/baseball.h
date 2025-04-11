#ifndef _BASEBALL_H
#define _BASEBALL_H

// BaseBallPlayer is a type, but it is top secret
// You don't need to know my implementation.
typedef struct _BaseBallPlayer BaseBallPlayer;
typedef BaseBallPlayer * PBaseBallPlayer;

// Functions in the library you can use
int AtBats(PBaseBallPlayer player);                  // Returns the at-bats for a given player
int PlateAppearances(PBaseBallPlayer player);        // Returns the plate-appearances for a given player
float AVG(PBaseBallPlayer player);                   // Returns the batting average for a given player
float OBP(PBaseBallPlayer player);                   // Returns the on-base percentage for a given player
float SLUG(PBaseBallPlayer player);                  // Returns the slugging percentage for a given player
void PrintBaseBallPlayer(PBaseBallPlayer player);    // Prints out a single player and their stats
void SwapPlayer(PBaseBallPlayer p1, PBaseBallPlayer p2);    // Copies data from p1 to p2 and data p2 to p1 properly
PBaseBallPlayer Next(PBaseBallPlayer player);               // Get a pointer to the next player in the array
PBaseBallPlayer GetSamplePlayers(int * pCount);             // Returns a pointer to the beginning of an array of players (output variable gives count)
#endif
