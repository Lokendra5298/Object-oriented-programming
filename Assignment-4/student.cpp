#include "student.hpp"

using namespace std;

    // A function that returns the total money owed by the student
double Student::owed_money() const {
    return T_fees + lib_fine;
}
    // Constructors of Base class
Student::Student() {
    name = "";
    T_fees = 0.0;
    lib_fine = 0.0;
}
Student::Student(string n, double t) {
    name = n;
    T_fees = t;
    lib_fine = 0.0;
}
Student::Student(string n, double t, double l) {
    name = n;
    T_fees = t;
    set_lib_fine(l);
}
    // A function to set the library fines only to nonnegative values
void Student::set_lib_fine(double l) {
    if (l >= 0.0) {
        lib_fine = l;
    } else {
        cout << "Invalid value for library fines.\n";
    }
}

double Student::get_libr_fine() const {
    return lib_fine;
}
    // Constructors for GraduateStudent
GraduateStudent::GraduateStudent() : full_time(true) {}

GraduateStudent::GraduateStudent(string n, double t, bool f) : Student(n, t), full_time(f) {}

GraduateStudent::GraduateStudent(string n, double t, double l, bool f) : Student(n, t, l), full_time(f) {}

    // Constructors for PhDStudent
PhDStudent::PhDStudent() {}

PhDStudent::PhDStudent(string n, double t, bool f) : GraduateStudent(n, t, f) {}

PhDStudent::PhDStudent(string n, double t, double l, bool f) : GraduateStudent(n, t, l, f) {}

double PhDStudent::owed_money() const {
    return T_fees;
}
