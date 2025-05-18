#ifndef CARDONHAND_H
#define CARDONHAND_H
#include "Card.h"
#include <iostream>
#include "CardGroup.h"
using namespace std;
class CardOnHand : public CardGroup {
    //this class is the cards drawn from the deck
    //and the cards in the player's hand
    //9 cards
    public:
        CardOnHand();//orginal hand constructor with 9 cards
        void discards(int index[5]);//discrds at most 5 cards, array of index filled with -1 for not full
        void printCards();//print with suit and rank order
        Card **select(int index[5]);//select,delete at most 5 cards, array of index filled with -1 for not full
        void drawFull();
    };      
#endif // CARDONHAND_H