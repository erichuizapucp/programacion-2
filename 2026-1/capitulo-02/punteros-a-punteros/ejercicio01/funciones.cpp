//
// Created by Eric Huiza on 3/26/26.
//

#include "funciones.h"

void cargarPacientes(const char* nombreArchivo, int**& pacientes,
    char**& nombresPacientes) {

    int num = 0, capacidad = 0;
    pacientes = nullptr;
    nombresPacientes = nullptr;

    int* paciente;
    char* nombre;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerPaciente(archivo, paciente, nombre)) {
        if (num == capacidad) {
            incrementarPacientes(pacientes, nombresPacientes, num, capacidad);
        }
        pacientes[num] = paciente;
        nombresPacientes[num] = nombre;
        num++;
    }

    pacientes[num] = nullptr;
    nombresPacientes[num] = nullptr;
}

void cargarDoctores(const char* nombreArchivo, int**& doctores, char**& nombresDoctores) {
    int num = 0, capacidad = 0;
    doctores = nullptr;
    nombresDoctores = nullptr;

    int* doctor;
    char* nombre;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerDoctor(archivo, doctor, nombre)) {
        if (num == capacidad) {
            incrementarDoctores(doctores, nombresDoctores, num, capacidad);
        }
        doctores[num] = doctor;
        nombresDoctores[num] = nombre;
        num++;
    }

    doctores[num] = nullptr;
    nombresDoctores[num] = nullptr;
}

void cargarCitas(const char* nombreArchivo, int***& citas) {
    int num = 0, capacidad = 0;
    citas = nullptr;

    int** cita;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerCita(archivo, cita)) {
        if (num == capacidad) {
            incrementarCitas(citas, num, capacidad);
        }
        citas[num] = cita;
        num++;
    }

    citas[num] = nullptr;
}

void cargarCancelaciones(const char* nombreArchivo, int***& cancelaciones) {
    int num = 0, capacidad = 0;
    cancelaciones = nullptr;

    int** cancelacion;
    ifstream archivo(nombreArchivo, ios::in);

    while (leerCancelacion(archivo, cancelacion)) {
        if (num == capacidad) {
            incrementarCancelaciones(cancelaciones, num, capacidad);
        }
        cancelaciones[num] = cancelacion;
        num++;
    }

    cancelaciones[num] = nullptr;
}

void incrementarPacientes(int**& pacientes, char**& nombresPacientes, int num, int& capacidad) {
    capacidad += 5;

    if (pacientes == nullptr) {
        pacientes = new int*[capacidad + 1] {};
        nombresPacientes = new char*[capacidad + 1] {};
    }
    else {
        int** auxPacientes = new int*[capacidad + 1] {};
        char** auxNombres = new char*[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            auxPacientes[i] = pacientes[i];
            auxNombres[i] = nombresPacientes[i];
        }
        delete[] pacientes;
        delete[] nombresPacientes;
        pacientes = auxPacientes;
        nombresPacientes = auxNombres;
    }
}

void incrementarDoctores(int**& doctores, char**& nombresDoctores, int num, int& capacidad) {
    capacidad += 5;

    if (doctores == nullptr) {
        doctores = new int*[capacidad + 1] {};
        nombresDoctores = new char*[capacidad + 1] {};
    }
    else {
        int** auxDoctores = new int*[capacidad + 1] {};
        char** auxNombres = new char*[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            auxDoctores[i] = doctores[i];
            auxNombres[i] = nombresDoctores[i];
        }
        delete[] doctores;
        delete[] nombresDoctores;
        doctores = auxDoctores;
        nombresDoctores = auxNombres;
    }
}

void incrementarCitas(int***& citas, int num, int& capacidad) {
    capacidad += 5;

    if (citas == nullptr) {
        citas = new int**[capacidad + 1] {};
    }
    else {
        int*** aux = new int**[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = citas[i];
        }
        delete[] citas;
        citas = aux;
    }
}

void incrementarCancelaciones(int***& cancelaciones, int num, int& capacidad) {
    capacidad += 5;

    if (cancelaciones == nullptr) {
        cancelaciones = new int**[capacidad + 1] {};
    }
    else {
        int*** aux = new int**[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = cancelaciones[i];
        }
        delete[] cancelaciones;
        cancelaciones = aux;
    }
}

