all: main

main: main.o ForwardEulerSolver.o AbstractOdeSolver.o 
    g++ main.o ForwardEulerSolver.o AbstractOdeSolver.o -o main

main.o: main.cpp
    g++ -c main.cpp -o main.o

ForwardEulerSolver.o: ForwardEulerSolver.cpp ForwardEulerSolver.hpp
    g++ -c ForwardEulerSolver.cpp -o ForwardEulerSolver.o

AbstractOdeSolver.o: AbstractOdeSolver.cpp AbstractOdeSolver.hpp
    g++ -c AbstractOdeSolver.cpp -o AbstractOdeSolver.o

clean:
    rm -f *.o main
