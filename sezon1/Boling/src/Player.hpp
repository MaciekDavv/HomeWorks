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
    Ture(const int& pins);
    ~Ture();

    int setPin(const int& pins);
    void addPinsToBoowl(const int& pins);
    std::vector<int> getBoowl() const;

private:
    int pins_{0};
    std::vector<int> boowl_;
};


class Player
{
public:
    Player();
    ~Player();
    int getNumberFromUser();
    std::shared_ptr<Ture> getTure () { return ture_ = std::make_shared<Ture>(); }
    std::vector<std::shared_ptr<Ture>> getRound() const { return round_; }
    void addTureToRound(std::shared_ptr<Ture> ture);

private:
    std::vector<std::shared_ptr<Ture>> round_;
    std::shared_ptr<Ture> ture_;
};

