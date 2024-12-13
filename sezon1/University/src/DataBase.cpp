#include "DataBase.hpp"

#include <algorithm>
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

School DataBase::searchStudentByLastName(const std::string& lastName) {
    auto searchLastName = [&lastName](const Student& student) { return lastName == student.getLastName(); };
    auto it = std::find_if(students_.cbegin(), students_.cend(), searchLastName);
    return it;
}

School DataBase::searchStudentByPesel(const std::string& pesel) {
    auto searchPesel = [&pesel](const Student& student) { return pesel == student.getPesel(); };
    auto it = std::find_if(students_.cbegin(), students_.cend(), searchPesel);
    return it;
}