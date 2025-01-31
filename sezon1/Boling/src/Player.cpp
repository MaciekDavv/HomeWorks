#include "Player.hpp"

Player::Player(const std::string& name) : name_(name)
{}

void Player::setPointConteiner(const int& pins) {
    pointCointeiner_.push_back(pins);
}
