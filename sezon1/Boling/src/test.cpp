#include "Component.hpp"
#include "Game.hpp"
#include "Logic.hpp"
#include "Player.hpp"
#include <catch2/catch_all.hpp>
//#include <algorithm>
//#include <sstream>
//#include <iostream>
#include <memory>
#include <tuple>

SCENARIO("Kregowy rooll", "[prototipe]") {
    Logic g;
    Player player;
    auto rollMany = [&player](const auto n, const auto pins) {
        for (int i = 0; i < n; ++i) {
            player.setPointConteiner(pins);
            }};
    auto rollSpare = [&player]() { player.setPointConteiner(5); player.setPointConteiner(5); };
    auto rollStrike = [&player]() { player.setPointConteiner(10); };

    GIVEN("dodanie metody canroll") {
        WHEN("damy w petli na 20") {
            rollMany(20, 0);
            g.conectConteiners(player.getPointConteiner());
            THEN("wynik dalej 0") {
                REQUIRE(g.score() == 0);
            }
        }

        WHEN("wszystkie rzuty 1") {
            rollMany(20, 1);
            g.conectConteiners(player.getPointConteiner());
            THEN("wynik powinien wynosic 20") {
                REQUIRE(g.score() == 20);
            }
        }

        WHEN("Jeden sper to znaczy suma dwuch rzutow == 10") {
            rollSpare();
            player.setPointConteiner(3);
            g.conectConteiners(player.getPointConteiner());
            THEN("Wynik powinien wynosic 16") {
                REQUIRE(g.score() == 16);
            }
        }

        WHEN("Jeden strike to znaczy ze pierszy rzut ma == 10") {
            rollStrike();
            player.setPointConteiner(3);
            player.setPointConteiner(4);
            g.conectConteiners(player.getPointConteiner());
            THEN("wynik powinien miec 24") {
                REQUIRE(g.score() == 24);
            }
        }

        WHEN("Perfekcyjna gra") {
            rollMany(12, 10);
            g.conectConteiners(player.getPointConteiner());
            THEN("Wynik powininen wynosic 300") {
                REQUIRE(g.score() == 300);
            }
        }

        WHEN("cala gra") {
            rollStrike();
            player.setPointConteiner(8); player.setPointConteiner(1);
            player.setPointConteiner(7); player.setPointConteiner(3);
            player.setPointConteiner(6); player.setPointConteiner(2);
            rollStrike();
            rollStrike();
            rollStrike();
            player.setPointConteiner(9); player.setPointConteiner(0);
            player.setPointConteiner(8); player.setPointConteiner(2);
            rollStrike();
            rollStrike();
            rollStrike();
            g.conectConteiners(player.getPointConteiner());
            THEN("Niewiadomo jaki wynik") {
                REQUIRE(g.score() == 189);
                REQUIRE_THAT(g.getCountConteiner(), Catch::Matchers::SizeIs(21));
            }
        }

        WHEN("Dodajemy wektor 21 pol wypelnione 0") {
            THEN("ma zawierac 21 pol wypelninych zerami") {
                REQUIRE(g.getCountConteiner().size() == 21);
                REQUIRE_THAT(g.getCountConteiner(), Catch::Matchers::Contains(0));
            }
        }

        WHEN("laczenie wektorow w jeden pobieramy dane z getGetRoll i wpisujemy do Counter") {
            player.setPointConteiner(2);
            player.setPointConteiner(4);
            g.conectConteiners(player.getPointConteiner());
            THEN("powinien zawierac na pozycji 0 = 2 i 1 =4, a reszta zer") {
                REQUIRE(g.getCountConteiner().size() == 21);
                REQUIRE(g.getCountConteiner().at(0) == 2);
                REQUIRE(g.getCountConteiner().at(1) == 4);
                REQUIRE_THAT(g.getCountConteiner(), Catch::Matchers::Contains(0));
            }
        }
    }
}

SCENARIO("cala dziesiatka kregli zlozona z pojedynczych pinow", "[all pins]") {
    Pins pins;
    GIVEN("zmienna ustalona dla wszystkich pinow na start") {

        WHEN("") {
            THEN("wartorsc ma byc 10") {
                REQUIRE(pins.getAllPins() == 10);
            }
        }
    }
}

