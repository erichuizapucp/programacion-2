#include <iostream>

#include "estructuras.h"
#include "funciones.h"

using namespace std;

int main() {
    Cliente c { 11111111, 20 };
    cout << "Edad del cliente: " << c.edad << endl;

    Cliente d = c++;
    cout << "Edad del cliente: " << c.edad << endl;

    ++c;
    cout << "Edad del cliente: " << c.edad << endl;

    c--;
    cout << "Edad del cliente: " << c.edad << endl;

    --c;
    cout << "Edad del cliente: " << c.edad << endl;

    Pedido p1 { 11111111, 400.00 };
    Pedido p2 { 11111111, 200.00 };

    Pedido p3 = p1 + p2;
    cout << endl;
    cout << c << p3 << endl;

    return 0;
}
