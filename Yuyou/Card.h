#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
enum Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades,
    wild
};
class Card {
    private:
        string cardType ;//"normal" or "bonus" or "mult" or "wild"
        int bonusPoint;
        int mult;
        string rank;
        int rankValue; // 1-13
        Suit suit; //"hearts", "diamonds", "clubs", "spades" ,"wild"
        int chips; 
    public:
        
        Card();//random card constructor
        Card(string rank,Suit suit);//constructor for normal card
        Card(string rank,Suit suit,string cardType);
        string get_cardType() ;
        void set_cardType(string newType) ;
        int get_bonusPoint() ;
        void set_bonusPoint();
        int get_mult();
        void set_mult();
        string get_rank();
        void set_rank(string newRank);
        int get_rankValue();
        void set_rankValue(int newRankValue);
        Suit get_suit();
        void set_suit(Suit newSuit);
        int get_chips();
        void set_chips(int newChips);
        void print_card(); 
        ~Card();
};
#endif // CARD_H