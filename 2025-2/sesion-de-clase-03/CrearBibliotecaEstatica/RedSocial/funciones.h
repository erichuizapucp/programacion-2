//
// Created by Eric Huiza on 8/21/25.
//

#ifndef SESION_DE_CLASE_02_FUNCIONES_H
#define SESION_DE_CLASE_02_FUNCIONES_H

#include <iostream>
#include "estructuras.h"

using namespace std;

// carga de datos de la red social (paso por referencia)
void cargarRedSocial(RedSocial&);

/*
 * Sobrecarga del operador += para agregar elementos a las estructuras
 * Estructoras soportadas:
 * - RedSocial: Agrega un Usuario a la red social.
 * - Usuario: Agrega una Publicacion al usuario.
 * - Publicacion: Agrega una Reaccion a la publicacion.
 * Uso:
 *      red += usuario;
 *      usuario += publicacion;
 *      publicacion += reaccion;
 */
RedSocial& operator+=(RedSocial&, Usuario&);
Usuario& operator+=(Usuario&, Publicacion&);
Publicacion& operator+=(Publicacion&, Reaccion&);

/*
 * Sobrecarga del operador ~ para calcular el rating total de una Publicacion
 * Uso:
 *      int totalRating = ~publicacion;
 */
int operator~(Publicacion&);

/*
 * Sobrecarga de operadores para incrementar o decrementar el rating de una Reaccion
 * Uso:
 *     reaccion++;
 *     reaccion--;
 *     --reaccion;
 *     ++reaccion;
 */
Reaccion& operator++(Reaccion&);
Reaccion operator++(Reaccion&, int);
Reaccion& operator--(Reaccion&);
Reaccion operator--(Reaccion&, int);

/*
 * Sobrecarga de operadores de comparación para comparar las estructuras
 * Estructuras soportadas:
 * - Publicacion: Compara por el raiting.
 * Uso:
 *      if (publicacion1 > publicacion2) { ... }
 *      if (publicacion1 >= publicacion2) { ... }
 *      if (publicacion1 < publicacion2) { ... }
 *      if (publicacion1 <= publicacion2) { ... }
 */
bool operator>(Publicacion&, Publicacion&);
bool operator>=(Publicacion&, Publicacion&);
bool operator<(Publicacion&, Publicacion&);
bool operator<=(Publicacion&, Publicacion&);

/*
 * Sobrecarga del operador << para imprimir las estructuras principales
 * de la red social en un formato legible a través de ostream.
 *
 * Estructuras soportadas:
 *  - RedSocial
 *  - Usuario
 *  - Reaccion
 *  - Publicacion
 *  Uso:
 *      cout << redSocial;
 *      cout << usuario;
 *      cout << reaccion;
 *      cout << publicacion;
 */
ostream& operator<<(ostream&, RedSocial&);
ostream& operator<<(ostream&, Usuario&);
ostream& operator<<(ostream&, Publicacion&);
ostream& operator<<(ostream&, Reaccion&);

Usuario& getUsuario(RedSocial&, int);
Publicacion& getPublicacion(Usuario&, int);
Reaccion& getReaccion(Publicacion&, int);

#endif //SESION_DE_CLASE_02_FUNCIONES_H