#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game() {
    player = nullptr;
    currentRound = nullptr;
    scoreBoard = new ScoreBoard();
    store = new Store();
    playerHand = new CardOnHand();
    playerHand->setOwnership(false);  // Player's hand doesn't own the cards
    isSaved = false;
    isGameActive = false;
    currentDifficulty = 0; // 0: Easy, 1: Medium, 2: Difficult
    cout << "Game created." << endl;
}


void Game::NewGame() {
    promptPlayerName();
    promptDifficultyLevel();
    isGameActive = true;
    startRound();
}

void Game::promptPlayerName() {
#ifdef TESTING
    // For unit testing, set a default name
    player = new Player("dehao");
#else
    string name;
    cout << "Welcome to the Poker Card Game!" << endl;
    cout << "Please enter your name: ";
    cin >> name;
    player = new Player(name);
#endif
}

void Game::promptDifficultyLevel() {
#ifdef TESTING
    // For unit testing, set difficulty to Easy
    currentDifficulty = 0;
    string levels[] = {"Easy", "Medium", "Difficult"};
    player->set_challengeLevel(levels[currentDifficulty]);
#else
    cout << "\nSelect difficulty level:" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Difficult" << endl;
    cout << "Enter your choice (1-3): ";
    
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter 1-3: ";
        cin >> choice;
    }
    
    currentDifficulty = choice - 1;
    string levels[] = {"Easy", "Medium", "Difficult"};
    player->set_challengeLevel(levels[currentDifficulty]);
#endif
}

void Game::startRound() {
    cout << "\n=== Starting New Round ===" << endl;
    cout << "Difficulty: " << player->get_challengeLevel() << endl;
    
    // Initialize round with reward coins based on difficulty
    int rewardCoins = (currentDifficulty + 1) * 10; // 10 for Easy, 20 for Medium, 30 for Difficult
    currentRound = new Round(rewardCoins);
    
    // Reset and shuffle the deck
    player->get_mydeck()->reset();
    player->get_mydeck()->shuffle();
    
    // Deal cards to the player's hand
    for (int i = 0; i < 5; i++) { // Deal 5 cards
        Card* drawn = player->get_mydeck()->drawTop();
        if (drawn) {
            playerHand->addCard(drawn, false);  // Don't transfer ownership
        }
    }
    
    displayHandCards();
    
#ifndef TESTING
    while (isGameActive) {
        cout << "\nYour options:" << endl;
        cout << "1. Play a card" << endl;
        cout << "2. View store" << endl;
        cout << "3. View deck status" << endl;
        cout << "4. End round" << endl;
        cout << "Enter your choice (1-4): ";
        
        int choice;
        cin >> choice;
        processPlayerChoice(choice);
        
        if (player->checkWinCondition()) {
            displayRoundResults();
            break;
        }
    }
#else
    // For testing purposes, we'll skip the interactive loop
    isGameActive = true;
#endif
}

