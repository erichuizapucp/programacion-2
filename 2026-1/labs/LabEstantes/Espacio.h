#ifndef LABESTANTES_ESPACIO_H
#define LABESTANTES_ESPACIO_H


class Espacio {
    char contenido;
    int posx;
    int posy;
public:
    Espacio();
    char getContenido() const;
    int getPosx() const;
    int getPosy() const;

    void setContenido(char);
    void setPosx(int);
    void setPosy(int);
};

#endif
