// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 13/09/2026
// Archivo: cliente_multiple_grades.cc
// Contiene el programa principal de la clase MultipleGrades

#include "multiple_grades.h"

int main(int argc, char* argv[]) {
    MultipleGrades multiples_notas;

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

    // METODO PRACTICA : --max 
    std::string segundo_argumento{argv[2]};
    if(segundo_argumento == "--max") {
        std::string alu_max{argv[3]};
        if(multiples_notas.ExisteAlumno(alu_max)) {
            double nota_max = multiples_notas.MaxALU(alu_max);
            std::cout << "La calificacion maxima del alumno " << alu_max << " es " << nota_max << std::endl;
            
        } else {
            std::cout << "No se ha encontrado al alumno " << alu_max << std::endl;
        }
        return 0;
    }

    // Programa Principal
    if(!multiples_notas.CargarDesdeFichero(primer_argumento)) {
        std::cerr << "Error. No se ha podido abrir el fichero " << primer_argumento << std::endl;
        return 1;
    }
    
    // Caso exitoso
    multiples_notas.MostrarListaNotas();
    // Opcion para añadir mas informacion
    std::string nuevo_alu;
    double nueva_nota;
    std::cout << "Introduzca el alu del estudiante: ";
    std::cin >> nuevo_alu;
    std::cout << "Introduzca la nota: ";
    std::cin >> nueva_nota;
    multiples_notas.InsertarNotasVector(nuevo_alu, nueva_nota);

    std::cout << "Estado final:" << std::endl;
    multiples_notas.MostrarListaNotas();
    return 0;
}
