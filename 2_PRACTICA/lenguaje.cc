// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 18/09/2026
// Archivo: lenguaje.cc
// Contiene la definicion de la clase Lenguaje

#include "lenguaje.h"
#include "cadena.h"

/**
 * @brief Definicion del constructor de la clase Lenguaje
 * @param cadena
 */

Lenguaje::Lenguaje(const Cadena& cadena) {
    lenguaje_.insert(cadena);
}



/**
 * @brief Insertar: Metodo que nos permite insertar una cadena en un lenguaje
 * @param cadena
 */

void Lenguaje::Insertar(const Cadena& cadena) {
    lenguaje_.insert(cadena);
}
/**
 * @brief operator<<: Sobrecarga del operador de insercion en el flujo de salida estandar
 * @param os
 * @param lenguaje
 */

std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje) {
    bool primero = true;
    os << "{";
    for(const Cadena& cadena : lenguaje.lenguaje_) {
        if(!primero) {
            os << ", ";
        }
        os << cadena;
        primero = false;
    }
    os << "}";
    return os;
}

