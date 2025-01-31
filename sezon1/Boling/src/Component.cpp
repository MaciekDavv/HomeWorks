#include "Component.hpp"

Points Teable::getPointTeable() const {
    return pointTeable_;
}

void Teable::setFirstAndSecondPointInTeable(const int& first, const int& second) {
    auto ture = std::make_tuple(first, second);
    pointTeable_.push_back(ture);
}

void Teable::setOnlyFirstPointInTeable(const int& first) {
    auto ture = std::make_tuple(first, std::optional<int>{});
    pointTeable_.push_back(ture);
}

/////////////////////////////////////// Ball

int Ball::firstThrowBall() const {
    auto throwBall = randomThrow(setAllPinsInTrack());
    return throwBall;
}

int Ball::secondThrowBall(const int& firstThrow) const {
    auto secondThrow = randomThrow(setAllPinsInTrack() - firstThrow);
    return secondThrow;
}

int Ball::randomThrow(int max) const {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, max);
    return distribution(generator);
}
