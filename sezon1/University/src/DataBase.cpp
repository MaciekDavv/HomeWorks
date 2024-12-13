#include "DataBase.hpp"

#include <algorithm>
#include <iostream>

void DataBase::add(const Student& s) {
    students_.push_back(s);
}

void DataBase::display() const {
    std::cout << show();
}

void DataBase::sortByPesel() {
    auto peselSort = [](const Student& a, const Student& b) { return a.getPesel() < b.getPesel(); };
    std::sort(students_.begin(), students_.end(), peselSort);
}

void DataBase::sortByLastName() {
    auto lastNameSort = [](const Student& a, const Student& b) { return a.getLastName() <= b.getLastName(); };
    std::sort(students_.begin(), students_.end(), lastNameSort);
}

void DataBase::deleteByIndexNumber(const int& index) {
    auto deleteByIdnex = [&index](const Student& a) { return a.getIndexNumber() == index; };
    bool checkErase = (std::find_if(students_.begin(), students_.end(), deleteByIdnex) != students_.end());
    if (students_.empty() || !checkErase) {
        std::cout << "DataBase is not exist, or this index number is not exist!" << "\n";
    } else {
        students_.erase(std::remove_if(students_.begin(), students_.end(), deleteByIdnex), students_.end());
    }

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