#ifndef TEAM_RECORD
#define TEAM_RECORD

class TeamRecord
{
private:
    int a_wins;
    int a_losses;
public:
    TeamRecord(int wins, int losses);
    TeamRecord();
    int getWins();
    int getLosses();
    void addWin();
    void addLoss();
    void resetVals();
    void printRecord();
};
#endif
