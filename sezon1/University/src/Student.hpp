#pragma once

#include <string>

enum class Gender {
    Male,
    Female
};

class Student {
public:
    Student(std::string name,
            std::string lastName,
            std::string address,
            int idexNumber,
            std::string pesel,
            Gender gender);

    std::string show() const;
    std::string maleOrFemale(Gender gen) const;
    std::string getLastName() const { return lastName_; }
    std::string getPesel() const { return pesel_; }
    int getIndexNumber() const { return idexNumber_; }
private:
    std::string name_;
    std::string lastName_;
    std::string address_;
    int idexNumber_;
    std::string pesel_;
    Gender gender_;
};