#include <iostream>

using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int muliplicar(int a, int b) {
    return a * b;
}

int main() {
    int (*op)(int, int);
    op = sumar;
    cout << op(10, 5) << endl;

    op = restar;
    cout << op(10, 5) << endl;

    op = muliplicar;
    cout << op(10, 5) << endl;

    return 0;
}
