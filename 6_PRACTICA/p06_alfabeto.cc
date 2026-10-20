// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de DFAs en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 16/10/2026
// Archivo: p06_alfabeto.cc
// Contiene la definicion de la clase Alfabeto

#include "p06_alfabeto.h"


/**
 * @brief Constructor de la clase Alfabeto
 * @param simbolos
 */

Alfabeto::Alfabeto(const std::string& simbolos) {
    for(char caracter : simbolos) {
        AñadirSimbolo(caracter);
    }
}



/**
 * @brief Pertenece: Funcion booleana que determina si un simbolo pertenece al alfabeto o no
 * @param simbolo
 */

bool Alfabeto::Pertenece(char simbolo) const {
    return simbolos_.find(simbolo) != simbolos_.end();
}



/**
 * @brief TamañoAlfabeto: Funcion que retorna el tamaño del alfabeto, es decir, la cantidad de simbolos que tiene
 */

size_t Alfabeto::TamañoAlfabeto() const {
    return simbolos_.size();
}



/**
 * @brief AñadirSimbolo: Funcion que permite añadir un simbolo al alfabeto
 * @param simbolo
 */

void Alfabeto::AñadirSimbolo(char simbolo) {
    if(simbolo != '&') simbolos_.insert(simbolo);
}
