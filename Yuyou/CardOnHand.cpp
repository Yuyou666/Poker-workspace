#include "CardOnHand.h"
#include <iostream>
using namespace std;

void CardOnHand::drawFull() {
    for (count;count<max;count++){
        Card *card = deck->drawCard();
        cards[count] = card;
    }
}
CardOnHand::CardOnHand(Deck *mydeck) : CardGroup(9) {
    this->deck = mydeck;
    drawFull();
}
void CardOnHand::discards(int index[5]) {
    for (int i = 0; i < 5; i++) {
        if (index[i] != -1) {
            delete cards[index[i]];
            for (int j = index[i]; j < count - 1; j++) {
                cards[j] = cards[j + 1];
            }
            count--;
        }
    }
    drawFull();
}
void CardOnHand::printCards() {
    for (int i = 0; i < count; i++) {
        cards[i]->print_card();
    }
}
Card **CardOnHand::select(int index[5]) {
    Card **selectedCards = new Card*[5];
    for (int i = 0; i < 5; i++) {
        if (index[i] != -1) {
            selectedCards[i] = cards[index[i]];
            removeCard(index[i]);
        } else {
            selectedCards[i] = nullptr;
        }
    }
    drawFull();
    return selectedCards;
}