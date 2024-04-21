/* 
 * File:   genericlist.h
 * Author: erichuiza
 *
 * Created on April 21, 2024, 11:03 AM
 */

#ifndef GENERICLIST_H
#define GENERICLIST_H

#include "structs.h"
#include <iostream>
#include <iomanip>
#include <cstring>

struct Employee* createEmployee(
    int, 
    const char*, 
    const char*, 
    int
);
Node* createNode(
    void*
);
Node* appendNode(
    Node*, 
    void*
);
void printList(
    Node*, 
    void(*)(Node*)
);
void printEmployee(
    Node*
);
void printInteger(
    Node*
);

#endif /* GENERICLIST_H */

