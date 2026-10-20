// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 12/09/2026
// Archivo: grades.cc
// Contiene la definicion de la clase Grades

#include "grades.h"
#include <fstream>
#include <sstream>


/**
 *@brief Constructor de la clase Grades (vacio)
 */
Grades::Grades() {};



/**
 *@brief CargarDesdeFichero: Carga la informacion desde el fichero
 *@param nombre_fichero : Nombre del fichero
 */

bool Grades::CargarDesdeFichero(const std::string& nombre_fichero) {

  // Tomamos todas las lineas del fichero y las tenemos en entrada_fichero
  std::ifstream entrada_fichero(nombre_fichero);
  // En el programa principal mostraremos un error en caso de que no se haya leido correctamente 
  if(!entrada_fichero.is_open()) return false;

  // Usando std::getline() vamos pillando linea por linea
  std::string linea;
  while(std::getline(entrada_fichero, linea)) {

    // Utilizamos std::istringstream para poder parsear esa linea en los dos tipos de dato que contienen (clave y valor)
    std::istringstream flujo(linea);
    std::string alu;
    double nota;
    // Comprobamos que estemos recibiendo el alu y la nota y la insertamos usando nuestro otro metodo
    if(flujo >> alu >> nota) {
        InsertarNota(alu,nota);
    }
	}
    // Si llegamos hasta aqui, se leyo correctamente el fichero
  return true;
}




/**
 * @brief Metodo que insertara alumnos y calificaciones en el mapa, si no existe inserta ambas cosas, si existe, comprobara la calificacion mas alta
 * @param alu
 * @param nota
 */

void Grades::InsertarNota(const std::string& alu, double nota) {
    // Comprobamos si el alu ya existe en el mapa, si no existe, iterador va ser mapa_notas_.end()
    auto iterador = mapa_notas_.find(alu);
    // Si se cumple, no existe, entonces hay que meter tanto alu como nota (usamos insert())
    if(iterador == mapa_notas_.end()) {
      mapa_notas_.insert({alu, nota});
    } else {
      // En este caso, si existia el alu en el mapa, asi que comparamos la nota
      if(nota > iterador->second) 
        iterador->second = nota;
    }
}



/**
 * @brief Metodo que mostrara por pantalla el contenido de la lista de calificaciones maximas de cada alumno
 */

void Grades::MostrarListaNotas() const {
	for(const auto& par_alu_nota : mapa_notas_) {
		std::cout << par_alu_nota.first << " " << par_alu_nota.second << std::endl;
	}
}