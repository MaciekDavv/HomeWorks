#include "DataBase.hpp"
#include "Student.hpp"
#include "Teacher.hpp"

#include <iostream>
#include <memory>

int main() {
    auto s1 = std::make_shared<Student>("Maciek", "Dawiec", "Brzeznica 200", "85092111333", Gender::Male, 43567);
    auto s2 = std::make_shared<Student>("Małgo", "Brus", "Bochnia", "84011234876", Gender::Female, 45678);
    auto s3 = std::make_shared<Student>("Anka", "Przyb", "Uscie Sole 600", "74040632065", Gender::Female, 54980);
    auto s4 = std::make_shared<Student>("Jas", "Walasek", "Krakow 32", "00011154924", Gender::Male, 34964);
    auto s5 = std::make_shared<Student>("Michal", "Jawien", "Berznica", "73100459909", Gender::Male, 45291);
    auto s6 = std::make_shared<Student>("Kuba", "Dawiec", "Brzeznica 200", "90022034900", Gender::Male, 65921);
    auto s7 = std::make_shared<Student>("Olaf", "Kowalski", "Szczecin 23", "02123143729", Gender::Male, 85390);
    auto s8 = std::make_shared<Student>("Jola", "Banas", "Warszawa 700", "92031581094", Gender::Female, 12094);
    auto s9 = std::make_shared<Student>("Ada", "Piernik", "Amsterdam 34", "05062481239", Gender::Female, 89012);
    auto s10 = std::make_shared<Student>("Henryk", "Trus", "Gdansk 563", "89120390123", Gender::Male, 24960);
    auto s11 = std::make_shared<Student>("Mateusz", "Rydz", "Krakow 43", "90012345666", Gender::Male, 65890);
    auto teacher = std::make_shared<Teacher>("Pawel", "Wiecek", "Nowy Sacz 321", "55122444702", Gender::Male, 45);
    auto teacher2 = std::make_shared<Teacher>("Adam", "Robajk", "Nowy Sacz 456", "52112449802", Gender::Male, 55);
    auto teacher3 = std::make_shared<Teacher>("Ewa", "Smigla", "Krakow 3", "85062444702", Gender::Female, 75);
    auto teacher4 = std::make_shared<Teacher>("Danka", "Pietrzyk", "Bochnia 21", "90032412792", Gender::Female, 7);
    auto teacher5 = std::make_shared<Teacher>("Jacek", "Plaxek", "Grobla", "83012444091", Gender::Male, 6);

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
    base.add(s11);
    base.add(teacher);
    base.add(teacher2);
    base.add(teacher3);
    base.add(teacher4);
    base.add(teacher5);

    std::cout << "\n";
    base.sortByPesel();
    std::cout << "\n";
    base.display();
    std::cout << "\n";
    base.sortBySelary();
    base.display();
    std::cout << "\n";
    
    return 0;
}
