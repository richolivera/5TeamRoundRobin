#5TeamRoundRobin Makefile

all: main.o TeamRecord.o Elims.o
	g++ -o 5TeamRoundRobin.o main.o TeamRecord.o Elims.o

main.o: main.cpp
	g++ -c main.cpp

TeamRecord.o: TeamRecord.cpp
	g++ -c TeamRecord.cpp

Elims.o: Elims.cpp
	g++ -c Elims.cpp
