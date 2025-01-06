#pragma once

#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include <iostream>

class Ture
{
public:
    Ture();
    ~Ture();

    void setPinsInBoowl(const int& pins);
    std::vector<int> getBoowl() const;

private:
    std::vector<int> boowl_;
};

///////////////////////////////////////////////////////////////////////////

class Player
{
public:
    Player();
    ~Player();

    std::vector<std::shared_ptr<Ture>> getRound() const { return round_; }
    void addTureToRound(const std::shared_ptr<Ture>& ture);

private:
    std::vector<std::shared_ptr<Ture>> round_;
};
