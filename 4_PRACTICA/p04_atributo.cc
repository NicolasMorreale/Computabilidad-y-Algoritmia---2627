// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_atributo.cc
// Contiene la definicion de la clase Atributo

#include "p04_atributo.h"
#include <iostream>

/**
 * @brief Constructor de la clase Atributo
 * @param nombre, valor
 */

Atributo::Atributo(const std::string& nombre, const std::string& valor) : nombre_(nombre), valor_(valor) {};



/**
 * @brief operator<<: Sobrecarga del operador de insercion en el flujo de salida estandar
 * @param os, atributo
 */

std::ostream& operator<<(std::ostream& os, const Atributo& atributo) {
    os << atributo.GetNombre() << "=\"" << atributo.GetValor() << "\"";
    return os;
}