/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on September 20, 2024, 3:38 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int comparar(const void* a, const void* b) {
    const int* pa = (const int*)a;
    const int* pb = (const int*)b;
    
    return *pb - *pa;
}

int compararNombres(const void* a, const void* b) {
    const char** pa = (const char**)a;
    const char** pb = (const char**)b;
    
    return strcmp(*pb, *pa);
}

int main(int argc, char** argv) {
    int* arr = new int[5] { 8, 3, 5, 6, 1 };
    qsort(arr, 5, sizeof(int), comparar);
    
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
    
    cout << endl;
    
    char** arr2 = new char*[5];
    arr2[0] = new char[20];
    strcpy(arr2[0], "María Gonzales");
    arr2[1] = new char[20];
    strcpy(arr2[1], "Ana Perez");
    arr2[2] = new char[20];
    strcpy(arr2[2], "Juan Torres");
    arr2[3] = new char[20];
    strcpy(arr2[3], "Xiomara Díaz");
    arr2[4] = new char[20];
    strcpy(arr2[4], "Carlos Torrez");
    qsort(arr2, 5, sizeof(char*), compararNombres);
    
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << endl;
    }
    
    return 0;
}

