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
    coins = 0;
    challengeLevel = "Easy";
    totalRoundCount = 0;
    currentScore = 0;
    highScore = 0;
    mydeck = new Deck();
}

void Player::playGame() {
    // Game logic will be handled by Game class
}

void Player::printPlayerInfo() {
    cout << "\nPlayer Information:" << endl;
    cout << "Name: " << name << endl;
    cout << "Coins: " << coins << endl;
    cout << "Current Score: " << currentScore << endl;
    cout << "High Score: " << highScore << endl;
    cout << "Difficulty Level: " << challengeLevel << endl;
}

void Player::addSpecialCard(Card* card) {
    specialCards.push_back(card);
}

void Player::removeSpecialCard(int index) {
    if (index >= 0 && index < static_cast<int>(specialCards.size())) {
        specialCards[index] = nullptr;
        specialCards.erase(specialCards.begin() + index);
    }
}

void Player::useSpecialCard(int index) {
    if (index < 0 || index >= static_cast<int>(specialCards.size())) {
        throw std::out_of_range("Invalid special card index");
    }
    Card* card = specialCards[index];
    // Apply special card effects
    if (card->get_cardType() == "bonus") {
        currentScore += card->get_bonusPoint();
    } else if (card->get_cardType() == "mult") {
        currentScore *= card->get_mult();
    }
    // Remove the used card
    removeSpecialCard(index);
}

vector<Card*> Player::getSpecialCards() {
    return specialCards;
}

void Player::updateScore(int points) {
    currentScore += points;
    if (currentScore > highScore) {
        highScore = currentScore;
    }
}

int Player::getCurrentScore() {
    return currentScore;
}

int Player::getHighScore() {
    return highScore;
}

void Player::setCurrentScore(int score) {
    currentScore = score;
}

void Player::setHighScore(int score) {
    highScore = score;
}

void Player::startNewRound() {
    totalRoundCount++;
    currentScore = 0;
}

void Player::endRound() {
    // Add bonus coins based on performance
    int bonusCoins = currentScore / 10;
    coins += bonusCoins;
}

bool Player::checkWinCondition() {
    // Check if player has met the win condition based on challenge level
    int requiredScore = 0;
    if (challengeLevel == "Easy") {
        requiredScore = 100;
    } else if (challengeLevel == "Medium") {
        requiredScore = 200;
    } else if (challengeLevel == "Difficult") {
        requiredScore = 300;
    }
    return currentScore >= requiredScore;
}

// Getters and setters
void Player::set_coins(int newCoins) { coins = newCoins; }
void Player::set_totalRoundCount(int newTotalRoundCount) { totalRoundCount = newTotalRoundCount; }
string Player::get_name() { return name; }
int Player::get_coins() { return coins; }
int Player::get_totalRoundCount() { return totalRoundCount; }
void Player::set_challengeLevel(string newChallengeLevel) { challengeLevel = newChallengeLevel; }
string Player::get_challengeLevel() { return challengeLevel; }
void Player::set_mydeck(Deck *newDeck) { mydeck = newDeck; }
Deck* Player::get_mydeck() { return mydeck; }

Player::~Player() {
    cout << "Player destructor starting..." << endl;
    
    // Clean up special cards first
    cout << "Cleaning up special cards..." << endl;
    for (Card* card : specialCards) {
        if (card) {
            cout << "Deleting special card..." << endl;
            delete card;
        }
    }
    specialCards.clear();
    
    // Clean up deck last since it owns the cards
    cout << "Cleaning up deck..." << endl;
    if (mydeck) {
        delete mydeck;
        mydeck = nullptr;
    }
    
    cout << "Player destructor complete." << endl;
}

