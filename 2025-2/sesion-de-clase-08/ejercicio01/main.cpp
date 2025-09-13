#include <iostream>

using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int main() {
    int (*p)(int a, int b);
    p = sumar;
    cout << "Suma: " << p(3, 5) << endl;
    p = restar;
    cout << "Resta: " << p(3, 5) << endl;
    p = multiplicar;
    cout << "Multiplicacion: " << p(3, 5) << endl;

    return 0;
}