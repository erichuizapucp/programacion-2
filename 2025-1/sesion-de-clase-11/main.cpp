/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 26, 2025, 8:53 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

bool listaVacia(void* lista) {
    return lista == nullptr;
}

void recorrerLista(void* lista) {
    if (listaVacia(lista)) {
        cout << "La lista está vacía" << endl;
        return;
    }
    
    void** nodo = (void**)lista; // obtengo una referencia a la cabeza de la lista.
    
    while (nodo != nullptr) {
        void* dato = nodo[0];
        cout << *(int*)dato << endl;
        nodo = (void**)nodo[1]; // apunta al siguiente nodo
    }
}

void insertar(void* nodo, void* nuevoNodo) {
    void** nuevo = (void**)nuevoNodo;
    void** nodoActual = (void**)nodo;
    nuevo[1] = nodoActual[1];
    
    nodoActual[1] = nuevo;
}

int main(int argc, char** argv) {
    void* lista;
    
    void** nodo1 = new void*[2];
    nodo1[0] = new int(1); // void* que apunta a un int*
    
    void** nodo2 = new void*[2];
    nodo2[0] = new int(2); // void* que apunta a un int*
    
    void** nodo3 = new void*[2];
    nodo3[0] = new int(3); // void* que apunta a un int*
    
    void** nodo4 = new void*[2];
    nodo4[0] = new int(4); // void* que apunta a un int*
    
    void** nodo5 = new void*[2];
    nodo5[0] = new int(5); // void* que apunta a un int*
    
    nodo1[1] = nodo2; // nodo1[1] es void* y apunta a nodo2 que es un void**
    nodo2[1] = nodo3; // nodo2[1] es void* y apunta a nodo3 que es un void**
    nodo3[1] = nodo4; // nodo3[1] es void* y apunta a nodo4 que es un void**
    nodo4[1] = nodo5; // nodo4[1] es void* y apunta a nodo5 que es un void**
    nodo5[1] = nullptr; // nodo5[1] apunta a nullptr para terminar la lista
    
    lista = nodo1; // La lista apunta a la cabeza que es nodo1 y que tiene tipo void**
    
    recorrerLista(lista);
    
    void** nuevoNodo = new void*[2];
    nuevoNodo[0] = new int(0);
    insertar(nodo4, nuevoNodo);
    
    cout << endl << endl;
    
    recorrerLista(lista);
    
    return 0;
}

