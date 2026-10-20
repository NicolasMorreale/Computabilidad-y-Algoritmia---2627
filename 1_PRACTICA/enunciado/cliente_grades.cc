// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 12/09/2026
// Archivo: cliente_grades.cc 
// Contiene el programa principal

#include "grades.h"

int main(int argc, char* argv[]) {
    // Caso 1: No saber usar el programa 
    if(argc == 1) {
        std::cerr << "Uso del programa: " << argv[0] << " grades.txt" << std::endl;
        std::cerr << "Pruebe " << argv[0] << " --help para mas informacion." << std::endl;
        return 1;
    }
    // Caso 2: Querer usar el --help
    std::string primer_argumento = argv[1];
    if(primer_argumento == "--help") {
        std::cout << "Uso del programa: " << argv[0] << " grades.txt" << std::endl;
        std::cout << "Carga un fichero de texto con calificaciones (alumno nota)" << std::endl;
        std::cout << "y muestra por pantalla, ordenando los alu numericamente la nota maxima de cada alumno" << std::endl;
        return 0;
    }
    // Programa principal

    Grades notas;
    if(!notas.CargarDesdeFichero(primer_argumento)) {
        std::cerr << "Error. No se ha podido abrir el fichero " << primer_argumento << std::endl;
        return 1;
    }
    // Caso exitoso
    notas.MostrarListaNotas();
    // Opcion para añadir mas informacion
    std::string nuevo_alu;
    double nueva_nota;
    std::cout << "Introduzca el alu del estudiante: ";
    std::cin >> nuevo_alu;
    std::cout << "Introduzca la nota: ";
    std::cin >> nueva_nota;
    notas.InsertarNota(nuevo_alu, nueva_nota);

    std::cout << "Estado final:" << std::endl;
    notas.MostrarListaNotas();
    return 0;
}