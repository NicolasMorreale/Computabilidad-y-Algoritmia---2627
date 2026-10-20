// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 13/09/2026
// Archivo: multiple_grades.h 
// Contiene la declaracion de la clase MultipleGrades

#ifndef MULTIPLEGRADES_H
#define MULTIPLEGRADES_H
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

class MultipleGrades {
 public:
    // Constructor de la clase
    MultipleGrades();
    // Metodo que permite cargar desde fichero
    bool CargarDesdeFichero(const std::string& nombre_fichero);
    // Metodo que permite insertar notas
    void InsertarNotasVector(const std::string& alu, double nota);
    // Metodo que permite visualizar por pantalla
    void MostrarListaNotas() const;
    // METODO DE LA PRACTICA
    double MaxALU(const std::string& alu);
    bool ExisteAlumno(const std::string& alu);
 private:
    // Atributo privado de la clase MultipleGrades
    std::map<std::string, std::vector<double>> mapa_notas_;
};

#endif