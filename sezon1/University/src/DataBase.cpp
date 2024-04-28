#include "DataBase.hpp"
#include <iostream>

bool DataBase::add(const Student& s) {
    if ( isAdded_ ) {
        return false;
    } else {
        isAdded_ = true;
        return true;
    }
}

void DataBase::display() const {
    std::cout << show();
}

std::string DataBase::show() const {
    return "";
}