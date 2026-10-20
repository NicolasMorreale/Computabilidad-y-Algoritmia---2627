#include "diccionario_sinonimos.h"

int main(int argc, char* argv[]) {
     // Caso 1: No saber usar el programa 
    if(argc == 1) {
        std::cerr << "Uso del programa: " << argv[0] << " diccionario.txt" << std::endl;
        std::cerr << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
        return 1;
    }
    // Caso 2: Querer usar el --help
    std::string primer_argumento = argv[1];
    if(primer_argumento == "--help") {
        std::cout << "Uso del programa: " << argv[0] << " diccionario.txt" << std::endl;
        std::cout << "Carga un fichero de texto con palabras y sus sinonimos" << std::endl;
        std::cout << "y muestra por pantalla, una palabra seguida de todos sus sinonimos recopilados" << std::endl;
        return 0;
    }
    // Programa Principal
    Diccionario diccionario_main;
    if(!diccionario_main.CargarDesdeFichero(primer_argumento)) {
        std::cerr << "Error. No se ha podido abrir el fichero de texto " << primer_argumento << std::endl;
        return 1;
    }
    // Mostramos el diccionario completo
    diccionario_main.MostrarDiccionario();

    // Para mostrar los sinonimos de una palabra
    std::string palabra;
    std::cout << "Introduzca una palabra para ver sus sinonimos: " << std::endl;
    std::cin >> palabra;
    diccionario_main.MostrarSinonimos(palabra);

    // Insertar un nuevo sinonimo
    std::cout << "Introduzca la palabra a la que quiere añadir un sinonimo: " << std::endl;
    std::string palabra_añadir;
    std::cin >> palabra_añadir;
    std::cout << "Introduzca el sinonimo: " << std::endl;
    std::string sinonimo_añadir;
    std::cin >> sinonimo_añadir;
    diccionario_main.InsertarSinonimo(palabra_añadir, sinonimo_añadir);

    // Mostrar estado final del diccionario
    std::cout << "Estado final del diccionario:" << std::endl;
    diccionario_main.MostrarDiccionario();
    return 0;
}