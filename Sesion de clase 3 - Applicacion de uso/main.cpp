/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 22, 2024, 3:42 PM
 */

#include <cstdlib>
#include <iostream>
#include "date.h"
#include "overloads.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    struct Date d1 { 25, 12, 2023 };
    struct Date d2 { 31, 12, 2023 };
    
    cout << "d1 == d2: " << boolalpha << (d1 == d2) << endl;
    cout << "d1 < d2: " << boolalpha << (d1 < d2) << endl;
    cout << "d1 > d2: " << boolalpha << (d1 > d2) << endl;
    cout << "d1 <= d2: " << boolalpha << (d1 <= d2) << endl;
    cout << "d1 >= d2: " << boolalpha << (d1 >= d2) << endl;
    
    return 0;
}

