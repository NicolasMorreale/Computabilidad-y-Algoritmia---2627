/**
 * Enunciado: Se dispone de un fichero donde cada línea contiene una palabra y uno de sus sinónimos, 
 * separados por un espacio (una palabra puede tener varios sinónimos, en líneas distintas):
 * Desarrolla una clase Diccionario que cargue el fichero y permita, dada una palabra, mostrar todos sus sinónimos.
 *  También debe permitir añadir un nuevo sinónimo para una palabra existente o nueva
 * EL FICHERO PUEDE LUCIR ASI
 *  feliz contento
 *  feliz alegre
 *  triste apenado
 *  feliz dichoso
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#pragma once

#include <iostream>
#include <map>
#include <string>

class Diccionario {
 public:
    Diccionario();
    bool CargarDesdeFichero(const std::string& nombre_fichero);
    void MostrarSinonimos(const std::string& palabra) const;
    void MostrarDiccionario() const;
    void InsertarSinonimo(const std::string& palabra, const std::string& sinonimo);
 private:
    std::multimap<std::string, std::string> diccionario_;
};

#endif 