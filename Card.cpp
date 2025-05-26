// Card.cpp: Implements the Card class, representing a single playing card and its properties.
#include "Card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Card::Card() {
    // Random card constructor
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string suits[] = {"hearts", "diamonds", "clubs", "spades"};
    
    rank = ranks[rand() % 13];
    suit = suits[rand() % 4];
    cardType = "normal";
    bonusPoint = 0;
    mult = 1;
    chips = 0;
}

Card::Card(string rank, string suit) {
    this->rank = rank;
    this->suit = suit;
    this->cardType = "normal";
    this->bonusPoint = 0;
    this->mult = 1;
    this->chips = 0;
}

Card::Card(string rank, string suit, string cardType, int bonusPoint, int mult) {
    this->rank = rank;
    this->suit = suit;
    this->cardType = cardType;
    this->bonusPoint = bonusPoint;
    this->mult = mult;
    this->chips = 0;
}

string Card::get_cardType() {
    return cardType;
}

void Card::set_cardType(string newType) {
    cardType = newType;
}

int Card::get_bonusPoint() {
    return bonusPoint;
}

void Card::set_bonusPoint() {
    bonusPoint = 10;  // Default bonus point
}

int Card::get_mult() {
    return mult;
}

void Card::set_mult() {
    mult = 2;  // Default multiplier
}

string Card::get_rank() {
    return rank;
}

void Card::set_rank(string newRank) {
    rank = newRank;
}

string Card::get_suit() {
    return suit;
}

void Card::set_suit(string newSuit) {
    suit = newSuit;
}

int Card::get_chips() {
    return chips;
}

void Card::set_chips(int newChips) {
    chips = newChips;
}

void Card::print_card() {
    cout << rank << " of " << suit;
    if (cardType != "normal") {
        cout << " (" << cardType;
        if (bonusPoint > 0) cout << ", +" << bonusPoint;
        if (mult > 1) cout << ", x" << mult;
        cout << ")";
    }
    cout << endl;
}

Card::~Card() {
    // Destructor implementation if needed
} 