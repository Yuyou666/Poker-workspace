// Deck.cpp: Implements the Deck class, which represents a deck of playing cards.
// Inherits from CardGroup and overrides printCards for polymorphism.
#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <random>

using namespace std;

// Default constructor: creates a standard deck of 52 cards
Deck::Deck() : CardGroup(52) {
    // Create a standard deck of 52 cards
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string suits[] = {"hearts", "diamonds", "clubs", "spades"};
    for (const string& suit : suits) {
        for (const string& rank : ranks) {
            addCard(new Card(rank, suit));
        }
    }
}

// Constructor for deck with given cards
Deck::Deck(Card** cards, int count) : CardGroup(count) {
    for (int i = 0; i < count; ++i) {
        addCard(cards[i]);
    }
}

// Polymorphic print: prints all cards in the deck
void Deck::printCards() const {
    cout << "\nDeck Contents (" << get_count() << " cards):" << endl;
    for (int i = 0; i < get_count(); i++) {
        cout << i << ": ";
        getCard(i)->print_card();
    }
}

// Draws the top card from the deck
Card* Deck::drawTop() {
    if (get_count() > 0) {
        Card* drawn = getCard(get_count() - 1);
        removeCard(get_count() - 1, false);  // Don't delete the card, just remove it from the deck
        return drawn;  // Return the card pointer without transferring ownership
    }
    return nullptr;
}

// Gets the card at the given index
Card* Deck::get_card(int index) const {
    return getCard(index);
}

// Deletes the card at the given index
bool Deck::deleteCard(int index) {
    if (index >= 0 && index < get_count()) {
        removeCard(index);
        return true;
    }
    return false;
}

// Replaces the card at the given index with a new card
bool Deck::replaceCard(int index, Card* newCard) {
    return CardGroup::replaceCard(index, newCard);
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
    for (int i = 0; i < get_count(); ++i) {
        Card* c = getCard(i);
        ofs << c->get_rank() << ' ' << c->get_suit() << ' ' << c->get_cardType() << ' ' << c->get_bonusPoint() << ' ' << c->get_mult() << '\n';
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

void Deck::displayCards() const {
    if (get_count() == 0) {
        cout << "No cards in deck." << endl;
        return;
    }
    cout << "Cards in deck:" << endl;
    for (int i = 0; i < get_count(); i++) {
        cout << setw(3) << (i + 1) << ". ";
        getCard(i)->print_card();
    }
    cout << endl;
}

int Deck::getSize() const {
    return get_count();
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card* Deck::dealCard() {
    if (!cards.empty()) {
        Card* card = cards.back();
        cards.pop_back();
        return card;
    }
    return nullptr;
}

void Deck::generateStandardDeck() {
    // Create a standard deck of 52 cards
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string suits[] = {"hearts", "diamonds", "clubs", "spades"};
    for (const string& suit : suits) {
        for (const string& rank : ranks) {
            addCard(new Card(rank, suit));  // Deck owns these cards
        }
    }
}

void Deck::reset() {
    // Clear existing cards first
    for (Card* card : cards) {
        delete card;  // Delete all existing cards
    }
    cards.clear();
    
    // Generate new standard deck
    generateStandardDeck();
}

Deck::~Deck() {
    // The base class CardGroup destructor will handle the cleanup
    // Since Deck owns its cards (ownsCards is true by default in CardGroup),
    // the cards will be properly deleted
} 