#pragma once

#include "Student.hpp"

class DataBase {
public:
    bool add(const Student& s);
    void display() const;
    std::string show() const;
private:
    bool isAdded_ = false;
};
