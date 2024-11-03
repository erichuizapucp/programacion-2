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
public:
    void insertar(int, T);
    T obtener(int);
};

template <typename T>
void Arreglo<T>::insertar(int pos, T valor) {
    elementos[pos] = valor;
}

template <typename T>
T  Arreglo<T>::obtener(int pos) {
    return elementos[pos];
}

#endif /* ARREGLO_H */

