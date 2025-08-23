#include "funciones.h"

void cargarRedSocial(RedSocial& red) {
    Usuario pedro{
        "Pedro Torres",
        20,
        "pedro.torres@pucp.edu.pe",
        {},
        0 };
    Publicacion pubPedro {
        "Mi primer post",
        "Hola a todos! Esta es mi primera publicación en esta red social.",
        {},
        0 };

    Reaccion reaccionPedroPub1 {
        "¡Bienvenido a la red social, Pedro!",
        5 };
    Reaccion reaccionPedroPub2 {
        "No me gusta",
        2 };

    pubPedro += reaccionPedroPub1;
    pubPedro += reaccionPedroPub2;

    pedro += pubPedro;
    red += pedro;

    Usuario ana{
        "Ana Días",
        20,
        "ana.dias@pucp.edu.pe",
        {},
        0 };
    Publicacion pubAna {
        "Mi primer post",
        "Hola a todos! Esta es mi primera publicación en esta red social.",
        {},
        0 };

    Reaccion reaccionAnaPub1 {
        "¡Bienvenido a la red social, Ana!",
        4 };
    Reaccion reaccionAnaPub2 {
        "Bienvenida.",
        5 };

    pubAna += reaccionAnaPub1;
    pubAna += reaccionAnaPub2;

    ana += pubAna;
    red += ana;
}

RedSocial& operator+=(RedSocial& red, Usuario& usuario) {
    return agregar(red, usuario);
}

Usuario& operator+=(Usuario& usuario, Publicacion& publicacion) {

    return agregar(usuario, publicacion);
}

Publicacion& operator+=(Publicacion& publicacion, Reaccion& reaccion) {

    return agregar(publicacion, reaccion);
}

int operator~(Publicacion& publicacion) {
    int total = 0;

    for (int i = 0; i < publicacion.num; i++) {
        total += publicacion.elementos[i].rating;
    }

    return total / publicacion.num;
}

Reaccion& operator++(Reaccion& reaccion) {
    ++reaccion.rating;
    return reaccion;
}

Reaccion operator++(Reaccion& reaccion, int) {
    Reaccion tmp = reaccion;
    reaccion.rating++;
    return tmp;
}

Reaccion& operator--(Reaccion& reaccion) {
    --reaccion.rating;
    return reaccion;
}

Reaccion operator--(Reaccion& reaccion, int) {
    Reaccion tmp = reaccion;
    reaccion.rating--;
    return tmp;
}

bool operator>(Publicacion& p1, Publicacion& p2) {
    return ~p1 > ~p2;
}

bool operator>=(Publicacion& p1, Publicacion& p2) {
    return ~p1 >= ~p2;
}

bool operator<(Publicacion& p1, Publicacion& p2) {
    return ~p1 < ~p2;
}

bool operator<=(Publicacion& p1, Publicacion& p2) {
    return ~p1 <= ~p2;
}

ostream& operator<<(ostream& os, RedSocial& red) {
    os << "Red Social: ("
        << "Nro Usarios: "
        << red.num
        << ")"
        << red.nombre << endl;

    for (int i = 0; i < red.num; i++) {
        os << red.elementos[i] << endl;
    }

    return os;
}

ostream& operator<<(ostream& os, Usuario& usuario) {
    os << "Nombre: " << usuario.nombre << endl;
    os << "Edad: " << usuario.edad << endl;
    os << "Correo: " << usuario.correo << endl;

    for (int i = 0; i < usuario.num; i++) {
        os << usuario.elementos[i] << endl;
    }

    return os;
}

ostream& operator<<(ostream& os, Publicacion& publicacion) {
    os << "Nombre: " << publicacion.nombre << endl;
    os << "Contenido: " << publicacion.contenido << endl;

    for (int i = 0; i < publicacion.num; i++) {
        os << publicacion.elementos[i] << endl;
    }

    return os;
}

ostream& operator<<(ostream& os, Reaccion& reaccion) {
    os << "Comentario: " << reaccion.comentario << endl;
    os << "Rating: " << reaccion.rating << endl;

    return os;
}