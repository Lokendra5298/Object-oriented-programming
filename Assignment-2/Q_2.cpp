#include <iostream>
#include <cmath>
using namespace std;

class Matrix {
private:
    double P[3][3]; // P is a matrix of order 3

public:
    // Default constructor with all 0 elements
    Matrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                P[i][j] = 0.0;
            }
        }
    }

    // Parameterized constructor
    Matrix(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        P[0][0] = a; P[0][1] = b; P[0][2] = c;
        P[1][0] = d; P[1][1] = e; P[1][2] = f;
        P[2][0] = g; P[2][1] = h; P[2][2] = i;
    }

    // Copy constructor
    Matrix(const Matrix& obj) {
        // Copy elements from the A matrix
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                P[i][j] = obj.P[i][j];
            }
        }
    }

    double determinant() {
        return P[0][0] * (P[1][1] * P[2][2] - P[1][2] * P[2][1])
            - P[0][1] * (P[1][0] * P[2][2] - P[1][2] * P[2][0])
            + P[0][2] * (P[1][0] * P[2][1] - P[1][1] * P[2][0]);
    }

    bool is_A_Singular() {
        return determinant() == 0.0;
    }
    Matrix inverse() {
        double det = determinant();
        if (det == 0.0) {
            throw runtime_error("Matrix is not invertible.");
        }
        Matrix result(
            (P[1][1] * P[2][2] - P[1][2] * P[2][1]) / det,
            (P[0][2] * P[2][1] - P[0][1] * P[2][2]) / det,
            (P[0][1] * P[1][2] - P[0][2] * P[1][1]) / det,
            (P[1][2] * P[2][0] - P[1][0] * P[2][2]) / det,
            (P[0][0] * P[2][2] - P[0][2] * P[2][0]) / det,
            (P[0][2] * P[1][0] - P[0][0] * P[1][2]) / det,
            (P[1][0] * P[2][1] - P[1][1] * P[2][0]) / det,
            (P[0][1] * P[2][0] - P[0][0] * P[2][1]) / det,
            (P[0][0] * P[1][1] - P[0][1] * P[1][0]) / det
        );

        return result;
    }

    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << P[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Default constructor
    Matrix B;
    cout << "Default Matrix B:" << endl;
    B.print();

    Matrix A(2, 3, 1, 1, 0, 1, 2, 1, 2);
    cout << "Matrix A:" << endl;
    A.print();

    cout << "Determinant of A: " << A.determinant() << endl;
    cout << "Is A Singular? " << A.is_A_Singular() << endl;

    if (!A.is_A_Singular()) {
        Matrix A_inv = A.inverse();
        cout << "Inverse of A:" << endl;
        A_inv.print();
    }
    // Copy constructor
    Matrix C(A);
    cout << "Copied Matrix C:" << endl;
    C.print();

    return 0;
}
