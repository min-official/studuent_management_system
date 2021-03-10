all : main main.o student.o

main : main.o student.o student.h
	g++ -o main main.o student.o
main.o : main.cpp student.h
	g++ -c main.cpp
student.o : student.cpp student.h
	g++ -c student.cpp
clean :
	rm -f *.o
