#include "Registro.h"

char* Registro::leerCadena(istream &archivo, char delim) { 
    char buffer[1000];
    archivo.getline(buffer, 1000, delim);
    
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    
    return cadena;
}
