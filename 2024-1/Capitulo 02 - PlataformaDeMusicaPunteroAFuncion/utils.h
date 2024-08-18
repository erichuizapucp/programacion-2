/* 
 * File:   ioutils.h
 * Author: erichuiza
 *
 * Created on April 4, 2024, 10:32 PM
 */

#ifndef IOUTILS_H
#define IOUTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "structs.h"

#define INCREMENT 3

using namespace std;

void openFile(const char*, ifstream&);
void openFile(const char*, ofstream&);
void readString(ifstream&, char*&, char);
void readIntArray(const char*, int *&, int &);
template<typename T> void incrementMemorySpaces(T*&, int, int&);

/**
 * Incrementa el espacio de memoria a la que apunta T
 * @param data es el puntero a los datos
 * @param numData es el número actual de datos en el espacio de memoria
 * @param capacity es la capacidad total actual
 */
template<typename T> 
void incrementMemorySpaces(T*& data, int numData, int& capacity) {
    T* aux;
    capacity += INCREMENT;
    
    if (data == nullptr) {
        data = new T[capacity];
    }
    else {
        aux = new T[capacity];
        for (int index = 0; index < numData; index++) {
            aux[index] = data[index];
        }
        delete data;
        data = aux;
    }
}

template<typename T>
int cmpByName(const void* a, const void* b) {
    const T* item1 = *(T**)a;
    const T* item2 = *(T**)b;
    
    return strcmp(item1->name, item2->name);
}

#endif /* IOUTILS_H */

