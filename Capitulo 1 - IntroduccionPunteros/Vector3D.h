#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
public:
    Vector3D(double x=0.0, double y=0.0, double z=0.0);
    Vector3D operator+(Vector3D&);
    void print();
    virtual ~Vector3D();
private:
    double x;
    double y;
    double z;
};

#endif /* VECTOR3D_H */

