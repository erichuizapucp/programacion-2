cmake_minimum_required(VERSION 4.2)
project(ejercicio02)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio02 main.cpp
        funciones.cpp
        Registro.cpp
        Registro.h
        Persona.cpp
        Persona.h
        Clinica.cpp
        Clinica.h
        paciente/Paciente.cpp
        paciente/Paciente.h
        paciente/PacienteParticular.cpp
        paciente/PacienteParticular.h
        paciente/PacienteAsegurado.cpp
        paciente/PacienteAsegurado.h
        doctor/Doctor.cpp
        doctor/Doctor.h
        doctor/DoctorGeneral.cpp
        doctor/DoctorGeneral.h
        doctor/DoctorEspecialista.cpp
        doctor/DoctorEspecialista.h
        cita/Cita.cpp
        cita/Cita.h
        cita/CitaPresencial.cpp
        cita/CitaPresencial.h
        cita/CitaVirtual.cpp
        cita/CitaVirtual.h
        cita/Cita.cpp)
