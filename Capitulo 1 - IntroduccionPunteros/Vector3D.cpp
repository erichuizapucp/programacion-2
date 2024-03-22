#include "Vector3D.h"
#include <iostream>

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {
}

Vector3D::~Vector3D() {
}

Vector3D Vector3D::operator+(Vector3D& other) {
    Vector3D result;
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    
    return result;
}

void Vector3D::print() {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}