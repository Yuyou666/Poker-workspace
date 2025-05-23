#include <ScoreBoard.h>
#include <iostream>
#include <vector>

using namespace std;

ScoreBoard::ScoreBoard(int roundNum, int targetScore, int rewardCoins) : Round(roundNum, targetScore, rewardCoins) {
    currentTotalScore = 0;
}

void ScoreBoard::addScore(int score) {
    scoreHistory.push_back(score);
    currentTotalScore += score;
}

int ScoreBoard::getTotalScore() const {
    return currentTotalScore;
}

vector<int> ScoreBoard::getHistory() const {
    return scoreHistory;
}

void ScoreBoard::resetScoreBoard() {
    scoreHistory.clear();
    currentTotalScore = 0;
}

void ScoreBoard::printScoreBoard() const {
    cout << "\n--- Score Board ---" << endl;
    cout << "Total Score: " << currentTotalScore << endl;
    cout << "Score History: ";
    for (int score : scoreHistory) {
        cout << score << " ";
    }
    cout << endl;
}
ScoreBoard::~ScoreBoard() {
    // Destructor logic if needed
}