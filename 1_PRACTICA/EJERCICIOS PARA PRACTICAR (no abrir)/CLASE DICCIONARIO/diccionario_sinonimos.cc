#include "diccionario_sinonimos.h"
#include <fstream>
#include <sstream>
/**
 * @brief Constructor de la clase Diccionario
 */

Diccionario::Diccionario() {};



/**
 * @brief CargarDesdeFichero: Metodo que permite cargar el contenido del fichero
 * @param nombre_fichero
 */

bool Diccionario::CargarDesdeFichero(const std::string& nombre_fichero) {
    std::ifstream entrada_fichero(nombre_fichero);
    // Comprobamos que el fichero se abra correctamente, luego lo manejaremos en main
    if(!entrada_fichero.is_open()) return false;
    std::string linea;
    // Tomamos el contenido del fichero linea por linea
    while(std::getline(entrada_fichero, linea)) {
        // Abrimos un flujo que nos permitira parsear la linea palabra a palabra
        std::istringstream flujo(linea);
        std::string palabra, sinonimo;
        // Insertamos a cada palabra su sinonimo
        if(flujo >> palabra >> sinonimo) InsertarSinonimo(palabra, sinonimo);
    }
    return true;
}



/**
 * @brief InsertarSinonimo: Metodo que nos permite añadir un sinonimo nuevo a cada palabra
 * @param palabra
 * @param sinonimo
 */

void Diccionario::InsertarSinonimo(const std::string& palabra, const std::string& sinonimo) {
    // No hace falta comprobar si ya existe la clave, ya que multimap permite que este repetida, asi que directamente insertamos palabra y sinonimo
    diccionario_.insert({palabra,sinonimo});
}



/**
 * @brief MostrarSinonimos: Metodo que nos permite visualizar los sinonimos de cada palabra por pantalla
 * @param palabra 
 */

void Diccionario::MostrarSinonimos(const std::string& palabra) const {
    // Como cada clave puede tener varias entradas o valores, tenemos que pillar el rango
    auto rango = diccionario_.equal_range(palabra);
    // Si las cotas del rango son iguales, significa que no hay 
    if(rango.first == rango.second) {
        std::cout << "No se encontraron sinonimos para " << palabra << std::endl;
        return;
    }
    std::cout << palabra << ":";
    // Mostramos los sinonimos
    for(auto it = rango.first; it != rango.second; ++it) {
        std::cout << " " << it->second;
    }
    std::cout << std::endl;
}



/**
 * @brief MostrarDiccionario: Metodo que nos permite visualizar el diccionario completo ordenado
 */

void Diccionario::MostrarDiccionario() const {
    // it nos sirve para movernos entre el principio y el final del diccionario
    auto it = diccionario_.begin();
    while(it != diccionario_.end()) {
        // rango nos sirve para movernos en los bloques de cada clave
        auto rango = diccionario_.equal_range(it->first);

        std::cout << it->first << ":";
        // it2 es el iterador que se mueve en los bloques de cada clave o palabra , mirando sus sinonimos
        for(auto it2 = rango.first; it2 != rango.second; ++it2) {
            std::cout << " " << it2->second;
        }
        std::cout << std::endl;
        // Acabamos con todas los sinonimos dentro del rango de "feliz"
        it = rango.second;
    }
}