/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 15, 2024, 7:34 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int suma(int a, int b) {
    return a + b;
}

int multiplicar(int a, int b) {
    return a * b;
}

const char* leeCadena(const char* c) {
    return c;
}

/**
 * Esta es la función de comparación cuya dirección de memoria se pasará a
 * qsort como parte del parámetro cmp el cual es un puntero a funciones que 
 * devuelven un entero y reciben dos `const void*`, `const void*` como 
 * parámetros
 * @param a contiene un puntero int*, por Cast (Boxing) se pasa como puntero 
 * genérico
 * @param b contiene un puntero int* por Cast (Boxing) se pasa como puntero 
 * genérico
 * @return -1, 0 o 1 si x es menor que y, es igual que y o es mayor que y 
 * respectivamente
 */
int compararEnteros(const void* a, const void* b) {
    // Se realiza el Cast de const void* a int* (Uboxing) y se asigna el valor
    // de su primer elemento a x
    int x = *(int*)a;
    
    // Se realiza el Cast de const void* a int* (Unboxing) y se asigna el valor
    // de su primer elemento a y
    int y = *(int*)b;
    
    if (x == y) {
        return 0;
    }
    else if (x < y) {
        return -1;
    }
    else {
        return 1;
    }
}

/**
 * Esta es la función de comparación cuya dirección de memoria se pasará a
 * qsort como parte del parámetro cmp el cual es un puntero a funciones que 
 * devuelven un entero y reciben dos `const void*`, `const void*` como 
 * parámetros
 * @param arr1 contiene un puntero doble char**, por Cast (Boxing) se pasa como 
 * puntero genérico
 * @param arr2 contiene un puntero doble char*, por Cast (Boxing) se pasa como
 * puntero genérico
 * @return -1 s1 es alfabéticamente menor que s2, 0 si s1 y s2 son 
 * alfabéticamente iguales, 1 si s1 es alfábeticamente mayor que s2
 */
int compararCadenas(const void* arr1, const void* arr2) {
    char* s1 = *(char**)arr1;
    char* s2 = *(char**)arr2;
    
    return strcmp(s1, s2);
}

int main(int argc, char** argv) {
    /*
     * USO DE PUNTERO A FUNCIONES
     */
    
    /*
     * Puntero a funciones que devuelven un entero y reciben dos 
     * parametros enteros
     */
    int (*p)(int, int);
    
    /*
     * Se asigna la dirección de memoria de la función suma al 
     * puntero a función p, esto es posible porque la función suma cumple con la
     * definición del puntero p
     */
    p = suma;
    cout << p(4, 2) << endl;
    
    /*
     * Se asigna la dirección de memoria de la función multiplicación al puntero
     * a función p, esto es posible porque la función multiplicación cumple con
     * la definición del puntero p
     */
    p = multiplicar;
    cout << p(4, 2) << endl;
    
    /*
     * Puntero a funciones que devuelven un `const char*` y reciben un 
     * `const char*` como parametro
     */
    const char* (*pLeeCadena)(const char*);
    /*
     * Se asigna la dirección de memoria de la función leeCadena al puntero a 
     * función pLeeCadena, esto es posible porque la función leeCadena cumple
     * con la definición del puntero pLeeCadena.
     */
    pLeeCadena = leeCadena;
    cout << pLeeCadena("Hola a todos");
    cout << endl;
    
    
    /* ====================================================================== */
    /*
     * USO DE QSORT
     */
    
    /*
     * Puntero de 6 enteros el cual se encuentra desordenado
     */
    int *a = new int[6] { 8, 9, 4, 2, 3 };
    /*
     * Se ordenan los 6 elementos asignados dinámicamente en la memoria
     * tener en cuenta que la función compararEntero se pasa como puntero en el
     * parámetro cmp.
     */
    qsort(a, 6, sizeof(int), compararEnteros);
    /*
     * Se imprimen los 6 elementos ordenados
     */
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    /*
     * Puntero doble de 4 punteros a caracteres `char*`
     */
    char** nombres = new char*[4];
    nombres[0] = new char[50];
    nombres[1] = new char[50];
    nombres[2] = new char[50];
    nombres[3] = new char[50];
    
    /*
     * Se asignan cadenas desordenadas
     */
    strcpy(nombres[0], "Teresa Castillo");
    strcpy(nombres[1], "Julián Torres");
    strcpy(nombres[2], "Diana Gutierrez");
    strcpy(nombres[3], "Roberto Alvarado");
    
    /*
     * Se ordenan las 4 cadenas. Tener en cuenta que la función compararCadenas
     * se pasa como puntero en el parámetro cmp.
     */
    qsort(nombres, 4, sizeof(char*), compararCadenas);
    /*
     * Se imprimen las 4 cadenas ya ordenadas.
     */
    for (int i = 0; i < 4; i++) {
        cout << nombres[i] << endl;
    }
    
    /* ====================================================================== */
    /* LIBERACIÓN DE MEMORIA */
    delete[] a;
    for (int i = 0; i < 4; i++) {
        delete[] nombres[i];
    }
    delete[] nombres;
    
    return 0;
}

