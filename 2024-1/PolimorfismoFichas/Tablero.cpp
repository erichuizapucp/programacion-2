#include "Tablero.h"

Tablero::Tablero() {
    cabeza = nullptr;
//    numFichas = 0;
}

Tablero::~Tablero() {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        Nodo* siguiente = temp->siguiente;
        delete temp->dato;
        delete temp;
        temp = siguiente;
    }
    
//    for (int i = 0; i < numFichas; i++) {    
//        delete ficha[i];
//    }
}

void Tablero::leerFichas(ifstream &archFichas) {
    char id[10], tipo;
    int fil, col;
    
    while (1) {
        archFichas >> id;
        if (archFichas.eof()) {
            break;
        }
        archFichas >> tipo >> fil >> col;
        colocarFicha(id, tipo, fil, col);
    }
}

void Tablero::colocarFicha(char* id, char tipo, int fil, int col) {
//    switch (tipo) {
//        case 'A':
//            ficha[numFichas] = new A;
//            break;
//        case 'B':
//            ficha[numFichas] = new B;
//            break;
//        case 'C':
//            ficha[numFichas] = new C;
//            break;
//    }
//    // Se aplica el polimorfismo?
//    ficha[numFichas]->asigna(id, fil, col);
//    numFichas++;
    
    Ficha* nuevaFicha = nullptr;
    switch (tipo) {
        case 'A':
            nuevaFicha = new A;
            break;
        case 'B':
            nuevaFicha = new B;
            break;
        case 'C':
            nuevaFicha = new C;
            break;
    }
    
    if (nuevaFicha != nullptr) {
        nuevaFicha->asigna(id, fil, col);
        Nodo* nuevoNodo = new Nodo(nuevaFicha);
        
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        }
        else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }
}

void Tablero::leerMovimientos(ifstream &archMov) {
    char id[10], dir;
    int cant;
    
    while (1) {
        archMov >> id;
        if (archMov.eof()) {
            break;
        }
        archMov >> dir >> cant;
        moverFicha(id, dir, cant);
    }
}

void Tablero::moverFicha(char* id, char dir, int cant) {
    char idTab[10];
//    for (int i = 0; i < numFichas; i++) {
//        ficha[i]->GetId(idTab);
//        
//        if(strcmp(idTab, id) == 0) {
//            // Se aplica el polimorfismo?
//            ficha[i]->mover(dir, cant);
//            return;
//        }
//    }
    
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        Ficha* ficha = temp->dato;
        ficha->GetId(idTab);
        
        if(strcmp(idTab, id) == 0) {
            // Se aplica el polimorfismo?
            ficha->mover(dir, cant);
            return;
        }
        
        temp = temp->siguiente;
    }
}

void Tablero::imprimeDatos(ofstream &archRep) {
//    for (int i = 0; i < numFichas; i++) {
//        // Se aplica el polimorfismo?
//        ficha[i]->imprime(archRep);
//    }
    
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        Ficha* ficha = temp->dato;
        ficha->imprime(archRep);
        temp = temp->siguiente;
    }
}