// RungeKuttaSolver.cpp
#include "RungeKuttaSolver.hpp"
#include <iostream>
#include <fstream>

RungeKuttaSolver::RungeKuttaSolver(double h, double t0, double t1, double y0)
{
    SetStepSize(h);
    SetTimeInterval(t0, t1);
    SetInitialValue(y0);
}

double RungeKuttaSolver::RightHandSide(double y, double t)
{
    // Implement the specific right-hand side function for the given ODE
    return 1.0 + t;
}

double RungeKuttaSolver::SolveEquation()
{
    double currentTime = initialTime;
    double currentY = initialValue;

    // Open a file to write the results
    std::ofstream outputFile("output_runge_kutta.txt");

    // Check if the file is open
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening output file." << std::endl;
        return -1; // Return an error code
    }

    // Write initial values to the file
    outputFile << currentTime << "\t" << currentY << std::endl;

    // Perform the Runge-Kutta method
    while (currentTime + stepSize <= finalTime)
    {
        double k1 = stepSize * RightHandSide(currentY, currentTime);
        double k2 = stepSize * RightHandSide(currentY + 0.5 * k1, currentTime + 0.5 * stepSize);
        double k3 = stepSize * RightHandSide(currentY + 0.5 * k2, currentTime + 0.5 * stepSize);
        double k4 = stepSize * RightHandSide(currentY + k3, currentTime + stepSize);

        currentY = currentY + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        currentTime += stepSize;

        // Write the current time and value to the file
        outputFile << currentTime << "\t" << currentY << std::endl;
    }

    // Close the file
    outputFile.close();

    return currentY; // Return the final value of y
}
