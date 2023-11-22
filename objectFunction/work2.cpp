#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<char> star;
std::vector<int> freeInts{5, 3, 52, 65, 2, 6};
auto function = [](auto word){std::cout << "\"" << word << "\""  << '\n';};
auto print = [](auto symbol){std::cout << symbol;};
auto printInts = [](auto number){std::cout << number << " ";};
auto inSideVector = [](auto toPrint){
    for(auto const& element : toPrint) {
        std::cout << element << " ";
    }
    std::cout << '\n';
};

int main()
{
    char symbol {'*'};
    function("baranek");

    auto addStar = [symbol](std::vector<char>& vec){
        vec.push_back(symbol);
        std::for_each(vec.begin(), vec.end(), print);
        std::cout << '\n';
    };

    addStar(star);
    addStar(star);
    addStar(star);
    addStar(star);
    addStar(star);
    addStar(star);

    inSideVector(freeInts);
    std::for_each(freeInts.begin(), freeInts.end(), printInts);
    std::cout << '\n';

    return 0;
}