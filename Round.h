#ifndef ROUND_H
#define ROUND_H
#include <iostream>
#include "CardOnHand.h"
#include "Deck.h"
#include "Score.h"

using namespace std;
class Round  {
    private:
        int roundNum;
        int targetScore;
        int rewardcoins;
        int handCount;//4
        int discardsCount;//3
    public:
        Round(int roundNum, int targetScore, int rewardCoins);
        void playRound(Deck *deck);
        void printRoundInfo();
        int get_roundNum();
        int get_targetScore();
        int get_totalRewardCoins();//basic reward coins + last hand
        int get_handCount();
        int get_discardsCount();
        ~Round();     
};
#endif // ROUND_H