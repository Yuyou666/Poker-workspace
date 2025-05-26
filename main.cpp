// This is the main entry point for the card game project.
// It demonstrates OOP concepts, dynamic memory, user interaction, and more.
#include <iostream>
#include "Store.h"
#include "Deck.h"

using namespace std;

// Prints the main menu and current coin count
void printMenu(int coins) {
    cout << "\n=== Store Menu ===" << endl;
    cout << "Coins: " << coins << "\n";
    cout << "1. Add [5 coins]" << endl;
    cout << "2. Delete [5 coins]" << endl;
    cout << "3. Replace [7 coins]" << endl;
    cout << "4. Show Deck" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

// Shows a list of cards (used for store options)
void showCards(const vector<Card*>& cards) {
    for (size_t i = 0; i < cards.size(); ++i) {
        cout << i << ": ";
        cards[i]->print_card();
    }
}

// Shows the player's current deck
void showPlayerDeck(const Deck& deck) {
    for (int i = 0; i < deck.get_count(); ++i) {
        cout << i << ": ";
        deck.get_card(i)->print_card();
    }
}

// Simple test function to demonstrate adding, deleting, and replacing cards
void runTests() {
    cout << "\n[TEST] Running basic card/deck/store tests..." << endl;
    Deck testDeck;
    Store testStore;
    // Add 3 cards
    vector<Card*> testCards = testStore.add();
    for (Card* c : testCards) testDeck.addCard(c);
    cout << "[TEST] Deck after adding 3 cards:" << endl;
    testDeck.printCards();
    // Delete a card
    testStore.deleteCard(testDeck, 0);
    cout << "[TEST] Deck after deleting card 0:" << endl;
    testDeck.printCards();
    // Replace a card
    Card* newCard = testStore.generateCardOfType("bonus");
    testStore.replaceCard(testDeck, 0, newCard);
    cout << "[TEST] Deck after replacing card 0 with bonus card:" << endl;
    testDeck.printCards();
    // Edge case: delete out of bounds
    bool result = testStore.deleteCard(testDeck, 100);
    cout << "[TEST] Delete out of bounds (should be 0): " << result << endl;
    // File I/O: save and load deck
    testDeck.saveToFile("test_deck.txt");
    Deck loadedDeck;
    loadedDeck.loadFromFile("test_deck.txt");
    cout << "[TEST] Loaded deck from file:" << endl;
    loadedDeck.printCards();
}

int main() {
    runTests(); // Run test cases at start
    // Create player deck and store
    Deck playerDeck;
    Store store;
    int coins = 20;
    int choice;

    // Add initial cards to the player's deck
    vector<Card*> starting = store.add();
    for (Card* c : starting) {
        playerDeck.addCard(c);
    }

    // Main game loop
    while (true) {
        printMenu(coins);
        cin >> choice;

        if (choice == 0) break;

        else if (choice == 1) {
            if (coins < 5) {
                cout << "Not enough coins.\n";
                continue;
            }
            vector<Card*> newCards = store.add();
            showCards(newCards);
            cout << "Choose card to add (0-2): ";
            int pick; cin >> pick;
            if (pick >= 0 && pick < 3) {
                playerDeck.addCard(newCards[pick]);
                // Delete the cards that weren't chosen
                for (size_t i = 0; i < newCards.size(); ++i) {
                    if (i != static_cast<size_t>(pick)) {
                        delete newCards[i];
                    }
                }
                coins -= 5;
                cout << "Card added.\n";
            }
        }

        else if (choice == 2) {
            if (coins < 5) {
                cout << "Not enough coins.\n";
                continue;
            }
            showPlayerDeck(playerDeck);
            cout << "Choose card to delete: ";
            int index; cin >> index;
            if (store.deleteCard(playerDeck, index)) {
                coins -= 5;
                cout << "Card deleted.\n";
            } else {
                cout << "Invalid index.\n";
            }
        }

        else if (choice == 3) {
            if (coins < 7) {
                cout << "Not enough coins.\n";
                continue;
            }

            cout << "\nYour current deck:" << endl;
            showPlayerDeck(playerDeck);
            cout << "Enter the index of the card you want to replace: ";
            int replaceIndex;
            cin >> replaceIndex;

            cout << "Replace with which type? (bonus/multiple): ";
            string type;
            cin >> type;

            if (type != "bonus" && type != "multiple") {
                cout << "Invalid type.\n";
                continue;
            }

            Card* newCard = store.generateCardOfType(type);
            if (store.replaceCard(playerDeck, replaceIndex, newCard)) {
                coins -= 7;
                cout << "Card replaced with a " << type << " card.\n";
            } else {
                delete newCard;  // Delete the card if replacement failed
                cout << "Invalid index.\n";
            }
        }

        else if (choice == 4) {
            // Demonstrate polymorphism: CardGroup pointer to Deck
            CardGroup* groupPtr = &playerDeck;
            groupPtr->printCards(); // Polymorphic call
        }

        else {
            cout << "Invalid choice.\n";
        }
    }

    // Game ends, resources cleaned up by destructors
    return 0;
}

