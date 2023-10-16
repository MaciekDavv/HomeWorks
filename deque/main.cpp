#include <iostream>
#include <deque>

void print(std::deque<int>& deq) {
    for(const int& el : deq) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

int main ()
{
    std::deque<int> deq{11, 22, 33, 44, 55};
    print(deq);

    auto it =  deq.begin();
    std::advance(it, 1);
    deq.erase(it);

    it = deq.begin();
    std::advance(it, 2);
    deq.erase(it);

    print(deq);

    deq.push_back(30);
    deq.push_front(30);

    print(deq);

    it = deq.begin();
    std::advance(it, 3);
    deq.insert(it, 20);

    print(deq);
    
    return 0;
}
