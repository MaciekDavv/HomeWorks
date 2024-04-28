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
};