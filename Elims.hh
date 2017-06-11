#ifndef ELIMS_HH
#define ELIMS_HH

#include "TeamRecord.hh"

typedef enum Standings
{
    UNCONSIDERED_OUTCOME,
    FOUR_THREE_TWO_ONE,
    FOUR_THREE_ONE_ONE_ONE,
    FOUR_TWO_TWO_TWO,
    FOUR_TWO_TWO_ONE_ONE,
    THREE_THREE_THREE_ONE,
    THREE_THREE_TWO_TWO,
    THREE_THREE_TWO_ONE_ONE,
    THREE_TWO_TWO_TWO_ONE,
    TWO_TWO_TWO_TWO_TWO
} Standings_t;

class Elims
{
private:
    TeamRecord a_teams[5];
    Standings_t a_standings;
public:
    Elims();
    void runMatches();
    void printResults();
    void analyzeResults();
    void resetElimRecords();
    Standings_t getStandings();
};
#endif
