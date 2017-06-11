#include "TeamRecord.hh"
#include "Elims.hh"
#include <iostream> 
#include <stdio.h>

int main(int argc, char* argv[])
{
/*    TeamRecord TeamA(0,0);
    TeamRecord TeamB(0,0);
    printf("TeamA: %d - %d\n", TeamA.getWins(), TeamA.getLosses());
    printf("TeamB: %d - %d\n", TeamB.getWins(), TeamB.getLosses());
    TeamA.addWin();
    TeamA.addWin();
    TeamA.addLoss();
    TeamB.addWin();
    TeamB.addLoss();
    TeamB.addLoss();
    printf("TeamA: %d - %d\n", TeamA.getWins(), TeamA.getLosses());
    printf("TeamB: %d - %d\n", TeamB.getWins(), TeamB.getLosses());
    return 0;*/
 
    int currentStandings;
    int numRuns = 0;
    int numErrors = 0;
    int i = 0;
    int resultArray[13] = {0};    

    Elims currentElimRound;

    std::cout << "enter number of simulated runs:" << std::endl;
    std::cin >> numRuns;
   
    for(i=0; i<numRuns; i++)
    {
        currentElimRound.resetElimRecords();
        currentElimRound.runMatches();
        //currentElimRound.printResults();
        currentElimRound.analyzeResults();
        currentStandings = currentElimRound.getStandings();
        if(currentStandings >= 0 && currentStandings <= 10)
        {
            resultArray[currentStandings]++;
        }
        else 
        {
            printf("error #%d", ++numErrors);
        }
    } 

    //print vals
    printf("4-0; 3-1; 2-2; 1-3; 0-4 \t = \t%d runs\t%f%%\n", 
        resultArray[FOUR_THREE_TWO_ONE],
        (float)resultArray[FOUR_THREE_TWO_ONE]*100/numRuns);
    printf("4-0; 3-1; 1-3; 1-3; 1-3 \t = \t%d runs\t%f%%\n", 
        resultArray[FOUR_THREE_ONE_ONE_ONE],
        (float)resultArray[FOUR_THREE_ONE_ONE_ONE]*100/numRuns);
    printf("4-0; 2-2; 2-2; 2-2; 0-4 \t = \t%d runs\t%f%%\n", 
        resultArray[FOUR_TWO_TWO_TWO],
        (float)resultArray[FOUR_TWO_TWO_TWO]*100/numRuns);
    printf("4-0; 2-2; 2-2; 1-3; 1-3 \t = \t%d runs\t%f%%\n", 
        resultArray[FOUR_TWO_TWO_ONE_ONE],
        (float)resultArray[FOUR_TWO_TWO_ONE_ONE]*100/numRuns);
    printf("3-1; 3-1; 3-1; 1-3; 0-4 \t = \t%d runs\t%f%%\n", 
        resultArray[THREE_THREE_THREE_ONE],
        (float)resultArray[THREE_THREE_THREE_ONE]*100/numRuns);
    printf("3-1; 3-1; 2-2; 2-2; 0-4 \t = \t%d runs\t%f%%\n", 
        resultArray[THREE_THREE_TWO_TWO],
        (float)resultArray[THREE_THREE_TWO_TWO]*100/numRuns);
    printf("3-1; 3-1; 2-2; 1-3; 1-3 \t = \t%d runs\t%f%%\n", 
        resultArray[THREE_THREE_TWO_ONE_ONE],
        (float)resultArray[THREE_THREE_TWO_ONE_ONE]*100/numRuns);
    printf("3-1; 2-2; 2-2; 2-2; 1-3 \t = \t%d runs\t%f%%\n", 
        resultArray[THREE_TWO_TWO_TWO_ONE],
        (float)resultArray[THREE_TWO_TWO_TWO_ONE]*100/numRuns);
    printf("2-2; 2-2; 2-2; 2-2; 2-2 \t = \t%d runs\t%f%%\n", 
        resultArray[TWO_TWO_TWO_TWO_TWO],
        (float)resultArray[TWO_TWO_TWO_TWO_TWO]*100/numRuns);
    printf("Unexpected Outcomes     \t = \t%d runs\t%f%%\n", 
        resultArray[UNCONSIDERED_OUTCOME],
        (float)resultArray[UNCONSIDERED_OUTCOME]*100/numRuns);


    printf("Odds you will need a tiebraker \t%f%%\n", 
        (float)(resultArray[FOUR_TWO_TWO_TWO] +
         resultArray[FOUR_TWO_TWO_ONE_ONE] + 
         resultArray[THREE_THREE_THREE_ONE] + 
         resultArray[THREE_TWO_TWO_TWO_ONE] + 
         resultArray[TWO_TWO_TWO_TWO_TWO])*100/numRuns);

    return 0;
}
