/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on August 19, 2024, 12:04 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void porValor(int* x) {
    *x = 80; // cambia el valor al que apunta el puntero a 80.
    x = new int; // el puntero apunta a una nueva direccíon en el heap
    *x = 100; // el dato en esa nueva dirección es 100
}

void porReferencia(int*& x) {
    *x = 80; // cambia el valor al que apunta el puntero a 80.
    x = new int; // el puntero apunta a una nueva direccíon en el heap, pero como
    // fue pasado por referencia, los variables g o x referencian a la misma dirección de memoria.
    *x = 100; // el dato en esa nueva dirección es 100
}

int main(int argc, char** argv) {
    int a = 5;
    
    int* p = &a; // el valor de p ahora es la dirección de memoria de a
    *p = 6; // se modifica el dato al que apunta p. Ahora a es 6
    a = 7; // se modifica a. Ahora *p es 7.
    cout << *p << endl; // imprime 7
    cout << &a << endl; // imprime la dirección de memoria de a
    
    // Se usa constante porque num se usará para determinar la dimensión del 
    // arreglo dnis.
    const int num = 3;
    // Siempre alocar un espacio adicional para el caracter de quiebre.
    // num + 1.
    int dnis[num + 1] { 12345678, 56738494, 18349578, -1 };
    
    // el puntero pa ahora contiene la dirección de memoria del primer elemento
    // en el arreglo dnis
    int *pa = dnis; 
    cout << *pa << endl; // imprime 12345678
    pa++; //se mueve al siguiente elemento del arreglo - aritmética de punteros.
    cout << *pa << endl; // imprime 56738494
    pa = &dnis[2]; // el puntero pa ahora contiene la dirección de memoria del tercer elemento
    cout << *pa << endl; // imprime 18349578
    
    cout << endl;
    // recorrido de un arreglo usando un índice.
    for (int i = 0; i < 3; i++) {
        cout << dnis[i] << endl;
    }

    cout << endl;
    
    // recorrido de un arreglo usando aritmética de punteros
    for (int* pa = dnis; *pa != -1; pa++) {
        cout << *pa << endl;
    }
    
    cout << endl;
    
    // asignación de memoria dinámica en el heap.
    int *d = new int; // el puntero d apunta a un entero en el heap.
    // el puntero se encuentra en el stack y el entero al que se apunta en el heap.
    *d = 5;
    cout << *d << endl;
    delete d; // siempre hay que liberar la memoria asignada dinámicamente.
    
    cout << endl;
    
    // asignación de memoria dinámica para un arreglo en el heap.
    int* numEnteros = new int[4] { 1, 2, 3, -1 };
    for (int* pnums = numEnteros; *pnums != -1; pnums++) {
        cout << *pnums << endl;
    }
    delete[] numEnteros; // se libera la memoria asignada al arreglo en el heap
    // se usa delete[] porque es un arreglo.
    
    cout << endl;
    
    int* g = new int(10);
    // al pasar un puntero por valor se copia el valor del puntero en el parámetro 
    // int* x, el valor del puntero es una dirección de memoria.
    porValor(g);
    cout << *g; // imprime 80, porque en la función porValor x es pasado por valor
    // entonces al realizar x = new int esto no afeta a g.
    
    cout << endl;
    porReferencia(g);
    cout << *g; // imprime 100, porque en la función porReferencia x es pasado por referencia
    // entonces al realizar x = new int esto sí afeta a g.
    
    return 0;
}

