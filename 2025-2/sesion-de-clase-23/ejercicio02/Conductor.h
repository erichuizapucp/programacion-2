#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Registro.h"
#include "Licencia.h"


using namespace std;

class Conductor : public Registro {
private:
    int codigo;
    string nombres;
    string apellidoPaterno;
    string apellidoMaterno;
    string numLicencia;
    int codigoLicencia;
    Licencia licencia;
    int puntos;
public:
    Conductor() = default;

    string getApellidoMaterno() const;
    void setApellidoMaterno(string);
    string getApellidoPaterno() const;
    void setApellidoPaterno(string);
    int getCodigo() const;
    void setCodigo(int codigo);
    int getCodigoLicencia() const;
    void setCodigoLicencia(int);
    Licencia getLicencia() const;
    void setLicencia(Licencia);
    string getNombres() const;
    void setNombres(string);
    string getNumLicencia() const;
    void setNumLicencia(string);
    int getPuntos() const;
    void setPuntos(int puntos);
    
    bool cargarDatos(ifstream&);
    void imprimir(ostream&) const;
    
    bool operator<(const Conductor&) const;
    
    virtual ~Conductor() = default;
};

#endif /* CONDUCTOR_H */

