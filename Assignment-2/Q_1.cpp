#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y, z;

    // Default constructor
    Point() { 
        x = 0;
        y = 0;
        z = 0;}
    
    // Copy constructor
    Point(const Point& obj) { 
        x = obj.x;
        y = obj.y;
        z = obj.z;}
    
    // Formatted constructor
    Point(double a, double b, double c) {
        x = a;
        y = b; 
        z = c; }

    void print() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    void negate() {
        x = -x;
        y = -y;
        z = -z; }

    double norm() {
        return sqrt(x * x + y * y + z * z);
    }
};

int main() {
    Point p(1.0, 2.0, 5.0);
    p.print();

    Point copyPoint(p);
    copyPoint.print();

    Point formattedPoint(1.5, 4.5, 7.8);
    formattedPoint.print();

    cout << "Norm of p: " << p.norm() << endl;
    p.negate();

    cout << "Negated p: ";
    p.print();
    return 0;
}