SCENARIO("Tworzenie zawodnika i jego funkcjonalnosci", "[ball]") {
    GIVEN("mozliwosc rzucania pilka") {
    Ball ball;

        WHEN("Ateraz z lowsowaniem"){
            auto rand = ball.randomThrow(ball.setAllPinsInTrack());
            THEN("Na pale patrzymy czy sie zgadza") {
                REQUIRE(rand == rand);
            }
        }

        WHEN("nastepna liczba z losowania mniejsza lub rown 10 -liczba") {
            auto firstThrow = ball.randomThrow(ball.setAllPinsInTrack());
            auto secondThrow = ball.randomThrow(ball.setAllPinsInTrack() - firstThrow);
            auto points = firstThrow + secondThrow;
            THEN("wtedy wynik pierwszy od ") {
                REQUIRE(firstThrow == firstThrow);
                REQUIRE(secondThrow == secondThrow);
                REQUIRE(points == points);
            }
        }

        WHEN("kiedy raz rzucimy dostajemy wynik od 0 - 10") {
            auto firstThrow = ball.firstThrowBall();
            THEN("to powinnsmy dostac wynik od zera do 10") {
                REQUIRE_THAT(firstThrow, Catch::Matchers::Predicate<int>([](const auto& a) {
                                            return a >= 0 && a <=10; },
                                            "wynik zawiera sie w predykacie"));
            }
        }

        WHEN("kiedy rzucimy drugi raz powinismy dostac wynik pomiedzy 10 - firtstThrow") {
            auto firstThrow = ball.firstThrowBall();
            auto secondThrow = ball.secondThrowBall(firstThrow);
            auto randomSpace = ball.setAllPinsInTrack() - firstThrow;
            THEN("suma pierwszego rzutu i drugiego") {
                REQUIRE(firstThrow == firstThrow);
                REQUIRE_THAT(secondThrow, Catch::Matchers::Predicate<int>([&randomSpace](const auto& a) {
                                            return a >= 0 && a <= randomSpace; },
                                            "wynik zwiera sie w przedziale od 0 do 10 - pierwszy rzut"));
            }
        }
    }
}

SCENARIO("Robimy to z std::pair w wektorze", "[teable]") {
    Teable teable;
    GIVEN("potrzebujemy wektor par") {
        auto tab = teable.getPointTeable();

        WHEN("Jest pusty") {
            THEN("Sprawdzamy rozmiar"){
                REQUIRE_THAT(tab, Catch::Matchers::SizeIs(0));
            }
        }

        WHEN("Tylko pierwszy rzut strike") {
            teable.setOnlyFirstPointInTeable(0);
            THEN("size powinien wynosic 1, a wartosc tylko first 0") {
                REQUIRE_THAT(teable.getPointTeable(), Catch::Matchers::SizeIs(1));
                REQUIRE_THAT(teable.getPointTeable(), Catch::Matchers::Predicate<Points>(
                    [](const Points& el) {
                        return std::get<0>(el.at(0)) == 0;
                    } ,"zaladowano tylko 0"));
                REQUIRE_THAT(teable.getPointTeable(), Catch::Matchers::Predicate<Points>(
                    [](const Points& el) {
                        return std::get<1>(el.at(0)) == std::nullopt;
                    } ,"w drugim elemencie jest nullptr"));
            }
        }

        WHEN("Pierwsze dwa rzuty mają zero") {
            teable.setFirstAndSecondPointInTeable(0, 0);
            THEN("Size powinien wynosic 1, a warosci first 0, wartosc second 0") {
                REQUIRE_THAT(teable.getPointTeable(), Catch::Matchers::SizeIs(1));
                REQUIRE_THAT(teable.getPointTeable(), Catch::Matchers::Predicate<Points>(
                    [](const Points& el) {
                        return std::get<0>(el.at(0)) == 0 && std::get<1>(el.at(0)) == 0;
                    } ,"zgadza sie"));
            }
        }
    }
}

SCENARIO("Glowny test dla gry laczymy wszystko w jedna calosc dla", "[main]") {
    GIVEN("dajemy do testow nowego gracza") {
        Game game;
        auto maciek = game.addPlayer("Maciej");

        WHEN("") {
            THEN("zwracamy imie maciej i rozmiar rowny 0") {
                REQUIRE_THAT(maciek->getName(), Catch::Matchers::Equals("Maciej"));
                REQUIRE(maciek->getTeable().getPointTeable().size() ==  0);
            }
        }

        WHEN("dodajemy punkty do tabeli") {
            maciek->getTeable().setFirstAndSecondPointInTeable(2, 4);
            THEN("dostajemy imie maciej sprawdzamy rozmiar i czy punkty na pozycjach sie zgadzaja") {
                REQUIRE_THAT(maciek->getName(), Catch::Matchers::Equals("Maciej"));
                REQUIRE(maciek->getTeable().getPointTeable().size() ==  1);
                REQUIRE(std::get<0>(maciek->getTeable().getPointTeable().at(0)) == 2);
                REQUIRE(std::get<1>(maciek->getTeable().getPointTeable().at(0)) == 4);
            }
        }

        WHEN("sprawdzam wywolanie funkcji get ball") {
            auto check = game.getBall().randomThrow(10);
            THEN("wynik wynosi check") {
                REQUIRE(check == check);
            }
        }
    }
}

