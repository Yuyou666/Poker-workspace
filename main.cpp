#include <iostream>
#include "Store.h"
#include "Deck.h"

using namespace std;

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

void showCards(const vector<Card*>& cards) {
    for (size_t i = 0; i < cards.size(); ++i) {
        cout << i << ": ";
        cards[i]->print_card();
    }
}

void showPlayerDeck(const Deck& deck) {
    for (int i = 0; i < deck.get_count(); ++i) {
        cout << i << ": ";
        deck.get_card(i)->print_card();
    }
}

int main() {
    Deck playerDeck;
    Store store;
    int coins = 20;
    int choice;

    vector<Card*> starting = store.add();
    for (Card* c : starting) {
        playerDeck.addCard(c);
    }

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
                cout << "Invalid index.\n";
            }
        }

        else if (choice == 4) {
            showPlayerDeck(playerDeck);
        }

        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

