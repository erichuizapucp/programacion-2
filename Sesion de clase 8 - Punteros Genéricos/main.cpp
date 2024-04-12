/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 8, 2024, 8:10 AM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a = 35;
    double *b;
    *b = 4.5;
    
    void *v = &a;
    
    cout << v << " " << &a << endl;
    cout << *(int*)v << endl;
    cout << *static_cast<int*>(v) << endl;
    
    v = b;
    
    cout << v << " " << b << endl;
    cout << *(double*)v << endl;
    
    return 0;
}

