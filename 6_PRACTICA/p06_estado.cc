// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de DFAs en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 16/10/2026
// Archivo: p06_estado.cc
// Contiene la definicion de la clase Estado

#include "p06_estado.h"


/**
 * @brief Constructor de la clase Estado
 * @param id, aceptacion
 */

Estado::Estado(int id, bool aceptacion) : id_(id), es_de_aceptacion_(aceptacion) {}



/**
 * @brief AñadirTransicion: Funcion que nos permite añadir transiciones a nuestro multimapa 
 * @param simbolo, id_estado
 */

void Estado::AñadirTransicion(char simbolo, int id_estado) {
    transiciones_[simbolo] = id_estado;
}



/**
 * @brief GetEstadoSiguiente : Funcion que al recibir un simbolo, devuelve por referencia el estado siguiente,
 * pero es booleana es decir, un false es que no hay transicion
 * @param simbolo, id_estado_siguiente
 */

bool Estado::GetEstadoSiguiente(char simbolo, int& id_estado_siguiente) const {
    auto iterador = transiciones_.find(simbolo);
    if(iterador != transiciones_.end()) {
        id_estado_siguiente = iterador->second;
        return true;
    }
    return false;
}
