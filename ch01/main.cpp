/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 17, 2024, 7:36 AM
 */

#include <cstdlib>
#include <iostream>
#include "myfunctions.h"
#include "Vector3D.h"

using namespace std;

void firstPointer();

void arrayWithoutPointers();

void arrayWithPointers();
void arrayWithPointers2();
void arrayWithPointers3();

void addTwoNumbers1(int a, int b, int c);
void addTwoNumbers2(int *a, int *b, int *c);

void twoDimensionArratWithPointers();

void printArray(int* array);

void updatePointerAddress(int *&a);

int main(int argc, char** argv) {
    cout << "First Pointer:";
    firstPointer();
    
    cout << "Array without pointers:";
    arrayWithoutPointers();
    
    cout << "Array with pointers:";
    arrayWithPointers();
    
    cout << "Array with pointers 2:";
    arrayWithPointers2();
    
    cout << "Array with pointers 3:";
    arrayWithPointers3();
    
    int a = 2;
    int b = 3;
    int c;
    addTwoNumbers2(&a, &b, &c);
    cout << c << "\n";
    
    twoDimensionArratWithPointers();
    
    int arr[5] = { 0, 1, 2, 3, 4 };
    printArray(arr);
    
    int* p = new int;
    *p = 30;
    cout << *p << "\n";
    updatePointerAddress(p);
    cout << *p << "\n";
    
    delete p;
    
    int sum1 = add(9);
    cout << sum1 << std::endl;
    
    int sum2 = add(9, 9);
    cout << sum2 << std::endl;
    
    int f = 10;
    add(&f);
    cout << f << std::endl;
    
    cout << multiply(4, 4) << std::endl;
    
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(1.1, 2.1, 3.1);
    
    Vector3D sum = v1 + v2;
    sum.print();
    
    return 0;
}
