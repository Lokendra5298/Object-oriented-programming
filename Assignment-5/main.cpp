#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"

int main()
{
    // Example of using Matrix class
    Matrix m1(2, 2);
    m1(1, 1) = 1.0, m1(1, 2) = 2.0;
    m1(2, 1) = 3.0, m1(2, 2) = 4.0;

    Matrix m2(2, 2);
    m2(1, 1) = 2.0, m2(1, 2) = 0.0;
    m2(2, 1) = 1.0, m2(2, 2) = 3.0;

    double scalar=5;
    Matrix m3 = m1;
    Matrix m4 = m1 * m2;
    Matrix m5 = m1 + m2;
    Matrix m6 = m1 - m2;
    Matrix m7 = m1 * scalar;


    std::cout << "Matrix m1:" << std::endl;
    for (int i = 1; i <= m1.GetNumRows(); ++i)
    {
        for (int j = 1; j <= m1.GetNumCols(); ++j)
        {
            std::cout << m1(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix m2:" << std::endl;
    for (int i = 1; i <= m2.GetNumRows(); ++i)
    {
        for (int j = 1; j <= m2.GetNumCols(); ++j)
        {
            std::cout << m2(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix m3 (result of m1 * m2):" << std::endl;
    for (int i = 1; i <= m3.GetNumRows(); ++i)
    {
        for (int j = 1; j <= m3.GetNumCols(); ++j)
        {
            std::cout << m3(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix m4 (result of m1 * m2):" << std::endl;
    for (int i = 1; i <= m4.GetNumRows(); ++i)
    {
        for (int j = 1; j <= m4.GetNumCols(); ++j)
        {
            std::cout << m4(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix m5 (result of m1 * m2):" << std::endl;
    for (int i = 1; i <= m5.GetNumRows(); ++i)
    {
        for (int j = 1; j <= m5.GetNumCols(); ++j)
        {
            std::cout << m5(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix m6 (result of m1 * m2):" << std::endl;
    for (int i = 1; i <= m6.GetNumRows(); ++i)
    {
        for (int j = 1; j <= m6.GetNumCols(); ++j)
        {
            std::cout << m6(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix m7 (result of m1 * m2):" << std::endl;
    for (int i = 1; i <= m7.GetNumRows(); ++i)
    {
        for (int j = 1; j <= m3.GetNumCols(); ++j)
        {
            std::cout << m7(i, j) << " ";
        }
        std::cout << std::endl;
    }

    // Example of using LinearSystem class
    Matrix A(3, 3);
    A(1, 1) = 2.0,  A(1, 2) = 1.0,  A(1, 3) = -1.0;
    A(2, 1) = -3.0, A(2, 2) = -1.0, A(2, 3) = 2.0;
    A(3, 1) = -2.0, A(3, 2) = 1.0,  A(3, 3) = 2.0;

    Vector b(3);
    b(1) = 8.0;
    b(2) = -11.0;
    b(3) = -3.0;

    LinearSystem linearSystem(&A, &b);
    Vector solution = linearSystem.Solve();

    std::cout << "Linear System Solution:" << std::endl;
    for (int i = 1; i <= solution.GetSize(); ++i)
    {
        std::cout << solution(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
