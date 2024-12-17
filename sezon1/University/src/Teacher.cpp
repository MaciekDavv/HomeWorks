#include "Teacher.hpp"

Teacher::Teacher(const std::string& name
               , const std::string& lastName
               , const std::string& address
               , const std::string& pesel
               , Gender gender
               , const int& paycheck)
    : School(name, lastName, address, pesel, gender)
    , paycheck_(paycheck)
{}

std::string Teacher::show() const {
        return name_ + "; "
         + lastName_ + "; "
         + address_ + "; "
         + pesel_ + "; "
         + maleOrFemale(gender_) + "; "
         + std::to_string(paycheck_) + "; "
         + "\n";
}
