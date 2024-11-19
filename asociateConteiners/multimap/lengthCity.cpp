// Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy też dane 4 miast:

// Wrocław (x = 17, y = 51)
// Moskwa (x = 37, y = 55)
// Nowy Jork (x = -74, y = 40)
// Sydney (x = 151, y = -33)

// Część A - łatwiejsza
// Stwórz std::map<std::string, Point>, która będzie przechowywać powyższe miejsca
// Sprawdź czy w mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
// Pobierz i wypisz współrzędne Sydney

// Część B - trudniejsza
// Skopiuj te dane do mapy std::map<Point, std::string>
// Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
// Pobierz i wypisz współrzędne Sydney

#include <iostream>
#include <map>
#include <cmath>

struct Point;
double radius(Point p);

struct Point
{
    int x;
    int y;

    bool operator<(const Point& other) const {
        return x < other.x && y < other.y;
    }
};

double radius(Point p) {
    return std::hypot(p.x, p.y);
}

int main()
{
    std::map<std::string, Point> mapCity = {
        {"Wrocław", {17, 51}},
        {"Moskwa", {37, 55}},
        {"Nowy Jork", {-74, 40}},
        {"Sydney", {151, -33}}
    };

    auto isClouserThan70 = [](auto point){ return radius(point) < 70; };

    for (const auto& [town, point] : mapCity) {
        if(isClouserThan70(point)) {
            std::cout << town << ": " << radius(point) << "\n";
        }
    }
    auto it = mapCity.find("Sydney");
    std::cout << "x: " << it->second.x << " y: " << it->second.y << "\n";

    auto compRadius = [](const auto& lhs, const auto& rhs) {
        return radius(lhs) < radius(rhs);
    };

    std::map<Point, std::string, decltype(compRadius)> mapCityInvert(compRadius);
    mapCityInvert = {
        {{17, 51}, "Wrocław"},
        {{37, 55}, "Moskwa"},
        {{-74, 40}, "Nowy Jork"},
        {{151, -33}, "Sydney"}
    };

    for (const auto& [point, town] : mapCityInvert) {
        if(isClouserThan70(point)) {
            std::cout << town << ": " << radius(point) << "\n";
        }
    }

    for (const auto& [point, town] : mapCityInvert) {
        if (town == "Sydney") {
            std::cout << "x: " << point.x << " y: " << point.y << "\n";
        } else {
            std::cout << "IS NOTHIG!" << "\n";
        }
    }
    
    return 0;
}
