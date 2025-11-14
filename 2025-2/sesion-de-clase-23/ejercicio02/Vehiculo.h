#ifndef VEHICULO_H
#define VEHICULO_H

#include "Registro.h"

using namespace std;

class Vehiculo : public Registro {
private:
    int codigo;
    string placa;
    string marca;
    string modelo;
    int anho;
public:
    Vehiculo() = default;
    
    bool cargarDatos(ifstream&);
    void imprimir(ostream&) const;
    
    int getAnho() const;
    void setAnho(int);
    int getCodigo() const;
    void setCodigo(int);
    string getMarca() const;
    void setMarca(string);
    string getModelo() const;
    void setModelo(string);
    string getPlaca() const;
    void setPlaca(string);
    
    virtual ~Vehiculo() = default;
};

#endif /* VEHICULO_H */

