/* 
 * File:   clased.h
 * Author: erichuiza
 *
 * Created on May 10, 2024, 1:38 PM
 */

#ifndef CLASED_H
#define CLASED_H

#include "claseb.h"
#include "clasec.h"
#include <iostream>

using namespace std;

class ClaseD : public ClaseB, public ClaseC {
};

#endif /* CLASED_H */
