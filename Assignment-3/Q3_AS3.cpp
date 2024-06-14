#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class GaussQuadrature {
private:
    vector<double> nodes;
    vector<double> weights;

public:
    GaussQuadrature() {
        // Gauss points and weights for n=3
        nodes = {-sqrt(3.0 / 5.0), 0.0, sqrt(3.0 / 5.0)};
        weights = {5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0};
    }
    double integrate(double (*func)(double), double a, double b) {
        double integral = 0.0;
        double scale = (b - a) / 2.0;
        double shift = (b + a) / 2.0;

        for (int i = 0; i < 3; ++i) {
            double x = scale * nodes[i] + shift;
            integral += weights[i] * func(x);
        }
        return scale * integral;
    }
};
// Define a polynomial function for testing
double polynomial(double x) {
    return 3 * x * x * x * x * x + 2 * x * x * x * x - x * x * x - 4 * x * x + 7 * x - 9;
}

int main() {
    GaussQuadrature gauss;
    // Test the quadrature for polynomials of various degrees
    for (int degree = 0; degree <= 5; ++degree) {
        double a = 0.0;
        double b = 2.0;
        double exact_integral = (pow(b, degree + 1) - pow(a, degree + 1)) / (degree + 1);
        double approx_integral = gauss.integrate(polynomial, a, b);

        cout << "Degree " << degree << " polynomial:" <<endl;
        cout << "Exact Integral: " << exact_integral <<endl;
        cout << "Approximate Integral: " << approx_integral <<endl;
        cout << "Error: " << abs(exact_integral - approx_integral) <<endl;
        cout << endl;
    }

    return 0;
}
