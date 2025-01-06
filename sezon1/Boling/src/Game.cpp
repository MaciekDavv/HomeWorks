#include "Game.hpp"

Game::Game()
{}
Game::~Game()
{}

int Game::getNumberFromUser() {
    auto number{0};
    std::cin >> number;
    if (number < 0 || number > 10) {
        throw std::invalid_argument("Wrong number is less or greter");
    }
    return number;
}