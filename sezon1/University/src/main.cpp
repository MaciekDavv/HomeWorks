#include "DataBase.hpp"
#include "Student.hpp"

#include <memory>

int main() {
    Student stu("Maciek", "Daaw", "Bochnia", 43567, "4562145778", Gender::Male);
    DataBase base;
    base.add(stu);
    base.display();
    return 0;
}