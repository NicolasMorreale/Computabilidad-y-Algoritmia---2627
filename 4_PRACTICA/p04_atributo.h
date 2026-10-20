// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_atributo.h
// Contiene la declaracion de la clase Atributo

#ifndef ATRIBUTO_H
#define ATRIBUTO_H
#include <string>

class Atributo {
 public:
    // Constructores de la clase
    Atributo() = default;
    Atributo(const std::string& nombre, const std::string& valor);

    // Getters de acceso
    std::string GetNombre() const {return nombre_;} 
    std::string GetValor() const {return valor_;} 

    // Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& os, const Atributo& atributo);
 private:
    // Atributos de la clase
    std::string nombre_, valor_;
};

#endif 