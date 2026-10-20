// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_comentario.h
// Contiene la declaracion de la clase Comentario

#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>

class Comentario {
 public:
    // Constructores de la clase
    Comentario() = default;
    Comentario(const std::string& texto, int inicio, int final, bool descripcion);

    // Getters de acceso
    std::string GetTexto() const {return texto_;}
    int GetLineaInicio() const {return linea_inicial_;}
    int GetLineaFinal() const {return linea_final_;}
    bool EsMultilinea() const {return linea_final_ > linea_inicial_;}
    bool EsDescripcion() const {return descripcion_;}

    // Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& os, const Comentario& comentario);
 private:
    // Atributos de la clase 
    std::string texto_;
    int linea_inicial_;
    int linea_final_;
    bool descripcion_;
};

#endif