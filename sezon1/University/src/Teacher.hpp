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
          , const std::string& teacher
          , const std::string& paycheck);

    ~Teacher() = default;

    std::string show() const override;
    std::string getLastName() const override { return lastName_; }
    std::string getPesel() const override { return pesel_; }
private :
    std::string teacher_;
    std::string paycheck_;
};
