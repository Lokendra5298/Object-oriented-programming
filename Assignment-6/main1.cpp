#include "RungeKuttaSolver.hpp"
#include <iostream>
#include <fstream>
#include <vector>

// Function to compute and compare solutions for different n
void ComputeAndCompareSolutions(const std::vector<int>& valuesOfN, const std::string& outputFileName)
{
    std::ofstream outputFile(outputFileName);

    for (int n : valuesOfN)
    {
        double h = 0.1;
        double t0 = 0.0;
        double tn = t0 + n * h;

        RungeKuttaSolver solver(h, t0, tn, 2.0);

        double numericalSolution = solver.SolveEquation();
        outputFile << "For n = " << n << "\t Numerical Solution: " << numericalSolution
                    << "\t Exact Solution: " << (tn * tn + 2 * tn + 4) / 2.0 << std::endl;
    }

    outputFile.close();
}

int main()
{
    // Define values of n for which to compute solutions
    std::vector<int> valuesOfN = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Specify the output file name
    std::string outputFileName = "output_results.txt";

    // Compute and compare solutions for different n and save the output to a file
    ComputeAndCompareSolutions(valuesOfN, outputFileName);

    return 0;
}
