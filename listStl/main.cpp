#include <iostream>
#include <list>
#include <array>

std::list<int> list{0, 1, 2, 3, 4, 5};
std::array<int, 8> arr;

void print(const std::list<int>& li) {
    for (const auto& el : li) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

int main ()
{
    print(list);

    auto it = list.begin();
    std::advance(it, 2);
    list.erase(it);
    print(list);

    list.emplace_front(10);
    list.emplace_back(20);
    print(list);

    it = list.begin();
    std::advance(it, 3);
    list.emplace(it, 100);
    print(list);

    int k;
    for (auto const& el : list) {
        arr[k++] = el;
    }

    for (auto const& arrEl : arr) {
        std::cout << arrEl << " ";
    }
    std::cout << '\n';
    std::cout << arr[0] << " " << arr.at(7) << '\n';

    return 0;
}