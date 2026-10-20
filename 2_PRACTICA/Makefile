CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

OBJS = cliente_practica2.o alfabeto.o cadena.o lenguaje.o
TARGET = p02_strings

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean