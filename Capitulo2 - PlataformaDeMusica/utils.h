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

bool openFile(const char*, ifstream&);
void readString(ifstream&, char*&, char);
void readIntArray(const char*, int *&, int &);
template<typename T> void incrementMemorySpaces(T*&, int, int&);

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

#endif /* IOUTILS_H */

