// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_html_document.h
// Contiene la declaracion de la clase HtmlDocument

#ifndef HTMLDOCUMENT_H
#define HTMLDOCUMENT_H

#include <string>
#include <vector>

#include "p04_etiqueta.h"
#include "p04_comentario.h"


// Definicion de una estructura para la modificacion
struct Enlace {
   size_t linea;
   std::string url;
   std::string texto;
};


class HtmlDocument {
 public:
    // Constructores de la clase HtmlDocument
    HtmlDocument() = default;
    HtmlDocument(const std::string& programa);

    // Setters de asignacion
    void SetDocType(bool valor);
    void SetHtml(bool valor);
    void SetHead(bool valor);
    void SetBody(bool valor);
    void SetDescripcion(const std::string& descripcion);

    // Getters de acceso
    std::string GetNombrePrograma() const {return nombre_programa_;}
    std::string GetDescripcion() const {return descripcion_;}

    // Metodos para añadir objetos a los vectores privados
    void AñadirEtiqueta(const Etiqueta& etiqueta);
    void AñadirComentario(const Comentario& comentario);
    // Modificacion
    void AñadirEnlace(const Enlace& enlace) { enlaces_.push_back(enlace);}

    // Metodo para exportar
    bool Export(const std::string& fichero_salida) const;

 private:
    // Atributos privados de la clase
    std::string nombre_programa_;
    std::string descripcion_;

    bool tiene_doctype_{false};
    bool tiene_html_{false};
    bool tiene_head_{false};
    bool tiene_body_{false};

    std::vector<Etiqueta> etiquetas_;
    std::vector<Comentario> comentarios_;
    // Modificacion
    std::vector<Enlace> enlaces_;

};

#endif