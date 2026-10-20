/**
 * Programa Principal : Clase Contador
 */

#include "contador_palabras.h"

int main(int argc, char* argv[]) {
    // Caso 1: No saber usar el programa 
    if(argc == 1) {
        std::cerr << "Uso del programa: " << argv[0] << " contador.txt" << std::endl;
        std::cerr << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
        return 1;
    }
    // Caso 2: Querer usar el --help
    std::string primer_argumento = argv[1];
    if(primer_argumento == "--help") {
        std::cout << "Uso del programa: " << argv[0] << " diccionario.txt" << std::endl;
        std::cout << "Carga un fichero de texto con palabras separadas por espacios" << std::endl;
        std::cout << "y muestra por pantalla, cada palabra y la frecuencia con la que aparece en el fichero de texto" << std::endl;
        return 0;
    }
    // Programa Principal
    Contador contador_main;
    if(!contador_main.CargarDesdeFichero(primer_argumento)) {
        std::cerr << "Error. No se ha podido cargar el fichero " << primer_argumento << std::endl;
        return 1;
    }
    // Mostramos el contador
    std::cout << "Estado del contador: " << std::endl;
    contador_main.MostrarContador();
    return 0;
}