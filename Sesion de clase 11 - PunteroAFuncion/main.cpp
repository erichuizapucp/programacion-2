/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 19, 2024, 12:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "genericlist.h"

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
    /*
     * ========================================================================
     * PARTE 1: bsearch y lectura de argumentos de la función main
     */
    
    /*
     * Obtenemos la llave a buscar en el arreglo desde un argumento del programa
     */
    char* param1 = new char[50];
    strcpy(param1, argv[1]);
    int key = atoi(param1);
    int* arr = new int[5] { 3, 8, 5, 9, 6 };
    
    /*
     * Ordenamos el arreglo antes de realizar la búsqueda binaria.
     */
    qsort(arr, 5, sizeof(int), compareInts);
    /*
     * Realizamos la búsqueda binaria
     */
    int* pItem = (int*)bsearch(
        &key, 
        arr, 
        5, 
        sizeof(int), 
        compareInts
    );
    
    if (pItem != nullptr) {
        cout << "El elemento " << key << " existe en el arreglo [";
        for (int i = 0; i < 5; i++) {
            cout << left << setw(2) << arr[i];
        }
        cout << "] y es " << *pItem << endl;
    }
    else {
        cout << "El elemento " << key << " no existe en el arreglo [";
        for (int i = 0; i < 5; i++) {
            cout << left << setw(2) << arr[i];
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    /*
     * ========================================================================
     * PARTE 2: Lista enlazada genérica
     */
    
    /*
     * Creamos una lista de estructuras de empleados.
     */
    struct Employee *employee1 = createEmployee(
        1, 
        "María Gonzales", 
        "Chief Executive Office", 
        10000
    );
    struct Employee *employee2 = createEmployee(
        2, 
        "Jimena Torres", 
        "Chief Technology Officer", 
        9000
    );
    struct Employee *employee3 = createEmployee(
        3, 
        "Carlos Mercado", 
        "Development Manager", 
        8000
    );
    struct Employee *employee4 = createEmployee(
        4, 
        "Developer", 
        "Mauricio Alba", 
        7000
    );
    
    /*
     * Ahora creamos la lista enlazada genérica
    */
    Node* head;
    /*
     * Lista enlazada de enteros
     */
    int *p0 = new int(0);
    int *p1 = new int(1);
    int *p2 = new int(2);
    int *p3 = new int(3);
    
    head = createNode(p0);
    head = appendNode(head, p1);
    head = appendNode(head, p2);
    head = appendNode(head, p3);
    printList(head, printInteger);
    cout << endl;
    
    /*
     * Lista enlazada de Registros / Estructuras
     */
    head = createNode(employee1);
    head = appendNode(head, employee2);
    head = appendNode(head, employee3);
    head = appendNode(head, employee4);
    
    printList(head, printEmployee);
    cout << endl;
    
    delete p0;
    delete p1;
    delete p2;
    delete p3;
    
    delete[] employee1->name;
    delete[] employee1->title;
    delete employee1;
    
    delete[] employee2->name;
    delete[] employee2->title;
    delete employee2;
    
    delete[] employee3->name;
    delete[] employee3->title;
    delete employee3;
    
    delete[] employee4->name;
    delete[] employee4->title;
    delete employee4;
    
    return 0;
}

