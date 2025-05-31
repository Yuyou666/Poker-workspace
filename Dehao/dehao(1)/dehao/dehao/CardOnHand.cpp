#include "CardOnHand.h"
#include <iostream>
using namespace std;

CardOnHand::CardOnHand() : CardGroup(9, false) {
    // Initialize with 0 cards, doesn't own cards by default
    // Cards are owned by the Deck
}

void CardOnHand::printCards() const {
    if (cards.empty()) {
        cout << "No cards in hand." << endl;
        return;
    }
    cout << "Cards in hand:" << endl;
    for (size_t i = 0; i < cards.size(); ++i) {
        cout << (i + 1) << ". ";
        cards[i]->print_card();
    }
    cout << endl;
}

void CardOnHand::discards(int index[5]) {
    // Discard up to 5 cards, marked by their indices
    // Just remove the cards from hand, don't delete them
    for (int i = 0; i < 5; i++) {
        if (index[i] >= 0 && index[i] < static_cast<int>(cards.size())) {
            removeCard(index[i], false);  // Don't delete, just remove from hand
        }
    }
}

Card** CardOnHand::select(int index[5]) {
    // Select up to 5 cards and return them
    // Return pointers to the cards without transferring ownership
    Card** selected = new Card*[5];
    for (int i = 0; i < 5; i++) {
        selected[i] = nullptr;
        if (index[i] >= 0 && index[i] < static_cast<int>(cards.size())) {
            selected[i] = cards[index[i]];
            removeCard(index[i], false);  // Remove from hand but don't delete
        }
    }
    return selected;
}

void CardOnHand::drawFull() {
    // Clear existing cards from hand without deleting them
    while (!cards.empty()) {
        removeCard(0, false);  // Remove but don't delete
    }
}

CardOnHand::~CardOnHand() {
    // The base class CardGroup destructor will handle the cleanup
    // Since ownsCards is false, it won't delete the cards
    // Cards are owned by the Deck
} 