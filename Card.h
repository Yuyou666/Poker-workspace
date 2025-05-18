#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
class Card {
    private:
        string cardType ;//"normal" or "bonus" or "mult" or "wild"
        int bonusPoint;
        int mult;
        string rank;
        string suit; //"hearts", "diamonds", "clubs", "spades" ,"wild"
        int chips; 
    public:
        
        Card();//random card constructor
        Card(string rank,string suit);//constructor for normal card
        Card(string rank,string suit,string cardType,int bonusPoint,int mult);
        string get_cardType() ;
        void set_cardType(string newType) ;
        int get_bonusPoint() ;
        void set_bonusPoint();
        int get_mult();
        void set_mult();
        string get_rank();
        void set_rank(string newRank);
        string get_suit();
        void set_suit(string newSuit);
        int get_chips();
        void set_chips(int newChips);
        void print_card(); 
        ~Card();
};
#endif // CARD_H