#pragma once

#include "Student.hpp"

class DataBase {
public:
    bool add(const Student& s);

private:
    bool isAdded_ = false;
};
