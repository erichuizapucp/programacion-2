//
// Created by Eric Huiza on 10/20/25.
//

#ifndef SESION_DE_CLASE_17_CIRCULO_H
#define SESION_DE_CLASE_17_CIRCULO_H

using namespace std;

class Circulo {
protected:
    double pi;
    double radio;
public:
    Circulo();
    Circulo(double);
    Circulo(const Circulo &);

    // double getPi() const;
    // double getRadio() const;

    double calcularArea() const;
    double calcularPerimetro() const;

    ~Circulo();
};


#endif //SESION_DE_CLASE_17_CIRCULO_H