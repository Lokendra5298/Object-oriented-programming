student.o : student.cpp student.hpp
	g++ -c student.cpp

main.o : main.cpp student.hpp
	g++ -c main.cpp

studentprog : student.o main.o
	g++ -o test student.o main.o