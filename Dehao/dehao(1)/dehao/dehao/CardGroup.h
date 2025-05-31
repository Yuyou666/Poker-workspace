// CardGroup.h: Abstract base class for groups of cards (e.g., Deck). Provides interface for card management and polymorphic printing.
#ifndef CARDGROUP_H
#define CARDGROUP_H
#include <vector>
#include "Card.h"
using namespace std;

class CardGroup {
protected:
    std::vector<Card*> cards;
    int count;
    bool ownsCards;  // Flag to indicate if this group owns the cards

public:
    CardGroup(int size = 0, bool ownsCards = true);
    virtual ~CardGroup();

    void addCard(Card* card, bool transferOwnership = true);
    void removeCard(int index, bool deleteCard = true);
    Card* getCard(int index) const;
    int get_count() const;
    bool replaceCard(int index, Card* newCard);
    void sortInSuit();
    void sortInRank();
    virtual void printCards() const = 0;
    void clearCardsWithoutDelete();
    void setOwnership(bool owns);
};

#endif // CARDGROUP_H