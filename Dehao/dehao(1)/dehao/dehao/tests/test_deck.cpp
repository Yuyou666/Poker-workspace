#include "../Deck.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testDeckCreation() {
    cout << "Testing Deck Creation..." << endl;
    Deck deck;
    assert(deck.getSize() == 52); // Standard deck should have 52 cards
    cout << "Deck creation test passed!" << endl;
}

void testDeckShuffling() {
    cout << "Testing Deck Shuffling..." << endl;
    Deck deck1;
    Deck deck2;
    
    // Store initial order
    vector<Card*> initialOrder;
    for (int i = 0; i < deck1.getSize(); i++) {
        initialOrder.push_back(deck1.getCard(i));
    }
    
    // Shuffle deck
    deck1.shuffle();
    
    // Check if order has changed
    bool orderChanged = false;
    for (int i = 0; i < deck1.getSize(); i++) {
        if (deck1.getCard(i) != initialOrder[i]) {
            orderChanged = true;
            break;
        }
    }
    
    assert(orderChanged);
    cout << "Deck shuffling test passed!" << endl;
}

void testDeckDealing() {
    cout << "Testing Deck Dealing..." << endl;
    Deck deck;
    int initialSize = deck.getSize();
    
    // Deal a card
    Card* dealtCard = deck.dealCard();
    assert(dealtCard != nullptr);
    assert(deck.getSize() == initialSize - 1);
    
    // Deal multiple cards
    vector<Card*> dealtCards;
    for (int i = 0; i < 5; i++) {
        Card* card = deck.dealCard();
        assert(card != nullptr);
        dealtCards.push_back(card);
    }
    
    assert(deck.getSize() == initialSize - 6);
    cout << "Deck dealing test passed!" << endl;
}

void testDeckReset() {
    cout << "Testing Deck Reset..." << endl;
    Deck deck;
    int initialSize = deck.getSize();
    
    // Deal some cards
    for (int i = 0; i < 10; i++) {
        deck.dealCard();
    }
    
    // Reset deck
    deck.reset();
    assert(deck.getSize() == initialSize);
    cout << "Deck reset test passed!" << endl;
}

void testDeckExceptions() {
    cout << "Testing Deck Exceptions..." << endl;
    Deck deck;
    
    // Try to deal more cards than available
    for (int i = 0; i < 53; i++) {
        try {
            Card* card = deck.dealCard();
            if (i == 52) {
                assert(card == nullptr);
            }
        } catch (const exception& e) {
            cout << "Expected exception caught: " << e.what() << endl;
        }
    }
    cout << "Deck exceptions test passed!" << endl;
}

int main() {
    try {
        cout << "Starting Deck Tests..." << endl;
        
        testDeckCreation();
        testDeckShuffling();
        testDeckDealing();
        testDeckReset();
        testDeckExceptions();
        
        cout << "All Deck tests passed successfully!" << endl;
        return 0;
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
} 