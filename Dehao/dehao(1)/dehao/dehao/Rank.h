#ifndef RANK_H
#define RANK_H
#include <string>
#include <vector>
#include <map>
using namespace std;

class Rank {
    private:
        map<string, vector<int>> playerRoundScores;
        
    public:
        Rank();
        void addScore(const string& playerName, int score);
        void sortRankings();
        void printRankings();
        ~Rank();
};

#endif
