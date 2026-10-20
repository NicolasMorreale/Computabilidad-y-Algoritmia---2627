// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de DFAs en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 17/10/2026
// Archivo: p06_dfa.cc
// Contiene la definicion de la clase DFA

#include "p06_dfa.h"
#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief GetLineaSigValida: Funcion auxiliar que me permite determinar si una linea a leer es valida del fichero .dfa
 * @param archivo, linea
 */

bool DFA::GetLineaSigValida(std::ifstream& archivo, std::string& linea) const {
    while(std::getline(archivo, linea)) {
        if(!linea.empty() && !(linea.length() >= 2 && linea[0] == '/' && linea[1] == '/')) return true;
    }
    return false;
}



/**
 * @brief CargarDesdeFichero: Funcion que nos permite cargar la informacion del DFA desde un fichero
 * @param nombre_fichero_dfa
 */
bool DFA::CargarDesdeFichero(const std::string& nombre_fichero_dfa) {
    std::ifstream entrada(nombre_fichero_dfa);
    if(!entrada.is_open()) {
        std::cerr << "ERROR. No se ha podido abrir el fichero " << nombre_fichero_dfa << ".\n";
        return false;
    }

    // Leemos la primera linea valida (simbolos del alfabeto del DFA)
    std::string linea;
    if(!GetLineaSigValida(entrada, linea)) return false;
    for(char simbolo : linea) {
        if(!std::isspace(simbolo)) alfabeto_.AñadirSimbolo(simbolo);
    }

    // Leemos la segunda linea valida (numero de estados del DFA)
    if(!GetLineaSigValida(entrada, linea)) return false;
    int numero_estados = std::stoi(linea);

    // Leemos la tercera linea valida que es el estado de arranque
    if(!GetLineaSigValida(entrada, linea)) return false;
    id_estado_arranque_ = std::stoi(linea);


    // Leemos cada estado junto a sus transiciones
    for(int i{0}; i < numero_estados; i++) {
        if(!GetLineaSigValida(entrada, linea)) return false;
        std::stringstream flujo(linea);
        int id_estado;
        int es_aceptacion;
        // Comprobamos que se haya leido el identificador y si es de aceptacion
        if(!(flujo >> id_estado >> es_aceptacion)) return false;

        // Instanciamos el objeto estado
        Estado estado(id_estado, es_aceptacion == 1);

        char simbolo_transicion;
        int estado_destino;
        // Tomamos todas las transiciones con el par (simbolo, destino)
        while(flujo >> simbolo_transicion >> estado_destino) {
            estado.AñadirTransicion(simbolo_transicion, estado_destino);
        }
        // Guardamos en nuestro std::map cada estado instanciado del DFA, utilizando como guia el identificador
        estados_[id_estado] = estado;
    }
    return true;
}



/**
 * @brief EsDFA: Funcion que nos permite validar si cumple todas las propiedades de un DFA
 */

bool DFA::EsDFA() const {
    // Primera comprobacion
    if(id_estado_arranque_ == -1 || estados_.find(id_estado_arranque_) == estados_.end()) return false;

    // Para todos los estados del automata (id, estado)
    for(const auto& par_id_estado : estados_) {

        const Estado& estado_actual = par_id_estado.second;

        // Comprobamos que para cada simbolo, haya una transicion (cantidad de simbolos del alfabeto == cantidad transiciones)
        if (estado_actual.GetTransiciones().size() != alfabeto_.TamañoAlfabeto()) {
            std::cerr << "ERROR. El estado " << estado_actual.GetId() 
                << " tiene un numero de transiciones (" << estado_actual.GetTransiciones().size()
                << ") diferente al tamano del alfabeto (" << alfabeto_.TamañoAlfabeto() << ").\n";
            return false;
        }

        // Miramos sus transiciones con todos los simbolos del alfabeto
        for(char simbolo : alfabeto_.GetSimbolos()) {   

            // Id del estado al que transitaremos con el simbolo, que se pasa como referencia a la funcion
            int id_destino;

            // GetEstadoSiguiente devuelve si hay transicion al estado siguiente
            if(!estado_actual.GetEstadoSiguiente(simbolo, id_destino)) {
                std::cerr << "ERROR. El estado " << estado_actual.GetId() << " no tiene transicion para el simbolo '" << simbolo << "'.\n";
                return false;
            }

            // Comprobamos si existe el estado de destino en el automata
            if(estados_.find(id_destino) == estados_.end()) {
                std::cerr << "ERROR. Transicion desde el estado " << estado_actual.GetId() 
                << " hacia un estado inexistente en el DFA: " << id_destino << ".\n";
                return false;
            }
        }
    }
    // Si pasa todas las pruebas, el DFA es valido.
    return true;
}



