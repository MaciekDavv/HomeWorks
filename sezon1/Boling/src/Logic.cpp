#include "Logic.hpp"

auto Logic::isSpare(VectorIterator firstInFrame) const {
    return *firstInFrame + *std::next(firstInFrame) == 10;
}
auto Logic::isStrike(VectorIterator firstInFrame) const {
    return *firstInFrame == 10;
}
auto Logic::addFirstAndSecondRollInFrame(VectorIterator firstInFrame) const {
    return *firstInFrame + *std::next(firstInFrame);
}
auto Logic::addOneBallForSper(VectorIterator firstInFrame) const {
    return 10 + *std::next(firstInFrame + 1);
}
auto Logic::addTwoBallsForStrike(VectorIterator firstInFrame) const {
    return 10 + *std::next(firstInFrame) + *std::next(firstInFrame + 1);
}

void Logic::conectConteiners(const std::vector<int>& pointConteiner) {
    auto pred = [](auto& a, auto& b) { return b = a; };
    std::transform(pointConteiner.begin(),
                   pointConteiner.end(),
                   countConteiner_.begin(),
                   countConteiner_.begin(),
                   pred);
}

int Logic::score(){
    int score = 0;
    auto firstInFrame = countConteiner_.begin();
    for (int frame = 0; frame < 10; ++frame) {
        if (firstInFrame != countConteiner_.end()) {
            if (isStrike(firstInFrame)) {
                score += addTwoBallsForStrike(firstInFrame);
                firstInFrame++;
            } else if (isSpare(firstInFrame)) {
                score += addOneBallForSper(firstInFrame);
                firstInFrame +=2;
            } else {
                score += addFirstAndSecondRollInFrame(firstInFrame);
                firstInFrame += 2;
            }
        } else {
            std::__throw_out_of_range("Wyjazd");
        }
    }
    return score;
}