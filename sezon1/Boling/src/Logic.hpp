#pragma once
#include "Component.hpp"

//#include <vector>
//#include <numeric>
//#include <functional>
//#include <algorithm>

using VectorIterator = std::vector<int>::iterator;

class Logic
{
public:
    Logic()
    {
        countConteiner_ = std::vector<int>(21, 0);
    }
    ~Logic() {}

    int score();
    std::vector<int> getCountConteiner() const {return countConteiner_; }
    void conectConteiners(const std::vector<int>& pointConteiner);

    auto isSpare(VectorIterator firstInFrame) const;
    auto isStrike(VectorIterator firstInFrame) const;
    auto addFirstAndSecondRollInFrame(VectorIterator firstInFrame) const;
    auto addOneBallForSper(VectorIterator firstInFrame) const;
    auto addTwoBallsForStrike(VectorIterator firstInFrame) const;

private:
    std::vector<int> countConteiner_;
};