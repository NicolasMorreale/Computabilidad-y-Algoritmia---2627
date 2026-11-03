// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramatica
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/10/2026
// Archivo: grammar.h
// Contiene la declaracion de la clase Grammar

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <iostream>

/**
 * @struct Produccion
 * @brief Produccion: Representa una regla de produccion de una gramatica de la forma A -> alpha.
 */

struct Produccion {
    std::string left; // Simbolo No-Terminal en la parte izquierda de una produccion.
    std::string right; // Simbolo/s Terminales y/o No-Termianles en la parte derecha de una produccion.
};

/**
 * @class Grammar
 * @brief Clase que modela una Gramatica Regular G = (V,Sigma,S,P)
 */

class Grammar {
    public:
        // Constructor
        Grammar() = default;

        // Metodos para construir la gramatica
        void AñadirTerminal(char terminal) { terminales_.insert(terminal); }
        void AñadirNoTerminal(const std::string& no_terminal) { no_terminales_.insert(no_terminal); }
        void SetSimboloArranque(const std::string& simbolo) { simbolo_arranque_ = simbolo; }
        void AñadirProduccion(const std::string& left, const std::string& right) { producciones_.push_back({left,right}); }

        // Metodo para generar el fichero .gra 
        bool ExportToFile(const std::string& filename) const;

        // MODIFICACION: Metodo para exportar al fichero .gra agrupado con (|)
        bool ExportToFileAlt(const std::string& filename) const;

        // Getters
        const std::set<char>& GetTerminales() const { return terminales_; }
        const std::set<std::string>& GetNoTerminales() const { return no_terminales_; }
        const std::string& GetSimboloArranque() const { return simbolo_arranque_; }
        const std::vector<Produccion>& GetProducciones() const { return producciones_; }
    private:
        // Atributos
        std::set<char> terminales_;
        std::set<std::string> no_terminales_;
        std::string simbolo_arranque_;
        std::vector<Produccion> producciones_;
};

#endif