/* 
 * File:   arreglo.h
 * Author: erichuiza
 *
 * Created on May 31, 2024, 4:13 PM
 */

#ifndef ARREGLO_H
#define ARREGLO_H

template <typename T>
class Arreglo {
private:
    T elementos[100];
    int numeroElementos;
public:
    Arreglo();
    void agregar(T);
    T obtener(int);
    int cantidad();
};

template <typename T>
Arreglo<T>::Arreglo() {
    numeroElementos = 0;
}

template <typename T>
void Arreglo<T>::agregar(T valor) {
    elementos[numeroElementos++] = valor;
}

template <typename T>
T Arreglo<T>::obtener(int pos) {
    return elementos[pos];
}

template <typename T>
int Arreglo<T>::cantidad() {
    return numeroElementos;
}

#endif /* ARREGLO_H */
