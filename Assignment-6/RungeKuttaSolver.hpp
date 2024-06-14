// RungeKuttaSolver.hpp
#ifndef RUNGEKUTTASOLVERDEF
#define RUNGEKUTTASOLVERDEF

#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver : public AbstractOdeSolver
{
public:
    RungeKuttaSolver() = default;
    RungeKuttaSolver(double h, double t0, double t1, double y0);
    double RightHandSide(double y, double t) override;
    double SolveEquation() override;
};

#endif
