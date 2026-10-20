// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 19/09/2026
// Archivo: cliente_practica2.cc
// Contiene el programa principal de la practica 2 donde utilizamos las clases Alfabeto, Cadena y Lenguaje

#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"
#include <fstream>
#include <sstream>


/**
 * @brief MostrarAyuda: Funcion auxiliar para el menu del programa principal
 * @param prog_name
 */

void MostrarAyuda(const char* prog_name) {
  std::cout << "Modo de empleo: " << prog_name << " filein.txt fileout.txt opcode\n"
            << "Este programa carga un fichero de entrada filein.txt con el formato (cadena alfabeto) linea a linea\n"
            << "y deposita los resultados en un fichero de salida fileout.txt segun el opcode [1-6].\n\n"
            << "Opciones de opcode:\n"
            << "  1. ALFABETO: Escribir el alfabeto asociado a cada cadena de entrada.\n"
            << "  2. LONGITUD: Escribir la longitud de cada cadena de entrada.\n"
            << "  3. INVERSA: Escribir la cadena inversa de cada entrada.\n"
            << "  4. PREFIJOS: Escribir el conjunto (lenguaje) de prefijos de la cadena.\n"
            << "  5. SUFIJOS: Escribir el conjunto (lenguaje) de sufijos de la cadena.\n"
            << "  6. VALIDACION: Comprobar si la cadena esta definida sobre el alfabeto asociado (OK / ERROR).\n"
            << "  7. CONCATENACION: Concatenar las cadenas del fichero de entrada con la cadena de linea de comandos. \n";
}

/**
 * @brief main: Programa principal
 * @param argc
 * @param argv
 */

int main(int argc, char* argv[]) {
    // Mostrar proposito de programa
    if(argc == 2 && std::string(argv[1]) == "--help") {
        MostrarAyuda(argv[0]);
        return 0;
    }

    // Error en la linea de comandos
    if (argc != 5) {
        std::cout << "Modo de empleo: " << argv[0] << " filein.txt fileout.txt opcode\n";
        std::cout << "Pruebe '" << argv[0] << " --help' para más información.\n";
        return 1;
    }

    // Programa Principal
    std::ifstream file_in(argv[1]);
    if(!file_in.is_open()) {
        std::cerr << "ERROR. No se ha podido abrir el fichero " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream file_out(argv[2]);
    if(!file_out.is_open()) {
        std::cerr << "ERROR. No se ha podido abrir el fichero " << argv[2] << std::endl;
        return 1;
    }

    std::string linea;
    int opcode = std::stoi(argv[3]);
    std::string cadena_a_concatenar = std::string(argv[4]);
    while(std::getline(file_in, linea)) {
        if(linea.empty()) continue;

        std::stringstream flujo(linea);
        Cadena cadena_recibida;
        Alfabeto alfabeto_recibido;
        flujo >> cadena_recibida >> alfabeto_recibido;

        // Primera opcion -> escribir en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada.
        if(opcode == 1) {
            file_out << cadena_recibida << ": " << alfabeto_recibido << std::endl;
        } 
        
        // Segunda opcion -> escribir en el fichero de salida la longitud de cada cadena de entrada.
        else if(opcode == 2) {
            file_out << cadena_recibida.Longitud() << std::endl;
        }

        // Tercera opcion -> escribir en el fichero de salida la inversa de cada cadena de entrada.
        else if(opcode == 3) {
            file_out << cadena_recibida << " -> " << cadena_recibida.Inversa() << std::endl;
        }

        // Cuarta opcion -> escribir en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente
        else if(opcode == 4) {
            file_out << cadena_recibida.Prefijos() << std::endl;
        }

        // Quinta opcion -> escribir en el fichero de salida el conjunto de cadenas que son sufijos de la cadena de entrada corresponiente
        else if(opcode == 5) {
            file_out << cadena_recibida.Sufijos() << std::endl;
        }

        // Sexta opcion -> comprobar que la cadena este definida sobre el alfabeto asociado
        else if(opcode == 6) {
            if(cadena_recibida.Validacion(alfabeto_recibido)) {
                file_out << "OK" << std::endl;
            }
            else {
                file_out << "ERROR" << std::endl;
            }
        }
        else if(opcode == 7 && argc == 5) {
                file_out << cadena_recibida << ": " << cadena_recibida.Concatenar(cadena_a_concatenar) << std::endl;
        }
        else {
            std::cerr << "ERROR. Opcode " << opcode << " no reconocido. Debe ser un numero entre 1 y 7." << std::endl;
            return 1;
        }
    }
    return 0;
}