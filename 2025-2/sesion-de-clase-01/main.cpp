#include <iostream>

using namespace std;

void porReferencia(int*& x) {
    // Afecta al puntero original ya que es una referencia
    x = new int;
    *x = 20;
}

void porValor(int* x) {
    // No afecta al puntero original ya que es una copia
    x = new int;
    *x = 20;
    delete x;
}

int sumar(int a) {
    return a + 8;
}

int sumar(int a = 3, int b = 5) {
    return a + b;
}

int sumar(int* a, int* b) {
    return *a + *b;
}

int sumar(int*& a, int*& b) {
    return *a + *b;
}

int main() {
    /*** Inicio: Punteros y referencias ***/
    int a = 3;
    int b = 5;

    // & operador de dirección
    cout << "Dirección de memoria de a: " << &a << endl;
    cout << "Dirección de memoria de b: " << &b << endl;

    int* p = &a; // p es un puntero a un entero, y almacena la dirección de memoria de a
    cout << "Dirección a la que apunta p: " << p << endl;
    cout << endl;

    *p = 10; // asigna el valor 10 a la dirección de memoria a la que apunta p
    cout << "Valor de a: " << a << endl; // ahora a es 10
    int c = a + b;
    cout << "Valor de c: " << c << endl; // c es 15, ya que a es 10 y b es 5
    /*** Fin: Punteros y referencias ***/

    /*** Inicio: Paso de punteros por valor o por referencia ***/
    p = new int; // reservar memoria dinámicamente en el heap
    *p = 10; // asignar valor a la dirección de memoria a la que apunta p
    porValor(p); // pasar puntero por valor
    cout << *p << endl; // sigue siendo 10, ya que la función no afecta al puntero original

    *p = 10; // asignar valor a la dirección de memoria a la que apunta p
    porReferencia(p); // pasar puntero por referencia
    cout << *p << endl; // ahora es 20, ya que la función afecta al puntero original

    delete p;
    /*** Fin: Paso de punteros por valor o por referencia ***/

    /*** Inicio: Arreglos y punteros ***/
    int arr[5] { 1, 2, 3, 4, 5 };
    cout << *arr << endl; // Imprime el primer elemento del arreglo
    cout << *(arr + 1) << endl; // Imprime el segundo elemento del arreglo
    cout << *(arr + 2) << endl; // Imprime el tercer elemento del arreglo
    cout << *(arr + 3) << endl; // Imprime el cuarto elemento del arreglo
    cout << *(arr + 4) << endl; // Imprime el quinto elemento del arreglo
    cout << &arr << endl; // Imprime la dirección de memoria del arreglo
    cout << &arr[2] << endl; // Imprime la dirección de memoria del tercer elemento del arreglo

    p = arr + 2; // p apunta al tercer elemento del arreglo arr

    // Imprimir los valores del arreglo usando el puntero
    cout << "Valores del arreglo usando el puntero:" << endl;
    for (int i = 2; i < 5; i++) {
        cout << *p << endl;
        p++;
    }
    /*** Fin: Arreglos y punteros ***/

    /*** Inicio: Funciones con parámetros por defecto y sobrecarga de funciones ***/
    cout << sumar() << endl;
    cout << sumar(5, 9) << endl;

    // Genera un error de ambigüedad
    // cout << sumar(5) << endl;

    int* x = new int(10);
    int* y = new int(20);
    // Genera un error de ambiguedad.
    // cout << sumar(x, y) << endl;

    delete x;
    delete y;
    /*** Fin: Funciones con parámetros por defecto y sobrecarga de funciones ***/

    return 0;
}