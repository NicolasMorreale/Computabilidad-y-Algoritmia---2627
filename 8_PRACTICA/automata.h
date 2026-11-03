// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramatica
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/10/2026
// Archivo: automata.h
// Contiene la declaracion de la clase Automata

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <set>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "alfabeto.h"
#include "estado.h"
#include "grammar.h"

class Automata {
    public:
        // Constructores
        Automata() = default;
        Automata(const std::string& filename);

        // Metodos de carga y validacion
        bool LoadFromFile(const std::string& filename);
        bool IsValidDFA() const;

        // Metodo principal de la practica
        Grammar ConvertToGrammar() const;

        // Getters
        const std::map<int,Estado>& GetEstados() const { return estados_; }
        const Alfabeto& GetAlfabeto() const { return alfabeto_; }
        int GetEstadoInicial() const { return id_estado_inicial_; }
    private:
        // Atributos
        int id_estado_inicial_;
        Alfabeto alfabeto_;
        std::map<int,Estado> estados_;
};

#endif