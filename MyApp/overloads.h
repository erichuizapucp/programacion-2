/* 
 * File:   overloads.h
 * Author: erichuiza
 *
 * Created on March 20, 2024, 10:45 PM
 */

#ifndef OVERLOADS_H
#define OVERLOADS_H

#include "date.h"
#include "vector3d.h"
#include "fraction.h"

using namespace std;

bool operator==     (const struct Date&, const struct Date&);
bool operator!=     (const struct Date&, const struct Date&);
bool operator<      (const struct Date&, const struct Date&);
bool operator>      (const struct Date&, const struct Date&);
bool operator<=     (const struct Date&, const struct Date&);
bool operator>=     (const struct Date&, const struct Date&);
ostream& operator<< (ostream&, const struct Date&);

Vector3D operator+      (const struct Vector3D&, const struct Vector3D&);
bool operator>(const Vector3D&, const Vector3D&);
bool operator<(const Vector3D&, const Vector3D&);
bool operator==(const Vector3D&, const Vector3D&);
bool operator>=(const Vector3D&, const Vector3D&);
bool operator<=(const Vector3D&, const Vector3D&);
ostream& operator<< (ostream&, const struct Vector3D&);

Fraction operator+  (const struct Fraction&, const struct Fraction&);
Fraction operator-  (const struct Fraction&, const struct Fraction&);
Fraction operator*  (const struct Fraction&, const struct Fraction&);
Fraction operator/  (const struct Fraction&, const struct Fraction&);
ostream& operator<< (ostream&, const struct Fraction&);

#endif /* OVERLOADS_H */

