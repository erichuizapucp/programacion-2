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
    char* nombre;
    double sueldo;
public: 
    Persona();
    Persona(const Persona&);
    virtual ~Persona();
    void SetSueldo(double);
    double GetSueldo() const;
    void SetNombre(const char*);
    void GetNombre(char*) const;
    void SetDni(int);
    int GetDni() const;
    void operator =(const class Persona&);
    bool operator ==(int);
    bool operator >(const Persona&);
};

ifstream& operator >>(ifstream&, Persona&);
ostream& operator <<(ostream&, const Persona&);

#endif /* PERSONA_H */
