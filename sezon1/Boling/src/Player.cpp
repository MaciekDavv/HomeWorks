#include "Player.hpp"

Ture::Ture()
{}
Ture::Ture(const int& pins) : pins_(pins)
{}
Ture::~Ture()
{}

int Ture::setPin(const int& pins) {
    return pins_ = pins;
}
void Ture::addPinsToBoowl(const int& pins) {
    setPin(pins);
    boowl_.push_back(pins_);
}
std::vector<int> Ture::getBoowl() const {
    return boowl_;
}


Player::Player()
{}
Player::~Player()
{}

int Player::getNumberFromUser() {
    auto number{0};
    std::cin >> number;
    if (number < 0 || number > 10) {
        throw std::invalid_argument("Wrong number is less or greter");
    }
    return number;
}

void Player::addTureToRound(std::shared_ptr<Ture> ture) {
    round_.push_back(ture);
}