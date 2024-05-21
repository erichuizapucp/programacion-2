/* 
 * File:   AsignaMemoria.h
 * Author: erichuiza
 *
 * Created on April 29, 2024, 12:47 AM
 */

#ifndef ASIGNAMEMORIA_H
#define ASIGNAMEMORIA_H

class AsignaMemoria {
public:
    template<typename T> 
    void incrementMemorySpaces(
        T*& data, 
        int numData, 
        int& capacity
    ) {
        T* aux;
        capacity += 5;

        if (data == nullptr) {
            data = new T[capacity] {};
        }
        else {
            aux = new T[capacity] {};
            for (int index = 0; index < numData; index++) {
                aux[index] = data[index];
            }
            delete data;
            data = aux;
        }
    }
};

#endif /* ASIGNAMEMORIA_H */

