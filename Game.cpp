#include "Game.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 构造函数
Game::Game() {
    player = nullptr;
    currentRound = nullptr;
    scoreBoard = nullptr;
    store = nullptr;
    isSaved = false;
    saveFileName = "game_save.txt";
    cout << "Game created." << endl;
}

// 启动新游戏
void Game::NewGame() {
    player = new Player("Player1");
    currentRound = new Round(10);  // Start with 10 reward coins
    scoreBoard = new ScoreBoard();
    store = new Store();
    cout << "Starting new game..." << endl;
}

// 保存游戏进度
void Game::save() {
    if (currentRound && currentRound->getHandCount() == 0) {
        // Save game state
        isSaved = true;
        cout << "Game saved." << endl;
    } else {
        cout << "Cannot save during a round." << endl;
    }
}

// 读取游戏存档
void Game::read() {
    if (isSaved) {
        // Load game state
        cout << "Game loaded." << endl;
    } else {
        cout << "No saved game found." << endl;
    }
}

// 退出游戏
void Game::exit() {
    delete player;
    delete currentRound;
    delete scoreBoard;
    delete store;
    cout << "Exiting game..." << endl;
}

// 析构函数
Game::~Game() {
    exit();
    cout << "Game destroyed." << endl;
}
