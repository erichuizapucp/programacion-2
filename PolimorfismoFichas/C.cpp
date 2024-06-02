#include "C.h"

void C::imprime(ofstream &arch) {
    char ident[10];
    GetId(ident);
    arch << "Tipo C: " << left << setw(5) << ident
            << right << setw(5) << GetFil()
            << setw(5) << GetCol() << endl;
}

void C::mover(char dir, int cant) {
    switch(dir) {
        case 'P':
            SetFil(GetFil() - 2);
            SetCol(GetCol() + 1);
            break;
        case 'Q':
            SetFil(GetFil() + 1);
            SetCol(GetCol() + 2);
            break;
        case 'R':
            SetFil(GetFil() + 2);
            SetCol(GetCol() - 1);
            break;
        case 'S':
            SetFil(GetFil() - 1);
            SetCol(GetCol() - 2);
            break;
    }
}