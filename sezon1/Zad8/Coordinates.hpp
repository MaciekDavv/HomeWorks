#pragma once

#include <cstddef>
#include <cmath>

class Coordinates {
    public:
    Coordinates(int positionX, int positionY)
                : positionX_(positionX)
                , positionY_(positionY)
    {}

    bool operator==(const Coordinates& other) {
        return (this->positionX_ == other.positionX_) && (this->positionY_ == other.positionY_);
    }
    static size_t distance(const Coordinates& lhs, const Coordinates& rhs) {
        auto toSize = std::sqrt(std::pow(static_cast<double>(lhs.positionX_ - rhs.positionX_), 2)
                         + std::pow(static_cast<double>(lhs.positionY_ - rhs.positionY_), 2));
        return static_cast<size_t>(toSize);
    }

    private:
    const int positionX_{0};
    const int positionY_{0};
};
