#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Persona {
private:
    int dni;
    char *nombre;
    double sueldo;
public:
    Persona();
    Persona(const Persona&);
    virtual ~Persona();
    
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator =(const Persona&);
    bool operator ==(int);
    bool operator >(const Persona&) const;
    bool operator <(const Persona&) const;
    bool operator >(int);
};

ifstream& operator >>(ifstream&, Persona&);
ostream& operator <<(ostream&, const Persona&);

#endif /* PERSONA_H */

