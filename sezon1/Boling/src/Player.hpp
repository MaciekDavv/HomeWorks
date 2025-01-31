#pragma once
#include "Component.hpp"

//#include <string>

class Player
{
public:
    Player() {}
    Player(const std::string& name);
    ~Player() {}

    Teable& getTeable()                         { return teable_; }
    std::vector<int> getPointConteiner() const  { return pointCointeiner_; }
    std::string getName() const                 {return name_; }
    void setPointConteiner(const int& pins);

private:
    std::string name_;
    Teable teable_;
    std::vector<int> pointCointeiner_;
};
