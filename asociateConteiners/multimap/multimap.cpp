// Stwórz multimapę i wypełnij ją podanymi wartościami
// map.insert({5, "Ala"});
// map.insert({5, "Ma"});
// map.insert({5, "Kota"});
// map.insert({5, "A"});
// map.insert({5, "Kot"});
// map.insert({5, "Ma"});
// map.insert({5, "Ale"});
// Napisz funkcję, która wyświetli słowa w mapie o liczbie znaków równej 3.

#include <iostream>
#include <map>


void insertMap(std::multimap<int, std::string>& map) {
    map.insert({5, "Ala"});
    map.insert({5, "Ma"});
    map.insert({5, "Kota"});
    map.insert({5, "A"});
    map.insert({5, "Kot"});
    map.insert({5, "Ma"});
    map.insert({5, "Ale"});
}

void readTreeLettersFromMap(std::multimap<int, std::string>& map) {
    auto it = map.find(5);
    for (; it != map.end(); ++it) {
        if (it->second.size() == 3) {
            std::cout << "Kay: " << it->first << " | " << "Value: " << it->second << '\n';
        }
    }
}

int main()
{
    std::multimap<int, std::string> map;
    insertMap(map);
    readTreeLettersFromMap(map);

    return 0;
}