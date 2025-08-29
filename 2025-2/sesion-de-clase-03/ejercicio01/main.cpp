#include <iostream>

using namespace std;

int* f(int*& p) {
    // Error grave de concepto.
    int arr[5] { 6, 7, 8, 9, 10 };
    p = arr;

    return p;
}

void imprimir(const int* p) {
    cout << *p << endl;
}

int main() {
    int* p = new int[5] { 1, 2, 3, 4, 5 };
    // p = f(p);

    for (int i = 0; i < 5; i++) {
        imprimir(&p[i]);
        // cout << p[i] << endl;
    }

    int* a = new int(8);
    cout << *a << endl;

    delete a;
    delete[] p;

    return 0;
}