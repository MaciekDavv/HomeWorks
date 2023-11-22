#include <iostream>

auto sum = [](int a, int b){return a + b;};

int main ()
{
    std::cout << sum(6, 2) << '\n';
    return 0;
}