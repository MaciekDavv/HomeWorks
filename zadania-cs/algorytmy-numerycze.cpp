// Utwórz wektor v1 z liczbami od 1 do 1000
// Oblicz sumę tych liczb
// Utwórz wektor v2 z 1000 elementów powtarzających się w następującej sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ...
// Oblicz iloczyn skalarny wektorów v1 i v2
// Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z wektora v2

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <execution>
#include <functional>

std::vector<int> generateSequence(std::vector<int>& vec) {
    std::vector<int> sequence = {-1, 0, 1, 0};
    for (size_t i = 0; i < 250; ++i) {
        std::copy(sequence.begin(), sequence.end(), std::back_inserter(vec));
    }
    return vec;
}

int main ()
{
    std::vector<int> v1(1000);
    std::iota(v1.begin(), v1.end(), 1);
    auto sum = std::reduce(v1.begin(), v1.end(), 0, std::plus<int>());
    std::cout << "sum = " << sum;

    std::vector<int> v2;
    generateSequence(v2);
    std::cout << std::endl;

    std::cout << v2.size();
    std::cout << std::endl;

    for (const auto el : v2) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    return 0;
}