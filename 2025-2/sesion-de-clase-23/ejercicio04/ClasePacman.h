//
// Created by Eric Huiza on 11/14/25.
//

#ifndef EJERCICIO04_CLASEPACMAN_H
#define EJERCICIO04_CLASEPACMAN_H


class ClasePacman {
private:
    static int puntaje;
public:
    ClasePacman();
    ClasePacman(const ClasePacman& orig);
    virtual ~ClasePacman();

    void incrementar();
    static void incrementarPuntaje();
};


#endif //EJERCICIO04_CLASEPACMAN_H