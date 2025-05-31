#include "../Card.h"
#include <cassert>
#include <iostream>

using namespace std;

void testCardCreation() {
    cout << "Testing Card Creation..." << endl;
    
    // Test normal card
    Card normalCard("Ace", "hearts");
    assert(normalCard.get_rank() == "Ace");
    assert(normalCard.get_suit() == "hearts");
    assert(normalCard.get_cardType() == "normal");
    
    // Test special card
    Card specialCard("King", "spades", "bonus", 10, 2);
    assert(specialCard.get_rank() == "King");
    assert(specialCard.get_suit() == "spades");
    assert(specialCard.get_cardType() == "bonus");
    assert(specialCard.get_bonusPoint() == 10);
    assert(specialCard.get_mult() == 2);
    
    cout << "Card creation test passed!" << endl;
}

void testCardGettersAndSetters() {
    cout << "Testing Card Getters and Setters..." << endl;
    Card card("Queen", "diamonds");
    
    // Test setters
    card.set_cardType("mult");
    card.set_bonusPoint();
    card.set_mult();
    card.set_chips(5);
    
    // Test getters
    assert(card.get_cardType() == "mult");
    assert(card.get_chips() == 5);
    
    cout << "Card getters and setters test passed!" << endl;
}

void testCardSpecialEffects() {
    cout << "Testing Card Special Effects..." << endl;
    
    // Test bonus card
    Card bonusCard("Jack", "clubs", "bonus", 20, 1);
    assert(bonusCard.get_bonusPoint() == 20);
    
    // Test multiplier card
    Card multCard("10", "hearts", "mult", 0, 3);
    assert(multCard.get_mult() == 3);
    
    // Test wild card
    Card wildCard("Joker", "wild", "wild", 0, 1);
    assert(wildCard.get_suit() == "wild");
    assert(wildCard.get_cardType() == "wild");
    
    cout << "Card special effects test passed!" << endl;
}

void testCardValidation() {
    cout << "Testing Card Validation..." << endl;
    
    try {
        // Test invalid suit
        Card invalidCard("Ace", "invalid_suit");
        assert(false); // Should not reach here
    } catch (const exception& e) {
        cout << "Expected exception caught: " << e.what() << endl;
    }
    
    try {
        // Test invalid card type
        Card invalidCard("King", "hearts", "invalid_type", 0, 0);
        assert(false); // Should not reach here
    } catch (const exception& e) {
        cout << "Expected exception caught: " << e.what() << endl;
    }
    
    cout << "Card validation test passed!" << endl;
}

void testCardPrinting() {
    cout << "Testing Card Printing..." << endl;
    Card card("Ace", "hearts");
    
    // Test print_card method
    cout << "Card should be printed below:" << endl;
    card.print_card();
    
    cout << "Card printing test passed!" << endl;
}

int main() {
    try {
        cout << "Starting Card Tests..." << endl;
        
        testCardCreation();
        testCardGettersAndSetters();
        testCardSpecialEffects();
        testCardValidation();
        testCardPrinting();
        
        cout << "All Card tests passed successfully!" << endl;
        return 0;
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
} 