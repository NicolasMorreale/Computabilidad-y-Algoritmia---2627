// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 17/09/2026
// Archivo: cadena.h
// Contiene la definicion de la clase Cadena

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <string>
#include "alfabeto.h"

// Declaración adelantada para evitar inclusión circular
class Lenguaje;

class Cadena {
 public:

    // Constructores de la clase 
    Cadena() : cadena_{""} {};
    Cadena(const std::string& cadena) : cadena_{cadena} {};

    // Metodos de la clase 
    int Longitud() const;
    bool Validacion(const Alfabeto& alfabeto) const;
    Cadena Inversa() const;
    Lenguaje Prefijos();
    Lenguaje Sufijos();

    // Sobrecarga de operadores
    bool operator<(const Cadena& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
    friend std::istream& operator>>(std::istream& is, Cadena& cadena);
    Cadena operator+(const Cadena& other);

    // Metodos adicionales a la practica (NO MENCIONADOS EN EL ENUNCIADO PERO PARA PRACTICAR)
    Lenguaje Subcadenas() const;
    Cadena Potencia(size_t exponente) const;
    
    // Getter
    std::string GetCadena() const { return cadena_; }
    // PRACTICA2: Añadir Concatenar()
    Cadena Concatenar(const Cadena& cadena);
    
 private:
    std::string cadena_;
};

#endif
