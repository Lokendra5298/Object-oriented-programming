#include <iostream>
#include <cassert>
#include "Matrix.hpp"

Matrix::Matrix(int numRows, int numCols)
{
    assert(numRows > 0 && numCols > 0);
    mNumRows = numRows;
    mNumCols = numCols;

    // Allocate memory for matrix
    mData = new double *[mNumRows];
    for (int i = 0; i < mNumRows; ++i)
    {
        mData[i] = new double[mNumCols];

        // Initialize entries to zero
        for (int j = 0; j < mNumCols; ++j)
        {
            mData[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(const Matrix &otherMatrix)
{
    mNumRows = otherMatrix.GetNumRows();
    mNumCols = otherMatrix.GetNumCols();

    // Allocate memory for matrix
    mData = new double *[mNumRows];
    for (int i = 0; i < mNumRows; ++i)
    {
        mData[i] = new double[mNumCols];

        // Copy entries from otherMatrix
        for (int j = 0; j < mNumCols; ++j)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

Matrix::~Matrix()
{
    // Free allocated memory for matrix
    for (int i = 0; i < mNumRows; ++i)
    {
        delete[] mData[i];
    }
    delete[] mData;
}

int Matrix::GetNumRows() const
{
    return mNumRows;
}

int Matrix::GetNumCols() const
{
    return mNumCols;
}
// Overloaded () operator
double &Matrix::operator()(int i, int j)
{
    assert(i > 0 && i <= mNumRows);
    assert(j > 0 && j <= mNumCols);
    return mData[i - 1][j - 1];
}
// Overloaded = operator
Matrix &Matrix::operator=(const Matrix &otherMatrix)
{
    assert(mNumRows == otherMatrix.mNumRows);
    assert(mNumCols == otherMatrix.mNumCols);

    for (int i = 0; i < mNumRows; ++i)
    {
        for (int j = 0; j < mNumCols; ++j)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }

    return *this;
}
// Overloaded binary + operator
Matrix Matrix::operator+(const Matrix &m) const
{
    assert(mNumRows == m.mNumRows);
    assert(mNumCols == m.mNumCols);

    Matrix result(mNumRows, mNumCols);

    for (int i = 0; i < mNumRows; ++i)
    {
        for (int j = 0; j < mNumCols; ++j)
        {
            result(i + 1, j + 1) = mData[i][j] + m.mData[i][j];
        }
    }

    return result;
}
// Overloaded binary - operator
Matrix Matrix::operator-(const Matrix &m) const
{
    assert(mNumRows == m.mNumRows);
    assert(mNumCols == m.mNumCols);

    Matrix result(mNumRows, mNumCols);

    for (int i = 0; i < mNumRows; ++i)
    {
        for (int j = 0; j < mNumCols; ++j)
        {
            result(i + 1, j + 1) = mData[i][j] - m.mData[i][j];
        }
    }

    return result;
}
// Overloaded Matrix Multiplication with scalar * operator
Matrix Matrix::operator*(double scalar) const
{
    Matrix result(mNumRows, mNumCols);

    for (int i = 0; i < mNumRows; ++i)
    {
        for (int j = 0; j < mNumCols; ++j)
        {
            result(i + 1, j + 1) = scalar * mData[i][j];
        }
    }

    return result;
}
// Overloaded Matrix Multiplication with Matrix * operator
Matrix Matrix::operator*(const Matrix &m) const
{
    assert(mNumCols == m.mNumRows);

    Matrix result(mNumRows, m.mNumCols);

    for (int i = 0; i < mNumRows; ++i)
    {
        for (int j = 0; j < m.mNumCols; ++j)
        {
            for (int k = 0; k < mNumCols; ++k)
            {
                result(i + 1, j + 1) += mData[i][k] * m.mData[k][j];
            }
        }
    }

    return result;
}
// To caculate 2x2 Matrix determinant
double Matrix::Determinant() const
{
    assert(mNumRows == mNumCols);
    if (mNumRows == 1)
    {
        return mData[0][0];
    }
    else if (mNumRows == 2)
    {
        return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0];
    }
    else
    {
        std::cout << "Determinant calculation for matrices larger than 2x2 not implemented." << std::endl;
        return 0.0;
    }
}
