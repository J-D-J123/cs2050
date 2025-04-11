/*
 * Lab8 Main
 * Test code for CMP_SC 2050 Lab 8
 * By Jim Ries
 * March 31, 2025
 *
 */
#include <stdio.h>
#include <mucsseg.h>
#include "lab8.h"

int main(void)
{
    printf("**** mypow() tests:\n");
    for (int i=-10;i<11;i++)
    {
        printf("2^%3d=%9.3f\n",i,mypow(2,i));
    }
    printf("-1^-2=%9.3f\n",mypow(-1,-2));
    printf("-1^-1=%9.3f\n",mypow(-1,-1));
    printf("-1^0=%9.3f\n",mypow(-1,0));
    printf("-1^1=%9.3f\n",mypow(-1,1));
    printf("-1^2=%9.3f\n",mypow(-1,2));
    printf("-1^3=%9.3f\n",mypow(-1,3));
    printf("\n\n");


    printf("**** PrintBaseBallPlayers() tests:\n");
    int count;
    PBaseBallPlayer players = GetSamplePlayers(&count);
    PrintBaseBallPlayers(players,count);
    printf("\n\n");


    printf("**** SortBaseBallPlayers() tests:\n");
    SortBaseBallPlayers(players,count);
    PrintBaseBallPlayers(players,count);
    printf("\n\n");

    printf("**** The dreaded boundary condition tests:\n");
    SEGSHIELD(PrintBaseBallPlayers(players,0),0);
    SEGSHIELD(PrintBaseBallPlayers(NULL,999),0);
    SEGSHIELD(SortBaseBallPlayers(NULL,999),0);
    SEGSHIELD(SortBaseBallPlayers(players,0),0);
}
