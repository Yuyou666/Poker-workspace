// Deck.h: Represents a deck of playing cards. Inherits from CardGroup and implements printCards for polymorphism.
#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "CardGroup.h"
#include <iostream>
using namespace std;

class Deck : public CardGroup {
    public:
        Deck();  // original deck constructor with 52 cards
        Deck(Card** cards, int count);  // constructor for deck with given cards
        void printCards() const override;  // print with suit and rank order
        Card* drawTop();  // draw a card from the top of the deck
        Card* get_card(int index) const;  // get card at index
        bool deleteCard(int index);  // delete card at index
        bool replaceCard(int index, Card* newCard);  // replace card at index
        bool modifyCard(Card* card);
        void saveToFile(const std::string& filename) const;
        void loadFromFile(const std::string& filename);
        ~Deck();
};
#endif // DECK_H