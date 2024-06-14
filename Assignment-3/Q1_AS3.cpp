#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Vector {
private:
    int size;
    double* entries;

public:
    // Constructor
    Vector(int n) {
        size = n;
        entries = new double[n];
    }
    // Destructor
    ~Vector() {
        delete[] entries;
    }

    // Copy constructor
    Vector(const Vector& other)//This is a reference to another Vector object, which you want to copy.
    {
        size = other.size;
        entries = new double[other.size];
        for (int i = 0; i < size; ++i) {
            entries[i] = other.entries[i];
        }
    }

    // Overload the "[]" operator 
    double& operator[](int index) {
        if (index < 0 || index >= size) 
            throw out_of_range("Index out of range");
        return entries[index];
    }

    // Overload the "+" operator for vector addition
    Vector operator+(const Vector& other) const {
        if (size != other.size) 
            throw invalid_argument("Vector sizes must be the same for addition.");
        Vector result(size);
        for (int i = 0; i < size; ++i) 
            result.entries[i] = entries[i] + other.entries[i];
        return result;
    }

    // Overload the "-" operator for vector subtraction
    Vector operator-(const Vector& other) const {
        if (size != other.size) 
            throw invalid_argument("Vector sizes must be the same for subtraction.");
        Vector result(size);
        for (int i = 0; i < size; ++i) 
            result.entries[i] = entries[i] - other.entries[i];
        return result;
    }

    // Overload the "*" operator for component-wise multiplication
    Vector operator*(const Vector& other) const {
        if (size != other.size) 
            throw invalid_argument("Vector sizes must be the same for multiplication.");
        Vector result(size);
        for (int i = 0; i < size; ++i) 
            result.entries[i] = entries[i] * other.entries[i];
        return result;
    }

    // Overload the scalar multiplication with vector
    Vector operator*(double scalar) const {
        Vector result(size);
        for (int i = 0; i < size; ++i) 
            result.entries[i] = entries[i] * scalar;
        return result;
    }

    // One norm function
    double oneNorm() const {
        double norm = 0.0;
        for (int i = 0; i < size; ++i) 
            norm += abs(entries[i]);
        return norm;
    }

    // Two norm function
    double twoNorm() const {
        double norm = 0.0;
        for (int i = 0; i < size; ++i) 
            norm += entries[i] * entries[i];
        return sqrt(norm);
    }

    // Max norm function
    double maxNorm() const {
        double norm = 0.0;
        for (int i = 0; i < size; ++i) 
            norm = max(norm, abs(entries[i]));
        return norm;
    }
};

int main() {
    Vector v1(3), v2(3),v6(1);
    v1[0] = 12.0; v1[1] = 3.0; v1[2] = 4.0;
    v2[0] = 4.0; v2[1] = 5.0; v2[2] = 6.0;
    v6[0] = 5;

    Vector v3 = v1 + v2;
    cout << "v1+v2 = " << endl;
    for (int i = 0; i < 3; ++i) 
        cout << v3[i] << " " << endl;

    cout << "v1*v2 = " << endl;//componant wise multiplication of two vectors
    Vector v4 = v1 * v2;
    for (int i = 0; i < 3; ++i) 
        cout << v4[i] << " " << endl;

    cout << "v1-v2 = " << endl;
    Vector v5 = v1 - v2;
    for (int i = 0; i < 3; ++i) 
        cout << v5[i] << " " << endl;

    double scalar = 5;//multiplication of scalar and vector
    cout << "v1*5 = " << endl;
    Vector result = v1 * scalar;
    for (int i = 0; i < 3; ++i) 
    cout << result[i] << " " << endl;

    cout << "\nOne-Norm of v1: " << v1.oneNorm() << endl;
    cout << "Two-Norm of v1: " << v1.twoNorm() << endl;
    cout << "Max-Norm of v1: " << v1.maxNorm() << endl;

    return 0;
}
