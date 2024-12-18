#pragma once

#include "Student.hpp"
#include "Teacher.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using Person = std::shared_ptr<School>;
using PersonIterator = std::vector<Person>::const_iterator;

class DataBase {
public:
    void add(Person person);
    void display() const;
    void sortByPesel();
    void sortByLastName();
    void sortBySelary();
    void deleteByIndexNumber(const int& index);
    void modyfiSelary(const std::string& pesel, const int& payment);
    std::string show() const;
    PersonIterator searchPersonByLastName(const std::string& lastName);
    PersonIterator searchPersonByPesel(const std::string& lastName);


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
