// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 17/09/2026
// Archivo: alfabeto.cc
// Contiene la definicion de la clase Alfabeto

#include "alfabeto.h"
#include <fstream>
#include <iostream>

typedef char Simbolo;

/**
 * @brief Constructor de la clase (para excluir el caracter &)
 * @param simbolos
 */

Alfabeto::Alfabeto(const std::string& simbolos) {
    InsertarEnAlfabeto(simbolos);
}
/**
 * @brief InsertarEnAlfabeto: Metodo auxiliar para el constructor de la clase, que permite insertar los simbolos del fichero en el alfabeto
 * @param simbolo
 */

void Alfabeto::InsertarEnAlfabeto(const std::string& simbolos) {
    for(const Simbolo& simbolo : simbolos) {
        if(simbolo != '&')
        alfabeto_.insert(simbolo);
    }
}



/**
 * @brief EscribirAlfabeto: Metodo auxiliar para la sobrecarga del operator<<
 */

void Alfabeto::EscribirAlfabeto(std::ostream& os) const {
    int size = alfabeto_.size();
    int contador{0};
    os << "{";
    for(const Simbolo& simbolo : alfabeto_) {
        if(contador < size - 1) {
            os << simbolo << ", ";
            contador++;
        } else {
            os << simbolo;
        }
    }
    os << "}";
}



/**
 * @brief operator<<: Sobrecarga del operador de insercion en el flujo de salida estandar
 * @param os
 * @param alfabeto
 */

std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
    alfabeto.EscribirAlfabeto(os);
    return os;
}



/**
 * @brief RecibirAlfabeto: Metodo auxiliar que permite la sobrecarga del operator>>
 */

void Alfabeto::RecibirAlfabeto(std::istream& is) {
    std::string simbolos;
    if(is >> simbolos) {
        alfabeto_.clear(); // Vaciamos el set por si tenia elementos
        InsertarEnAlfabeto(simbolos);
    }   
}



/**
 * @brief operator>>: Sobrecarga del operator>>
 * @param is
 * @param alfabeto
 */

std::istream& operator>>(std::istream& is, Alfabeto& alfabeto) {
    alfabeto.RecibirAlfabeto(is);
    return is;
}



/**
 * @brief Pertenece: Metodo que permite determinar si un simbolo pertenece al alfabeto
 * @param simbolo
 */

bool Alfabeto::Pertenece(const Simbolo& simbolo) const {
    return alfabeto_.find(simbolo) != alfabeto_.end();
}