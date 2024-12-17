#include "Student.hpp"

Student::Student(const std::string& name
               , const std::string& lastName
               , const std::string& address
               , const std::string& pesel
               , Gender gender
               , int indexNumber)
    : School(name, lastName, address, pesel, gender)
    , indexNumber_(indexNumber)
{}

std::string Student::show () const
{
    return name_ + "; "
         + lastName_ + "; "
         + address_ + "; "
         + pesel_ + "; "
         + maleOrFemale(gender_) + "; "
         + std::to_string(indexNumber_) + "; "
         + "\n";
}
