// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de DFAs en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 16/10/2026
// Archivo: p06_estado.h
// Contiene la declaracion de la clase Estado

#ifndef ESTADO_H
#define ESTADO_H

#include <map>

class Estado {
 public:

   // Constructores 
   Estado() = default;
   Estado(int id, bool aceptacion);
   // Metodos
   void AñadirTransicion(char simbolo, int id_estado);
   bool GetEstadoSiguiente(char simbolo, int& id_estado_siguiente) const;

   // Getters
   int GetId() const { return id_; }
   bool GetEsAceptacion() const { return es_de_aceptacion_; }
   const std::map<char, int>& GetTransiciones() const { return transiciones_; } 

 private:

   // Atributos 
   int id_;
   bool es_de_aceptacion_{false};
   std::map<char, int> transiciones_;
};

#endif