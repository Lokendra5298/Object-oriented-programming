// ForwardEulerSolver.cpp
#include "ForwardEulerSolver.hpp"
#include <iostream>
#include <fstream>

ForwardEulerSolver::ForwardEulerSolver(double h, double t0, double t1, double y0)
{
    SetStepSize(h);
    SetTimeInterval(t0, t1);
    SetInitialValue(y0);
}

double ForwardEulerSolver::RightHandSide(double y, double t) const
{
    // Implement your specific right-hand side function here
    // For the given example dy/dt = 1 + t
    return 1.0 + t;
}

double ForwardEulerSolver::SolveEquation()
{
    double currentTime = initialTime;
    double currentY = initialValue;

    // Open a file to write the results
    std::ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening output file." << std::endl;
        return -1; // Return an error code
    }

    // Write initial values to the file
    outputFile << currentTime << "\t" << currentY << std::endl;

    // Perform the forward Euler method
    while (currentTime + stepSize <= finalTime)
    {
        currentY = currentY + stepSize * RightHandSide(currentY, currentTime);
        currentTime += stepSize;

        // Write the current time and value to the file
        outputFile << currentTime << "\t" << currentY << std::endl;
    }

    // Close the file
    outputFile.close();

    return currentY; // Return the final value of y
}
