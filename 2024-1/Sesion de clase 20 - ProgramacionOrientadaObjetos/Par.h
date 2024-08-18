/* 
 * File:   Par.h
 * Author: erichuiza
 *
 * Created on June 3, 2024, 11:46 AM
 */

#ifndef PAR_H
#define PAR_H

#include <iostream>

using namespace std;

template <typename K, typename V>
class Diccionario;

template <typename K, typename V>
class Par {
private:
    K key;
    V value;
public:
    Par() = default;
    Par(K, V);
    friend class Diccionario<K, V>;
    friend ostream& operator<< (ostream &os, Par<K, V> p) {
        os << "[" << p.key << ", " << p.value << "]" << endl;
        return os;
    }
};

template <typename K, typename V>
Par<K, V>::Par(K key, V value) : key(key), value(value) {
}

#endif /* PAR_H */

