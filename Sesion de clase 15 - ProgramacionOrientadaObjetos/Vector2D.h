/* 
 * File:   Vector2D.h
 * Author: erichuiza
 *
 * Created on May 6, 2024, 3:34 PM
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

using namespace std;

class Vector2D {
private:
    int x;
    int y;
public:
    Vector2D();
    Vector2D(int x, int y);
    
    int getX();
    int getY();
    
//    Vector2D operator+(Vector2D&);
    friend Vector2D operator+(Vector2D&, Vector2D&);
    friend ostream& operator<< (ostream&, Vector2D&);
    
    ~Vector2D();
};

#endif /* VECTOR2D_H */

