#pragma once

#include <string>

enum class Gender {
    Male,
    Female
};

class School {
public :
    School(const std::string& name
         , const std::string& lastName
         , const std::string& address
         , const std::string& pesel
         , Gender gender);

    virtual std::string show() const = 0;
    virtual std::string getLastName() const = 0;
    virtual std::string getPesel() const = 0;
    std::string maleOrFemale(Gender gen) const;

    virtual ~School() = default;

protected :
    std::string name_;
    std::string lastName_;
    std::string address_;
    std::string pesel_;
    Gender gender_;
};
