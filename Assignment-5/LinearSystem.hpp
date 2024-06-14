#ifndef LINEARSYSTEMHEADERDEF
#define LINEARSYSTEMHEADERDEF

#include "Matrix.hpp"
#include "Vector.hpp"

class LinearSystem
{
private:
    int mSize;         // Size of the linear system
    Matrix *mpA;       // Pointer to the coefficient matrix
    Vector *mpb;       // Pointer to the right-hand side vector

    // Private copy constructor to prevent its use
    LinearSystem(const LinearSystem &otherSystem);

public:
    // Constructor to set up the linear system
    LinearSystem(Matrix *matrixA, Vector *vectorb);

    // Destructor
    ~LinearSystem();

    // Solve the linear system using Gaussian elimination
    Vector Solve();
};

#endif
