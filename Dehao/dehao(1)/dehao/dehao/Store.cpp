// Store.cpp: Implements the Store class for card buying, deleting, and replacing.
#include "Store.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

Store::Store() noexcept {
    srand(time(nullptr));
    // Populate the store with a few random cards
    for (int i = 0; i < 3; ++i) {
        int r = rand() % 3;
        string type = (r == 0) ? "normal" : (r == 1) ? "bonus" : "multiple";
        availableCards.push_back(generateRandomCard(type));
    }
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

void Store::displayCards() const {
    if (availableCards.empty()) {
        cout << "No cards available in store." << endl;
        return;
    }

    cout << "Available cards in store:" << endl;
    for (size_t i = 0; i < availableCards.size(); i++) {
        cout << setw(3) << (i + 1) << ". ";
        availableCards[i]->print_card();
        cout << " (Cost: " << availableCards[i]->get_chips() << " coins)" << endl;
    }
    cout << endl;
}

int Store::getCardCount() const {
    return availableCards.size();
}

Card* Store::getCard(int index) const {
    if (index >= 0 && index < static_cast<int>(availableCards.size())) {
        return availableCards[index];
    }
    return nullptr;
}

void Store::addCard(Card* card) {
    availableCards.push_back(card);
}

void Store::removeCard(int index) {
    if (index >= 0 && index < static_cast<int>(availableCards.size())) {
        // Only delete the card if it's still in our possession
        if (availableCards[index]) {
            delete availableCards[index];
        }
        availableCards.erase(availableCards.begin() + index);
    }
}

void Store::removeCardNoDelete(int index) {
    if (index >= 0 && index < static_cast<int>(availableCards.size())) {
        // Set the pointer to nullptr before erasing to prevent double deletion
        availableCards[index] = nullptr;
        availableCards.erase(availableCards.begin() + index);
    }
}

Store::~Store() {
    for (Card* card : availableCards) {
        if (card) {
            delete card;
        }
    }
    availableCards.clear();
}