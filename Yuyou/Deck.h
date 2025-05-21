#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "CardGroup.h"
#include <iostream>
using namespace std;
class Deck : public CardGroup {
    public:
        //max could be 100?
        Deck();//original deck constructor with 52 cards
        Deck(Card **cards, int count);//constructor for deck with given cards
        void printCards();//print with suit and rank order
        Card *drawCard();//draw a card from the deck with ramdom index and remove it from the deck
        bool modifyCard(Card *card);
        ~Deck();
};
#endif // DECK_H