#include "DataBase.hpp"
#include "Student.hpp"

#include <iostream>

int main() {
    Student s1("Maciek", "Dawiec", "Brzeznica 200", 43567, "85092111333", Gender::Male);
    Student s2("Małgo", "Brus", "Bochnia", 45678, "84011234876", Gender::Female);
    Student s3("Anka", "Przyb", "Uscie Sole 600", 54980, "74040632065", Gender::Female);
    Student s4("Jas", "Walasek", "Krakow 32", 34964, "00011154924", Gender::Male);
    Student s5("Michal", "Jawien", "Berznica", 45291, "73100459909", Gender::Male);
    Student s6("Kuba", "Dawiec", "Brzeznica 200",65921 , "90022034900", Gender::Male);
    Student s7("Olaf", "Kowalski", "Szczecin 23", 85390, "02123143729", Gender::Male);
    Student s8("Jola", "Banas", "Warszawa 700", 12094, "92031581094", Gender::Female);
    Student s9("Ada", "Piernik", "Amsterdam 34", 89012, "05062481239", Gender::Female);
    Student s10("Henryk", "Trus", "Gdansk 563", 24960, "89120390123", Gender::Male);
    DataBase base;
    base.add(s1);
    base.add(s2);
    base.add(s3);
    base.add(s4);
    base.add(s5);
    base.add(s6);
    base.add(s7);
    base.add(s8);
    base.add(s9);
    base.add(s10);
    base.display();
    std::cout << "\n";
    base.sortByLastName();
    base.display();
    std::cout << "\n";
    base.deleteByIndexNumber(1294);
    base.display();
    return 0;
}