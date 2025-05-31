#ifndef GAME_H
#define GAME_H
#include <string>
#include "Player.h"
#include "Round.h"
#include "ScoreBoard.h"
#include "Store.h"
#include "CardOnHand.h"

class Game {

private:
    Player* player;              // Current player
    Round* currentRound;         // Current round
    ScoreBoard* scoreBoard;      // Score board
    Store* store;                // Game store
    CardOnHand* playerHand;      // Player's hand
    bool isSaved;                // Save state
    std::string saveFileName;    // Save file name
    int currentDifficulty;       // Current difficulty level

public:
    bool isGameActive;           // Game state

    // Constructor
    Game();

    // Game flow methods
    void NewGame();
    void startRound();
    void endRound();
    void displayRoundResults();
    void displayGameSummary();
    
    // Player interaction
    void promptPlayerName();
    void promptDifficultyLevel();
    void displayHandCards();
    void processPlayerChoice(int choice);
    
    // Store interaction
    void openStore();
    void purchaseCard(int cardIndex);
    void useSpecialCard(int cardIndex);
    
    // Game state management
    void save();
    void read();
    void exit();
    
    // Utility methods
    void checkForPairs();
    void updateScore();
    void displayDeckStatus();
    int getRequiredScore();      // Get required score based on difficulty

    ~Game();
};

#endif
