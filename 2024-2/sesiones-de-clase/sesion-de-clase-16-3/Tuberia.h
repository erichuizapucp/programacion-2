/* 
 * File:   Tuberia.h
 * Author: erichuiza
 *
 * Created on October 25, 2024, 4:10 PM
 */

#ifndef TUBERIA_H
#define TUBERIA_H

#include "Cilindro.h"

class Tuberia : public Cilindro { 
private:
    double radio2;
public:
    Tuberia();
    Tuberia(double radio, double altura, double radio2);
    Tuberia(const Tuberia& orig);
    
    double getRadio2() const;
    virtual double calcularArea() const;
    void imprimir(ostream&) const;
    void operator=(const Tuberia&);
    
    virtual ~Tuberia();
};

//ostream& operator<<(ostream&, const Tuberia&);

#endif /* TUBERIA_H */