bool leerPaciente(ifstream& archivo, int*& paciente, char*& nombre) {
    int dni;
    if (!(archivo >> dni)) {
        return false;
    }

    archivo.ignore();
    nombre = leerCadena(archivo);

    int edad;
    archivo >> edad;
    archivo.ignore();

    char genero;
    archivo >> genero;
    if (archivo.peek() == '\n') archivo.get();

    paciente = new int[3]{dni, edad, (int)genero};
    return true;
}

bool leerDoctor(ifstream& archivo, int*& doctor, char*& nombre) {
    int dni;
    if (!(archivo >> dni)) {
        return false;
    }

    archivo.ignore();
    nombre = leerCadena(archivo);

    int especialidad;
    archivo >> especialidad;
    if (archivo.peek() == '\n') archivo.get();

    doctor = new int[2]{dni, especialidad};
    return true;
}

bool leerCita(ifstream& archivo, int**& cita) {
    int anho;
    if (!(archivo >> anho)) {
        return false;
    }

    archivo.ignore();
    int mes, dia;
    archivo >> mes;
    archivo.ignore();
    archivo >> dia;
    int fecha = anho * 10000 + mes * 100 + dia;

    archivo.ignore();
    int hora, minuto;
    archivo >> hora;
    archivo.ignore();
    archivo >> minuto;
    int horaCompleta = hora * 100 + minuto;

    archivo.ignore();
    int dniPaciente, dniDoctor;
    archivo >> dniPaciente;
    archivo.ignore();
    archivo >> dniDoctor;
    archivo.ignore();

    int estado;
    archivo >> estado;
    if (archivo.peek() == '\n') archivo.get();

    cita = new int*[3];
    cita[0] = new int[2]{fecha, horaCompleta};
    cita[1] = new int[2]{dniPaciente, dniDoctor};
    cita[2] = new int[1]{estado};
    return true;
}

bool leerCancelacion(ifstream& archivo, int**& cancelacion) {
    int anho;
    if (!(archivo >> anho)) {
        return false;
    }

    archivo.ignore();
    int mes, dia;
    archivo >> mes;
    archivo.ignore();
    archivo >> dia;
    int fecha = anho * 10000 + mes * 100 + dia;

    archivo.ignore();
    int hora, minuto;
    archivo >> hora;
    archivo.ignore();
    archivo >> minuto;
    int horaCompleta = hora * 100 + minuto;

    archivo.ignore();
    int dniPaciente, dniDoctor;
    archivo >> dniPaciente;
    archivo.ignore();
    archivo >> dniDoctor;
    if (archivo.peek() == '\n') archivo.get();

    cancelacion = new int*[1];
    cancelacion[0] = new int[4]{fecha, horaCompleta, dniPaciente, dniDoctor};
    return true;
}

bool esMismaCita(int** cita, int fecha, int hora, int dniPaciente, int dniDoctor) {
    int* fechaHora = cita[0];
    int* dniPacienteDoctor = cita[1];

    return fechaHora[0] == fecha and fechaHora[1] == hora and
           dniPacienteDoctor[0] == dniPaciente and dniPacienteDoctor[1] == dniDoctor;
}

