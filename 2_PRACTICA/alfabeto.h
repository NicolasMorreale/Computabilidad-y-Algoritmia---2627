// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 17/09/2026
// Archivo: alfabeto.h
// Contiene la declaracion de la clase Alfabeto

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include <string>
typedef char Simbolo;

class Alfabeto {
 public:

    // Constructores
    Alfabeto() = default;
    Alfabeto(const std::string& simbolos);

    // Funciones auxiliares para constructor y operadores
    void InsertarEnAlfabeto(const std::string& alfabeto);
    void EscribirAlfabeto(std::ostream& os) const;
    void RecibirAlfabeto(std::istream& is);

    // Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto);
    friend std::istream& operator>>(std::istream& is, Alfabeto& alfabeto);

    // Metodos de la clase 
    bool Pertenece(const Simbolo& simbolo) const;

 private:

    std::set<Simbolo> alfabeto_;
};

#endif