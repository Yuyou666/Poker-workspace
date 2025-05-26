#ifndef ROUND_H
#define ROUND_H
#include "Deck.h"
#include <iostream>
using namespace std;

class Round {
    private:
        int rewardcoins;
        int handCount;
        int discardsCount;
        
    public:
        Round(int rewardCoins);
        void play(Deck* deck);
        void printStatus();
        int calculateReward();
        int getHandCount();
        int getDiscardCount();
        ~Round();
};

#endif