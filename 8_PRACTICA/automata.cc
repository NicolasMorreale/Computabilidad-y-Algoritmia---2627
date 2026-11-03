// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramatica
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/10/2026
// Archivo: automata.cc
// Contiene la definicion de la clase Automata

#include "automata.h"

/**
 * @brief Constructor de la clase Automata
 * @param filename
 */

Automata::Automata(const std::string& filename) {
    LoadFromFile(filename);
}



/**
 * @brief Carga datos del automata desde el fichero .dfa
 * @param filename
 * @return true si la carga fue exitosa, false en caso contrario
 */

bool Automata::LoadFromFile(const std::string& filename) {
    std::ifstream entrada(filename);
    if(!entrada.is_open()) {
        std::cerr << "ERROR. No se ha podido abrir el fichero " << filename << "\n";
        return false;
    }

    estados_.clear();
    // 1. Leemos el alfabeto
    std::string linea;
    if(!std::getline(entrada,linea)) {
        return false;
    }
    std::stringstream flujo(linea);
    char simbolo;
    while (flujo >> simbolo) {
        alfabeto_.AñadirSimbolo(simbolo);
    }

    // 2. Leemos numero total de estados
    int total_estados{0};
    if(!(entrada >> total_estados)) return false;

    // 3. Leemos estado de arranque
    if(!(entrada >> id_estado_inicial_)) return false;

    // 4. Leemos los estados del automata
    for(int i{0}; i < total_estados; i++) {
        int id_estado{0};
        int aceptacion{0};
        int num_transiciones{0};
        
        if(!(entrada >> id_estado >> aceptacion >> num_transiciones)) {
            std::cerr << "ERROR. Error al leer la cabecera del estado.\n";
            return false;
        }

        // Instanciamos el objeto Estado
        Estado estado_actual(id_estado, aceptacion);

        // 5. Leemos las transiciones desde este estado
        for(int j{0}; j < num_transiciones; j++) {
            char simbolo;
            int id_destino;
            
            if(!(entrada >> simbolo >> id_destino)) {
                std::cerr << "ERROR. Error al leer las transiciones del estado.\n";
                return false;
            }

            // Guardamos transicion
            estado_actual.AñadirTransicion(simbolo, id_destino);
        }

        // Guardamos en nuestro mapa de estados el nuevo Estado instanciado, guiandonos con su id.
        estados_[id_estado] = estado_actual;
    }
    return IsValidDFA();
}



/**
 * @brief Comprueba que la estructura cargada desde el fichero .dfa pertenezca a un DFA valido
 * @return true si es DFA valido, false en caso contrario
 */

bool Automata::IsValidDFA() const {

    // Comprobar que el estado de arranque existe
    if(GetEstados().find(id_estado_inicial_) == GetEstados().end()) {
        std::cerr << "ERROR. El estado de arranque (" << id_estado_inicial_ << ") no existe en el automata.\n";
        return false;
    }

    // Validar que cada estado tenga transiciones para todo simbolo del alfabeto
    size_t size_alfabeto{GetAlfabeto().TamañoAlfabeto()};
    for(const auto& [id, estado] : GetEstados()) {
        const auto& transiciones = estado.GetTransiciones();
        if (transiciones.size() != size_alfabeto) {
            std::cerr << "ERROR. El estado " << id << " tiene " << transiciones.size() << " transiciones, pero el alfabeto contiene " 
            << size_alfabeto << " simbolos.\n";
            return false;
        }
        
        // Comprobar que todos los estados destino existan en el automata
        for(const auto& [simbolo, id_destino] : transiciones) {
            if(GetEstados().find(id_destino) == GetEstados().end()) {
                std::cerr << "ERROR. Transicion desde el estado " << id << " con simbolo '" << simbolo << "' al estado " << id_destino << " que no pertenece al automata.\n";
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Aplica un algoritmo para obtener una Gramatica Regular a partir de un DFA
 * @return Gramatica Regular
 */

Grammar Automata::ConvertToGrammar() const {
    Grammar gramatica;

    // Guardamos el alfabeto en el conjunto de terminales (Sigma)
    for(char simbolo : GetAlfabeto().GetSimbolos()) {
        gramatica.AñadirTerminal(simbolo);
    }

    // Generamos un no-terminal por cada estado del automata (V)
    for(const auto& [id, estado] : GetEstados()) {
        std::string no_terminal = "Q" + std::to_string(id);
        gramatica.AñadirNoTerminal(no_terminal);
    }

    // Guardamos el simbolo de arranque
    std::string sim_arranque="Q" + std::to_string(id_estado_inicial_);
    gramatica.SetSimboloArranque(sim_arranque);

    // Reglas de producciones 
    for(const auto& [id, estado] : GetEstados()) {
        std::string no_terminal_origen= "Q" + std::to_string(id);

        // Funcion de transicion: delta(q,a) = p   => Q_q -> a Q_p
        for(const auto& [simbolo, id_destino] : estado.GetTransiciones()) {

            std::string no_terminal_destino = "Q" + std::to_string(id_destino);
            std::string lado_derecho = std::string(1, simbolo) + no_terminal_destino;
            gramatica.AñadirProduccion(no_terminal_origen, lado_derecho);
        }

        // Produccion vacia para estados de aceptacion : q in F -> Q_q -> &
        if(estado.GetEsAceptacion()) {
            gramatica.AñadirProduccion(no_terminal_origen, "&");
        }
    }
    return gramatica;
}