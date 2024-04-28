#pragma once

#include <vector>
#include "Student.hpp"

class DataBase {
public:
    void add(const Student& s);
    void display() const;
    std::string show() const;
    
private:
    std::vector<Student> students_;
};
