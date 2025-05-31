#include "Round.h"
#include <iostream>
using namespace std;

Round::Round(int rewardCoins) {
    this->rewardcoins = rewardCoins;
    this->handCount = 5;
    this->discardsCount = 3;
    this->score = 0;  // We'll use this to track coins earned
}

void Round::play(Deck* deck) {
    while (handCount > 0) {
        cout << "\n=== Current Status ===" << endl;
        cout << "Remaining hands: " << handCount << ", Discards left: " << discardsCount << endl;
        cout << "Coins earned this round: " << score << endl;
        cout << "Cards in hand:" << endl;
        deck->displayCards();
        
        cout << "\nDraw a card? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y') {
            Card* drawn = deck->drawTop();
            if (drawn) {
                cout << "Drawn card: ";
                drawn->print_card();
                cout << "Keep or discard? (k/d): ";
                cin >> choice;
                if (choice == 'k') {
                    score += 1;  // Add 1 coin for playing a card
                    delete drawn;
                } else if (choice == 'd' && discardsCount > 0) {
                    score += 1;  // Add 1 coin for playing a card
                    discardsCount--;
                    delete drawn;
                }
            }
        }

        handCount--;
    }
}

void Round::printStatus() {
    cout << "Base Reward Coins: " << rewardcoins << endl;
    cout << "Hands Left: " << handCount << ", Discards Left: " << discardsCount << endl;
}

int Round::calculateReward() {
    return rewardcoins + (handCount * 2); 
}

int Round::getHandCount() {
    return handCount;
}

int Round::getDiscardCount() {
    return discardsCount;
}

int Round::calculateScore() {
    // Return the total coins earned
    return score;
}

Round::~Round() {}
