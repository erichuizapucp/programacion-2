//
// Created by Eric Huiza on 4/17/26.
//

#ifndef EJERCICIO01_ENUM_H
#define EJERCICIO01_ENUM_H

enum cpsPaciente {
    pacDni = 0,
    pacNombre = 1,
    pacEdad = 2,
    pacGenero = 3,
    pacCitas = 4,
    pacCancelaciones = 5,
    pacNumCampos = 6
};

enum cpsDoctor {
    docDni = 0,
    docNombre = 1,
    docEspecialidad = 2,
    docColaAtencion = 3,
    docNumCampos = 4
};

enum cpsCita {
    citaFecha = 0,
    citaHora = 1,
    citaDniDoctor = 2,
    citaEstado = 3,
    citaNumCampos = 4
};

enum cpsCancelacion {
    canFecha = 0,
    canHora = 1,
    canDniPaciente = 2,
    canDniDoctor = 3,
    canNumCampos = 4
};

enum cpsClinica {
    cliPacientes = 0,
    cliDoctores = 1,
    cliNumCampos = 2
};

#endif //EJERCICIO01_ENUM_H
