#ifndef SCORE_H 
#define SCORE_H
#include <iostream>
#include "CardGroup.h"
#include "Card.h"
using namespace std;
class Score : public CardGroup{
    private:
        string handType;
        int basicChips;
        int basicMult;
    public:
        Score(Card **cards,int count);
        int caculateScore();
        ~Score();


};
#endif // SCORE_H