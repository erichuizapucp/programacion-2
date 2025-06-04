/* 
 * File:   Ficha.h
 * Author: erichuiza
 *
 * Created on May 30, 2024, 9:21 PM
 */

#ifndef FICHA_H
#define FICHA_H

#include <fstream>

using namespace std;

class Ficha {
private:
    char *id;
    int fil;
    int col;
public:
    Ficha();
    virtual ~Ficha();
    void SetCol(int col);
    int GetCol() const;
    void SetFil(int fil);
    int GetFil() const;
    void SetId(const char* id);
    void GetId(char*) const;
    void asigna(char*, int, int);
    virtual void imprime(ofstream&) = 0;
    virtual void mover(char, int) = 0;
};

#endif /* FICHA_H */

