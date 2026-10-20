// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_html_document.cc
// Contiene la definicion de la clase HtmlDocument

#include "p04_html_document.h"
#include <fstream>
#include <iostream>

/**
 * @brief Constructor de la clase HtmlDocument: recibe el nombre del archivo HTML de entrada
 * @param programa
 */

HtmlDocument::HtmlDocument(const std::string& programa) {
    nombre_programa_ = programa;
}

/**
 * @brief SetDocType: Setter que nos permite asignar valor a un atributo privado
 * @param valor
 */

void HtmlDocument::SetDocType(bool valor) {
    tiene_doctype_ = valor;
}



/**
 * @brief SetHtml: Setter que nos permite asignar valor a un atributo privado
 * @param valor
 */

void HtmlDocument::SetHtml(bool valor) {
    tiene_html_ = valor;
}



/**
 * @brief SetHead: Setter que nos permite asignar valor a un atributo privado
 * @param valor
 */

void HtmlDocument::SetHead(bool valor) {
    tiene_head_ = valor;
}



/**
 * @brief SetBody: Setter que nos permite asignar valor a un atributo privado
 * @param valor
 */

void HtmlDocument::SetBody(bool valor) {
    tiene_body_ = valor;
}



/**
 * @brief SetDescripcion: Setter que nos permite asignar valor a un atributo privado
 * @param descripcion
 */

void HtmlDocument::SetDescripcion(const std::string& descripcion) {
    descripcion_ = descripcion;
}



/**
 * @brief AñadirEtiqueta: Metodo que permite añadir objetos a los vectores privados
 * @param etiqueta
 */

void HtmlDocument::AñadirEtiqueta(const Etiqueta& etiqueta) {
    etiquetas_.push_back(etiqueta);
}



/**
 * @brief AñadirComentario: Metodo que permite añadir objetos a los vectores privados
 * @param comentario
 */

void HtmlDocument::AñadirComentario(const Comentario& comentario) {
    comentarios_.push_back(comentario);
}



/**
 * @brief Export: Metodo para escribir en el fichero de salida el resultado de ordenar Etiquetas, Comentarios, Atributos, etc
 * @param fichero_salida
 */

bool HtmlDocument::Export(const std::string& fichero_salida) const {
    std::ofstream output(fichero_salida);
    if(!output.is_open()) {
        std::cerr << "ERROR. No se ha podido abrir el fichero" << fichero_salida;
        return false;
    }

    output << "PROGRAM: " << GetNombrePrograma() << std::endl;
    output << std::endl;

    output << "DESCRIPTION:" << std::endl;
    output << GetDescripcion() << std::endl;
    output << std::endl;

    output << "STRUCTURE:" << std::endl;
    output << "HTML: " << (tiene_html_ ? "True" : "False") << std::endl;
    output << "HEAD: "<< (tiene_head_ ? "True" : "False") << std::endl;
    output << "BODY: " << (tiene_body_ ? "True" : "False") << std::endl;
    output << "DOCTYPE: " << (tiene_doctype_ ? "HTML5" : "False") << std::endl;
    output << std::endl;
    
    output << "TAGS:" << std::endl;
    for(const Etiqueta& etiqueta : etiquetas_) {
            output << etiqueta << std::endl;
    }
    output << std::endl;

    output << "ATTRIBUTES:" << std::endl;
    for(const Etiqueta& etiqueta : etiquetas_) {
        if(etiqueta.HayAtributos()) {
            output << etiqueta << std::endl;
            for(const Atributo& atributo : etiqueta.GetAtributos()) {
                output << atributo << std::endl;
            }
            output << std::endl;
        }
    }

    output << "COMMENTS:" << std::endl;
    for(const Comentario& comentario : comentarios_) {
        output << comentario << std::endl;
        output << std::endl;
    }

    output << "LINKS:" << std::endl;
    for(const Enlace& enlace : enlaces_) {
        output << "[Line " << enlace.linea << "]" << std::endl;
        output << "URL: " << enlace.url << std::endl;
        output << "TEXT: " << enlace.texto << std::endl;
        output << std::endl;
    }

    return true;
}