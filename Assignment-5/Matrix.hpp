#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

class Matrix
{
private:
    double **mData; // Pointer to the first entry of the first row
    int mNumRows;   // Number of rows
    int mNumCols;   // Number of columns

public:
    Matrix(int numRows, int numCols); // Constructor
    Matrix(const Matrix &otherMatrix); // Copy constructor
    ~Matrix();                         // Destructor

    int GetNumRows() const; // Public method to access the number of rows
    int GetNumCols() const; // Public method to access the number of columns

    double &operator()(int i, int j);            // Overloaded round bracket operator for one-based indexing
    Matrix &operator=(const Matrix &otherMatrix); // Overloaded assignment operator
    Matrix operator+(const Matrix &m) const;     // Overloaded + operator
    Matrix operator-(const Matrix &m) const;     // Overloaded - operator
    Matrix operator*(double scalar) const;       // Overloaded scalar multiplication
    Matrix operator*(const Matrix &m) const;     // Overloaded matrix multiplication

    double Determinant() const; // Public method to compute the determinant of a square matrix
};

#endif
