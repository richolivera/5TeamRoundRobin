#include "TeamRecord.hh"
#include <stdio.h>

TeamRecord::TeamRecord(int wins, int losses)
{
    a_wins = wins;
    a_losses = losses;
} 

TeamRecord::TeamRecord()
{
    a_wins = 0;
    a_losses = 0;
} 

int TeamRecord::getWins()
{
    return a_wins;
}

int TeamRecord::getLosses()
{
    return a_losses;
}

void TeamRecord::addWin()
{
    a_wins++;
}

void TeamRecord::addLoss()
{
    a_losses++;
}

void TeamRecord::resetVals()
{
    a_wins = 0;
    a_losses = 0;
}
