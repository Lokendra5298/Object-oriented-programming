// STUDENT_HPP File
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

class Student {
private:
    double lib_fine; // A double variable to store the library fine

public:
    std::string name;
    double T_fees; // A double variable to store the tuition fees owed by the student

    double owed_money() const; // A function that returns the total money owed by the student

    Student();
    Student(std::string n, double t);
    Student(std::string n, double t, double l);

    void set_lib_fine(double l);
    double get_libr_fine() const;
};

class GraduateStudent : public Student {
public:
    bool full_time; // A bool variable to know if the student is full-time or part-time

    GraduateStudent();
    GraduateStudent(std::string n, double t, bool f);
    GraduateStudent(std::string n, double t, double l, bool f);
};

class PhDStudent : public GraduateStudent {
public:
    PhDStudent();
    PhDStudent(std::string n, double t, bool f);
    PhDStudent(std::string n, double t, double l, bool f);

    double owed_money() const;
};

#endif 
