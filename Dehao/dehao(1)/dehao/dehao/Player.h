#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "CardOnHand.h"
#include "Deck.h"
#include "Round.h"
#include "Score.h"
#include <vector>
using namespace std;

class Player {
    private:
        string name;
        int coins;
        string challengeLevel;  // "Easy", "Medium", "Difficult"
        int totalRoundCount;
        Deck *mydeck;
        vector<Card*> specialCards;  // Store purchased special cards
        int currentScore;
        int highScore;
        
    public:
        Player(string name);
        void playGame();
        void printPlayerInfo();
        void set_coins(int newCoins);
        void set_totalRoundCount(int newTotalRoundCount);
        string get_name();
        int get_coins();
        int get_totalRoundCount();
        void set_challengeLevel(string newChallengeLevel);
        string get_challengeLevel();
        void set_mydeck(Deck *newDeck);
        Deck* get_mydeck();
        
        // New methods for special cards management
        void addSpecialCard(Card* card);
        void removeSpecialCard(int index);
        void useSpecialCard(int index);
        vector<Card*> getSpecialCards();
        
        // Score management
        void updateScore(int points);
        int getCurrentScore();
        int getHighScore();
        void setCurrentScore(int score);
        void setHighScore(int score);
        
        // Game state
        void startNewRound();
        void endRound();
        bool checkWinCondition();
        ~Player();  // Add destructor
};
#endif // PLAYER_H