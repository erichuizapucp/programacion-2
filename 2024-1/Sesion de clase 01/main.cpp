#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

int add(int a) {
   return a + 10; 
}

int add(int a, int b) {
    return a + b;
}

void add(int a, int b, int* c) {
    *c = a + b;
}

int main(int argc, char** argv) {
    int nums[5] = { 0, 5, 10, 15, 20 };
    
    int* p = nums;
    
    for (int index = 0; index < 5; index++) {   
        cout << *(p + index) << endl;
    }
//    (*p)++;
    
    
    
//    int a = 10;
//    int b = 15;
//    int c = 0;
//    
//    c = add(a);
//    cout << c << endl;
//    
//    c = add(a, b);
//    cout << c << endl;
//    
//    add(a, b, &c);
//    cout << c << endl;
    
//    int* a = new int;
//    int* b = new int;
//    int* c = new int;
//    
//    *a = 10;
//    *b = 15;
//    
//    *c = *a + *b;
//    
//    cout << *c;
//    
//    delete a;
//    delete b;
//    delete c;
//    
//    cout << c;
    
//    int a = 100; //
//    int* p = &a;
//    
//    *p = 120;
//    (*p)++;
//    
//    cout << "Direcciones de memoria" << "\n";
//    cout << &a << "\n";
//    cout << p << "\n";
//    
//    cout << endl;
//    cout << "Valores" << "\n";
//    cout << a << "\n";
//    cout << *p << "\n";
    
    return 0;
}

