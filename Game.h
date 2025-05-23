#ifndef GAME_H
#define GAME_H

class Game {

private:
    Player* player;              // 当前玩家
    Round* currentRound;         // 当前回合
    ScoreBoard* 
    Store* store;                // 游戏内商店
    bool isSaved;                // 是否保存状态
    std::string saveFileName;    // 存档文件名

public:
    // 构造函数
    Game();

    // 启动新游戏
    void NewGame();

    // 保存游戏进度（进保存关卡的，如果一个关卡中四轮没结束就无法保存）保存Player
    void save();

    // 读取游戏存档
    void read();

    // 退出游戏（需要恢复到什么程度）
    void exit();

    ~Game();
};

#endif
