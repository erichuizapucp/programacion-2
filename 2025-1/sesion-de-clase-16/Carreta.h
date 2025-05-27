#ifndef CARRETA_H
#define CARRETA_H

class Carreta {
private:
    int cantRuedas;
    double peso;
    int capacidad;
    int caballos;
public:
    Carreta();
    Carreta(int, double, int, int);
    
    int getCaballos() const;
    void setCaballos(int caballos);

    int getCantRuedas() const;
    void setCantRuedas(int cantRuedas);

    int getCapacidad() const;
    void setCapacidad(int capacidad);

    double getPeso() const;
    void setPeso(double peso);
    
    Carreta(const Carreta& orig);
    virtual ~Carreta();
};

#endif /* CARRETA_H */

