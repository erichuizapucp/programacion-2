/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Person.h
 * Author: erichuiza
 *
 * Created on March 22, 2024, 1:10 PM
 */

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "MyString.h"

using namespace std;

struct Person {
    struct MyString Name;
    struct MyString LastName;
    struct MyString FullName;
    int age;
};

MyString getFullName(const struct Person&);
ostream& operator<< (ostream&, const struct Person&);


#endif /* PERSON_H */

