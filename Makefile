###########################################################
# Name:        Jory Ehman
# Course:      Program Translation / Compilers
# Project:     P2
# File:        Makefile
# Description:
#   Builds executable P2 using g++ with debugging and
#   warning flags enabled. Provides clean target to
#   remove object files and executable.
###########################################################

CXX = g++
CXXFLAGS = -g -Wall -std=c++11

OBJS = main.o scanner.o testScanner.o

TARGET = P2

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp testScanner.h
	$(CXX) $(CXXFLAGS) -c main.cpp

scanner.o: scanner.cpp scanner.h token.h
	$(CXX) $(CXXFLAGS) -c scanner.cpp

testScanner.o: testScanner.cpp testScanner.h scanner.h token.h
	$(CXX) $(CXXFLAGS) -c testScanner.cpp

clean:
	rm -f *.o $(TARGET)