// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de DFAs en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 16/10/2026
// Archivo: p06_alfabeto.h
// Contiene la declaracion de la clase Alfabeto

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include <string>

class Alfabeto {
 public:

   // Constructores
   Alfabeto() = default;
   Alfabeto(const std::string& simbolos);

   // Metodos
   bool Pertenece(char simbolo) const;
   void AñadirSimbolo(char simbolo);
   size_t TamañoAlfabeto() const;

   // Getter
   const std::set<char>& GetSimbolos() const { return simbolos_; }

 private:

   // Atributo
   std::set<char> simbolos_;
};

#endif