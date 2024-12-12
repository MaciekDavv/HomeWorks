#include "Student.hpp"

Student::Student(std::string name,
                 std::string lastName,
                 std::string address,
                 int idexNumber,
                 std::string pesel,
                 Gender gender)
    : name_(name)
    , lastName_(lastName)
    , address_(address)
    , idexNumber_(idexNumber)
    , pesel_(pesel)
    , gender_(gender)
{}

std::string Student::show () const
{
    return name_ + " "
         + lastName_ + "; "
         + address_ + "; "
         + std::to_string(idexNumber_) + "; "
         + pesel_ + "; "
         + maleOrFemale(gender_)
         + "\n";
}

std::string Student::maleOrFemale(Gender gen) const {
    if (gen == Gender::Male) {
        return "Male";
    } else {
        return "Female";
    }
}