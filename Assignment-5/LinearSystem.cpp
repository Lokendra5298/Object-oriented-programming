#include <cmath>
#include <cassert>
#include "LinearSystem.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"

// Constructor to set up the linear system
LinearSystem::LinearSystem(Matrix *matrixA, Vector *vectorb)
{
    assert(matrixA != nullptr && vectorb != nullptr);
    mpA = matrixA;
    mpb = vectorb;
    mSize = matrixA->GetNumRows(); // Assuming the matrix is square
}

// Destructor
LinearSystem::~LinearSystem(){}

// Private copy constructor to prevent its use
LinearSystem::LinearSystem(const LinearSystem &otherSystem)
{
    // Empty body to prevent copying
}

// Solve the linear system using Gaussian elimination with pivoting
Vector LinearSystem::Solve()
{
    Vector m(mSize); 
    Vector solution(mSize);

    // We introduce references to make the syntax readable
    Matrix &rA = *mpA;
    Vector &rb = *mpb;

    // forward sweep of Gaussian elimination
    for (int k = 0; k < mSize - 1; k++)
    {
        // TO cheak if pivoting is necessary
        double max = 0.0;
        int row = -1;
        for (int i = k; i < mSize; i++)
        {
            if (fabs(rA(i + 1, k + 1)) > max)
            {
                row = i;
                max = fabs(rA(i + 1, k + 1));
            }
        }
        assert(row >= 0);
        // pivot if necessary
        if (row != k)
        {
            // swap matrix rows k+1 with row+1
            for (int i = 0; i < mSize; i++)
            {
                double temp = rA(k + 1, i + 1);
                rA(k + 1, i + 1) = rA(row + 1, i + 1);
                rA(row + 1, i + 1) = temp;
            }
            // swap vector entries k+1 with row+1
            double temp = rb(k + 1);
            rb(k + 1) = rb(row + 1);
            rb(row + 1) = temp;
        }

        // create zeros in the lower part of column k
        for (int i = k + 1; i < mSize; i++)
        {
            m(i + 1) = rA(i + 1, k + 1) / rA(k + 1, k + 1);
            for (int j = k; j < mSize; j++)
            {
                rA(i + 1, j + 1) -= rA(k + 1, j + 1) * m(i + 1);
            }
            rb(i + 1) -= rb(k + 1) * m(i + 1);
        }
    }

    // back substitution
    for (int i = mSize - 1; i > -1; i--)
    {
        solution(i + 1) = rb(i + 1);
        for (int j = i + 1; j < mSize; j++)
        {
            solution(i + 1) -= rA(i + 1, j + 1) * solution(j + 1);
        }
        solution(i + 1) /= rA(i + 1, i + 1);
    }

    return solution;
}
