#include <iostream>

#include "Cilindro.h"
#include "Circulo.h"

using namespace std;
int main() {
    Circulo c(3.5);
    cout << "Area del circulo: " << c.calcularArea() << endl;

    Cilindro c2(3.5, 5.0);
    cout << "Area del cilindro: " << c2.calcularArea() << endl;


    return 0;
}