#ifndef INFRACCION_H
#define INFRACCION_H

#include <string>
#include "enumeraciones.h"
#include "Registro.h"
#include <map>

using namespace std;

class Infraccion : public Registro {
private:
    int codigo;
    string descripcion;
    double monto;
    GRAVEDAD_INFRACCION gravedad;
    int puntos;
    
    static map<string, GRAVEDAD_INFRACCION> infraccionMap;
public:
    Infraccion() = default;
    
    int getCodigo() const;
    void setCodigo(int);
    string getDescripcion() const;
    void setDescripcion(string);
    GRAVEDAD_INFRACCION getGravedad() const;
    void setGravedad(GRAVEDAD_INFRACCION);
    double getMonto() const;
    void setMonto(double);
    int getPuntos() const;
    void setPuntos(int);
    
    GRAVEDAD_INFRACCION leerGravedad(ifstream&);
    bool cargarDatos(ifstream&);
    void imprimir(ostream&) const;
    
    virtual ~Infraccion() = default;
};

#endif /* INFRACCION_H */

