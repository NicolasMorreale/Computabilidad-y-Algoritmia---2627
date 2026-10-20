/**
 * 3. Contador de palabras (std::map)
Enunciado: Dado un fichero de texto libre (varias palabras por línea, separadas por espacios),
 desarrolla una clase ContadorPalabras que cuente cuántas veces aparece cada palabra en el fichero completo,
 y las muestre ordenadas alfabéticamente junto con su frecuencia.
 */

#ifndef CONTADOR_H
#define CONTADOR_H
#pragma once

#include <iostream>
#include <map>
#include <string>

class Contador {
 public:
   Contador();
   bool CargarDesdeFichero(const std::string& nombre_fichero);
   void MostrarContador() const;
   void AgregarPalabras(const std::string& palabra);
   int ObtenerFrecuencia(const std::string& palabra);
 private:
   std::map<std::string, int> contador_;
};

#endif