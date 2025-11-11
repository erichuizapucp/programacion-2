//
// Created by Eric Huiza on 11/10/25.
//

#include "ComparadorAlumnos.h"

ComparadorAlumnos::ComparadorAlumnos() {
    sortOrder = ascendente;
}
ComparadorAlumnos::ComparadorAlumnos(SortOrder sortOrder) {
    this->sortOrder = sortOrder;
}

bool ComparadorAlumnos::operator()(const AlumnoInfo& a, const AlumnoInfo& b) const {
    return sortOrder == ascendente ? a < b : a > b;
}