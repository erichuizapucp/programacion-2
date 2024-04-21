/* 
 * File:   overloads.h
 * Author: erichuiza
 *
 * Created on March 20, 2024, 10:45 PM
 */

#ifndef OVERLOADS_H
#define OVERLOADS_H

#include "date.h"

using namespace std;

bool operator==     (const struct Date&, const struct Date&);
bool operator!=     (const struct Date&, const struct Date&);
bool operator<      (const struct Date&, const struct Date&);
bool operator>      (const struct Date&, const struct Date&);
bool operator<=     (const struct Date&, const struct Date&);
bool operator>=     (const struct Date&, const struct Date&);
ostream& operator<< (ostream&, const struct Date&);

#endif /* OVERLOADS_H */

