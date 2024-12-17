#pragma once

#include "Student.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using PersonIterator = std::vector<std::shared_ptr<School>>::const_iterator;
using Person = std::shared_ptr<School>;

class DataBase {
public:
    void add(std::shared_ptr<School> s);
    void display() const;
    void sortByPesel();
    void sortByLastName();
    void deleteByIndexNumber(const int& index);
    std::string show() const;
    PersonIterator searchStudentByLastName(const std::string& lastName);
    PersonIterator searchStudentByPesel(const std::string& lastName);

    template <typename Func>
    void displayStudent(Func loking) {
        auto person = loking;
        if (person != dataBase_.end()) {
            std::cout << (*person)->show() << "\n";
        } else {
            std::cout << "We don't hava a studet, wahat are you looking for" << "\n";
        }
    }

private:
    std::vector<Person> dataBase_;
};
