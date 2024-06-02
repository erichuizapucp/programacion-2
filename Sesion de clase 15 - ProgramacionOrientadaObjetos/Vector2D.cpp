#include "Vector2D.h"

Vector2D::Vector2D() : x(0), y(0) {
}

Vector2D::Vector2D(int x, int y) : x(x), y(y) {
}

//Vector2D Vector2D::operator+(Vector2D &other) {
//    Vector2D result;
//    result.x = this->x + other.x;
//    result.y = this->y + other.y;
//    
//    return result;
//}

Vector2D operator+(Vector2D &vec1, Vector2D &vec2) {
    Vector2D vec3;
    vec3.x = vec1.x + vec2.x;
    vec3.y = vec1.y + vec2.y;
    
    return vec3;
}

ostream& operator<< (ostream &os, Vector2D &vec) {
    os << "(" << vec.x << ", " << vec.y << ")" << endl;
    return os;
}

int Vector2D::getX() {
    return x;
}

int Vector2D::getY() {
    return y;
}

Vector2D::~Vector2D() {
    cout << "El objeto se destruye" << endl;
}