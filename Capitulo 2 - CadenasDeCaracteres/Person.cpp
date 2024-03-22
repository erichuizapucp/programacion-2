#include "Person.h"

MyString getFullName(const struct Person& person) {
    MyString separator = { ", " };
    
    MyString sTemp = person.Name + separator;
    MyString sFullName = sTemp + person.LastName;
    
    delete[] sTemp.s;
    
    return sFullName;
}

ostream& operator<< (ostream& os, const struct Person& person) {
    os << "First Name: " << person.Name << endl;
    os << "Last Name: " << person.LastName << endl;
    os << "Full Name: " << person.FullName << endl;
    os << "Age: " << person.age;
    
    return os;
}