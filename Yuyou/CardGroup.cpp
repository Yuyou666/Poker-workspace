#include "CardGroup.h"
#include <iostream>
using namespace std;
CardGroup::CardGroup(int capacity) {
    this->max = capacity;
    this->count = 0;
    this->cards = new Card*[capacity];
}
CardGroup::CardGroup(Card **cards, int count, int max) {
    this->cards = cards;
    this->count = count;
    this->max = max;
}
Card** CardGroup::get_group() {
    return cards;
}
int CardGroup::get_count() {
    return count;
}
int CardGroup::get_max() {
    return max;
}
void CardGroup::set_group(Card **cards) {
    this->cards = cards;
}
void CardGroup::addCard(Card *card) {
    if (count < max) {
        cards[count] = card;
        count++;
    } else {
        cout << "Card group is full!" << endl;
    }
}
void CardGroup::removeCard(int index) {
    if (index >= 0 && index < count) {
        delete cards[index];
        for (int i = index; i < count - 1; i++) {
            cards[i] = cards[i + 1];
        }
        count--;
    } else {
        cout << "Invalid index!" << endl;
    }
}
void CardGroup::sortInRank() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (cards[j]->get_rankValue() > cards[j + 1]->get_rankValue()) {
                Card* temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }
}
void CardGroup::sortInSuit() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (cards[j]->get_suit() > cards[j + 1]->get_suit()) {
                Card* temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }
}
CardGroup::~CardGroup() {
    for (int i = 0; i < count; i++) {
        delete cards[i];
    }
    delete[] cards;
}
