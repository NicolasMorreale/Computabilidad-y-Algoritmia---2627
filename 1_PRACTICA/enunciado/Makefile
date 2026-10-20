CXX = g++
CXXFLAGS = -Wall -std=c++11

all: p01_single_grades p01_multiple_grades

p01_single_grades: cliente_grades.cc grades.cc grades.h
	$(CXX) $(CXXFLAGS) cliente_grades.cc grades.cc -o p01_single_grades

p01_multiple_grades: cliente_multiple_grades.cc multiple_grades.cc multiple_grades.h
	$(CXX) $(CXXFLAGS) cliente_multiple_grades.cc multiple_grades.cc -o p01_multiple_grades

clean:
	rm -f p01_single_grades p01_multiple_grades

.PHONY: all clean