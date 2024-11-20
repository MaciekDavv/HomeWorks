// Wygeneruj zbiór liczb od -20 do 20 i zapisz go w std::set w kolejności malejącej
// Wstaw nowe elementy: -10, 0, 10, 100, -100
// Wygeneruj drugi zbiór z liczb od 0 do 40 i zapisz go w std::multiset
// Wstaw nowe elementy: -10, 0, 10, 100, -100
// Połącz oba zbiory w jeden (ma to być std::multiset)
// Znajdź wszystkie elementy równe 0 i 50
// Co każdy krok wypisuj zawartości kontenerów.

#include <functional>
#include <numeric>
#include <vector>
#include <set>
#include <iostream>

auto print = [](const auto& el){ std::cout << el << ", "; };

int main()
{
    std::vector<int> vec(41);
    //vec.reserve(50);
    std::iota(vec.begin(), vec.end(), -20);

    std::for_each(vec.begin(), vec.end(), print);
    std::cout << "\n";
    std::cout << "\n";

    std::set<int, std::greater<int>> set{vec.begin(), vec.end()};

    std::for_each(set.begin(), set.end(), print);
    std::cout << "\n";
    std::cout << set.size() << "\n";
    std::cout << "\n";

    set.insert(-10);
    set.insert(0);
    set.insert(10);
    set.insert(100);
    set.insert(-100);

    std::for_each(set.begin(), set.end(), print);
    std::cout << "\n";
    std::cout << set.size() << "\n";
    std::cout << "\n";

    std::iota(vec.begin(), vec.end(), 0);
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << "\n";
    std::cout << "\n";

    std::multiset<int> mset = {vec.begin(), vec.end()};
    std::for_each(mset.begin(), mset.end(), print);
    std::cout << "\n";
    std::cout << mset.size() << "\n";
    std::cout << "\n";

    mset.insert(-10);
    mset.insert(0);
    mset.insert(10);
    mset.insert(100);
    mset.insert(-100);
    
    std::for_each(mset.begin(), mset.end(), print);
    std::cout << "\n";
    std::cout << mset.size() << "\n";
    std::cout << "\n";    


    return 0;
}