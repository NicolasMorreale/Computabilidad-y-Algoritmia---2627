// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 3/10/2026
// Archivo: p04_cliente_main.cc
// Contiene el programa principal

#include "p04_html_analyzer.h"
#include <iostream>


/**
 * @brief MostrarUso: Funcion auxiliar para mostrar el uso del programa principal
 * @param nombre_ejecutable
 */

void MostrarUso(const std::string& nombre_ejecutable) {
  std::cout << "Modo de uso:\n"
            << "  " << nombre_ejecutable << " <fichero_entrada.html> <fichero_salida.txt>\n\n"
            << "Descripcion de parametros:\n"
            << "  fichero_entrada.html : Ruta al archivo HTML que se va a analizar.\n"
            << "  fichero_salida.txt   : Ruta del archivo donde se guardara el informe generado.\n";
}



/**
 * @brief Programa Principal
 */

int main(int argc, char* argv[]) {
    if(argc != 3) {
        MostrarUso(std::string(argv[0]));
        return 1;
    }

    std::string fichero_entrada{argv[1]};
    std::string fichero_salida{argv[2]};
    HtmlAnalyzer analizador;
    HtmlDocument documento(fichero_entrada);

    // Llamamos al metodo para que analice todo y en caso de que falle, muestre un aviso de error
    if(!analizador.AnalizadorCompleto(fichero_entrada, documento)) {
        std::cerr << "Error. Ocurrio un error al intentar analizar el documento HTML." << std::endl;
        return 1;
    }

    // Llamamos al metodo que exporte todo el informe al .txt y en caso de que falle, muestre un aviso de error
    if(!documento.Export(fichero_salida)) {
        std::cerr << "Error. Ocurrio un error al intentar exportar el informe a " << fichero_salida << std::endl;
        return 1;
    }
    return 0;
}