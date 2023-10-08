#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;
auto print = [](const int& n) {std::cout << n << ' ';};

int main ()
{
    std::cout << "Vector size: " << vec.size() << " Vector capacity: " << vec.capacity() << '\n';
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';
    
    vec.reserve(10);
    vec.insert(vec.begin(), 10, 5);
    std::cout << "Vector size: " << vec.size() << " Vector capacity: " << vec.capacity() << '\n';
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';

    vec.reserve(20);
    std::cout << "Vector size: " << vec.size() << " Vector capacity: " << vec.capacity() << '\n';
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';

    vec.shrink_to_fit();
    std::cout << "Vector size: " << vec.size() << " Vector capacity: " << vec.capacity() << '\n';
    std::for_each(vec.cbegin(), vec.cend(), print);
    std::cout << '\n';

    return 0;
}
