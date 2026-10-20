# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 6: Simulacion de DFAs en C++
# Autor: Nicolas Morreale Toledo
# Correo: alu0101829173@ull.edu.es
# Archivo: Makefile

# Compilador y flags requeridos por las pautas de la asignatura
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

# Nombre del ejecutable indicado en el guion de la practica
TARGET = p06_DFA_simulator

# Archivos fuente y sus correspondientes objetos
SRCS = p06_alfabeto.cc p06_estado.cc p06_dfa.cc p06_cliente_main.cc
OBJS = $(SRCS:.cc=.o)

# Regla principal por defecto
all: $(TARGET)

# Regla para enlazar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada archivo .cc a .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean