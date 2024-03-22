/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 20, 2024, 9:36 PM
 */

#include <cstdlib>
#include "date.h"
#include "overloads.h"
#include "fraction.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    struct Date date1 { 10, 10, 2023 };
    struct Date date2 { 20, 03, 2024 };
    
    cout << "Date 1: " << date1 << endl;
    cout << "Date 2: " << date2 << endl;
    
    cout << "Date 1 == Date 2: " << boolalpha <<(date1 == date2) << endl;
    cout << "Date 1 != Date 2: " << boolalpha <<(date1 != date2) << endl;
    cout << "Date 1 < Date 2: " << boolalpha <<(date1 < date2) << endl;
    cout << "Date 1 > Date 2: " << boolalpha <<(date1 > date2) << endl;
    cout << "Date 1 <= Date 2: " << boolalpha <<(date1 <= date2) << endl;
    cout << "Date 1 >= Date 2: " << boolalpha <<(date1 >= date2) << endl;
    
    cout << endl;
    struct Date date3 { 25, 12, 2023 };
    struct Date date4 { 25, 12, 2023 };
    
    cout << "Date 3: " << date3 << endl;
    cout << "Date 4: " << date4 << endl;
    
    cout << "Date 3 == Date 4: " << boolalpha <<(date3 == date4) << endl;
    cout << "Date 3 != Date 4: " << boolalpha <<(date3 != date4) << endl;
    cout << "Date 3 < Date 4: " << boolalpha <<(date3 < date4) << endl;
    cout << "Date 3 > Date 4: " << boolalpha <<(date3 > date4) << endl;
    cout << "Date 3 <= Date 4: " << boolalpha <<(date3 <= date4) << endl;
    cout << "Date 3 >= Date 4: " << boolalpha <<(date3 >= date4) << endl;
    
    cout << endl;
    struct Vector3D vector1 { 1, 1, 1 };
    struct Vector3D vector2 { 2, 2, 2 };
    
    cout << "Vector 1: " << vector1 << endl;
    cout << "Vector 2: " << vector2 << endl;
    
    struct Vector3D vector3 = vector1 + vector2;
    cout << "Vector 3: " << vector3 << endl;
    
    cout << endl;
    struct Fraction f1 { 2, 4 };
    struct Fraction f2 { 4, 8 };
    
    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;
    
    cout << "F1 + F2: " << (f1 + f2) << endl;
    cout << "F1 - F2: " << (f1 - f2) << endl;
    cout << "F1 * F2: " << (f1 * f2) << endl;
    cout << "F1 / F2: " << (f1 / f2) << endl;
    
    return 0;
}

