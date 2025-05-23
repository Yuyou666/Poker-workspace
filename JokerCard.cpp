#include "JokerCards.h"

// 构造函数实现：初始化五张 Joker 卡
JokerCards::JokerCards() {
    cards.push_back({"Joker A", 10});
    cards.push_back({"Joker B", 20});
    cards.push_back({"Joker C", 30});
    cards.push_back({"Joker D", 40});
    cards.push_back({"Joker E", 50});
}

// 返回指定索引的 Joker 卡
JokerCard JokerCards::getCard(int index) const {
    if (index >= 0 && index < cards.size()) {
        return cards[index];
    } else {
        // 返回一个默认卡（错误处理，可改为抛出异常）
        return {"Invalid Joker", 0};
    }
}

// 返回 Joker 卡的总数
int JokerCards::getCardCount() const {
    return cards.size();
}