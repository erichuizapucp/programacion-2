/* 
 * File:   MyString.h
 * Author: erichuiza
 *
 * Created on March 22, 2024, 1:10 PM
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

struct MyString {
    const char* s;
};

MyString operator+(const struct MyString&, const struct MyString&);
ostream& operator<< (ostream&, const struct MyString&);

#endif /* MYSTRING_H */

