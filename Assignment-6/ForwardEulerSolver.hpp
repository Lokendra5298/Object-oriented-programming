// ForwardEulerSolver.hpp
#ifndef FORWARDEULERSOLVERDEF
#define FORWARDEULERSOLVERDEF

#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver : public AbstractOdeSolver
{
public:
    ForwardEulerSolver() = default;
    ForwardEulerSolver(double h, double t0, double t1, double y0);
    double RightHandSide(double y, double t) const override;
    double SolveEquation() override;
};

#endif
