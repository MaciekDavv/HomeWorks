#pragma once

#include "School.hpp"
#include <string>

class Teacher : public School {
public :
    Teacher(const std::string& name
          , const std::string& LastName
          , const std::string& address
          , const std::string& pesel
          , Gender gender
          , const int& paycheck);

    ~Teacher() = default;

    std::string show() const override;
    std::string getLastName() const override { return lastName_; }
    std::string getPesel() const override { return pesel_; }
    int getPayCheck() const { return paycheck_; }
    void setPayCheck(const int& set) { paycheck_ = set; }
private :
    int paycheck_;
};
