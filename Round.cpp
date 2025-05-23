#include "Round.h"
using namespace std;

Round::Round(int roundNum, int targetScore, int rewardCoins) {
    this->roundNum = roundNum;
    this->targetScore = targetScore;
    this->rewardCoins = rewardCoins;
    this->handCount = 4;
    this->discardCount = 3;
}

void Round::playRound(Deck* deck) {
    cout << "\n[ Round " << roundNum << " Start ]" << endl;
    while (handCount > 0) {
        cout << "Remaining hands: " << handCount << ", Discards left: " << discardCount << endl;

        // 模拟抽一张卡并显示
        Card* drawn = deck->drawTop();
        if (!drawn) {
            cout << "Deck is empty!" << endl;
            break;
        }

        cout << "You drew: ";
        drawn->print_card();

        cout << "Keep or discard? (k/d): ";
        char choice;
        cin >> choice;

        if (choice == 'd' && discardCount > 0) {
            discardCount--;
            cout << "Card discarded.\n";
        } else {
            cout << "Card kept (or no discards left).\n";

        }
        handCount--;
    }

    cout << "[ Round " << roundNum << " End ]\n";
}

void Round::printRoundInfo() {
    cout << "\n--- Round Info ---" << endl;
    cout << "Round: " << roundNum << endl;
    cout << "Target Score: " << targetScore << endl;
    cout << "Base Reward Coins: " << rewardCoins << endl;
    cout << "Hands Left: " << handCount << ", Discards Left: " << discardCount << endl;
}

int Round::get_roundNum() {
    return roundNum;
}

int Round::get_targetScore() {
    return targetScore;
}

int Round::get_totalRewardCoins() {
    return rewardCoins + (handCount * 2); 
    // 假设每次保留一张卡牌可以获得2个奖励金币

}

int Round::get_handCount() {
    return handCount;
}

int Round::get_discardsCount() {
    return discardCount;
}

Round::~Round() {
    // Destructor implementation (if needed)
    cout << "Round " << roundNum << " destroyed." << endl;
}
