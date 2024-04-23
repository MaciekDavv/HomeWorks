#include "ship.hpp"


int main() {

    auto aple = std::make_shared<Fruit>(54, "apple", 54, 14, 6);
    auto johenson = std::make_shared<Alcohol>(3,"Jameson", 45, 40);
    auto bober = std::make_shared<Item>(43, "Bober", 12, Item::Rarity::rare);
    auto banana = std::make_shared<Fruit>(5, "Banana", 45.3, 34, 12);

    Ship statek;
    statek.addLoad(aple);
    statek.addLoad(banana);

    statek.read();




    return 0;
}