#pragma once

#include "School.hpp"
#include <string>

class Student : public School {
public:
    Student(const std::string& name
          , const std::string& lastName
          , const std::string& address
          , const std::string& pesel
          , Gender gender
          , int idexNumber);

    ~Student() = default;

    std::string show() const override;
    std::string getLastName() const override { return lastName_; }
    std::string getPesel() const override { return pesel_; }
    int getIndexNumber() const { return indexNumber_; }

private:
    int indexNumber_;
};
