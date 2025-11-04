//
// Created by Eric Huiza on 11/3/25.
//

#ifndef SESION_DE_CLASE_21_1_ARREGLO_H
#define SESION_DE_CLASE_21_1_ARREGLO_H

using namespace std;

template <typename T>
class Arreglo {
    T elementos[100];
    int numElementos;
public:
    Arreglo();
    void agregar(T);
    T obtener(int);
};

template <typename T>
Arreglo<T>::Arreglo() {
    numElementos = 0;
}

template <typename T>
void Arreglo<T>::agregar(T elemento) {
    elementos[numElementos++] = elemento;
}

template <typename T>
T Arreglo<T>::obtener(int indice) {
    return elementos[indice];
}

#endif //SESION_DE_CLASE_21_1_ARREGLO_H