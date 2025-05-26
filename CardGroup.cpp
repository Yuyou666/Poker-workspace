// CardGroup.cpp: Implements the CardGroup abstract base class for managing groups of cards.
#include "CardGroup.h"
#include <iostream>
#include <algorithm>

using namespace std;

CardGroup::CardGroup(int capacity) {
    max = capacity;
    count = 0;
    cards = new Card*[max];
    for (int i = 0; i < max; i++) {
        cards[i] = nullptr;
    }
}

CardGroup::CardGroup(Card** cards, int count, int max) {
    this->max = max;
    this->count = count;
    this->cards = new Card*[max];
    for (int i = 0; i < count; i++) {
        this->cards[i] = cards[i];
    }
    for (int i = count; i < max; i++) {
        this->cards[i] = nullptr;
    }
}

Card** CardGroup::get_group() const {
    return cards;
}

int CardGroup::get_count() const {
    return count;
}

int CardGroup::get_max() const {
    return max;
}

void CardGroup::set_group(Card** newCards) {
    // Delete existing cards and array
    for (int i = 0; i < count; i++) {
        if (cards[i] != nullptr) {
            delete cards[i];
        }
    }
    delete[] cards;
    
    // Create new array
    cards = new Card*[max];
    for (int i = 0; i < count; i++) {
        cards[i] = newCards[i];
    }
    for (int i = count; i < max; i++) {
        cards[i] = nullptr;
    }
}

void CardGroup::addCard(Card* card) {
    if (count < max) {
        cards[count++] = card;
    }
}

void CardGroup::removeCard(int index) {
    if (index >= 0 && index < count) {
        delete cards[index];
        for (int i = index; i < count - 1; i++) {
            cards[i] = cards[i + 1];
        }
        cards[count - 1] = nullptr;
        count--;
    }
}

void CardGroup::sortInSuit() {
    sort(cards, cards + count, [](Card* a, Card* b) {
        if (a->get_suit() != b->get_suit()) {
            return a->get_suit() < b->get_suit();
        }
        return a->get_rank() < b->get_rank();
    });
}

void CardGroup::sortInRank() {
    sort(cards, cards + count, [](Card* a, Card* b) {
        if (a->get_rank() != b->get_rank()) {
            return a->get_rank() < b->get_rank();
        }
        return a->get_suit() < b->get_suit();
    });
}

CardGroup::~CardGroup() {
    for (int i = 0; i < count; i++) {
        delete cards[i];
    }
    delete[] cards;
} 