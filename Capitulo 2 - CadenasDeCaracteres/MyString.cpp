
#include "MyString.h"
#include <cstring>

MyString operator+(const struct MyString& s1, const struct MyString& s2) {
    char* result = new char[strlen(s1.s) + strlen(s2.s) + 1];
    strcpy(result, s1.s);
    strcat(result, s2.s);
    
    MyString sResult { result };
    
    return sResult;
}

ostream& operator<< (ostream &os, const struct MyString &s) {
    os << s.s;
    return os;
}