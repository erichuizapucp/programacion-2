/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 24, 2025, 4:48 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


void f(int a = 4, int b = 10) {
    cout << a << endl;
    cout << b << endl;
}

int main(int argc, char** argv) {
    int a = 5; //Stack
    int* b = &a;
    
    cout << *b << endl;
    
    *b = 10;
    
    cout << a << endl;
    cout << b << endl; // Dirección a la que apunta b
    cout << &b << endl; // Dirección de b
    
    int arr[5] { 4, 6, 7, 8, 10 };
    
    cout << *arr << endl; // primer elemento 
    cout << *(arr + 1) << endl; // segundo elemento del arreglo
    
    f();
    f(6);
    f(7, 20);
    
    
    return 0;
}

