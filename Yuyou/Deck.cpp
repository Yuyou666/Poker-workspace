#include "Deck.h"
#include <iostream>
using namespace std;
Deck::Deck() : CardGroup(100) {
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 2; j <= 14; j++) {
            string rank;
            if (j >= 2 && j <= 10) {
                rank = to_string(j);
            } else if (j == 11) {
                rank = "J";
            } else if (j == 12) {
                rank = "Q";
            } else if (j == 13) {
                rank = "K";
            } else if (j == 14) {
                rank = "A";
            }
            Suit suit;
            switch (i) {
                case 0: suit = Clubs; break;
                case 1: suit = Diamonds; break;
                case 2: suit = Hearts; break;
                case 3: suit = Spades; break;
            }
            cards[index] = new Card(rank, suit);
            index++;
        }
    }
}
Deck::Deck(Card **cards, int count) : CardGroup(cards, count, 100) {
    this->cards = cards;
    this->count = count;
    this->max = count;
}
Deck::~Deck() {
    for (int i = 0; i < count; i++) {
        delete cards[i];
    }
    delete[] cards;
}
Deck::Deck(Card **cards, int count) : CardGroup(cards, count, count) {
    this->cards = cards;
    this->count = count;
    this->max = count;
}
void Deck::printCards() {
    for (int i = 0; i < count; i++) {
        cards[i]->print_card();
    }
}
Card *Deck::drawCard() {
    if (count == 0) {
        cout << "No cards left in the deck!" << endl;
        return nullptr;
    }
    int randomIndex = rand() % count;
    Card *drawnCard = cards[randomIndex];
    removeCard(randomIndex);
    return drawnCard;
}
bool Deck::modifyCard(Card *card) {
    for (int i = 0; i < count; i++) {
        if (cards[i]->get_rank() == card->get_rank() && cards[i]->get_suit() == card->get_suit()) {
            cards[i]->set_cardType(card->get_cardType());
            return true;
        }
    }
    return false;
}
