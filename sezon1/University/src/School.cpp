#include "School.hpp"

School::School(const std::string& name
             , const std::string& lastName
             , const std::string& address
             , const std::string& pesel
             , Gender gender)
    : name_(name)
    , lastName_(lastName)
    , address_(address)
    , pesel_(pesel)
    , gender_(gender)
{}

std::string School::maleOrFemale(Gender gen) const {
    return gen == Gender::Male ? "Male" : "Female";
}
