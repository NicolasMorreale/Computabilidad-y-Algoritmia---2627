// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_etiqueta.h
// Contiene la declaracion de la clase Etiqueta

#ifndef ETIQUETA_H
#define ETIQUETA_H
#include <string>
#include <vector>
#include "p04_atributo.h"

class Etiqueta {
 public:
    // Constructores de la clase Etiqueta
    Etiqueta() = default;
    Etiqueta(const std::string& nombre, size_t linea, bool cierre = false);

    // Getters de acceso
    std::string GetNombre() const {return nombre_;}
    size_t GetLinea() const {return numero_linea_;}
    bool EsCierre() const;
    const std::vector<Atributo> GetAtributos() const;

    // Metodos 
    void AñadirAtributo(const Atributo& atributo);
    bool HayAtributos() const;
    size_t CantidadAtributos() const;

    // Sobrecarga de operadores 
    friend std::ostream& operator<<(std::ostream& os, const Etiqueta& etiqueta);
 private:
    std::string nombre_;   
    size_t numero_linea_;
    bool cierre_;
    std::vector<Atributo> atributos_;
         
};

#endif