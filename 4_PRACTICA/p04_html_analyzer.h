// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_html_analyzer.h
// Contiene la declaracion de la clase HtmlAnalyzer

#ifndef HTML_ANALYZER_H
#define HTML_ANALYZER_H

#include "p04_html_document.h"
#include <string>

class HtmlAnalyzer {
 public:
    // Constructores de la clase HtmlAnalyzer
   HtmlAnalyzer() = default;

    // Metodo de la clase donde llamaremos a todos los metodos privados
   bool AnalizadorCompleto(const std::string& fichero_entrada, HtmlDocument& documento) const;
 private:
    // Metodos privados de la clase 
   std::string LeerArchivoToString(const std::string& nombre_archivo) const;
   size_t CalcularNumeroLinea(const std::string& texto, size_t indice_caracter) const;

   // Metodos privados de la clase para analizar usando regex
    void AnalizarEstructura(const std::string& texto, HtmlDocument& documento) const;
    void AnalizarComentarios(const std::string& texto, HtmlDocument& documento) const;
    void AnalizarEtiquetas(const std::string& texto, HtmlDocument& documento) const;
    void AnalizarAtributos(const std::string& cadena_atributos, Etiqueta& etiqueta) const;
    // Modificacion
    void AnalizarEnlaces(const std::string& texto, HtmlDocument& documento) const;
};

#endif