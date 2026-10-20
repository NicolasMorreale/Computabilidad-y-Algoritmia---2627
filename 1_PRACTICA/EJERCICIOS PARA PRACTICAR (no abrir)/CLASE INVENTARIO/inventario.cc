/**
 * Enunciado: Un fichero contiene una lista de códigos de producto (pueden repetirse), uno por línea:
P001
P045
P001
P102
P045
Desarrolla una clase Inventario que cargue el fichero y muestre, ordenado, 
el listado de códigos únicos que aparecen (sin duplicados, sin contar cuántas veces aparece cada uno).
 Debe permitir además comprobar si un código concreto existe.
 */


#include "inventario.h"
#include <fstream>


/**
 * @brief CargarDesdeFichero: Metodo que permite cargar los codigos del inventario desde un fichero de texto
 * @param nombre_fichero
 */

bool Inventario::CargarDesdeFichero(const std::string& nombre_fichero) {
    std::ifstream entrada_fichero(nombre_fichero);
    if(!entrada_fichero.is_open()) return false;
    std::string linea;
    while(entrada_fichero >> linea) {
        InsertarCodigo(linea);
    }
    return true;
}



/**
 * @brief MostrarInventario: Metodo que nos permite mostrar por la salida estandar el inventario (sin codigos repetidos)
 */

void Inventario::MostrarInventario() const {
    for(const std::string codigo : inventario_) {
        std::cout << codigo << std::endl;
    }
}



/**
 * @brief InsertarCodigo: Metodo que permite insertar un codigo en el inventario
 * @param codigo
 */

bool Inventario::InsertarCodigo(const std::string& codigo) {
    // std::set::insert devuelve un std::pair<iterator, bool>
    // .second vale true si se insertó con éxito, o false si ya existía
    auto resultado = inventario_.insert(codigo);
    return resultado.second;
}



/**
 * @brief ExisteCodigo: Metodo que permite determinar si un codigo concreto existe
 * @param codigo
 */

bool Inventario::ExisteCodigo(const std::string& codigo) {
    // Si find() == end() significa que no se ha encontrado
    return inventario_.find(codigo) != inventario_.end();
}