#include "A.h"

void A::imprime(ofstream &arch) {
    char ident[10];
    GetId(ident);
    arch << "Tipo A: " << left << setw(5) << ident
            << right << setw(5) << GetFil()
            << setw(5) << GetCol() << endl;
}

void A::mover(char dir, int cant) {
    switch (dir) {
        case 'P': // ARRIBA
            SetFil(GetFil() - cant);
            break;
        case 'Q': // DERECHA
            SetCol(GetCol() + cant);
            break;
        case 'R': // ABAJO
            SetFil(GetFil() + cant);
            break;
        case 'S': // IZQUIERDA
            SetCol(GetCol() - cant);
            break;
    }
}