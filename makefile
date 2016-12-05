GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

A = main.o
M = String.o
R = Gene.o

a.out: $(A) $(M) $(R)
	$(GPP) -o a.out $(A) $(M) $(R)

main.o: main.cpp
	$(GPP) -c main.cpp

String.o: String.h String.cpp
	$(GPP) -c String.cpp

Gene.o: Gene.h Gene.cpp
	$(GPP) -c Gene.cpp
