// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 18/09/2026
// Archivo: cadena.cc
// Contiene la declaracion de la clase Cadena

#include "cadena.h"
#include "alfabeto.h"
#include "lenguaje.h"
typedef char Simbolo;
/**
 * @brief Inversa: Metodo que permite calcular la cadena inversa de una cadena dada
 */

Cadena Cadena::Inversa() const {
    std::string str_invertida{""};
    size_t tamaño = cadena_.size();

    for(int i = tamaño - 1; i >= 0; i--) {
        str_invertida += cadena_[i];
    }
    
    Cadena cad_invertida(str_invertida);
    return cad_invertida;
}



/**
 * @brief Longitud: Metodo que permite obtener la longitud de la cadena
 */

int Cadena::Longitud() const {
    return cadena_.length();
}



/**
 * @brief Validacion: Metodo que permite determinar si una cadena es valida
 * @param alfabeto
 */

bool Cadena::Validacion(const Alfabeto& alfabeto) const {
    for(char simbolos : cadena_) {
        if(!alfabeto.Pertenece(simbolos)) {
            return false;
        }
    }
    return true;
}



/**
 * @brief operator<<: Sobrecarga de operador de insercion en el flujo de salida estandar
 * @param os
 * @param cadena
 */

std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
    if(cadena.Longitud() == 0) {
        os << "&";
    } else {
    os << cadena.cadena_;
    }
    return os;
}



/**
 * @brief operator>>: Sobrecarga del operador de insercion desde el flujo de entrada estandar
 * @param os
 * @param cadena
 */

std::istream& operator>>(std::istream& is, Cadena& cadena) {
    is >> cadena.cadena_;
    return is;
}



/**
 * @brief Prefijos: Metodo de la clase que muestra todos los prefijos posibles de una cadena dada
 * @param cadena
 */

Lenguaje Cadena::Prefijos() {
    Lenguaje lenguaje_prefijos;
    Cadena cadena_vacia("&");
    lenguaje_prefijos.Insertar(cadena_vacia);
    std::string string_aux{""};

    for(Simbolo simbolo : GetCadena()) {
        string_aux += simbolo;
        Cadena prefijo(string_aux);
        lenguaje_prefijos.Insertar(prefijo);
    }

    return lenguaje_prefijos;
}



/**
 * @brief Sufijos: Metodo de la clase que muestra todos los posibles sufijos de una cadena dada
 * @param cadena
 */

Lenguaje Cadena::Sufijos() {
    Lenguaje lenguaje_sufijos;
    Cadena cadena_vacia("&");
    lenguaje_sufijos.Insertar(cadena_vacia);

    for(size_t i{0}; i < cadena_.length(); i++) {
        lenguaje_sufijos.Insertar(cadena_.substr(i));
    }

    return lenguaje_sufijos;
}



/**
 * @brief operator<: Sobrecarga del operador de comparacion para el tipo de dato Cadena
 * @param other
 */

bool Cadena::operator<(const Cadena& other) const {
    if(Longitud() != other.Longitud()) {
        return Longitud() < other.Longitud();
    }
    return GetCadena() < other.GetCadena();
}



/**
 * @brief Subcadenas: Metodo que calcula las subcadenas de una cadena dada y devuelve un objeto de tipo Lenguaje con todas las subcadenas
 */

Lenguaje Cadena::Subcadenas() const {
    size_t tamaño = cadena_.length();
    Lenguaje lenguaje_subcadenas;
    lenguaje_subcadenas.Insertar(Cadena("&"));

    for(size_t i{0}; i < tamaño; i++) {
        for(size_t l{1}; l <= l - i; l++) {
            std::string sub_str = cadena_.substr(i,l);
            lenguaje_subcadenas.Insertar(Cadena(sub_str));
        }
    }

    return lenguaje_subcadenas;
}



/**
 * @brief operator+: Sobrecarga del operador + para la clase Cadena
 * @param other
 */

Cadena Cadena::operator+(const Cadena& other) {
    return cadena_ + other.cadena_;
}



/**
 * @brief Potencia: Metodo que permite calcular la potencia de una cadena dado el grado
 * @param n
 */

Cadena Cadena::Potencia(size_t exponente) const {
    if(exponente == 0) return Cadena("&");
    return Cadena(GetCadena() + Potencia(exponente - 1).GetCadena());
}



/**
 * @brief Concatenar: Metodo que permite concatenar dos cadenas
 * @param cadena
 */

Cadena Cadena::Concatenar(const Cadena& cadena) {
    if(cadena.GetCadena() == "&") return GetCadena();
    return (GetCadena() + cadena.GetCadena());
}