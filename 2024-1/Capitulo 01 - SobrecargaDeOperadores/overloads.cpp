/* 
 * File:   Date.cpp
 * Author: erichuiza
 *
 * Created on March 20, 2024, 9:36 PM
 */

#include <iostream>
#include "date.h"
#include "fraction.h"
#include "overloads.h"

using namespace std;

bool operator==(const struct Date& date, const struct Date& other) {
    return date.day == other.day 
            && date.month == other.month
            && date.year == other.year;
}

bool operator!=(const struct Date& date, const struct Date& other) {
    return !(date == other);
}

bool operator<(const struct Date& date, const struct Date& other) {
    if (date.year != other.year) {
        return date.year < other.year;
    }
    
    if (date.month != other.month) {
        return date.month < other.month;
    }
    
    return date.day < other.day;
}

bool operator>(const struct Date& date, const struct Date& other) {
    return other < date;
}

bool operator<=(const struct Date& date, const struct Date& other) {
    return !(date > other);
}

bool operator>=(const struct Date& date, const struct Date& other) {
    return !(date < other);
}

ostream& operator<<(ostream& os, const struct Date& date) {
    os << date.day << "/" << date.month <<  "/" << date.year;
    return os;
}

Vector3D operator+(const struct Vector3D& vector, const struct Vector3D& other) {
    struct Vector3D result;
    result.x = vector.x + other.x;
    result.y = vector.y + other.y;
    result.z = vector.z + other.z;
    
    return result;
}

ostream& operator<<(ostream& os, const struct Vector3D& vector) {
    os << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
    return os;
}

Fraction operator+  (const struct Fraction& f1, const struct Fraction& f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    simplify(result);
    return result;
}

Fraction operator-  (const struct Fraction& f1, const struct Fraction& f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    simplify(result);
    return result;
}

Fraction operator*  (const struct Fraction& f1, const struct Fraction& f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    simplify(result);
    return result;
}

Fraction operator/  (const struct Fraction& f1, const struct Fraction& f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    simplify(result);
    return result;
}

ostream& operator<< (ostream& os, const struct Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}