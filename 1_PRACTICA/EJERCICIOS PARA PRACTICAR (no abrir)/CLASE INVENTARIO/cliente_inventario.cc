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

int main(int argc, char* argv[]) {
    // 1. Caso de error en argumentos
    if(argc == 1) {
        std::cerr << "Uso del programa: " << argv[0] << " diccionario.txt" << std::endl;
        std::cerr << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
        return 1;
    }
    // Caso 2: Querer usar el --help
    std::string primer_argumento = argv[1];
    if(primer_argumento == "--help") {
        std::cout << "Uso del programa: " << argv[0] << " inventario.txt" << std::endl;
        std::cout << "Carga un fichero de texto con codigos de un inventario, desordenados y repetidos" << std::endl;
        std::cout << "y muestra por pantalla, el inventario ordenado, sin repeticion y dando la opcion de buscar si un codigo concreto existe" << std::endl;
        return 0;
    }
    // Programa principal
    Inventario inventario_main;
    if(!inventario_main.CargarDesdeFichero(primer_argumento)) {
        std::cerr << "Error. No se ha podido abrir el fichero " << primer_argumento << std::endl;
        return 1;
    }
    inventario_main.MostrarInventario();
    std::string codigo;
    std::cout << "Introduzca el codigo que desea saber si existe en el inventario:" << std::endl;
    std::cin >> codigo;
    if(inventario_main.ExisteCodigo(codigo)) {
        std::cout << "Si, el codigo que ha introducido existe actualmente en el inventario." << std::endl;
    } else {
        std::cout << "No, el codigo que ha introducido no existe actualmente en el inventario." << std::endl;
        std::cout << "¿Desea introducirlo en el inventario? [S/N]." << std::endl;
        std::string respuesta;
        std::cin >> respuesta;
        if(respuesta == "S") inventario_main.InsertarCodigo(codigo);
    }

    // Mostrar estado final del inventario
    std::cout << "Mostrando estado final del inventario:" << std::endl;
    inventario_main.MostrarInventario();
    return 0;
}