#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Elims.hh"

bool compare_gt(const int first, const int second)
{
    return(first > second);
}

Elims::Elims()
{
    resetElimRecords();
    srand(time(NULL));
}

void Elims::resetElimRecords()
{
    int i = 0;
    for(i = 0; i<5; i++ )
    {
        a_teams[i].resetVals();
    }   
    a_standings = UNCONSIDERED_OUTCOME;
}

void Elims::runMatches()
{
    int i = 0;
    int j = 0;
    int matchOutcome = 0;
    //seed the random number generator
    //srand(time(NULL));

    resetElimRecords();
    //two nested loops to run each team against all others
    for(i = 0; i<4; i++)
    {
        for(j = i+1; j<5; j++)
        {
            matchOutcome = rand() % 2; 
            if( matchOutcome == 0)
            {
                a_teams[i].addWin();
                a_teams[j].addLoss();
            } 
            else
            {
                a_teams[i].addLoss();
                a_teams[j].addWin();
            } 
        }
    }
}

void Elims::printResults()
{
     printf("TeamA: %d - %d\n", a_teams[0].getWins(), a_teams[0].getLosses());
     printf("TeamB: %d - %d\n", a_teams[1].getWins(), a_teams[1].getLosses());
     printf("TeamC: %d - %d\n", a_teams[2].getWins(), a_teams[2].getLosses());
     printf("TeamD: %d - %d\n", a_teams[3].getWins(), a_teams[3].getLosses());
     printf("TeamE: %d - %d\n", a_teams[4].getWins(), a_teams[4].getLosses());
}

void Elims::analyzeResults()
{
    int i = 0;
    int numFours = 0;
    int numThrees = 0;
    int numTwos = 0;
    int numOnes = 0;
    int numZeros = 0;
    int temp = 0;
    //populate list with wins
    for(i = 0; i<5; i++)
    {
        temp =  a_teams[i].getWins();
        switch(temp)
        {
            case 4:
                numFours++;
                break;
            case 3:
                numThrees++;
                break;
            case 2:
                numTwos++;
                break;
            case 1:
                numOnes++;
                break;
            case 0:
                numZeros++;
                break;
            default:
                printf("impossible win count!!\n");
                break;
        }
    }
    //determine standings
    if(numFours==1 && numThrees == 1 && numTwos == 1 && numOnes == 1 && 
        numZeros ==1)
    {
        a_standings = FOUR_THREE_TWO_ONE;
    } 
    else if(numFours==1 && numThrees == 1 && numTwos == 0 && numOnes == 3 && 
        numZeros ==0)
    {
        a_standings = FOUR_THREE_ONE_ONE_ONE;
    } 
    else if(numFours==1 && numThrees == 0 && numTwos == 3 && numOnes == 0 && 
        numZeros ==1)
    {
        a_standings = FOUR_TWO_TWO_TWO;
    } 
    else if(numFours==1 && numThrees == 0 && numTwos == 2 && numOnes == 2 && 
        numZeros ==0)
    {
        a_standings = FOUR_TWO_TWO_ONE_ONE;
    } 
    else if(numFours==0 && numThrees == 3 && numTwos == 0 && numOnes == 1 && 
        numZeros ==1)
    {
        a_standings = THREE_THREE_THREE_ONE;
    } 
    else if(numFours==0 && numThrees == 2 && numTwos == 2 && numOnes == 0 && 
        numZeros ==1)
    {
        a_standings = THREE_THREE_TWO_TWO;
    } 
    else if(numFours==0 && numThrees == 2 && numTwos == 1 && numOnes == 2 && 
        numZeros ==0)
    {
        a_standings = THREE_THREE_TWO_ONE_ONE;
    } 
    else if(numFours==0 && numThrees == 1 && numTwos == 3 && numOnes == 1 && 
        numZeros ==0)
    {
        a_standings = THREE_TWO_TWO_TWO_ONE;
    } 
    else if(numFours==0 && numThrees == 0 && numTwos == 5 && numOnes == 0 && 
        numZeros ==0)
    {
        a_standings = TWO_TWO_TWO_TWO_TWO;
    } 
    else
    {
        a_standings = UNCONSIDERED_OUTCOME;
    }
}

Standings_t Elims::getStandings()
{
    return a_standings;
}
