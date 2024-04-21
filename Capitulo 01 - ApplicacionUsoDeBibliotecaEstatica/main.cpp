/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 21, 2024, 10:39 PM
 */

#include <cstdlib>
#include <iostream>
#include "date.h"
#include "vector3d.h"
#include "overloads.h"
#include "templates.h"
#include "fraction.h"

using namespace std;

/*
 * Referencia a una librería estática FunctionsStaticLibrary
 */
int main(int argc, char** argv) {
    int arr1[3] = { 5, 6, 1 };
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    
    float arr2[3] = { 3.0, 10.3, 11.2 };
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    
    sortArray(arr1, arr1Size);
    cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << endl;;
    
    sortArray(arr2, arr2Size);
    cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << endl;;
    
    cout << endl;
    int arr1MaxElement = maxElement(arr1, arr1Size);
    float arr2MaxElement = maxElement(arr2, arr2Size);
    cout << "Array 1 Max Element: " << arr1MaxElement << endl;
    cout << "Array 2 Max Element: " << arr2MaxElement << endl;
    
    cout << endl;
    struct Vector3D v1 { 2.0, 2.0, 2.0 };
    struct Vector3D v2 { 3.0, 3.0, 3.0 };
    
    cout << "v1 == v2: " << boolalpha << equal(v1, v2) << endl;
    cout << "v1 < v2: " << boolalpha << lessThan(v1, v2) << endl;
    cout << "v1 > v2: " << boolalpha << greaterThan(v1, v2) << endl;
    cout << "v1 <= v2: " << boolalpha << lessOrEqualThan(v1, v2) << endl;
    cout << "v1 >= v2: " << boolalpha << greaterOrEqualThan(v1, v2) << endl;
    
    cout << endl;
    struct Date d1 { 25, 12, 2023 };
    struct Date d2 { 31, 12, 2023 };
    
    cout << "d1 == d2: " << boolalpha << equal(d1, d2) << endl;
    cout << "d1 < d2: " << boolalpha << lessThan(d1, d2) << endl;
    cout << "d1 > d2: " << boolalpha << greaterThan(d1, d2) << endl;
    cout << "d1 <= d2: " << boolalpha << lessOrEqualThan(d1, d2) << endl;
    cout << "d1 >= d2: " << boolalpha << greaterOrEqualThan(d1, d2) << endl;
    
    return 0;
}