/**
 * @brief ReconocerCadena: Funcion que nos permite simular el DFA aceptando o rechazando una cadena
 * @param cadena
 */

bool DFA::ReconocerCadena(const std::string& cadena) const {
    int id_estado_actual = id_estado_arranque_;
    // Comprobacion de la cadena vacia
    if(cadena == "&") {
        bool es_estado_aceptacion = estados_.at(id_estado_actual).GetEsAceptacion();
        std::cout << "Cadena de entrada " << (es_estado_aceptacion ? "ACEPTADA" : "RECHAZADA") << ".\n";
        return es_estado_aceptacion;
    }

    // Imprimimos los nombres de las columnas
    std::cout << "Est. Actual\tEntrada\t\tNuevo Est.\n";

    // Comprobacion de que todos los simbolos de la cadena pertenezcan al alfabeto del DFA
    for(char simbolo : cadena) {
        if(!alfabeto_.Pertenece(simbolo)) {
            std::cerr << "El simbolo " << simbolo << " no pertenece al alfabeto.\n";
            std::cout << "Cadena de entrada RECHAZADA.\n";
            return false;
        }

        // Empezamos a hacer transiciones
        int id_estado_siguiente;
        estados_.at(id_estado_actual).GetEstadoSiguiente(simbolo, id_estado_siguiente);

        std::cout << id_estado_actual << "\t\t" << simbolo << "\t\t" << id_estado_siguiente << "\n";

        // Actualizamos el estado actual 
        id_estado_actual = id_estado_siguiente;
    }

    // Ahora mismo, estado actual es el ultimo estado posible del automata, por tanto, si es de aceptacion, la cadena es aceptada
    bool es_estado_aceptacion = estados_.at(id_estado_actual).GetEsAceptacion();
    std::cout << "Cadena de entrada " << (es_estado_aceptacion ? "ACEPTADA" : "RECHAZADA") << ".\n\n";

    return es_estado_aceptacion;
}



/**
 * @brief FicheroTexto: Funcion que nos permite recibir las cadenas desde el archivo de texto y pasarselo a la funcion que se encarga de simular el DFA
 * @param nombre_fichero_txt
 */

bool DFA::FicheroTexto(const std::string& nombre_fichero_txt) const {
    std::ifstream entrada(nombre_fichero_txt);
    if(!entrada.is_open()) {
        std::cerr << "ERROR. No fue posible abrir el fichero de cadenas " << nombre_fichero_txt << ".\n";
        return false;
    }

    std::string cadena;
    while(entrada >> cadena) {
        ReconocerCadena(cadena);
    }
    return true;
}

// MODIFICACION 20 DE OCTUBRE 2026
// ESTADOS DE ABSORCION

/**
 * @brief EstadosAbsorcion: Modificacion de la clase DFA, para mostrar los estados de absorcion
 */

void DFA::EstadosAbsorcion() const {
    // Vector donde almacenaremos los estados de absorcion
    std::vector<int> vector_estados_absorcion;

    // Accedemos a cada estado del automata
    for(const auto& par_id_estado : GetEstados()) {

        int id_actual = par_id_estado.first;
        const Estado& estado_actual = par_id_estado.second;

        // Comprobamos que no sea de aceptacion -> Estado absorcion nunca es de aceptacion
        if(!estado_actual.GetEsAceptacion()) {

            bool es_absorcion = true;

            // Probamos con las transiciones con cada simbolo, si hay alguno con el que salga de ese estado, no es de absorcion
            for(char simbolo : GetAlfabeto().GetSimbolos()) {

                int id_destino;
                estado_actual.GetEstadoSiguiente(simbolo, id_destino);
                
                // Comprobamos la condicion de un estado de absorcion
                if(id_destino != id_actual) {
                    es_absorcion = false;
                    break;
                }
            }
            // Si no salio con ningun simbolo, es de absorcion
            if(es_absorcion) {
                vector_estados_absorcion.push_back(id_actual);
            }
        }
    }

    // Mostramos los estados
    if(vector_estados_absorcion.empty()) {
        std::cout << "El DFA no tiene estados de absorcion.\n";
    }
    else {
        std::cout << "Estados de absorcion encontrados: " << std::endl;
        for(size_t i{0}; i < vector_estados_absorcion.size(); i++) {
            std::cout << vector_estados_absorcion[i] << (i + 1 < vector_estados_absorcion.size() ? "," : "");
        }
        std::cout << std::endl;
    }
}