#include "Player.h"
#include "Deck.h"
#include "Round.h"
#include "Store.h"
#include "Score.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Player::Player(string name) {
    this->name = name;
    this->coins = 0;
    this->totalRoundCount = 0;
    this->mydeck = new Deck();
}
void Player::playGame() {
    cout << "Playing game..." << endl;
    // Game logic goes here
}
//The player have three level can be choose easy, medium, hard
void Player::printPlayerInfo() {
    cout << "Player Name: " << name << endl;
    cout << "Coins: " << coins << endl;
    cout << "Challenge Level: " << challengeLevel << endl;
    cout << "Total Round Count: " << totalRoundCount << endl;
}
void Player::set_coins(int newCoins) {
    coins = newCoins;
}
void Player::set_totalRoundCount(int newTotalRoundCount) {
    totalRoundCount = newTotalRoundCount;
}
string Player::get_name() {
    return name;
}
int Player::get_coins() {
    return coins;
}
int Player::get_totalRoundCount() {
    return totalRoundCount;
}
void Player::set_challengeLevel(string newChallengeLevel) {
    challengeLevel = newChallengeLevel;
}
string Player::get_challengeLevel() {
    return challengeLevel;
}
void Player::set_mydeck(Deck *newDeck) {
    mydeck = newDeck;
}
Deck* Player::get_mydeck() {
    return mydeck;
}
Player::~Player() {
    delete mydeck;
}

