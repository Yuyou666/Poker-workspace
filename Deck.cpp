// Deck.cpp: Implements the Deck class, which represents a deck of playing cards.
// Inherits from CardGroup and overrides printCards for polymorphism.
#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

// Default constructor: creates a standard deck of 52 cards
Deck::Deck() : CardGroup(52) {
    // Create a standard deck of 52 cards
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string suits[] = {"hearts", "diamonds", "clubs", "spades"};
    
    count = 0;
    for (const string& suit : suits) {
        for (const string& rank : ranks) {
            cards[count++] = new Card(rank, suit);
        }
    }
}

// Constructor for deck with given cards
Deck::Deck(Card** cards, int count) : CardGroup(count) {
    this->count = count;
    for (int i = 0; i < count; i++) {
        this->cards[i] = cards[i];
    }
}

// Polymorphic print: prints all cards in the deck
void Deck::printCards() const {
    cout << "\nDeck Contents (" << count << " cards):" << endl;
    for (int i = 0; i < count; i++) {
        cout << i << ": ";
        cards[i]->print_card();
    }
}

// Draws the top card from the deck
Card* Deck::drawTop() {
    if (count > 0) {
        Card* drawn = cards[count - 1];
        cards[count - 1] = nullptr;
        count--;
        return drawn;
    }
    return nullptr;
}

// Gets the card at the given index
Card* Deck::get_card(int index) const {
    if (index >= 0 && index < count) {
        return cards[index];
    }
    return nullptr;
}

// Deletes the card at the given index
bool Deck::deleteCard(int index) {
    if (index >= 0 && index < count) {
        delete cards[index];
        for (int i = index; i < count - 1; i++) {
            cards[i] = cards[i + 1];
        }
        cards[count - 1] = nullptr;
        count--;
        return true;
    }
    return false;
}

// Replaces the card at the given index with a new card
bool Deck::replaceCard(int index, Card* newCard) {
    if (index >= 0 && index < count) {
        delete cards[index];
        cards[index] = newCard;
        return true;
    }
    return false;
}

// Placeholder for card modification
bool Deck::modifyCard(Card* /*card*/) {
    // Implementation depends on what modification means
    // For now, just return true
    return true;
}

// Save the deck to a file
void Deck::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (int i = 0; i < count; ++i) {
        ofs << cards[i]->get_rank() << ' ' << cards[i]->get_suit() << ' ' << cards[i]->get_cardType() << ' ' << cards[i]->get_bonusPoint() << ' ' << cards[i]->get_mult() << '\n';
    }
}

// Load the deck from a file
void Deck::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    std::string rank, suit, type;
    int bonus, mult;
    while (ifs >> rank >> suit >> type >> bonus >> mult) {
        addCard(new Card(rank, suit, type, bonus, mult));
    }
}

// Destructor: CardGroup handles memory cleanup
Deck::~Deck() {
    // CardGroup destructor will handle card deletion
} 