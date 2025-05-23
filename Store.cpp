#include "Store.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Store::Store() {
    srand(static_cast<unsigned>(time(0)));
}

Card* Store::generateRandomCard(const string& type) {
    string rank = ranks[rand() % ranks.size()];
    string suit = suits[rand() % suits.size()];

    if (type == "normal") {
        return new Card(rank, suit, "normal", 0, 1);
    } else if (type == "bonus") {
        return new Card(rank, suit, "bonus", 10, 1);
    } else if (type == "multiple") {
        return new Card(rank, suit, "mult", 0, 50);
    }
    return new Card(rank, suit, "normal", 0, 1);
}

Card* Store::generateCardOfType(const string& type) {
    return generateRandomCard(type);
}

vector<Card*> Store::add() {
    vector<Card*> cards;
    for (int i = 0; i < 3; ++i) {
        int r = rand() % 3;
        string type = (r == 0) ? "normal" : (r == 1) ? "bonus" : "multiple";
        cards.push_back(generateRandomCard(type));
    }
    return cards;
}

bool Store::deleteCard(Deck& playerDeck, int index) {
    return playerDeck.deleteCard(index);
}

bool Store::replaceCard(Deck& playerDeck, int replaceIndex, Card* newCard) {
    return playerDeck.replaceCard(replaceIndex, newCard);
}

Store::~Store() {}