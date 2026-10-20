// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares en C++
// Autor: Nicolas Morreale Toledo
// Correo: alu0101829173@ull.edu.es
// Fecha: 30/09/2026
// Archivo: p04_html_analyzer.cc
// Contiene la definicion de la clase HtmlAnalyzer

#include "p04_html_analyzer.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>

/**
 * @brief LeerArchivoToString: Metodo para leer el archivo HTML y pasarlo a un std::string
 * @param nombre_archivo
 */

std::string HtmlAnalyzer::LeerArchivoToString(const std::string& nombre_archivo) const {
    std::ifstream input(nombre_archivo);
    if(!input.is_open()) {
        std::cerr << "ERROR. No se ha podido abrir el fichero " << nombre_archivo;
        return "";
    }
    std::string texto_completo{""};
    std::string linea{""};
    while(std::getline(input, linea)) {
        texto_completo += linea + '\n';
    }
    return texto_completo;
}



/**
 * @brief CalcularNumeroLinea: Metodo para calcular el numero de linea, contando la cantidad de veces que aparece el caracter '\n'
 * @param texto_completo, indice_caracter
 */

size_t HtmlAnalyzer::CalcularNumeroLinea(const std::string& texto_completo, size_t indice_caracter) const {
    if(indice_caracter > texto_completo.size()) {
        indice_caracter = texto_completo.size();
    }
    size_t contador{1};
    for(size_t i{0}; i < indice_caracter; i++) {
        if(texto_completo.at(i) == '\n') {
            contador++;
        }
    }
    return contador;
}



/**
 * @brief AnalizarEstructura: Metodo privado de la clase que nos permitira analizar la estructura del documento HTML usando regex
 * @param texto, documento
 */

void HtmlAnalyzer::AnalizarEstructura(const std::string& texto, HtmlDocument& documento) const {
    // Usamos std::regex::icase que significa IGNORE CASE, es decir, reconocera el patron ya sea en mayus o minus
    std::regex regex_doctype("<!DOCTYPE\\s+html>", std::regex::icase);
    std::regex regex_html("<html\\b>", std::regex::icase);
    std::regex regex_head("<head\\b>", std::regex::icase);
    std::regex regex_body("<body\\b>", std::regex::icase);

    // Usamos el setter del objeto HtmlDocument para darle valor a los atributos internos
   // std::regex_search devuelve true si encuentra al menos una coincidencia en el texto
  bool tiene_doctype = std::regex_search(texto, regex_doctype);
  bool tiene_html = std::regex_search(texto, regex_html);
  bool tiene_head = std::regex_search(texto, regex_head);
  bool tiene_body = std::regex_search(texto, regex_body);

  documento.SetDocType(tiene_doctype);
  documento.SetHtml(tiene_html);
  documento.SetHead(tiene_head);
  documento.SetBody(tiene_body);
}



/**
 * @brief AnalizarComentarios: Metodo privado de la clase que nos permitira analizar los comentarios del documento HTML usando regex
 * @param texto, documento
 */

void HtmlAnalyzer::AnalizarComentarios(const std::string& texto, HtmlDocument& documento) const {
    // Expresion regular de los comentarios del documento HTML
    std::regex regex_comentario("<!--([\\s\\S]*?)-->");
    // La variable iterador apunta a la primera coincidencia en el texto con regex_comentario
    std::sregex_iterator iterador(texto.begin(), texto.end(), regex_comentario);
    // Iterador nulo que marca el final del bloque de atributos
    std::sregex_iterator fin;
    // Bandera para saber si el comentario actual es el primero del documento
    bool es_primer_comentario = true;

    while(iterador != fin) {

        // match contiene la informacion obtenida de lo que es apuntado por iterador (coincidencia actual)
        std::smatch match = *iterador;
        // Posicion del primer caracter del comentario dentro del std::string texto
        size_t posicion_inicio = match.position();
        // Posicion del ultimo caracter del comentario dentro del std::string texto
        size_t posicion_final = posicion_inicio + match.length() - 1;

        // Calculamos la linea inicial y la final
        size_t linea_inicial = CalcularNumeroLinea(texto, posicion_inicio);
        size_t linea_final = CalcularNumeroLinea(texto, posicion_final);

        // Texto del comentario completo incluyendo <!-- -->
        std::string comentario_completo = match.str();

        // Texto interno del comentario (informacion que debe estar en el apartado de DESCRIPTION)
        std::string comentario_interno = match[1].str();
        
        // Si es el primer comentario, sera la descripcion
        bool es_descripcion = es_primer_comentario;
        if(es_primer_comentario) {
            documento.SetDescripcion(comentario_interno);
            es_primer_comentario = false;
        }

        // Por otro lado, si no es la descripcion, almacenamos como Comentario y guardamos en el objeto HtmlDocument
        Comentario comentario(comentario_completo, linea_inicial, linea_final, es_descripcion);
        documento.AñadirComentario(comentario);

        // Avanzamos el iterador 
        ++iterador;
    }
}



/**
 * @brief AnalizarEtiquetas: Metodo privado de la clase que nos permitira analizar las etiquetas del documento HTML usando regex
 * @param texto, documento
 */

void HtmlAnalyzer::AnalizarEtiquetas(const std::string& texto, HtmlDocument& documento) const {
    std::regex regex_etiqueta("<(/)?(html|body|head|title|h1|a|p|img)\\b([^>]*)>");
    std::sregex_iterator iterador(texto.begin(), texto.end(), regex_etiqueta);
    std::sregex_iterator fin;

    while(iterador != fin) {
        // Obtenemos la coincidencia
        std::smatch match = *iterador;

        // Extraemos cada cosa de cada grupo
        bool es_cierre{match[1].matched};
        std::string nombre{match[2].str()};
        std::string cadena_atributos{match[3].str()};

        // Normalizamos el nombre a minuscula
        for(char& caracter : nombre) {
            caracter = std::tolower(caracter);
        }

        size_t posicion_etiqueta = match.position();
        size_t numero_linea = CalcularNumeroLinea(texto, posicion_etiqueta);

        // Instanciamos el objeto Etiqueta
        Etiqueta etiqueta(nombre, numero_linea, es_cierre);

        // Solo se procesan los atributos si tiene atributos y no es de cierre
        if(!es_cierre && !cadena_atributos.empty()) {
            AnalizarAtributos(cadena_atributos, etiqueta);
        }
        // Añadimos la etiqueta al documento
        documento.AñadirEtiqueta(etiqueta);
        ++iterador;
    }
}



/**
 * @brief AnalizarAtributos: Metodo privado de la clase que nos permitira analizar los atributos del documento HTML usando regex
 * @param cadena_atributos, etiqueta
 */

void HtmlAnalyzer::AnalizarAtributos(const std::string& cadena_atributos, Etiqueta& etiqueta) const {
    std::regex regex_atributos("([a-zA-Z0-9_-]+)\\s*=\\s*\"([^\"]*)\"");
    std::sregex_iterator iterador(cadena_atributos.begin(), cadena_atributos.end(), regex_atributos);
    std::sregex_iterator fin;

    while(iterador != fin) {
        // Tomamos la coincidencia y lo que haya en sus grupos
        std::smatch match = *iterador;
        std::string nombre_atributo = match[1].str();
        std::string valor_atributo = match[2].str();

        // Instanciamos el objeto Atributo y lo añadimos a la etiqueta que esta asociado
        Atributo atributo(nombre_atributo, valor_atributo);
        etiqueta.AñadirAtributo(atributo);
        ++iterador;
    }
}



/**
 * @brief AnalizarEnlaces: MODIFICACION. Metodo privado que nos permite analizar los enlaces 
 * @param texto, documento
 */

void HtmlAnalyzer::AnalizarEnlaces(const std::string& texto, HtmlDocument& documento) const {
    // Tomamos la expresion regular que tiene el enlace, donde el grupo 1 es la URL y el grupo 2 es el texto
    std::regex regex_enlace("<a\\b[^>]*?\\bhref=[\"']([^\"']+)[\"'][^>]*?>([\\s\\S]*?)<\\/a>", std::regex_constants::icase);
    std::sregex_iterator iterador(texto.begin(), texto.end(), regex_enlace);
    std::sregex_iterator fin;

    while(iterador != fin) {
        std::smatch match = *iterador;
        size_t posicion_inicio = match.position();
        size_t linea = CalcularNumeroLinea(texto, posicion_inicio);

        // Instanciamos el objeto enlance
        Enlace enlace;
        enlace.linea = linea;
        enlace.url = match[1].str();
        enlace.texto = match[2].str();
        
        // Finalmente añadimos a nuestro vector en HtmlDocument
        documento.AñadirEnlace(enlace);

       ++iterador;
    }
}

/**
 * @brief AnalizadorCompleto: Metodo que utilizaremos para llamar a todos los atributos internos y analizar el documento HTML todo junto
 * @param fichero_entrada, documento
 */

bool HtmlAnalyzer::AnalizadorCompleto(const std::string& fichero_entrada, HtmlDocument& documento) const {
    // Llamamos al metodo que pase el fichero de entrada a texto
    std::string texto = LeerArchivoToString(fichero_entrada);
    if(texto.empty()) return false;
    
    // Llamamos a los metodos internos que analizan el documento HTML
    AnalizarEstructura(texto, documento);
    AnalizarEtiquetas(texto, documento);
    AnalizarComentarios(texto, documento);
    // Modificacion
    AnalizarEnlaces(texto,documento);

    return true;
}