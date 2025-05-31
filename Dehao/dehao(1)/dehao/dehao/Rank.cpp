#include "Rank.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

Rank::Rank() {}

void Rank::addScore(const string& playerName, int score) {
    playerRoundScores[playerName].push_back(score);
}

void Rank::printRankings() {
    cout << "\n--- All Player Rankings ---" << endl;
    for (const auto& entry : playerRoundScores) {
        cout << "Player: " << entry.first << ", Scores: ";
        for (int score : entry.second) {
            cout << score << " ";
        }
        cout << endl;
    }
}

void Rank::sortRankings() {
    for (auto& entry : playerRoundScores) {
        int totalScore = accumulate(entry.second.begin(), entry.second.end(), 0);
        entry.second.push_back(totalScore);
    }
}

Rank::~Rank() {}