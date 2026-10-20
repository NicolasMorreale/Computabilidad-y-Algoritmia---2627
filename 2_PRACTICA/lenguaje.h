// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 18/09/2026
// Archivo: lenguaje.h
// Contiene la declaracion de la clase Lenguaje

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <set>
#include <string>
#include "cadena.h"

class Lenguaje {
 public:

    // Constructores de la clase
    Lenguaje() = default;
    Lenguaje(const Cadena& cadena);
    
    // Metodos de la clase
    void Insertar(const Cadena& cadena);

    // Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje);

    // Getter 
    const std::set<Cadena> GetLenguaje() const { return lenguaje_; }
 private:
 
    std::set<Cadena> lenguaje_;
};

#endif