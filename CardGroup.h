// CardGroup.h: Abstract base class for groups of cards (e.g., Deck). Provides interface for card management and polymorphic printing.
#ifndef CARDGROUP_H
#define CARDGROUP_H
#include "Card.h"
#include <iostream>
using namespace std;
class CardGroup {
    protected:
        Card** cards;
        int count;
        int max;
    public:
        CardGroup(int capacity);
        CardGroup(Card **cards, int count, int max);
        Card** get_group() const;
        int get_count() const;
        int get_max() const;
        void set_group(Card **cards);
        void addCard(Card *card);
        void removeCard(int index);
        void sortInSuit();
        void sortInRank();
        virtual void printCards() const = 0;
        ~CardGroup();
};


#endif // CARDGROUP_H