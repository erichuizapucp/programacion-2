/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 21, 2024, 10:16 AM
 */

#include <cstdlib>
#include "Persona.h"
#include "Estudiante.h"
#include <cstring>

using namespace std;

int main(int argc, char** argv) {
//    Persona* persona1 = new Persona("Juan Perez", 12345678, 20, 1.75, 70, "Peruano");
//    persona1->imprimir();
//    delete persona1;
//    
//    cout << endl;
//    
//    Persona persona2;
//    persona2.setDni(98765432);
//    persona2.setAltura(1.65);
//    persona2.setEdad(20);
//    persona2.setNombre("María Carranza");
//    persona2.setPeso(60);
//    persona2.setNacionalidad("Peruana");
//    persona2.imprimir();
    
    const char* curso1 = "Técnicas de programación 2";
    const char* curso2 = "Proceso de construcción de Software 1";
    const char* curso3 = "Economía";
    
    char** cursos = new char*[3];
    cursos[0] = new char[20];
    cursos[1] = new char[20];
    cursos[2] = new char[20];
    
    strcpy(cursos[0], curso1);
    strcpy(cursos[1], curso2);
    strcpy(cursos[2], curso3);
    
    Estudiante* estudiante1 = new Estudiante();
    estudiante1->setCodigo(20215678);
    estudiante1->setDni(98765432);
    estudiante1->setCarrera("Ingeniería Informática");
    estudiante1->setCategoria('B');
    estudiante1->setCursos(cursos);
    estudiante1->setEdad(21);
    estudiante1->setNombre("Rodrigo Torres");
    estudiante1->setAnnosEstudio(3);
    
    estudiante1->imprimir();
    
    cout << endl << endl;
    
    delete estudiante1;
    
    Estudiante* estudiante2 = new Estudiante(
        12345678, 
        20206758,
        "María Casas",
        "Ingeniería Informática", 
        3, 
        'A', 
        20, 
        cursos  
    );
    estudiante2->imprimir();
    
    delete estudiante2;
    
    return 0;
}

