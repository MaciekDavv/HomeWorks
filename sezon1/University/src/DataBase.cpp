#include "DataBase.hpp"

#include <algorithm>
#include <iostream>

void DataBase::add(std::shared_ptr<School> person) {
    dataBase_.push_back(person);
}

void DataBase::display() const {
    std::cout << show();
}

void DataBase::sortByPesel() {
    auto peselSort = [](const Person& personFirst, const Person& personSecond) {
        return personFirst->getPesel() < personSecond->getPesel();
    };
    std::sort(dataBase_.begin(), dataBase_.end(), peselSort);
}

void DataBase::sortByLastName() {
    auto lastNameSort = [](const Person& personFirst, const Person& personSecond) {
        return personFirst->getLastName() <= personSecond->getLastName();
    };
    std::sort(dataBase_.begin(), dataBase_.end(), lastNameSort);
}

void DataBase::deleteByIndexNumber(const int& index) {
    auto deleteByIdnex = [&index](const Person& person) {
        if (auto student = dynamic_cast<Student*>(person.get())) {
            return student->getIndexNumber() == index;
        } return false;
    };
    bool checkErase = (std::find_if(dataBase_.cbegin(), dataBase_.cend(), deleteByIdnex) != dataBase_.end());
    if (dataBase_.empty() || !checkErase) {
        std::cout << "DataBase is not exist, or this index number is not exist!" << "\n";
    } else {
        dataBase_.erase(std::remove_if(dataBase_.begin(), dataBase_.end(), deleteByIdnex), dataBase_.end());
    }
}

std::string DataBase::show() const {
    std::string result = "";
    for (auto && person : dataBase_) {
        result += person->show();
    }
    return result;
}

PersonIterator DataBase::searchStudentByLastName(const std::string& lastName) {
    auto searchLastName = [&lastName](const Person& person) { return lastName == person->getLastName(); };
    auto it = std::find_if(dataBase_.cbegin(), dataBase_.cend(), searchLastName);
    return it;
}

PersonIterator DataBase::searchStudentByPesel(const std::string& pesel) {
    auto searchPesel = [&pesel](const Person& person) { return pesel == person->getPesel(); };
    auto it = std::find_if(dataBase_.cbegin(), dataBase_.cend(), searchPesel);
    return it;
}
