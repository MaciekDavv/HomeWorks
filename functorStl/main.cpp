#include <iostream>
#include <vector>
#include <algorithm>

struct checkDevideBy6 {
    void operator() (int element) {
        if (element % 6 == 0) {
            std::cout << "This is number devide by 6: " << element << '\n';
        }
    }
};

std::vector<int> myVec {1, 2, 3, 6, 42, 18, 54, 33};
int main()
{
    std::for_each(myVec.begin(), myVec.end(), checkDevideBy6{});
    return 0;
}