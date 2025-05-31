// Store.h: Represents the in-game store for buying, deleting, and replacing cards in the player's deck.
#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardGroup.h"
#include "Deck.h"
#include "Player.h"
#include "Round.h"
using namespace std;

class Store {
    private:
        vector<string> ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        vector<string> suits = {"hearts", "diamonds", "clubs", "spades"};
        Card* generateRandomCard(const string& type);
        vector<Card*> availableCards;
        
    public:
        Store() noexcept;
        ~Store();
        vector<Card*> add();
        bool deleteCard(Deck& playerDeck, int index);
        bool replaceCard(Deck& playerDeck, int replaceIndex, Card* newCard);
        Card* generateCardOfType(const string& type);
        void displayCards() const;
        int getCardCount() const;
        Card* getCard(int index) const;
        void addCard(Card* card);
        void removeCard(int index);
        void removeCardNoDelete(int index);
};
#endif // STORE_H