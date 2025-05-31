// CardGroup.cpp: Implements the CardGroup abstract base class for managing groups of cards.
#include "CardGroup.h"
#include <iostream>
#include <algorithm>

using namespace std;

CardGroup::CardGroup(int initialSize, bool ownsCards) : ownsCards(ownsCards) {
    cards.reserve(initialSize);
}

CardGroup::~CardGroup() {
    // Only delete cards if this group owns them
    if (ownsCards) {
        for (Card* card : cards) {
            if (card) {
                delete card;
            }
        }
    }
    cards.clear();
}

void CardGroup::addCard(Card* card, bool transferOwnership) {
    if (card) {
        std::cout << "[DEBUG] CardGroup::addCard: " << card << " (" << card->get_rank() << " of " << card->get_suit() << ", " << card->get_cardType() << ") transferOwnership=" << transferOwnership << std::endl;
        cards.push_back(card);
        // If we're transferring ownership, this group now owns the card
        if (transferOwnership) {
            ownsCards = true;
        }
    }
}

void CardGroup::removeCard(int index, bool deleteCard) {
    if (index >= 0 && index < (int)cards.size()) {
        std::cout << "[DEBUG] CardGroup::removeCard: " << cards[index] << " (" << cards[index]->get_rank() << " of " << cards[index]->get_suit() << ", " << cards[index]->get_cardType() << ") deleteCard=" << deleteCard << std::endl;
        if (deleteCard && ownsCards) {
            delete cards[index];
        }
        cards.erase(cards.begin() + index);
    }
}

Card* CardGroup::getCard(int index) const {
    if (index >= 0 && index < (int)cards.size()) {
        return cards[index];
    }
    return nullptr;
}

int CardGroup::get_count() const {
    return cards.size();
}

bool CardGroup::replaceCard(int index, Card* newCard) {
    if (index >= 0 && index < (int)cards.size() && newCard) {
        delete cards[index];
        cards[index] = newCard;
        return true;
    }
    return false;
}

void CardGroup::sortInSuit() {
    std::sort(cards.begin(), cards.end(), [](Card* a, Card* b) {
        if (a->get_suit() != b->get_suit()) {
            return a->get_suit() < b->get_suit();
        }
        return a->get_rank() < b->get_rank();
    });
}

void CardGroup::sortInRank() {
    std::sort(cards.begin(), cards.end(), [](Card* a, Card* b) {
        if (a->get_rank() != b->get_rank()) {
            return a->get_rank() < b->get_rank();
        }
        return a->get_suit() < b->get_suit();
    });
}

void CardGroup::clearCardsWithoutDelete() {
    cards.clear();
}

void CardGroup::setOwnership(bool owns) {
    ownsCards = owns;
} 