#include <iostream>
#include <array>
#include <algorithm>

std::array<int, 10> arr;
std::array<int, 10> brr;

auto print = [](const int& n) {std::cout << n << ' ';};

int main ()
{
    arr.fill(5);
    brr.fill(2);
    std::for_each(arr.cbegin(), arr.cend(), print);
    std::cout << '\n';
    std::for_each(brr.cbegin(), brr.cend(), print);
    std::cout << '\n';

    arr.at(2) = 3;
    brr.at(9) = 8;
    std::for_each(arr.cbegin(), arr.cend(), print);
    std::cout << '\n';
    std::for_each(brr.cbegin(), brr.cend(), print);
    std::cout << '\n';

    std::swap(arr, brr);
    std::for_each(arr.cbegin(), arr.cend(), print);
    std::cout << '\n';
    std::for_each(brr.cbegin(), brr.cend(), print);
    std::cout << '\n';

    return 0;
}