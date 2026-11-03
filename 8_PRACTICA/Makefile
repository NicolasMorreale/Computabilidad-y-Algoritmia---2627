# Universidad de La Laguna
# Computabilidad y Algoritmia - Práctica 8: Gramática
# Makefile para el ejecutable dfa2grammar

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

# Nombre del ejecutable final
TARGET = dfa2grammar

# Archivos fuente (.cc) y objetos (.o)
SRCS = dfa2grammar.cc automata.cc grammar.cc estado.cc alfabeto.cc
OBJS = $(SRCS:.cc=.o)

# Regla principal
all: $(TARGET)

# Vinculación del ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilación de los archivos objeto
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de ejecutables y archivos objeto
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean