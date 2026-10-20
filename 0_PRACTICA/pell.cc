#include <iostream>
#include <cmath>

/**
@brief Funcion recursiva que calcula los primeros N terminos de la Serie de Pell
@param int n : Cantidad de terminos de la Serie de Pell
 */

int pell_recursiva(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return 2*pell_recursiva(n-1) + pell_recursiva(n-2);
}


/** 
@brief Funcion que calcula una potencia
@param int n : Orden de la potencia
@param int base : Base 
*/

int potencia(int n,int base) {
    if(n == 0) return 1;
    int resultado{0};
    for(int i = 0; i < n; i++) {
        resultado += base * base;
    }
    return resultado;
}
/** 
@brief Funcion iterativa que calcula los primeros N terminos de la Serie de Pell
@param int n : Cantidad de terminos de la Serie de Pell
*/

int pell_iterativa(int n) {
    return (potencia(n, (1 + std::sqrt(2))) - potencia(n, (1 - std::sqrt(2)))) / (2 * std::sqrt(2));
}

