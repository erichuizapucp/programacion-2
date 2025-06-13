#include "Comparadores.h"
#include "Mesero.h"

bool OrdenaMeseroPorNombre::operator()(const Mesero& a, const Mesero& b) const {
    return a < b;
}

bool OrdenarMeseroPorExperiencia::operator()(
    const Mesero& a, const Mesero& b
) const {
    int expa = a.getExperiencia();
    int expb = b.getExperiencia();
    
    return expb < expa;
}