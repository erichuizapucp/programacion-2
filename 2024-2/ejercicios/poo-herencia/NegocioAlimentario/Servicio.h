/* 
 * File:   Servicio.h
 * Author: erichuiza
 *
 * Created on November 3, 2024, 3:27 PM
 */

#ifndef SERVICIO_H
#define SERVICIO_H

#include "Enums.h"
#include "Lista.h"

using namespace std;

template<typename T>
class Servicio {
private:
    Lista<T> datos;
public:
    Servicio();
    Servicio(const Servicio& orig);
    
    void cargarDatos(ifstream&);
    T& buscar(const char*);
    
    const Lista<T>& getDatos() const;
    
    void operator=(const Servicio&);
    
    virtual ~Servicio();
};

template<typename T>
Servicio<T>::Servicio() {
    datos = {};
}

template<typename T>
Servicio<T>::Servicio(const Servicio& orig) {
    *this = orig;
}

template<typename T>
const Lista<T>& Servicio<T>::getDatos() const {
    return datos;
}

template<typename T>
void Servicio<T>::cargarDatos(ifstream& archivo) {
    T aux {};
    while (archivo >> aux) datos += aux;
}

template<typename T>
T& Servicio<T>::buscar(const char* llave) {
    T& resultado = {};
    
    T* elementos = datos.getElementos();
    for (int i = 0; i < datos.getCantidad(); i++) {
        T& elemento = elementos[i];
        char* codigo = elemento->getCodigo();
        
        if (strcmp(llave, codigo) == 0) {
            resultado = elemento;
            break;
        }
    }
    
    return resultado;
}

template<typename T>
void Servicio<T>::operator=(const Servicio& orig) {
    datos = orig.getDatos();
}

template<typename T>
Servicio<T>::~Servicio() {
}

#endif /* SERVICIO_H */

