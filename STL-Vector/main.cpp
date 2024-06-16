#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void f(vector<int> v) {
    for (int x : v) {
        cout << setw(5) << x;
    }
    
    cout << endl << endl;
}

int main(int argc, char** argv) {
    vector<int> vInt;
    
    cout << "Número de elementos = " << vInt.size() << endl;
    cout << "Capacidad de arreglo = " << vInt.capacity() << endl << endl;
    
    vInt.push_back(56);
    cout << "Número de elementos = " << vInt.size() << endl;
    cout << "Capacidad de arreglo = " << vInt.capacity() << endl << endl;
    
    vInt.push_back(39);
    cout << "Número de elementos = " << vInt.size() << endl;
    cout << "Capacidad de arreglo = " << vInt.capacity() << endl << endl;
    
    vInt.push_back(327);
    cout << "Número de elementos = " << vInt.size() << endl;
    cout << "Capacidad de arreglo = " << vInt.capacity() << endl << endl;
    
    vInt.push_back(21);
    vInt.push_back(9);
    cout << "Número de elementos = " << vInt.size() << endl;
    cout << "Capacidad de arreglo = " << vInt.capacity() << endl << endl;
    
    vInt.shrink_to_fit();
    cout << "Número de elementos = " << vInt.size() << endl;
    cout << "Capacidad de arreglo = " << vInt.capacity() << endl << endl;
    
    vInt.push_back(101);
    cout << "Número de elementos = " << vInt.size() << endl;
    cout << "Capacidad de arreglo = " << vInt.capacity() << endl << endl;
    
    for (int i = 0; i < vInt.size(); i++) {
        cout << setw(5) << vInt[i];
    }
    cout << endl << endl;
    
    for (int x : vInt) {
        cout << setw(5) << x;
    }
    cout << endl << endl;
    
    vector<int> vInt2 { 23, 14, 62, 77, 21, 12, 9, 102, 47, 81 };
    for (int x : vInt2) {
        cout << setw(5) << x;
    }
    cout << endl << endl;
    
    vector<int> vInt3(10);
    cout << "Número de elementos = " << vInt3.size() << endl;
    cout << "Capacidad del arreglo = " << vInt3.capacity() << endl << endl;
    for (int x : vInt3) {
        cout << setw(5) << x;
    }
    cout << endl << endl;
    
//    vector<int> vInt4(10, 55);
//    cout << "Número de elementos = " << vInt4.size() << endl;
//    cout << "Capacidad del arreglo = " << vInt4.capacity() << endl << endl;
//    for (int x : vInt4) {
//        cout << setw(5) << x;
//    }
//    cout << endl << endl;
//    
//    vInt4.assign(5, 101);
//    cout << "Número de elementos = " << vInt4.size() << endl;
//    cout << "Capacidad del arreglo = " << vInt4.capacity() << endl << endl;
//    for (int x : vInt4) {
//        cout << setw(5) << x;
//    }
//    cout << endl << endl;
//    
//    vInt4.assign({ 23, 14, 62, 77, 21, 12, 9, 102, 47, 81, 52 });
//    cout << "Número de elementos = " << vInt4.size() << endl;
//    cout << "Capacidad del arreglo = " << vInt4.capacity() << endl << endl;
//    for (int x : vInt4) {
//        cout << setw(5) << x;
//    }
//    cout << endl << endl;
//    
//    vInt4.pop_back();
//    for (int x : vInt4) {
//        cout << setw(5) << x;
//    }
//    cout << endl << endl;
//    
//    int dIni, dFin;
//    dIni = vInt4.front();
//    dFin = vInt4.back();
//    
//    cout << "Dato Ini = " << dIni << endl;
//    cout << "Dano Fin = " << dFin << endl;
//    for (int x : vInt4) {
//        cout << setw(5) << x;
//    }
//    cout << endl << endl;
//    
//    for (vector<int>::iterator it=vInt4.begin(); it != vInt4.end(); it++) {
//        cout << setw(5) << *it;
//    }
//    cout << endl << endl;
//    
//    vector<int>::iterator it2=vInt4.begin();
//    vector<int>::iterator it3=vInt4.begin();
//    
//    it2+=3;
//    it3+=6;
//    
//    cout << setw(5) << *it2 << endl;
//    
//    vInt4.erase(it2);
//    for (int x : vInt4) {
//        cout << setw(5) << x;
//    }
//    cout << endl << endl;
//    cout << setw(5) << *it2 << endl;
//    
//    vInt4.clear();
//    cout << "Número de elementos = " << vInt4.size() << endl;
//    cout << "Capacidad del arreglo = " << vInt4.capacity() << endl << endl;
//    
//    for (int x: vInt4) {
//        cout << setw(5) << x;
//    }
//    cout << endl << endl;
//    
//    vInt4.assign({ 23, 14, 62, 77, 21, 12, 9, 102, 47, 81, 52 });
//    sort(vInt4.begin(), vInt4.end());
//    
//    for (int x: vInt4) {
//        cout << setw(5) << x;
//    }
//    cout << endl << endl;
    
    return 0;
}

