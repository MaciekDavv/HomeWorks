#include "Teacher.hpp"

Teacher::Teacher(const std::string& name
               , const std::string& lastName
               , const std::string& address
               , const std::string& pesel
               , Gender gender
               , const std::string& teacher
               , const std::string& paycheck)
    : School(name, lastName, address, pesel, gender)
    , teacher_(teacher)
    , paycheck_(paycheck)
{}

std::string Teacher::show() const {
        return name_ + "; "
         + lastName_ + "; "
         + address_ + "; "
         + pesel_ + "; "
         + maleOrFemale(gender_) + "; "
         + teacher_ + "; "
         + paycheck_ + "; "
         + "\n";
}
