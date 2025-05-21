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
        Card** get_group();
        int get_count();
        int get_max();
        void set_group(Card **cards);
        void addCard(Card *card);
        void removeCard(int index);
        void sortInSuit();
        void sortInRank();
        virtual void printCards()=0;
        ~CardGroup();
};


#endif // CARDGROUP_H