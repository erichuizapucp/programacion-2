/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 19, 2024, 12:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int compareInts(const void* pkey, const void* pelem) {
    int key = *(int*)pkey;
    int elem = *(int*)pelem;
    
    if (key < elem) {
        return -1;
    }
    else if (key == elem) {
        return 0;
    }
    else {
        return 1;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    char* param1 = new char[50];
    strcpy(param1, argv[1]);

    int* arr = new int[5] { 3, 8, 5, 9, 6 };
    int key = atoi(param1);
    
    qsort(arr, 5, sizeof(int), compareInts);
    int* pItem = (int*)bsearch(
        &key, 
        arr, 
        5, 
        sizeof(int), 
        compareInts
    );
    
    if (pItem != nullptr) {
        cout << "El elemento " << key << " existe y es " << *pItem << endl;
        
        for (int i = 0; i < 5; i++) {
            cout << left << setw(2) << arr[i];
        }
    }
    else {
        cout << "El elemento " << key << " no existe";
        
        for (int i = 0; i < 5; i++) {
            cout << left << setw(2) << arr[i];
        }
    }
    
    return 0;
}

