#include "Coordinates.hpp"
#include <iostream>


int main() {
    Coordinates x{-45, 20};
    Coordinates y{35, -15};
    
    std::cout << Coordinates::distance(x, y);

    return 0;
}
