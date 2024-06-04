/* 
 * File:   Dictionario.h
 * Author: erichuiza
 *
 * Created on June 3, 2024, 11:49 AM
 */

#ifndef DICTIONARIO_H
#define DICTIONARIO_H

#include "Contenedor.h"
#include "Arreglo.h"
#include "Par.h"

template <typename K, typename V>
class Diccionario : Contenedor<Par<K, V>> {
private:
    Arreglo<Par<K, V>> elementos;
public:
    void agregar(Par<K, V>) override;
    int buscar(Par<K, V>) override;
    Par<K, V> obtener(int) override;
};

template <typename K, typename V>
void Diccionario<K, V>::agregar(Par<K, V> valor) {
    elementos.agregar(valor);
}

template <typename K, typename V>
int Diccionario<K, V>::buscar(Par<K, V> par) {
    for (int i = 0; i < elementos.cantidad(); i++) {
        Par<K, V> p = elementos.obtener(i);
        if (p.key == par.key) {
            return i;
        }
    }
    
    return -1;
}

template <typename K, typename V>
Par<K, V> Diccionario<K, V>::obtener(int index) {
    return elementos.obtener(index);
}

#endif /* DICTIONARIO_H */

