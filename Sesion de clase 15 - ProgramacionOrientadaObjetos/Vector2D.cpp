#include "Vector2D.h"

Vector2D::Vector2D() : x(0), y(0) {
}

Vector2D::Vector2D(int x, int y) : x(x), y(y) {
}

Vector2D Vector2D::operator+(Vector2D &other) {
    Vector2D result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    
    return result;
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