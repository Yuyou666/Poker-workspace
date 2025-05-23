#include <Rank.h>
#include <iostream>
#include <algorithm>

using namespace std;

Rank::Rank(int roundNum, int targetScore, int rewardCoins)
    : ScoreBoard(roundNum, targetScore, rewardCoins) {}

void Rank::recordScore(const string& playerName, int score) {
    playerRoundScores[playerName].push_back(score);
}

vector<int> Rank::getPlayerScores(const string& playerName) const {
    auto it = playerRoundScores.find(playerName);
    if (it != playerRoundScores.end()) {
        return it->second;
    }
    return {};
}

void Rank::printAllRankings() const {
    cout << "\n--- All Player Rankings ---" << endl;
    for (const auto& entry : playerRoundScores) {
        cout << "Player: " << entry.first << ", Scores: ";
        for (int score : entry.second) {
            cout << score << " ";
        }
        cout << endl;
    }
}

//Print the scores of all players in all rounds and the total score
void Rank::printPlayerRanking(const string& playerName) const {
    auto it = playerRoundScores.find(playerName);
    if (it != playerRoundScores.end()) {
        cout << "Player: " << playerName << ", Scores: ";
        for (int score : it->second) {
            cout << score << " ";
        }
        cout << endl;
    } else {
        cout << "No scores found for player: " << playerName << endl;
    }
}

//sort them in descending order of the total score
void Rank::sortRankings() {
    vector<pair<string, int>> totalScores;
    for (const auto& entry : playerRoundScores) {
        int totalScore = accumulate(entry.second.begin(), entry.second.end(), 0);
        totalScores.push_back(make_pair(entry.first, totalScore));
    }
    sort(totalScores.begin(), totalScores.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    
    cout << "\n--- Sorted Rankings ---" << endl;
    for (const auto& entry : totalScores) {
        cout << "Player: " << entry.first << ", Total Score: " << entry.second << endl;
    }
}
Rank::~Rank() {}