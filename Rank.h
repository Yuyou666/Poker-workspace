#ifndef RANK_H
#define RANK_H

#include "ScoreBoard.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Rank : public ScoreBoard {
private:
    std::map<std::string, std::vector<int>> playerRoundScores;

public:
    Rank(int roundNum, int targetScore, int rewardCoins);

    void recordScore(const std::string& playerName, int score);
    std::vector<int> getPlayerScores(const std::string& playerName) const;
    void printAllRankings() const;
    void printPlayerRanking(const std::string& playerName) const;

    ~Rank();
};

#endif
