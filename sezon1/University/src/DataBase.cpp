#include "DataBase.hpp"
#include <iostream>

void DataBase::add(const Student& s) {
    students_.push_back(s);
}

void DataBase::display() const {
    std::cout << show();
}

std::string DataBase::show() const {
    std::string result = "";
    for (auto && student : students_) {
        result += student.show();
    }
    return result;
}