#define TESTING
#include "../Game.h"
#include <cassert>
#include <iostream>

using namespace std;

void testGameCreation() {
    cout << "Testing Game Creation..." << endl;
    Game game;
    assert(!game.isGameActive);
    cout << "Game creation test passed!" << endl;
}

void testGameInitialization() {
    cout << "Testing Game Initialization..." << endl;
    Game game;
    
    // Test new game creation
    game.NewGame();
    assert(game.isGameActive);
    
    // Clean up properly
    game.exit();
    cout << "Game initialization test passed!" << endl;
}

void testGameScoreManagement() {
    cout << "Testing Game Score Management..." << endl;
    Game game;
    
    // Initialize game state
    game.NewGame();
    game.startRound();
    
    // Test score updates
    game.updateScore();
    
    // Clean up properly
    game.exit();
    cout << "Game score management test passed!" << endl;
}

void testGameExceptions() {
    cout << "Testing Game Exceptions..." << endl;
    Game game;
    
    try {
        // Test invalid card purchase
        game.purchaseCard(-1);
        assert(false); // Should not reach here
    } catch (const exception& e) {
        cout << "Expected exception caught: " << e.what() << endl;
    }
    
    // Clean up properly
    game.exit();
    cout << "Game exceptions test passed!" << endl;
}

int main() {
    try {
        cout << "Starting Game Tests..." << endl;
        
        testGameCreation();
        testGameInitialization();
        testGameScoreManagement();
        testGameExceptions();
        
        cout << "All Game tests passed successfully!" << endl;
        return 0;
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
} 