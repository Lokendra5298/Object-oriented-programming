//Name-Lokendra Kumar
//Roll no.- MA23M008

//Q.1- Solution
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// Function definition to multiply two matrix
vector<vector<int>> Multiply( vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    int rows1 = mat1.size(); // no. of rows in matrix 1
    int cols1 = mat1[0].size();// no. of columns in matrix 1
    int rows2 = mat2.size();// no. of rows in matrix 2
    int cols2 = mat2[0].size();// no. of columns in matrix 2

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));//Result Matrix after multiplication

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}
//To inter order of matrices A,B
int main() {
    int row1, row2, column1, column2;
    cout << "Enter the rows of matrix A: ";
    cin >> row1;
    cout << "Enter the columns of matrix A: ";
    cin >> column1;
    cout << "Enter the rows of matrix B: ";
    cin >> row2;
    cout << "Enter the columns of matrix B: ";
    cin >> column2;
//Assertion to cheak matrix multiplication is possible or not
    assert(column1 == row2);
    cout << "Multiplication will be possible" << endl;
//To take elements of matrix A
    vector<vector<int>> A(row1, vector<int>(column1));
    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            cin >> A[i][j];
        }
    }
//To take elements of matrix B
    vector<vector<int>> B(row2, vector<int>(column2));
    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < column2; ++j) {
            cin >> B[i][j];
        }
    }
//To print elements of matrix A
    cout << "First matrix:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
//To print elements of matrix B
    cout << "Second matrix:" << endl;
    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < column2; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
//Function call
    vector<vector<int>> C = Multiply(A, B);
    cout << "Resultant matrix after multiplication:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column2; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

//To multiply Matrix and scalar
    return 0;
}




//Q.2- Solution
// Using Q.1 code if we take row or column=1 then we can also multiply a matrix and a vector to each other. 
//Now i am writing code to muktiply a scalar with a vector or a matrix. For this i will use function name "MultiplyByScalar".
/*
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// Function definition to multiply matrix by scalar
vector<vector<int>> MultiplyByScalar(const vector<vector<int>>& mat, int scalar) {
    int rows = mat.size();//no. of rows in matrix
    int cols = mat[0].size();//no. of columns in matrix
//TO get result matrix
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat[i][j] * scalar;
        }
    }

    return result;
}

int main() {
    int row1, column1;
    cout << "Enter the rows of matrix A: ";
    cin >> row1;
    cout << "Enter the columns of matrix A: ";
    cin >> column1;
//To take elements of Matrix or vector
    vector<vector<int>> A(row1, vector<int>(column1));
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            cin >> A[i][j];
        }
    }
//To take scalar
    int scalar; 
    cout << "Enter the scalar: ";
    cin >>scalar;
//To print elements of Matrix or vector
    cout << "Matrix A:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
//To print scalar
    cout << "Scalar value: " << scalar << endl;
//Function call
    vector<vector<int>> result = MultiplyByScalar(A, scalar);

    cout << "Resultant matrix after scalar multiplication:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/



//Q.3- Solution
//code to calculate the p−norm of a given vector, where p takes the default value 2.
/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int row,p = 2; // Set default value of p to 2;
    cout << "Enter the dimension of vector v: ";
    cin >> row;
//To take dimension of vector v
    vector<int> A(row);
    cout << "Enter elements of the vector:" << endl;
    for (int i = 0; i < row; ++i) {
          cin >> A[i];
    }
    cout << "Elements of the vector:" << endl;
   for (int i = 0; i < row; ++i) {
          cout<< A[i]<<endl;
    }
//To take value of p
    cout << "Enter the value of p for p-norm: ";
    cin >> p;
    double norm=0.0;
    for (int i = 0; i < row; ++i){
     norm += pow(abs(A[i]), p);    
     }
     norm = pow(norm, 1.0 / p); // To take the p-th root of the sum
    cout << "p-norm of the vector: " << norm << endl;
        return 0; 
}
*/