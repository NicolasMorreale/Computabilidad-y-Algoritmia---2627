// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramatica
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/10/2026
// Archivo: grammar.cc
// Contiene la definicion de la clase Grammar

#include "grammar.h"
#include <map>

/**
 * @brief Exporta toda la descripcion de la Gramatica Regular a un fichero .gra
 * @param filename
 * @return true si se exporto exitosamente, false de lo contrario
 */


bool Grammar::ExportToFile(const std::string& filename) const {
    std::ofstream salida(filename);
    if(!salida.is_open()) {
        std::cerr << "ERROR. No se ha podido abrir el fichero " << filename << ".\n";
        return false;
    }

    // Bloque de simbolos terminales
    salida << GetTerminales().size() << '\n';
    for(char terminales : GetTerminales()) {
        salida << terminales << '\n';
    }

    // Bloque de simbolos no-terminales
    salida << GetNoTerminales().size() << '\n';
    for(const std::string& no_terminales : GetNoTerminales()) {
        salida << no_terminales << '\n';
    }

    // Simbolo de arranque
    salida << GetSimboloArranque() << '\n';

    // Bloque de producciones
    salida << GetProducciones().size() << '\n';
    for(const Produccion& produccion : GetProducciones()) {
        salida << produccion.left << " -> " << produccion.right << '\n';
    }
    return true;
}


/**
 * @brief MODIFICACION: Exporta toda la descripcion de la Gramatica Regular a un fichero .gra de manera agrupada (|)
 * @param filename
 * @return true si se exporto exitosamente, false de lo contrario
 */

bool Grammar::ExportToFileAlt(const std::string& filename) const {
    std::ofstream salida(filename);
    if(!salida.is_open()) {
        std::cerr << "EROR. No se ha podido abrir el fichero " << filename << ".\n";
        return false;
    }

    // Bloque de simbolos terminales
    salida << GetTerminales().size() << '\n';
    for(char terminales : GetTerminales()) {
        salida << terminales << '\n';
    }

    // Bloque de simbolos no-terminales
    salida << GetNoTerminales().size() << '\n';
    for(const std::string& no_terminales : GetNoTerminales()) {
        salida << no_terminales << '\n';
    }

    // Simbolo de arranque
    salida << GetSimboloArranque() << '\n';

    // Bloque de producciones 
    std::vector<std::string> orden_no_terminales;
    std::map<std::string, std::vector<std::string>> agrupadas;

    for(const Produccion& prod : GetProducciones()) {
        if(agrupadas.find(prod.left) == agrupadas.end()) {
            orden_no_terminales.push_back(prod.left);
        }
        agrupadas[prod.left].push_back(prod.right);
    }

    salida << orden_no_terminales.size() << '\n';

    for(const std::string& no_terminal : orden_no_terminales) {
        salida << no_terminal << " -> ";
        const auto& derechos = agrupadas[no_terminal];
        for(size_t i{0}; i < derechos.size(); i++) {
            salida << derechos[i];
            if(i + 1 < derechos.size()) {
                salida << " | ";
            }
        }
        salida << '\n';
    }

}