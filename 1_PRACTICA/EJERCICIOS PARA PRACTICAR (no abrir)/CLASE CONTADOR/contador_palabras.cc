/**
 * 3. Contador de palabras (std::map)

Enunciado: Dado un fichero de texto libre (varias palabras por línea,
 separadas por espacios), desarrolla una clase ContadorPalabras
 que cuente cuántas veces aparece cada palabra en el fichero completo
 , y las muestre ordenadas alfabéticamente junto con su frecuencia.
 */

#include "contador_palabras.h"
#include <fstream>
#include <sstream>



/**
 * @brief CargarDesdeFichero: Metodo que permite cargar las palabras desde el fichero 
 * @param nombre_fichero
 */

bool Contador::CargarDesdeFichero(const std::string& nombre_fichero) {
    std::ifstream entrada_fichero(nombre_fichero);
    if(!entrada_fichero.is_open()) return false;
    std::string palabra;
    // El operador >> lee palabra a palabra, separadas por espacios
    while(entrada_fichero >> palabra) {
        AgregarPalabras(palabra);
    }
    return true;
}

/**
 * @brief AgregarPalabras: Metodo que permite agregar las palabras y sus frecuencias
 * @param palabra
 */

void Contador::AgregarPalabras(const std::string& palabra) {
    auto it = contador_.find(palabra);
    if(it != contador_.end()) {
        it->second++;
    } else {
        contador_.insert({palabra,1});
    }
}

/**
 * @brief ObtenerFrecuencia: Metodo que permite obtener la frecuencia de cada palabra
 * @param palabra
 */

int Contador::ObtenerFrecuencia(const std::string& palabra) {
    auto it = contador_.find(palabra);
    if(it != contador_.end()) return it->second;
    return 0;
}

/**
 * @brief MostrarContador: Metodo que nos permite mostrar por la salida estandar las palabras y su frecuencia
 */

void Contador::MostrarContador() const {
    for(const auto& par : contador_) {
        std::cout << par.first << " " << par.second << std::endl;
    }
}