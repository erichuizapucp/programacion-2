/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 22, 2024, 12:29 PM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "MyString.h"
#include "Person.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const char *str1 = "Hello World";
    const char *str2 = "Hello World";
    
    cout << "Are they equal? -> " << boolalpha << (strcmp(str1, str2) == 0) << endl;
    
    cout << endl;
    const char *str3 = "Hello World";
    char *substr = new char[7 + 1];
    
    strncpy(substr, str3 + 7, 2);
  
    cout << substr;
    delete[] substr;
    cout << endl;
    
    /*
     * Sin sobrecarga de operadores.
     */
    const char *name = "John";
    const char *lastName = ", Smith";
    char *fullName = new char[strlen(name) + strlen(lastName) + 1];
    
    strcpy(fullName, name);
    strcat(fullName, lastName);
    
    cout << fullName;
    
    delete[] fullName;
    
    cout << endl;
    
    /*
     * Con sobrecarga de operadores.
     */
    struct MyString sName = { "Peter" };
    struct MyString separator = { ", " };
    struct MyString sLastName = { "Simpson" };
    
    struct MyString sTemp = sName + separator;
    struct MyString sFullName = sTemp + sLastName;
    
    cout << "First Name: " << sName << endl;
    cout << "Last Name: " << sLastName << endl;
    cout << "Full Name: " << sFullName << endl;
    
    delete[] sTemp.s;
    delete[] sFullName.s;
    
    /*
     * Con estructura Persona
     */
    struct Person person = { "Michael", "Jackson", "", 60 };
    person.FullName = getFullName(person);
    cout << person;
    
    delete[] person.FullName.s;
    
    return 0;
}

