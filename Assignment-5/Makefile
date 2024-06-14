all: main

main: main.o Matrix.o Vector.o LinearSystem.o
    g++ main.o Matrix.o Vector.o LinearSystem.o -o main

main.o: main.cpp
    g++ -c main.cpp -o main.o

Matrix.o: Matrix.cpp Matrix.hpp
    g++ -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp
    g++ -c Vector.cpp -o Vector.o

LinearSystem.o: LinearSystem.cpp LinearSystem.hpp
    g++ -c LinearSystem.cpp -o LinearSystem.o

clean:
    rm -f *.o main