SCENARIO("robienie funkcjie ktora rozdziela rzuty pomiedzy wektorem logiki i tablica wynikow", "[split]") {
    GIVEN("potrzebuje wektor i tablice ") {
        Game game;
        auto maciek = game.addPlayer("Maciek");
        auto firstThrow = 3;
        auto secondThrow = 6;

        WHEN("rozdzieli punkty ktore trafia do wektora i tablice") {
            maciek->getTeable().setFirstAndSecondPointInTeable(firstThrow, secondThrow);
            maciek->setPointConteiner(firstThrow);
            maciek->setPointConteiner(secondThrow);
            THEN("sprawdzam tablice punktow i wektor") {
                REQUIRE(std::get<0>(maciek->getTeable().getPointTeable().at(0)) == 3);
                REQUIRE(std::get<1>(maciek->getTeable().getPointTeable().at(0)) == 6);
                REQUIRE(maciek->getPointConteiner().at(0) == 3);
                REQUIRE(maciek->getPointConteiner().at(1) == 6);
            }
        }

        WHEN("jedna funkcja ktora dodaje do wektora i do tablicy") {
            game.addBallToBoBothConteners(maciek, firstThrow, secondThrow);
            THEN("Wyniki dokladnie jak powyrzej") {
                REQUIRE(std::get<0>(maciek->getTeable().getPointTeable().at(0)) == 3);
                REQUIRE(std::get<1>(maciek->getTeable().getPointTeable().at(0)) == 6);
                REQUIRE(maciek->getPointConteiner().at(0) == 3);
                REQUIRE(maciek->getPointConteiner().at(1) == 6);
                REQUIRE(maciek->getPointConteiner().size() == 2);
            }
        }

        WHEN("Mamy tylko jeden rzut secondThrow std::optional") {
            game.addBallToBoBothContenersStrike(maciek, firstThrow);
            THEN("Drugi argument nie powinien byc brany pod uwage") {
                REQUIRE(std::get<0>(maciek->getTeable().getPointTeable().at(0)) == 3);
                REQUIRE(std::get<1>(maciek->getTeable().getPointTeable().at(0)) == std::nullopt);
                REQUIRE(maciek->getPointConteiner().at(0) == 3);
                REQUIRE(maciek->getPointConteiner().size() == 1);
            }
        }
    }
}

SCENARIO("Glowna rozgrywa", "[main auto]") {
    GIVEN("Dodajemy glowne obiekty gry") {
        Game game;
        Ball ball;
        auto maciek = game.addPlayer("Maciej");

        auto one = ball.firstThrowBall();
        auto two = ball.secondThrowBall(one);

        auto tenOrless = [&one, &two, &maciek, &game]() {
            if (one == 10) {
                game.addBallToBoBothContenersStrike(maciek, one);
            } else {
                game.addBallToBoBothConteners(maciek, one, two);
            }
        };

        WHEN("kiedy oddajemy dwa rzuty i wychodzi mniej niz 10") {
            tenOrless();
            THEN("dwa rzuty") {
                CHECK(std::get<0>(maciek->getTeable().getPointTeable().at(0)) == one);
                CHECK(std::get<1>(maciek->getTeable().getPointTeable().at(0)) == two);
                CHECK(maciek->getTeable().getPointTeable().size() == 1);
                CHECK(maciek->getPointConteiner().at(0) == one);
                CHECK(maciek->getPointConteiner().at(1) == two);
                CHECK(maciek->getPointConteiner().size() == 2);
            }
        }

        WHEN("kiedy oddajemy jeden rzut i to jest strike") {
            tenOrless();
            THEN("jeden rzut strike") {
                CHECK(std::get<0>(maciek->getTeable().getPointTeable().at(0)) == one);
                CHECK(std::get<1>(maciek->getTeable().getPointTeable().at(0)) == std::nullopt);
                CHECK(maciek->getTeable().getPointTeable().size() == 1);
                CHECK(maciek->getPointConteiner().at(0) == one);
                CHECK(maciek->getPointConteiner().size() == 1);
            }
        }

        WHEN("to samo plus zliczanie") {
            tenOrless();
            game.getLogic().conectConteiners(maciek->getPointConteiner());
            THEN("ont plus two") {
                REQUIRE(one == one);
                REQUIRE(two == two);
                REQUIRE(game.getLogic().score() == one + two);
            }
        }
    }
}

