#pragma once
#include "Component.hpp"
#include "Logic.hpp"
#include "Player.hpp"

#include <iostream>

//#include <vector>
//#include <numeric>
//#include <functional>
//#include <optional>

class Game
{
public:
    Game() {}
    ~Game() {}

    const Ball& getBall() const { return ball_; }
    Logic& getLogic() { return logic_; }
    std::shared_ptr<Player> addPlayer(const std::string& name);
    void addBallToBoBothConteners(std::shared_ptr<Player> player, const int& firstThrow, const int& secondThrow);
    void addBallToBoBothContenersStrike(std::shared_ptr<Player> player, const int& firstThrow);
    void GamePlay();
    int roll();
    int secondRoll(const int& firstThrow);
    int getScore() const { return score_; }
    void setScore(const int& score) { score_ = score; }
private:
    Ball ball_;
    Logic logic_;
    std::string playerName_;
    int score_{0};
    //bool gameLoop = true;
};