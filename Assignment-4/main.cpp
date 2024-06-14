#include <iostream>
#include "student.hpp"

int main() {
    Student s1("Ram", 1000.0, 50.0);
    GraduateStudent g1("Shyam", 600.0, true);
    GraduateStudent g2("Hari", 860.0, 30.0, false);
    PhDStudent p1("Pravesh", 750.0, true);
    PhDStudent p2("Shailendra", 3500.0, 100.0, false);

    std::cout << "Name\tTotal owed\n";
    std::cout << s1.name << " : " << s1.owed_money() << "\n";
    std::cout << g1.name << " : " << g1.owed_money() << "\n";
    std::cout << g2.name << " : " << g2.owed_money() << "\n";
    std::cout << p1.name << " : " << p1.owed_money() << "\n";
    std::cout << p2.name << " : " << p2.owed_money() << "\n";

    s1.set_lib_fine(40.0);
    g2.set_lib_fine(-3.0);
    p2.set_lib_fine(10.0);

    std::cout << "Name : Changed Library fines\n";
    std::cout << s1.name << " : " << s1.get_libr_fine() << "\n";
    std::cout << g2.name << " : " << g2.get_libr_fine() << "\n";
    std::cout << p2.name << " : " << p2.get_libr_fine() << "\n";

    return 0;
}