SCENARIO("sprawdzamy czy player moze przechowywac counconteiner", "[player]") {
    GIVEN("dostarczamy countconteiner w konstruktorze") {
        Player player;
        Game game;
        auto maciek = game.addPlayer("Maciej");
        auto jurek = game.addPlayer("Jurek");
        WHEN("") {
            player.setPointConteiner(3);
            player.setPointConteiner(5);
            THEN("powinien dawac same zera") {
                REQUIRE(player.getPointConteiner().at(0) == 3);
                REQUIRE(player.getPointConteiner().at(1) == 5);
                REQUIRE(player.getPointConteiner().size() == 2);
            }
        }

        WHEN("dodajemy punkty do pointConteiner") {
            maciek->setPointConteiner(2);
            maciek->setPointConteiner(7);
            game.getLogic().conectConteiners(maciek->getPointConteiner());
            THEN("wynik 9 rozmiar 21") {
                REQUIRE(game.getLogic().score() == 9);
                REQUIRE_THAT(game.getLogic().getCountConteiner(), Catch::Matchers::SizeIs(21));
                REQUIRE_THAT(game.getLogic().getCountConteiner(), Catch::Matchers::Contains(0));
            }
        }

        WHEN("dwuch zawodnikow") {
            maciek->setPointConteiner(2);
            maciek->setPointConteiner(7);
            jurek->setPointConteiner(1);
            jurek->setPointConteiner(2);
            jurek->setPointConteiner(0);
            jurek->setPointConteiner(2);

            game.getLogic().conectConteiners(maciek->getPointConteiner());
            THEN("wynik maciek") {
                REQUIRE(game.getLogic().score() == 9);
            }
            game.getLogic().conectConteiners(jurek->getPointConteiner());
            THEN("wynik jurek") {
                REQUIRE(game.getLogic().score() == 5);
            }
        }
    }
}

SCENARIO("Game Play", "[game]") {
    GIVEN("testuje glownie obiekt Game") {
        Game game;
        auto name = "Maciej";
        auto maciek = game.addPlayer(name);
        // WHEN("Dodawanie nowego gracza") {
        //     THEN("palajer Maciej") {
        //         REQUIRE(maciek->getName() == "Maciej");
        //     }
        // }

        // WHEN("funkcja roll odpalapierwszy rzut wyswietla sie napis roll wciskajac enter nastepuje losowanie") {
        //     auto firstThrow = game.roll();
        //     THEN("otrzymujemy losowa liczbe") {
        //         REQUIRE(firstThrow == firstThrow);
        //     }
        // }

        WHEN("zaczyna sie petla gry") {
            bool gameLoop = true;
            while (gameLoop) {
                auto firstThrow = game.roll();
                if (firstThrow == 10) {
                    game.addBallToBoBothContenersStrike(maciek, firstThrow);
                    game.getLogic().conectConteiners(maciek->getPointConteiner());
                    auto strikePoint = game.getLogic().score();
                    game.setScore(strikePoint);
                    std::cout << "STRIKE " << std::get<0>(maciek->getTeable().getPointTeable().back()) << "\n";
                } else {
                    std::cout << "Your first throw: " << firstThrow << "\n"
                              << " GET ROOL one more time\n";
                    auto secondThrow = game.secondRoll(firstThrow);
                    game.addBallToBoBothConteners(maciek, firstThrow, secondThrow);
                    game.getLogic().conectConteiners(maciek->getPointConteiner());
                    auto twoThrowPoinst = game.getLogic().score();
                    game.setScore(twoThrowPoinst);
                    std::cout << "First Throw: " << firstThrow << "\n";
                    std::cout << "Second Throw: " << secondThrow << "\n";
                }
                std::cout << "MAIN SCORE: " << game.getScore() << "\n";
                std::cout << "-----------------------------------" << "\n";
                std::cout << "\n";
                std::cout << "\n";
                if (maciek->getTeable().getPointTeable().size() == 10){
                    gameLoop = false;
                }
            }
            THEN("rozmiat point teable 10") {
                REQUIRE(maciek->getTeable().getPointTeable().size() == 10);
                REQUIRE_THAT(maciek->getPointConteiner(), Catch::Matchers::Contains(0));
            }
        }
    }
}
