#include "Player.hpp"
#include <catch2/catch_all.hpp>
#include <algorithm>
#include <sstream>

TEST_CASE( "Get input form kaybord numbers", "[input]" ) {
    Player player;
    SECTION("corect number between 1 - 10") {
        auto generate = GENERATE("0", "5", "10");
        std::istringstream input(generate);
        std::streambuf* originalCin = std::cin.rdbuf();
        std::cin.rdbuf(input.rdbuf());

        REQUIRE_THAT(player.getNumberFromUser(), Catch::Matchers::Predicate<int>([](const auto& nr) {
                                                 return nr >= 0 && nr <= 10; } , "is between 0 and 10"));
        std::cin.rdbuf(originalCin);
    }
    SECTION("wrong number") {
        auto generate = GENERATE("-1", "11");
        std::istringstream input(generate);
        std::streambuf* originalCin = std::cin.rdbuf();
        std::cin.rdbuf(input.rdbuf());

        REQUIRE_THROWS(player.getNumberFromUser(), "less or greter than 1- 10");
        // REQUIRE_THAT(player.getNumberFromUser(), Catch::Matchers::Predicate<int>([](const auto& nr) {
        //                                          return nr < 0 || nr >= 10; } , "is less than 0 or greater than 10"));
        std::cin.rdbuf(originalCin);
    }

}

TEST_CASE( "Take the input and push to de table", "[teable]" ) {

    auto ture = std::make_shared<Ture>();
    Player player;
    // SECTION("push nuber and inrease boowl and round vector") {
    //     ture.addPinsToBoowl(1);
    //     ture.addPinsToBoowl(5);
    //     REQUIRE_THAT(ture.getBoowl(), Catch::Matchers::Equals(std::vector<int>{1, 5}));
    // }
    SECTION("add pins to the bowl in first and second throw") {
        auto input = player.getNumberFromUser();
        if (ture->getBoowl().size() < 2) {
            ture->addPinsToBoowl(input);
        }
        player.addTureToRound(ture);

        REQUIRE(ture->getBoowl().size() == 1);
        REQUIRE_THAT(ture->getBoowl(), Catch::Matchers::Equals(std::vector<int>{10}));
        REQUIRE(player.getRound().size() == 1);
        REQUIRE_THAT(player.getRound().at(0)->getBoowl(), Catch::Matchers::Equals(std::vector<int>{10}));
        // auto input2 = player.getNumberFromUser();
        // //letRool(input2);
        // if (ture.getBoowl().front() < 10 || ture.getBoowl().size()  2) {
        //     ture.addPinsToBoowl(input2);
        // }
        // //REQUIRE_THAT(ture.getBoowl(), Catch::Matchers::Equals(std::vector<int>{2}));
        // REQUIRE_THAT(player.getTure()->getBoowl(), Catch::Matchers::Equals(std::vector<int>{2}));
    }
}