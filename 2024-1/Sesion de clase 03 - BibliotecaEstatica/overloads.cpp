/* 
 * File:   Date.cpp
 * Author: erichuiza
 *
 * Created on March 20, 2024, 9:36 PM
 */

#include <iostream>
#include "date.h"
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