char* leerCadena(ifstream& archivo, char separador) {
    char buffer[256];
    archivo.getline(buffer, 256, separador);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

bool citaMenor(int** cita1, int** cita2) {
    int* fechaHora1 = cita1[0];
    int* fechaHora2 = cita2[0];

    int fecha1 = fechaHora1[0];
    int hora1 = fechaHora1[1];
    int fecha2 = fechaHora2[0];
    int hora2 = fechaHora2[1];

    if (fecha1 == fecha2) {
        return hora1 < hora2;
    }
    return fecha1 < fecha2;
}

void cancelarCita(int**& cita) {
    int* estadoPacienteDoctor = cita[2];
    estadoPacienteDoctor[0] = 0;
}

int** obtenerCitaPorCriterio(int*** citas, int* criterio) {
    int fecha = criterio[0];
    int hora = criterio[1];
    int dniPaciente = criterio[2];
    int dniDoctor = criterio[3];

    for (int i = 0; citas[i]; i++) {
        int** cita = citas[i];
        if (esMismaCita(cita, fecha, hora, dniPaciente, dniDoctor)) {
            return cita;
        }
    }
    return nullptr;
}

void cancelarCitas(int*** cancelaciones, int*** citas) {
    for (int i = 0; cancelaciones[i]; i++) {
        int** cancelacion = cancelaciones[i];
        int* criterio = cancelacion[0];

        int** cita = obtenerCitaPorCriterio(citas, criterio);
        if (cita != nullptr) {
            cancelarCita(cita);
        }
    }
}

int obtenerIndicePacientePorDni(int dni, int** pacientes) {
    for (int i = 0; pacientes[i]; i++) {
        int* paciente = pacientes[i];
        int dniPaciente = paciente[0];
        if (dniPaciente == dni) return i;
    }
    return -1;
}

int obtenerIndiceDoctorPorDni(int dni, int** doctores) {
    for (int i = 0; doctores[i]; i++) {
        int* doctor = doctores[i];
        int dniDoctor = doctor[0];
        if (dniDoctor == dni) return i;
    }
    return -1;
}

void insertarOrdenado(int*** citas, int& numCitas, int** nuevaCita) {
    int i;
    for (i = numCitas - 1; i >= 0; i--) {
        if (citaMenor(citas[i], nuevaCita)) {
            break;
        }
        citas[i + 1] = citas[i];
    }
    citas[i + 1] = nuevaCita;
    numCitas++;
}

ostream& operator<<(ostream& os, int** cita) {
    int* fechaHora = cita[0];
    int* estadoPacienteDoctor = cita[2];

    int fecha = fechaHora[0];
    int hora = fechaHora[1];
    int estado = estadoPacienteDoctor[0];

    os << "Fecha: ";
    imprimirFecha(os, fecha);
    os << " ";
    imprimirHora(os, hora);
    os << " ";
    imprimirEstado(os, estado);
    return os;
}

ostream& operator<<(ostream& os, int*** citas) {
    for (int i = 0; citas[i]; i++) {
        os << citas[i] << endl;
    }
    return os;
}

void imprimirReporte(ofstream& archivo, int*** citas,
        int** pacientes, char** nombresPacientes,
        int** doctores, char** nombresDoctores) {
    for (int i = 0; citas[i]; i++) {
        int** cita = citas[i];
        int* fechaHora = cita[0];
        int* dniPacienteDoctor = cita[1];
        int* estadoPacienteDoctor = cita[2];

        int fecha = fechaHora[0];
        int hora = fechaHora[1];
        int estado = estadoPacienteDoctor[0];
        int dniPaciente = dniPacienteDoctor[0];
        int dniDoctor = dniPacienteDoctor[1];

        imprimirCita(archivo, fecha, hora, estado);

        int idxPaciente = obtenerIndicePacientePorDni(dniPaciente, pacientes);
        if (idxPaciente >= 0) {
            int* paciente = pacientes[idxPaciente];
            char* nombrePaciente = nombresPacientes[idxPaciente];
            imprimirPaciente(archivo, paciente, nombrePaciente);
        } else {
            imprimirPaciente(archivo, nullptr, nullptr);
        }

        int idxDoctor = obtenerIndiceDoctorPorDni(dniDoctor, doctores);
        if (idxDoctor >= 0) {
            int* doctor = doctores[idxDoctor];
            char* nombreDoctor = nombresDoctores[idxDoctor];
            imprimirDoctor(archivo, doctor, nombreDoctor);
        }

        archivo << "------------------------------" << endl;
        archivo << "==============================" << endl << endl;
    }
}

void imprimirCita(ofstream& archivo, int fecha, int hora, int estado) {
    archivo << "==============================" << endl;
    archivo << "DATOS DEL CITA" << endl;
    archivo << "------------------------------" << endl;
    imprimirFecha(archivo, fecha);
    imprimirHora(archivo, hora);
    imprimirEstado(archivo, estado);
    archivo << endl;
    archivo << "------------------------------" << endl;
    archivo << "DATOS DEL PACIENTE" << endl;
    archivo << "------------------------------" << endl;
}

void imprimirPaciente(ofstream& archivo, int* paciente, const char* nombrePaciente) {
    if (paciente != nullptr && nombrePaciente != nullptr) {
        int dniPaciente = paciente[0];
        int edadPaciente = paciente[1];
        char generoPaciente = (char)paciente[2];

        archivo << "DNI: " << dniPaciente << endl;
        archivo << "Nombre: " << nombrePaciente << endl;
        archivo << "Edad: " << edadPaciente << endl;
        archivo << "Genero: " << generoPaciente << endl;
    }
    archivo << "------------------------------" << endl;
    archivo << "DATOS DEL DOCTOR" << endl;
    archivo << "------------------------------" << endl;
}

void imprimirDoctor(ofstream& archivo, int* doctor, const char* nombreDoctor) {
    int dniDoctor = doctor[0];
    int especialidadDoctor = doctor[1];

    archivo << "DNI: " << dniDoctor << endl;
    archivo << "Nombre: " << nombreDoctor << endl;
    imprimirEspecialidad(archivo, especialidadDoctor);
}


void imprimirFecha(ostream& os, int fecha) {
    int anho = fecha / 10000;
    int mes = (fecha / 100) % 100;
    int dia = fecha % 100;

    os << "Fecha: " << anho << "-";
    if (mes < 10) {
        os << "0";
    }
    os << mes << "-";
    if (dia < 10) {
        os << "0";
    }
    os << dia << endl;
}

void imprimirHora(ostream& os, int hora) {
    int horas = hora / 100;
    int minutos = hora % 100;

    os << "Hora: ";
    if (horas < 10) {
        os << "0";
    }
    os << horas << ":";
    if (minutos < 10) {
        os << "0";
    }
    os << minutos << endl;
}

void imprimirEstado(ostream& os, int estado) {
    if (estado == 1) {
        os << "Estado: RESERVADA" << endl;
    }
    else if (estado == 0) {
        os << "Estado: CANCELADA" << endl;
    }
    else {
        os << "Estado: NA" << endl;
    }
}

void imprimirEspecialidad(ostream& os, int especialidad) {
    switch (especialidad) {
        case 0: os << "Especialidad: CARDIOLOGIA" << endl; break;
        case 1: os << "Especialidad: DERMATOLOGIA" << endl; break;
        case 2: os << "Especialidad: NEUROLOGIA" << endl; break;
        case 3: os << "Especialidad: PEDIATRIA" << endl; break;
        case 4: os << "Especialidad: PSIQUIATRIA" << endl; break;
        case 5: os << "Especialidad: TRAUMATOLOGIA" << endl; break;
        case 6: os << "Especialidad: ENDOCRINOLOGIA" << endl; break;
        case 7: os << "Especialidad: GINECOLOGIA" << endl; break;
        case 8: os << "Especialidad: PSICOLOGIA" << endl; break;
        case 9: os << "Especialidad: ORTOPEDIA" << endl; break;
        default: os << "Especialidad: GENERAL" << endl; break;
    }
}

void liberarPacientes(int**& pacientes, char**& nombresPacientes) {
    if (pacientes == nullptr) return;

    for (int i = 0; pacientes[i]; i++) {
        int* paciente = pacientes[i];
        char* nombrePaciente = nombresPacientes[i];

        delete[] paciente;
        delete[] nombrePaciente;
    }

    delete[] pacientes;
    delete[] nombresPacientes;

    pacientes = nullptr;
    nombresPacientes = nullptr;
}

void liberarDoctores(int**& doctores, char**& nombresDoctores) {
    if (doctores == nullptr) return;

    for (int i = 0; doctores[i]; i++) {
        int* doctor = doctores[i];
        char* nombreDoctor = nombresDoctores[i];

        delete[] doctor;
        delete[] nombreDoctor;
    }

    delete[] doctores;
    delete[] nombresDoctores;

    doctores = nullptr;
    nombresDoctores = nullptr;
}

void liberarCitas(int***& citas) {
    if (citas == nullptr) return;

    for (int i = 0; citas[i]; i++) {
        int** cita = citas[i];
        int* fechaHora = cita[0];
        int* dniPacienteDoctor = cita[1];
        int* estadoPacienteDoctor = cita[2];

        delete[] fechaHora;
        delete[] dniPacienteDoctor;
        delete[] estadoPacienteDoctor;
        delete[] cita;
    }

    delete[] citas;
    citas = nullptr;
}

void liberarCancelaciones(int***& cancelaciones) {
    if (cancelaciones == nullptr) return;

    for (int i = 0; cancelaciones[i]; i++) {
        int** cancelacion = cancelaciones[i];
        int* criterio = cancelacion[0];
        delete[] criterio;
        delete[] cancelacion;
    }

    delete[] cancelaciones;
    cancelaciones = nullptr;
}
