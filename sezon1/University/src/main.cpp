#include "DataBase.hpp"
#include "Student.hpp"
#include "Teacher.hpp"

#include <iostream>
#include <memory>

int main() {
    // Student s1("Maciek", "Dawiec", "Brzeznica 200", 43567, "85092111333", Gender::Male);
    // Student s2("Małgo", "Brus", "Bochnia", 45678, "84011234876", Gender::Female);
    // Student s3("Anka", "Przyb", "Uscie Sole 600", 54980, "74040632065", Gender::Female);
    // Student s4("Jas", "Walasek", "Krakow 32", 34964, "00011154924", Gender::Male);
    // Student s5("Michal", "Jawien", "Berznica", 45291, "73100459909", Gender::Male);
    // Student s6("Kuba", "Dawiec", "Brzeznica 200",65921 , "90022034900", Gender::Male);
    // Student s7("Olaf", "Kowalski", "Szczecin 23", 85390, "02123143729", Gender::Male);
    // Student s8("Jola", "Banas", "Warszawa 700", 12094, "92031581094", Gender::Female);
    // Student s9("Ada", "Piernik", "Amsterdam 34", 89012, "05062481239", Gender::Female);
    // Student s10("Henryk", "Trus", "Gdansk 563", 24960, "89120390123", Gender::Male);
    auto student = std::make_shared<Student>("Mateusz", "Rydz", "Krakow 43", "90012345666", Gender::Male, 65890);
    auto teacher = std::make_shared<Teacher>("Pawel", "Wiecek", "Nowy Sacz 321", "55122444702", Gender::Male, 4500);
    DataBase base;
    base.add(student);
    base.add(teacher);
    //base.display();
    std::cout << "\n";
    base.display();
    std::cout << "\n";
    base.modyfiSelary("55122444702", 5'660);
    std::cout << "\n";
    base.display();


    return 0;
}
