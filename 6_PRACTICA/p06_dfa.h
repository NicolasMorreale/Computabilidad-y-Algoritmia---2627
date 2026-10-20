// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de DFAs en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 16/10/2026
// Archivo: p06_dfa_simulator.h
// Contiene la declaracion de la clase DFA

#ifndef DFA_H
#define DFA_H
#include "p06_alfabeto.h"
#include "p06_estado.h"
#include <vector>

class DFA {
 public:
   // Constructores
   DFA() = default;

   // Metodos
   bool CargarDesdeFichero(const std::string& nombre_fichero_dfa);
   bool FicheroTexto(const std::string& nombre_fichero_txt) const;
   bool GetLineaSigValida(std::ifstream& archivo, std::string& linea) const;
   bool EsDFA() const;
   bool ReconocerCadena(const std::string& cadena) const;
   // Modificacion de la practica 6: 20 octubre 2026.
   void EstadosAbsorcion() const;

   // Getters
   const Alfabeto& GetAlfabeto() const { return alfabeto_; }
   const std::map<int, Estado>& GetEstados() const { return estados_; }

 private:

   // Atributos
   Alfabeto alfabeto_;
   std::map<int, Estado> estados_;
   int id_estado_arranque_{-1}; // Le damos valor -1 por seguridad
};

#endif
