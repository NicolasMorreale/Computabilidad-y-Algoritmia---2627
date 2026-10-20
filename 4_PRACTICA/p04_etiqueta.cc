// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_etiqueta.cc
// Contiene la definicion de la clase Etiqueta

#include "p04_etiqueta.h"
#include <iostream>


/**
 * @brief Constructor de la clase Etiqueta
 * @param nombre, linea, es_cierre
 */
Etiqueta::Etiqueta(const std::string& nombre, size_t linea, bool es_cierre) : nombre_(nombre), numero_linea_(linea), cierre_(es_cierre) {}

/**
 * @brief AñadirAtributo: Metodo de la clase que poermite añadir un atributo al vector
 * @param atributo
 */

void Etiqueta::AñadirAtributo(const Atributo& atributo) {
    atributos_.push_back(atributo);
}



/**
 * @brief HayAtributos: Metodo booleano que nos permite saber si hay atributos en el vector
 */

bool Etiqueta::HayAtributos() const {
    return !atributos_.empty();
}



/**
 * @brief CantidadAtributos: Metodo que nos permite acceder al tamaño del vector
 */

size_t Etiqueta::CantidadAtributos() const {
    return atributos_.size();
}



/**
 * @brief GetAtributos: Getter que nos permite acceder a los atributos
 */

const std::vector<Atributo> Etiqueta::GetAtributos() const {
    return atributos_;
}



/**
 * @brief EsCierre: Getter booleano que nos permite acceder al atributo que nos dice si es una etiqueta de cierre
 */

bool Etiqueta::EsCierre() const {
    return cierre_;
}



/**
 * @brief operator<<: Sobrecarga del operador de insercion en el flujo de salida estandar
 * @param os, etiqueta
 */

std::ostream& operator<<(std::ostream& os, const Etiqueta& etiqueta) {
    os << "[Line " << etiqueta.GetLinea() << "] ";
    if(etiqueta.EsCierre()) {
        os << "/";
    }
    os << etiqueta.GetNombre();
    return os;
}