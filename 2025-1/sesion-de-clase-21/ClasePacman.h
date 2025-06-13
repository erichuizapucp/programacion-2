/* 
 * File:   ClasePacman.h
 * Author: erichuiza
 *
 * Created on June 13, 2025, 5:55 PM
 */

#ifndef CLASEPACMAN_H
#define CLASEPACMAN_H

class ClasePacman {
private:
    static int puntaje;
public:
    ClasePacman();
    ClasePacman(const ClasePacman& orig);
    virtual ~ClasePacman();

    static void incrementarPuntaje();
};

#endif /* CLASEPACMAN_H */

