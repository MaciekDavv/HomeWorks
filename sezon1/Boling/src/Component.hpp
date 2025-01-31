#pragma once

#include <vector>
#include <tuple>
#include <random>
#include <optional>

using Points = std::vector<std::tuple<int, std::optional<int>>>;

class Pins
{
public:
    Pins() {}
    ~Pins() {}

    int getAllPins() const { return allPins_; }

private:
    static constexpr int allPins_{10};
};

class Ball
{
public:
    Ball() {}
    ~Ball() {}

    int firstThrowBall() const;
    int randomThrow(int max) const;
    int secondThrowBall(const int& firstThrow) const;
    int setAllPinsInTrack() const { return pins_.getAllPins(); }

private:
    Pins pins_;
};

class Teable
{
public:
    Teable() {}
    ~Teable() {}

    Points getPointTeable() const;
    void setFirstAndSecondPointInTeable(const int& first, const int& second);
    void setOnlyFirstPointInTeable(const int& first);

private:
    Points pointTeable_;
    Ball ball_;
};
