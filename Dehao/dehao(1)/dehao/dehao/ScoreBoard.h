#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <vector>
#include <iostream>

class ScoreBoard {
private:
    std::vector<int> scoreHistory;
    int currentTotalScore;

public:
    ScoreBoard();

    void addScore(int score);                       // 添加一轮得分
    int getTotalScore() const;                      // 获取总得分
    std::vector<int> getHistory() const;            // 获取历史得分列表
    void resetScoreBoard();                         // 重置得分（用于新局）
    void printScoreBoard() const;                   // 打印所有得分记录

    ~ScoreBoard();
};

#endif
