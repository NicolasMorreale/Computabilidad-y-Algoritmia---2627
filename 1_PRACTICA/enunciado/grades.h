// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 12/09/2026
// Archivo: grades.h 
// Contiene la declaracion de la clase Grades
#ifndef GRADES_H
#define GRADES_H
#pragma once

#include <iostream>
#include <map>
#include <string>

class Grades {
 public:
    // Constructor de la clase Grades
   Grades();
    // Metodo que carga el alu y la nota desde un fichero
   bool CargarDesdeFichero(const std::string& nombre_fichero);
    // Metodo que inserta las notas
   void InsertarNota(const std::string& alu, double nota);
    // Metodo que muestra la lista de notas (aluXXXX: nota)
   void MostrarListaNotas() const;
 private:
    // Atributo privado de la clase Grades, mapa donde almacenaremos las calificaciones de los alumnos
   std::map<std::string , double> mapa_notas_;
};

#endif