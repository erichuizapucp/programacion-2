#include <cstring>
#include "Ficha.h"

Ficha::Ficha() {
    id = nullptr;
}

Ficha::~Ficha() {
    if (id != nullptr) {
        delete id;
    }
}

void Ficha::SetCol(int col) {
    this->col = col;
}

int Ficha::GetCol() const {
    return col;
}

void Ficha::SetFil(int fil) {
    this->fil = fil;
}

int Ficha::GetFil() const {
    return fil;
}

void Ficha::SetId(const char* ident) {
    if (id != nullptr) {
        delete id;
    }
    id = new char[strlen(ident) + 1];
    strcpy(id, ident);
}

void Ficha::GetId(char* ident) const {
    if (id == nullptr) {
        ident[0] = 0;
    }
    else {
        strcpy(ident, this->id);
    }
}

void Ficha::asigna(char* ident, int f, int c) {
    SetId(ident);
    SetFil(f);
    SetFil(c);
}