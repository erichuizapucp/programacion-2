#include <cstdlib>
#include <iostream>

using namespace std;

void firstPointer() {
    int a;
    a = 20;
    
    int *p;
    p = &a;
    
    cout << a << "\n";
    cout << p << "\n";
    cout << *p << "\n";
    
    (*p)++;
    cout << *p << "\n";
    cout << a << "\n";
}