#include "Card.h"
#include <iostream>
using namespace std;

// Card::Card() {
//     // Ramdomly generate a card
//     int randomRank = rand() % 13 + 1; // Random rank between 1 and 13
// }
Card::Card(string rank, Suit suit) {
    this->rank = rank;
    this->suit = suit;
    this->cardType = "normal";
    this->bonusPoint = 0;
    this->mult = 0;
    if (rank>= "2" && rank <= "10") {
        this->rankValue = stoi(rank);
    } else if (rank == "J" ) {
        this->rankValue = 11;
    } else if (rank == "Q" ) {
        this->rankValue = 12;
    } else if (rank == "K" ) {
        this->rankValue = 13;
    } else if (rank == "A" ) {
        this->rankValue = 14;
    } else {
        this->rankValue = 0; // Invalid rank
    }
    if (rankValue >= 2 && rankValue <= 10) {
        this->chips = rankValue;
    } else if (rankValue >= 11 && rankValue <= 13) {
        this->chips = 10;
    } else if (rankValue == 14) {
        this->chips = 11;
    } else {
        this->chips = 0; // Invalid rank
    }
}
Card::Card(string rank, Suit suit, string cardType) {
    this->rank = rank;
    this->suit = suit;
    this->cardType = cardType;
    if (cardType == "bonus") {
        this->bonusPoint = 30;
        this->mult = 0;
    } else if (cardType == "mult") {
        this->bonusPoint = 0;
        this->mult = 3;
    } else if (cardType == "wild") {
        this->bonusPoint = 0;
        this->mult = 0;
    } else {
        this->bonusPoint = 0;
        this->mult = 0;
    }
    if (rank>= "2" && rank <= "10") {
        this->rankValue = stoi(rank);
    } else if (rank == "J" ) {
        this->rankValue = 11;
    } else if (rank == "Q" ) {
        this->rankValue = 12;
    } else if (rank == "K" ) {
        this->rankValue = 13;
    } else if (rank == "A" ) {
        this->rankValue = 14;
    } else {
        this->rankValue = 0; // Invalid rank
    }
    if (rankValue >= 2 && rankValue <= 10) {
        this->chips = rankValue;
    } else if (rankValue >= 11 && rankValue <= 13) {
        this->chips = 10;
    } else if (rankValue == 14) {
        this->chips = 11;
    } else {
        this->chips = 0; // Invalid rank
    }
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
    bonusPoint = 0;
}
int Card::get_mult() {
    return mult;
}
void Card::set_mult() {
    mult = 0;
}
string Card::get_rank() {
    return rank;
}
void Card::set_rank(string newRank) {
    rank = newRank;
}
int Card::get_rankValue() {
    return rankValue;
}
void Card::set_rankValue(int newRankValue) {
    rankValue = newRankValue;
}
Suit Card::get_suit() {
    return suit;
}
void Card::set_suit(Suit newSuit) {
    suit = newSuit;
}
int Card::get_chips() {
    return chips;
}
void Card::set_chips(int newChips) {
    chips = newChips;
}
void Card::print_card() {
    cout << "Card: " << rank << " of " << suit << endl;
    cout << "Type: " << cardType << endl;
    cout << "Bonus Points: " << bonusPoint << endl;
    cout << "Mult Points: " << mult << endl;
    cout << "Chips: " << chips << endl;
}
Card::~Card() {
    // Destructor
    // No dynamic memory allocation, so nothing to free
}