/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on November 18, 2024, 3:14 PM
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>

using namespace std;

int main(int argc, char** argv) {
    vector<string> v1;
    
    cout << "Tamaño: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl;
    
    v1.push_back("José");
    v1.push_back("Alberto");
    v1.push_back("Sofía");
    v1.push_back("Teresa");
    v1.push_back("Juán");
    v1.push_back("Pedro");
    v1.push_back("María");
    
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << endl;
    }
    cout << endl;
    
//    sort(v1.begin(), v1.end(), greater<string>());
    sort(v1.begin(), v1.end(), less<string>());
   
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << endl;
    }
    
    cout << "Tamaño: " << v1.size() << endl;
    cout << "Capacidad: " << v1.capacity() << endl;
    
    list<int> l1();
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    
    l1.push_front(1);
    l1.push_front(0);
    
    map<int, string> m1;
    m1[0] = "Test 1";
    m1[1] = "Test 2";
    m1[2] = "Test 3";
    
    m1[0] = "Test 0";
    
    return 0;
}

