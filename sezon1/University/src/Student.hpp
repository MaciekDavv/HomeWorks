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
private:
    std::string name_;
    std::string lastName_;
    std::string address_;
    int idexNumber_;
    std::string pesel_;
    Gender gender_;
};