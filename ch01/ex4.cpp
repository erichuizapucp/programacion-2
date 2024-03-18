#include <cstdlib>
#include <iostream>

using namespace std;

void twoDimensionArratWithPointers() {
    // memory allocation for the 2D array
    int** a = new int*[10];
    
    // memory allocation for each row
    for (int index = 0; index < 10; index++) {
        a[index] = new int[10];
    }
    
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            a[row][col] = row * col;
        }
    }
    
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            cout << a[row][col] << " ";
        }
        cout << endl;
    }
    
    // release memory for each row
    for (int index = 0; index < 10; index++) {
        delete[] a[index];
    }
    
    // release memory for the 2D array
    delete[] a;
}

