/* 
 * File:   structs.h
 * Author: erichuiza
 *
 * Created on April 21, 2024, 10:52 AM
 */

#ifndef STRUCTS_H
#define STRUCTS_H

struct Node {
    void* data;
    struct Node* link;
};

struct Employee {
    int id;
    char* name;
    char* title;
    double salary;
};

#endif /* STRUCTS_H */

