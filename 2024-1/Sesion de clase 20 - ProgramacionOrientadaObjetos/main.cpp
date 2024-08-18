/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on June 3, 2024, 10:24 AM
 */

#include <cstdlib>
#include <iostream>

#include "Diccionario.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Diccionario<const char*, int> dic;
    
    dic.agregar(Par<const char*, int>("key1", 1));
    dic.agregar(Par<const char*, int>("key2", 2));
    dic.agregar(Par<const char*, int>("key3", 3));
    
    int index = dic.buscar(Par<const char*, int>("key1", 1));
    Par<const char*, int> p = dic.obtener(index);
    
    cout << p;
    
    return 0;
}

