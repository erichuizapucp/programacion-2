#include "Arbol.h"
#include "Nodo.h"

Arbol::Arbol() {
    arbol = nullptr;
}

Arbol::~Arbol() {
    elimina(arbol);
}

void Arbol::elimina(Nodo* arbol) {
    if (arbol) {
        elimina(arbol->izq);
        elimina(arbol->der);
        delete arbol;
    }
}

void Arbol::crear(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
    }
    
    Persona dato;
    while (true) {
        arch >> dato;
        if (arch.eof()) {
            break;
        }
        insertarR(arbol, dato);
    }
}

void Arbol::insertar(const Persona &dato) {
    insertarR(arbol, dato);
}

void Arbol::insertarR(Nodo* &arbol, const Persona &dato) {
    if (arbol == nullptr) {
        arbol = new Nodo;
        arbol->dato = dato;
        return;
    }
    
    if (arbol->dato > dato) {
        insertarR(arbol->izq, dato);
    }
    else {
        insertarR(arbol->der, dato);
    }
}

void Arbol::mostrarEnOrden() {
    mostrarEnOrdenR(arbol);
    cout << endl;
}

void Arbol::mostrarEnOrdenR(Nodo* arbol) {
    if (arbol) {
        mostrarEnOrdenR(arbol->izq);
        cout << arbol->dato;
        mostrarEnOrdenR(arbol->der);
    }
}

Persona Arbol::buscar(int dni) {
    return buscarR(arbol, dni);
}

Persona Arbol::buscarR(Nodo* arbol, int dni) {
    Persona p;
    int d;
    p.SetDni(-1);
    if (arbol == nullptr) {
        return p;
    }
    if (arbol->dato == dni) {
        return arbol->dato;
    }
    
    d = arbol->dato.GetDni();
    
    if (d > dni) {
        return buscarR(arbol->izq, dni);
    }
    else {
        return buscarR(arbol->der, dni);
    }
}