void Game::processPlayerChoice(int choice) {
    switch (choice) {
        case 1: {
            // Use the Round's play method to handle card playing
            if (currentRound) {
                currentRound->play(player->get_mydeck());
            }
            break;
        }
        case 2:
            openStore();
            break;
        case 3:
            displayDeckStatus();
            break;
        case 4:
            endRound();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void Game::displayHandCards() {
    cout << "\nYour current hand:" << endl;
    playerHand->printCards();
}

void Game::checkForPairs() {
    // Implement pair checking logic
    // Update score if pairs are found
}

void Game::displayRoundResults() {
    cout << "\n=== Round Results ===" << endl;
    cout << "Player: " << player->get_name() << endl;
    cout << "Coins earned: " << player->get_coins() << endl;
    
    if (player->get_coins() >= getRequiredScore()) {
        cout << "Congratulations! You have successfully passed this level!" << endl;
    }
}

void Game::displayGameSummary() {
    cout << "\n=== Game Summary ===" << endl;
    cout << "Total Coins: " << player->get_coins() << endl;
    cout << "High Score: " << player->getHighScore() << endl;
}

void Game::openStore() {
    cout << "\n=== Store ===" << endl;
    store->displayCards();
    cout << "Your coins: " << player->get_coins() << endl;
    cout << "Enter card number to purchase (0 to exit): ";
    
    int choice;
    cin >> choice;
    if (choice > 0) {
        purchaseCard(choice);
    }
}

void Game::purchaseCard(int cardIndex) {
    // Throw exception for invalid index
    if (cardIndex <= 0 || cardIndex > store->getCardCount()) {
        throw std::out_of_range("Invalid card index");
    }
    // Implement card purchase logic
    Card* card = store->getCard(cardIndex - 1);
    if (card && player->get_coins() >= card->get_chips()) {
        player->set_coins(player->get_coins() - card->get_chips());
        player->addSpecialCard(card);
        store->removeCardNoDelete(cardIndex - 1); // Remove from store, do NOT delete
        cout << "Card purchased successfully!" << endl;
    } else {
        cout << "Not enough coins to purchase this card." << endl;
    }
}

void Game::displayDeckStatus() {
    cout << "\n=== Deck Status ===" << endl;
    // Display remaining cards in deck
    player->get_mydeck()->displayCards();
}

int Game::getRequiredScore() {
    // Return required score based on difficulty
    switch (currentDifficulty) {
        case 0: return 100;  // Easy
        case 1: return 200;  // Medium
        case 2: return 300;  // Difficult
        default: return 100;
    }
}

void Game::save() {
    if (currentRound && currentRound->getHandCount() == 0) {
        // Save game state
        isSaved = true;
        cout << "Game saved." << endl;
    } else {
        cout << "Cannot save during a round." << endl;
    }
}

void Game::read() {
    if (isSaved) {
        // Load game state
        cout << "Game loaded." << endl;
    } else {
        cout << "No saved game found." << endl;
    }
}


void Game::exit() {
    cout << "Starting game exit process..." << endl;
    isGameActive = false;

    // Display game summary before cleanup
    if (player) {
        displayGameSummary();
    }

    cout << "Cleaning up game resources..." << endl;

    // First clean up the current round
    if (currentRound) {
        cout << "Cleaning up current round..." << endl;
        delete currentRound;
        currentRound = nullptr;
    }

    // Clean up store first as it might have references to cards
    if (store) {
        cout << "Cleaning up store..." << endl;
        delete store;
        store = nullptr;
    }

    // Clean up scoreboard
    if (scoreBoard) {
        cout << "Cleaning up scoreboard..." << endl;
        delete scoreBoard;
        scoreBoard = nullptr;
    }

    // Clean up playerHand before player to avoid double-free
    if (playerHand) {
        cout << "Cleaning up player hand..." << endl;
        delete playerHand;
        playerHand = nullptr;
    }

    // Finally clean up the player (which deletes the deck and specialCards)
    if (player) {
        cout << "Cleaning up player..." << endl;
        delete player;
        player = nullptr;
    }

    cout << "Game exit complete." << endl;
    // Force exit the program
    std::exit(0);
}

void Game::endRound() {
    if (currentRound) {
        // Get the coins earned from the round
        int coinsEarned = currentRound->calculateScore();
        
        // Update player's coins directly
        player->set_coins(player->get_coins() + coinsEarned);
        
        // Display round summary
        cout << "\n=== Round Ended ===" << endl;
        cout << "Coins Earned: " << coinsEarned << endl;
        cout << "Total Coins: " << player->get_coins() << endl;
        
        // Clean up round
        delete currentRound;
        currentRound = nullptr;
    }
    
    // Prompt user to continue or exit only in game mode
#ifndef TESTING
    char choice;
    cout << "\nThis round is finished. Would you like to start a new round? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        startRound();
    } else {
        exit();
    }
#else
    // In test mode, simply end the game
    isGameActive = false;
#endif
}

void Game::updateScore() {
    if (currentRound && player) {
        int roundScore = currentRound->calculateScore();
        player->setCurrentScore(player->getCurrentScore() + roundScore);
        
        // Update high score if current score is higher
        if (player->getCurrentScore() > player->getHighScore()) {
            player->setHighScore(player->getCurrentScore());
        }
    }
}

// Destructor
Game::~Game() {
    // Empty destructor since we handle everything in exit()
}
