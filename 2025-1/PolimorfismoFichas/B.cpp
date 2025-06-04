#include "B.h"

void B::imprime(ofstream &arch) {
    char ident[10];
    GetId(ident);
    arch << "Tipo B: " << left << setw(5) << ident
            << right << setw(5) << GetFil() 
            << setw(5) << GetCol() << endl;
}

void B::mover(char dir, int cant) {
    switch (dir) {
        case 'P':
            SetFil(GetFil() - cant);
            SetCol(GetCol() - cant);
            break;
        case 'Q':
            SetFil(GetFil() - cant);
            SetCol(GetCol() + cant);
            break;
        case 'R':
            SetFil(GetFil() + cant);
            SetCol(GetCol() + cant);
            break;
        case 'S':
            SetFil(GetFil() + cant);
            SetCol(GetCol() - cant);
            break;
    }
}