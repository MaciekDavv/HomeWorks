#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <iterator>

template <typename T>
auto middle(T first, T last) {
    auto it = std::distance(first, last);
    std::advance(first, it / 2);
    return *first;
}

int main()
{
    std::array<int, 7> arr{2, 3, 4, 5, 7, 8, 6};
    std::vector<int> vec{3, 9, 3, 5, 6, 4, 6, 7, 9, 56};
    std::deque<int> deq{4, 2, 4, 8, 2, 9, 3, 2};
    std::forward_list<int> flis{1, 4, 5, 2, 6, 3, 6, 6, 5, 7, 2, 3, 4, 5};
    std::list<int> lis{4, 6, 3, 2, 5, 3};

    std::cout << middle(arr.begin(), arr.end());
    std::cout << '\n';
    std::cout << middle(vec.begin(), vec.end());
    std::cout << '\n';
    std::cout << middle(deq.begin(), deq.end());
    std::cout << '\n';
    std::cout << middle(lis.begin(), lis.end());
    std::cout << '\n';
    std::cout << middle(flis.begin(), flis.end());
    std::cout << '\n';

    return 0;
}