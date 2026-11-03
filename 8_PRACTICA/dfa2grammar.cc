// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramatica
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/10/2026
// Archivo: dfa2grammar.cc
// Contiene el programa principal

#include "automata.h"
#include "grammar.h"

/**
 * @brief Muestra ayuda sobre el uso del programa.
 * @param program_name
 */

void Help(const std::string& program_name) {
  std::cout << "Uso: " << program_name << " input.dfa output.gra\n\n"
            << "Descripción:\n"
            << "  Lee la especificación de un Automata Finito Determinista (DFA)\n"
            << "  desde el fichero 'input.dfa' y genera una Gramática Regular equivalente\n"
            << "  guardándola en el fichero 'output.gra'.\n\n"
            << "Opciones:\n"
            << "  --help, -h    Muestra esta información de ayuda.\n";
}



/**
 * @brief Programa principal
 */

int main(int argc, char* argv[]) {

    // Comprobaciones de la linea de comandos.
    if(argc == 1) {
        std::cout << "Modo de empleo: " << argv[0] << " input.dfa output.gra\n";
        std::cout << "Pruebe '" << argv[0] << " --help' para mas informacion.\n";
        return 0;
    } 

    if(argc == 2 && ((std::string(argv[1])) == "--help" || std::string(argv[1]) == "-h")) {
        Help(std::string(argv[0]));
        return 0;
    }

    if (argc != 3 && argc != 4) {
        std::cerr << "ERROR. Número de argumentos incorrecto.\n";
        std::cerr << "Pruebe: " << argv[0] << " --help para más información.\n";
        return 1;
    }

    // Guardamos nombres de los ficheros.
    std::string input_dfa_filename = std::string(argv[1]);
    std::string output_gra_filename = std::string(argv[2]);
    bool modo_alt = false;

    // Comprobamos si nos pasan el alt
    if(argc == 4) {
        if(std::string(argv[3]) == "alt") {
            modo_alt = true;
        }
        else {
            std::cerr << "ERROR. El tercer parámetro opcional debe ser 'alt'.\n";
            std::cerr << "Pruebe: " << argv[0] << " --help para más información.\n";
            return 1;
        }
    }

    // Instancia del Automata.
    Automata automata;
    if(!automata.LoadFromFile(input_dfa_filename)) {
        std::cerr << "ERROR. No se pudo cargar el automata desde el fichero '" << input_dfa_filename << "'.\n";
        return 1;
    }

    std::cout << "Automata cargado con exito desde el fichero '" << input_dfa_filename << "'.\n";

    // Instancia de la gramatica.
    Grammar gramatica = automata.ConvertToGrammar();
    bool exito = false;

    // Lo mostramos de una forma u otra en funcion de si se introdujo alt
    if (modo_alt) {
        exito = gramatica.ExportToFileAlt(output_gra_filename);
    } 
    else {
        exito = gramatica.ExportToFile(output_gra_filename);
    }

    if (!exito) {
        std::cerr << "ERROR. No se pudo exportar la gramática al fichero '" 
        << output_gra_filename << "'.\n";
        return 1;
    }
    
    std::cout << "Gramática Regular exportada con éxito a '" << output_gra_filename << "' "
    << (modo_alt ? "(Formato alternativo agrupado)." : "(Formato estándar).") << "\n";

    return 0;
}