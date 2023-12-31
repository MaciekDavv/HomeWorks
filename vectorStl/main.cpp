#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec {1, 2, 4, 5, 6};
auto print = [](const int& n) {std::cout << n << ' ';};

int main ()
{
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';

    vec.erase(vec.begin());
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';

    vec.push_back(5);
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';

    vec.emplace(vec.begin(), 12);
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';

    std::cout << "Vector size: " << vec.size() << " Vector capacity: " << vec.capacity() << '\n';
    vec.clear();
    
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';    
    std::cout << "Vector size: " << vec.size() << " Vector capacity: " << vec.capacity() << '\n';

    return 0;
}
