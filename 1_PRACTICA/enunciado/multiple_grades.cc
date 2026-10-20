// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 13/09/2026
// Archivo: multiple_grades.cc
// Contiene la definicion de la clase MultipleGrades, asi como la de sus metodos MostrarListaNotas(), InsertarNotaVector(), CargarDesdeFichero()

#include "multiple_grades.h"
#include <fstream>
#include <sstream>



/**
 * @brief Constructor de la clase MultipleGrades
 */

MultipleGrades::MultipleGrades() {};



/**
 * @brief CargarDesdeFichero: Metodo que nos permite cargar la informacion (alu, nota) desde un fichero de texto
 * @param nombre_fichero 
 */

bool MultipleGrades::CargarDesdeFichero(const std::string& nombre_fichero) {
    std::ifstream entrada_fichero(nombre_fichero);
    if(!entrada_fichero.is_open()) return false;
    
    std::string linea;
    while(std::getline(entrada_fichero,linea)) {
        std::istringstream flujo(linea);
        std::string alu;
        double nota;
        if(flujo >> alu >> nota) InsertarNotasVector(alu, nota);
    }
    return true;
}



/**
 * @brief InsertarNotasVector: Metodo que nos permite insertar las notas obtenidas desde el fichero en el vector 
 * @param alu
 * @param nota
 */

void MultipleGrades::InsertarNotasVector(const std::string& alu, double nota) {
    // Buscamos si existe ya este alumno
    auto iterador = mapa_notas_.find(alu);
    // Si no existe el alumno en la lista, lo añadimos con su alu y su nota
    if(iterador == mapa_notas_.end()) {
        std::vector<double> vector_notas;
        vector_notas.push_back(nota);
        mapa_notas_.insert({alu,vector_notas});
    } else {
        // Si existe el alu, simplemente añadimos la nueva nota al vector
        iterador->second.push_back(nota);
    }

}



/**
 * @brief MostrarListaNotas: Metodo que nos permite visualizar por pantalla los alus y las notas
 */

 void MultipleGrades::MostrarListaNotas() const {
    for(const auto& par_alu_nota : mapa_notas_) {
        std::cout << par_alu_nota.first << ":";
        for(double nota : par_alu_nota.second) {
            std::cout << " " << nota;
        }
        std::cout << std::endl;
    }
}



/**
 * @brief MaxALU: Metodo que permite acceder a la calificacion maxima de un estudiante 
 * @param alu
 */

double MultipleGrades::MaxALU(const std::string& alu) {
    double max{0.0};
    auto iterador = mapa_notas_.find(alu);
    for(size_t i{0}; i < iterador->second.size(); i++) {
        if(iterador->second[i] > max) {
            max = iterador->second[i];
        }
    }
    return max;
}

/**
 * @brief ExisteAlumno: Metodo que permite saber si existe un alumno en el mapa de notas
 * @param alu
 */

bool MultipleGrades::ExisteAlumno(const std::string& alu) {
    return mapa_notas_.find(alu) != mapa_notas_.end();
}