/**
 * Enunciado: Un fichero contiene una lista de códigos de producto (pueden repetirse), uno por línea:
P001
P045
P001
P102
P045
Desarrolla una clase Inventario que cargue el fichero y muestre, ordenado, 
el listado de códigos únicos que aparecen (sin duplicados, sin contar cuántas veces aparece cada uno).
 Debe permitir además comprobar si un código concreto existe.
 */

#include <iostream>
#include <set>

#ifndef INVENTARIO_H
#define INVENTARIO_H
#pragma once

class Inventario {
 public:
    Inventario();
    bool CargarDesdeFichero(const std::string& nombre_fichero);
    void MostrarInventario() const;
    bool InsertarCodigo(const std::string& codigo);
    bool ExisteCodigo(const std::string& codigo);
 private:
    std::set<std::string> inventario_;
};

#endif 