// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_comentario.cc
// Contiene la definicion de la clase Comentario

#include "p04_comentario.h"
#include <cassert>
#include <iostream>

/**
 * @brief Constructor de la clase Comentario
 * @param texto, inicio, final, descripcion
 */

Comentario::Comentario(const std::string& texto, int inicio, int final, bool descripcion) 
 : texto_(texto), linea_inicial_(inicio), linea_final_(final), descripcion_(descripcion) 
 {
    assert(linea_final_ >= linea_inicial_);
 };




/**
 * @brief operator<<: Sobrecarga del operador de insercion en el flujo de salida estandar
 * @param os, comentario
 */

std::ostream& operator<<(std::ostream& os, const Comentario& comentario) {
    if(comentario.EsMultilinea()) {
        os << "[Line " << comentario.GetLineaInicio() << "-" << comentario.GetLineaFinal() << "]";
    }
    else {
        os << "[Line " << comentario.GetLineaInicio() << "]";
    }
    if(comentario.EsDescripcion()) {
        os << " DESCRIPTION";
    }
    os << std::endl;
    os << comentario.GetTexto();
    return os;
}
