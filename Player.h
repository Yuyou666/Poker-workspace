#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "CardOnHand.h"
#include "Deck.h"
#include "Round.h"
#include "Score.h"
using namespace std;
class Player {
    private:
        string name;
        int coins;
        string challengeLevel;
        int totalRoundCount;
        Deck *mydeck;
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
        
};
#endif // PLAYER_H