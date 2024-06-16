#include <cstdlib>
#include <list>
#include <iostream>
#include <fstream>
#include <iterator>
#include "Persona.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    list<double> lDbl { 38, 645, 4.64, 12.656, 676.635, 10.253, 3.333 };
//    list<double> lDbl2 { 1.1, 2.2, 3.3, 4.4 };
//    
//    cout << "SIZE: " << lDbl.size() << endl;
//    cout.precision(2);
//    cout << fixed;
//    
//    for (double x : lDbl) {
//        cout << setw(8) << x;
//    }
//    cout << endl;
//    lDbl.push_front(123.65);
//    lDbl.push_front(777.373);
//    lDbl.push_front(565.711);
//    lDbl.push_back(1.11);
//    lDbl.push_back(2.222);
//    lDbl.push_back(3.333);
//    
//    for (double x:lDbl) {
//        cout << setw(10) << x;
//    }
//    cout << endl;
//    
//    lDbl.sort();
//    
//    for (auto it=lDbl.begin(); it != lDbl.end(); it++) {
//        cout << setw(10) << *it;
//    }
//    cout << endl;
//    
//    lDbl.merge(lDbl2);
//    for (double x:lDbl) {
//        cout << setw(9) << x;
//    }
//    cout << endl;
//    
//    auto it = lDbl.begin();
//    
//    it++;
//    it++;
//    it++;
//    auto it2 = it;
//    it2++;
//    it2++;
//    it2++;
//    
//    lDbl.insert(it, 555.777);
//    lDbl.erase(it, it2);
//    for (double x:lDbl) {
//        cout << setw(9) << x;
//    }
//    cout << endl;
    
    list<Persona> lPer;
    
    ifstream arch("personas.csv", ios::in);
    if (!arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    Persona per;
    while (true) {
        arch >> per;
        if (arch.eof()) {
            break;
        }
        
        lPer.push_front(per);
    }
    lPer.sort();
    
    for (Persona x:lPer) {
        cout << x;
    }
    
    return 0;
}

