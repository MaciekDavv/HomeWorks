#include "Game.hpp"

std::shared_ptr<Player> Game::addPlayer(const std::string& name) {
   return std::make_shared<Player>(name);
}

void Game::addBallToBoBothConteners(std::shared_ptr<Player> player, const int& firstThrow, const int& secondThrow) {
    player->setPointConteiner(firstThrow);
    player->setPointConteiner(secondThrow);
    player->getTeable().setFirstAndSecondPointInTeable(firstThrow, secondThrow);
}

void Game::addBallToBoBothContenersStrike(std::shared_ptr<Player> player, const int& firstThrow) {
    player->setPointConteiner(firstThrow);
    player->getTeable().setOnlyFirstPointInTeable(firstThrow);
}

int Game::roll(){
    std::cout << "push leter and enter to ROOL\n";
    std::string forPush;
    std::cin >> forPush;
    return getBall().firstThrowBall();
}

int Game::secondRoll(const int& firstThrow) {
    std::cout << "push leter and enter to ROOL\n";
    std::string forPush;
    std::cin >> forPush;
    return getBall().secondThrowBall(firstThrow);
}

void Game::GamePlay() {
    std::cout << "Tojet gra w kręgle podaj swoje imie: ";
    std::cin >> playerName_;
    auto player1 = addPlayer(playerName_);
    std::cout << "Czesc " << player1->getName() << " no to zaczynamy \n";


}