#ifndef LICENCIA_H
#define LICENCIA_H

#include <string>
#include "Registro.h"

using namespace std;

class Licencia : public Registro {
private:
    int codigo;
    string nombre;
    string descripcion;
public:
    Licencia() = default;
    
    int getCodigo() const;
    void setCodigo(int);
    string getDescripcion() const;
    void setDescripcion(string);
    string getNombre() const;
    void setNombre(string);
    
    bool cargarDatos(ifstream&);
    void imprimir(ostream&) const;
    
    virtual ~Licencia() = default;
};

#endif /* LICENCIA_H */

