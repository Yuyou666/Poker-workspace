#include "../Player.h"
#include "../Card.h"
#include <cassert>
#include <iostream>

using namespace std;

void testPlayerCreation() {
    cout << "Testing Player Creation..." << endl;
    Player player("TestPlayer");
    
    assert(player.get_name() == "TestPlayer");
    assert(player.get_coins() == 0);
    assert(player.get_challengeLevel() == "Easy");
    assert(player.get_totalRoundCount() == 0);
    assert(player.getCurrentScore() == 0);
    
    cout << "Player creation test passed!" << endl;
}

void testPlayerScoreManagement() {
    cout << "Testing Player Score Management..." << endl;
    Player player("TestPlayer");
    
    // Test score updates
    player.updateScore(50);
    assert(player.getCurrentScore() == 50);
    
    player.updateScore(30);
    assert(player.getCurrentScore() == 80);
    
    // Test high score
    assert(player.getHighScore() == 80);
    
    player.updateScore(-20);
    assert(player.getCurrentScore() == 60);
    assert(player.getHighScore() == 80); // High score should not decrease
    
    cout << "Player score management test passed!" << endl;
}

void testPlayerSpecialCards() {
    cout << "Testing Player Special Cards..." << endl;
    Player player("TestPlayer");
    
    // Create and add special cards
    Card* bonusCard = new Card("Ace", "hearts", "bonus", 10, 1);
    Card* multCard = new Card("King", "spades", "mult", 0, 2);
    
    player.addSpecialCard(bonusCard);
    player.addSpecialCard(multCard);
    
    // Test special cards management
    vector<Card*> specialCards = player.getSpecialCards();
    assert(specialCards.size() == 2);
    
    // Test using special cards
    player.useSpecialCard(0); // Use bonus card
    assert(player.getCurrentScore() == 10);
    
    player.useSpecialCard(0); // Use multiplier card
    assert(player.getCurrentScore() == 20);
    
    cout << "Player special cards test passed!" << endl;
}

void testPlayerRoundManagement() {
    cout << "Testing Player Round Management..." << endl;
    Player player("TestPlayer");
    
    // Test round start
    player.startNewRound();
    assert(player.getCurrentScore() == 0);
    assert(player.get_totalRoundCount() == 1);
    
    // Test score accumulation
    player.updateScore(50);
    player.endRound();
    assert(player.get_coins() > 0); // Should earn coins
    
    cout << "Player round management test passed!" << endl;
}

void testPlayerWinConditions() {
    cout << "Testing Player Win Conditions..." << endl;
    Player player("TestPlayer");
    
    // Test Easy level
    player.set_challengeLevel("Easy");
    player.setCurrentScore(0);
    player.updateScore(90);
    assert(!player.checkWinCondition());
    player.updateScore(10);
    assert(player.checkWinCondition());
    
    // Test Medium level
    player.set_challengeLevel("Medium");
    player.setCurrentScore(0);
    player.updateScore(190);
    assert(!player.checkWinCondition());
    player.updateScore(10);
    assert(player.checkWinCondition());
    
    // Test Difficult level
    player.set_challengeLevel("Difficult");
    player.setCurrentScore(0);
    player.updateScore(290);
    assert(!player.checkWinCondition());
    player.updateScore(10);
    assert(player.checkWinCondition());
    
    cout << "Player win conditions test passed!" << endl;
}

void testPlayerExceptions() {
    cout << "Testing Player Exceptions..." << endl;
    Player player("TestPlayer");
    
    try {
        // Test invalid special card index
        player.useSpecialCard(0);
        assert(false); // Should not reach here
    } catch (const exception& e) {
        cout << "Expected exception caught: " << e.what() << endl;
    }
    
    cout << "Player exceptions test passed!" << endl;
}

int main() {
    try {
        cout << "Starting Player Tests..." << endl;
        
        testPlayerCreation();
        testPlayerScoreManagement();
        testPlayerSpecialCards();
        testPlayerRoundManagement();
        testPlayerWinConditions();
        testPlayerExceptions();
        
        cout << "All Player tests passed successfully!" << endl;
        return 0;
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
} 