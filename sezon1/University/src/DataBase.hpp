#pragma once

#include "Student.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using School = std::vector<Student>::const_iterator;

class DataBase {
public:
    void add(const Student& s);
    void display() const;
    void sortByPesel();
    void sortByLastName();
    std::string show() const;
    School searchStudentByLastName(const std::string& lastName);
    School searchStudentByPesel(const std::string& lastName);

    template <typename Func>
    void displayStudent(Func loking) {
        auto student = loking;
        if (student != students_.end()) {
            std::cout << student->show() << "\n";
        } else {
            std::cout << "We don't hava a studet, wahat are you looking for" << "\n";
        }
    }
    
private:
    std::vector<Student> students_;
};
