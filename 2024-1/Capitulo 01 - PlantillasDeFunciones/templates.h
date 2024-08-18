/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   templates.h
 * Author: erichuiza
 *
 * Created on March 21, 2024, 8:19 PM
 */

#ifndef TEMPLATES_H
#define TEMPLATES_H

/*
 * Aquí vamos a mostrar dos métodos clásicos de arreglos para ordenar arreglos y 
 * obtener el máximo elemento.
 */
template<typename T> void sortArray(T[], int);
template<typename T> T maxElement(const T[], int);

/*
 * Aquí vamos a combinar plantillas de funciones y sobre carga de operadores.

 * 
 */

//template<typename T, typename C> C foo(const T, const T);

template<typename T> bool equal(const T&, const T&);
template<typename T> bool greaterThan(const T&, const T&);
template<typename T> bool greaterOrEqualThan(const T&, const T&);
template<typename T> bool lessThan(const T&, const T&);
template<typename T> bool lessOrEqualThan(const T&, const T&);

template<typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<typename T>
T maxElement(const T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template<typename T>
bool equal(const T &a, const T &b) {
    return a == b;
}

template<typename T>
bool greaterThan(const T &a, const T &b) {
    return a > b;
}

template<typename T>
bool greaterOrEqualThan(const T &a, const T &b) {
    return a >= b;
}

template<typename T>
bool lessThan(const T &a, const T &b) {
    return a < b;
}

template<typename T>
bool lessOrEqualThan(const T &a, const T &b) {
    return a <= b;
}

#endif /* TEMPLATES_H */

