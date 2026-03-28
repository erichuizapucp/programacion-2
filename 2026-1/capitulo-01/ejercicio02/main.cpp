#include <iostream>

using namespace std;

int main() {
    // Manejo de arreglos estáticos y punteros.
    int arr[5] { 1, 2, 3, 4, 5 };
    int* p = arr;

    // cout << *(p + 2) << endl;

    for (int i = 0; i < 5; i++, p++) {
        cout << *p << endl;
    }

    // Manejo de arreglos dinámicos y punteros.
    int* numeros = new int[5] { 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; i++) {
        cout << numeros[i] << endl;
    }

    delete[] numeros;

    return 0;
}