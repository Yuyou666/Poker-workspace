// This is the main entry point for the card game project.
// It demonstrates OOP concepts, dynamic memory, user interaction, and more.
#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    Game game;
    game.NewGame();  // This will start the game with player name and difficulty selection
    
    while (game.isGameActive) {
        cout << "\nYour options:" << endl;
        cout << "1. Play a card" << endl;
        cout << "2. View store" << endl;
        cout << "3. View deck status" << endl;
        cout << "4. End round" << endl;
        cout << "Enter your choice (1-4): ";
        
        int choice;
        cin >> choice;
        game.processPlayerChoice(choice);
    }
    
    return 0;
}

