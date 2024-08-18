/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on June 10, 2024, 3:53 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string str1 = "primera cadena";
    string str2 = "segunda cadena";
    
    string str3 = str1 + ", " + str2;
    cout << str3 << endl; // Ejemplo de concatenación de cadenas usando <string>
    
    string texto = "Created on June 10, 2024, 3:53 PM";
    string buscar = "June";
    
    /*
     * Ejemplo de búsqueda y reemplazo de cadenas usando <string>
     */
    int pos = texto.find(buscar);
    cout << pos << endl;
    
    if (pos != string::npos) {
        texto.replace(pos, buscar.length(), "July");
        cout << texto;
    }
    
    cout << endl;
    
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    
    auto it = v1.cbegin();
    v1.insert(it, 0);
    
    for (auto num : v1) {
        cout << num << " ";
    }
    
    cout << endl;
    for (auto it=v1.begin(); *it!=3; ++it) {
        cout << *it;
    }
    
    return 0;
}

