#ifndef STORE_H
#define STORE_H

#include <vector>
#include <string>
#include "Card.h"
#include "Deck.h"

class Store {
private:
    std::vector<std::string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::vector<std::string> suits = {"hearts", "diamonds", "clubs", "spades"};

    Card* generateRandomCard(const std::string& type);

public:
    Store();

    std::vector<Card*> add();                 // 随机生成3张
    bool deleteCard(Deck& playerDeck, int index); // 删除玩家卡牌
    std::vector<Card*> replaceOptions();     // 随机生成3张替换卡牌
    bool replaceCard(Deck& playerDeck, int replaceIndex, Card* newCard); // 替换玩家卡牌

    ~Store();
};

#endif