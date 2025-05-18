#ifndef STORE_H
#define STORE_H
#include <iostream>
#include "Card.h"
#include "CardGroup.h"
#include "Deck.h"
#include "Player.h"
#include "Round.h"
using namespace std;
class Store{
    private:
        Card *CreatCard();//random card creator
    public:
        void addCard();
        void removeCard(Card *card);
        void modifyCard(Card *card);
        void printCards();

};
#endif // STORE_H