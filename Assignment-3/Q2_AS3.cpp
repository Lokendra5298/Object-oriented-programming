#include <iostream>
#include <cmath>
using namespace std;

class Matrix {
private:
    int rows, cols;
    double** data;
public:
    Matrix(int nRows, int nCols){
        rows=nRows;
        cols=nCols;
        // Allocate memory for data
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0.0;
            }
        }
    }
    // Destructor to release memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    double& operator()(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
            return data[row][col];
        throw out_of_range("Matrix index out of range");
    }

    double oneNorm() const {
        double norm = 0.0;
        for (int j = 0; j < cols; ++j) {
            double colSum = 0.0;
            for (int i = 0; i < rows; ++i) colSum += abs(data[i][j]);
            norm = max(norm, colSum);
        }
        return norm;
    }

    double maxNorm() const {
        double norm = 0.0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                norm = max(norm, abs(data[i][j]));
        return norm;
    }

    double frobeniusNorm() const {
        double norm = 0.0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                norm += data[i][j] * data[i][j];
        return sqrt(norm);
    }

    Matrix operator + (const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions must match for addition");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator - (const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions must match for subtraction");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] - other.data[i][j];
        return result;
    }

    Matrix operator * (const Matrix& other) const {
        if (cols != other.rows)
            throw invalid_argument("Matrix dimensions are not compatible for multiplication");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result(i, j) += data[i][k] * other.data[k][j];
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

int main() {
    // Create two 3x3 matrices
    Matrix mat1(3, 3), mat2(3, 3);

    // Populate mat1 and mat2 with values
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1(i, j) = i * 3 + j; // Example values for mat1 (0, 1, 2, 3, 4, 5, 6, 7, 8)
            mat2(i, j) = 2 * i + j; // Example values for mat2 (0, 1, 2, 2, 3, 4, 4, 5, 6)
        }
    }

    // Perform matrix operations
    Matrix mat3 = mat1 + mat2; // Addition
    Matrix mat4 = mat1 - mat2; // Subtraction
    Matrix mat5 = mat1 * mat2; // Multiplication

    // Print the matrices and their results
    cout << "Matrix 1:" << endl;
    mat1.print();
    cout << "Matrix 2:" << endl;
    mat2.print();
    cout << "Matrix 3 (Addition Result):" << endl;
    mat3.print();
    cout << "Matrix 4 (Subtraction Result):" << endl;
    mat4.print();
    cout << "Matrix 5 (Multiplication Result):" << endl;
    mat5.print();

    // Calculate and print the norms of matrices
    cout << "One-Norm of Matrix-1: " << mat1.oneNorm() << endl;
    cout << "Max-Norm of Matrix-1: " << mat1.maxNorm() << endl;
    cout << "Frobenius-Norm of Matrix 1: " << mat1.frobeniusNorm() << endl;

    return 0;
}
