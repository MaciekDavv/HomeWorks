#include "Player.hpp"

Ture::Ture()
{}
Ture::~Ture()
{}

void Ture::setPinsInBoowl(const int& pins) {
    boowl_.push_back(pins);
}
std::vector<int> Ture::getBoowl() const {
    return boowl_;
}

/////////////////////////////////////////////////////////////////////

Player::Player()
{}
Player::~Player()
{}



void Player::addTureToRound(const std::shared_ptr<Ture>& ture) {
    round_.push_back(ture);
}