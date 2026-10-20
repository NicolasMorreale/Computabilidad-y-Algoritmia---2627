// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de DFAs en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 16/10/2026
// Archivo: p06_cliente_main.cc
// Contiene el programa principal

/**
 * @brief Funcion auxiliar para el mensaje de ayuda
 */

#include <iostream>
#include "p06_dfa.h"

void help() {
    std::cout << "Modo de empleo: ./p06_DFA_simulator input.dfa input.txt\n\n"
            << "Descripcion:\n"
            << "  Simula el comportamiento de un Automata Finito Determinista (DFA)\n"
            << "  definido en 'input.dfa' para las cadenas contenidas en 'input.txt'.\n\n"
            << "Formato del fichero .dfa:\n"
            << "  Linea 1: Simbolos del alfabeto sin espacios.\n"
            << "  Linea 2: Numero total de estados.\n"
            << "  Linea 3: Estado inicial.\n"
            << "  Lineas siguientes: ID_estado es_aceptacion (0|1) [simbolo estado_destino]...\n"
            << "  Las lineas que comiencen por '//' se consideran comentarios.\n";
}


int main(int argc, char* argv[]) {
    if(argc == 2 && std::string(argv[1]) == "--help") {
        help();
        return 0;
    }

    if (argc != 3) {
        std::cout << "Modo de empleo: " << argv[0] << " input.dfa input.txt\n"
                << "Pruebe '" << argv[0] << " --help' para mas informacion." << std::endl;
        return 1;
    }

    DFA dfa;
    if (!dfa.CargarDesdeFichero(std::string(argv[1]))) {
        std::cerr << "Error al cargar el fichero .dfa." << std::endl;
        return 1;
    }

    if (!dfa.EsDFA()) {
        std::cerr << "El automata definido no es un DFA valido." << std::endl;
        return 1;
    }

    if (!dfa.FicheroTexto(std::string(argv[2]))) {
        std::cerr << "Error al procesar las cadenas de entrada." << std::endl;
        return 1;
    }
    // MODIFICACION 20 OCTUBRE 2026 -> Mostrar Estados Absorcion
    dfa.EstadosAbsorcion();
    
    return 0;
}