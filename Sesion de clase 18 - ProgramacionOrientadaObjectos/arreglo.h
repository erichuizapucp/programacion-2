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
//    void insetar(int, T);
//    T obtener(int);
    void insetar(int pos, T valor) {
        elementos[pos] = valor;
    }

    T obtener(int pos) {
        return elementos[pos];
    }
};

//template <typename T, typename Q>
//class OtroArreglo : public Arreglo<T> {
//private:
//    T otrosElementos[100];
//    Q otrosOtrosElementos[100]; 
//};


#endif /* ARREGLO_H */

