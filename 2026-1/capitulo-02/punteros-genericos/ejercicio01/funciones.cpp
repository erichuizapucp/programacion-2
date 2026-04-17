//
// Created by Eric Huiza on 3/26/26.
//

#include "funciones.h"

void cargarDatos(void*& clinica,
        const char* archivoPacientes,
        const char* archivoDoctores,
        const char* archivoCitas,
        const char* archivoCancelaciones) {

    void* pacientes;
    void* doctores;

    cargarPacientes(archivoPacientes, pacientes);
    cargarDoctores(archivoDoctores, doctores);

    clinica = new void*[cliNumCampos] {};
    void** regClinica = (void**)clinica;
    regClinica[cliPacientes] = pacientes;
    regClinica[cliDoctores] = doctores;

    cargarCitas(archivoCitas, clinica);
    cargarCancelaciones(archivoCancelaciones, clinica);
}

void cargarPacientes(const char* nombreArchivo, void*& pacientes) {
    ifstream archivo(nombreArchivo, ios::in);
    void** registros = nullptr;
    int num = 0, capacidad = 0;
    void* paciente;

    while (leerPaciente(archivo, paciente)) {
        if (num == capacidad) {
            incrementarCapacidad(registros, num, capacidad);
        }
        registros[num++] = paciente;
    }

    if (registros == nullptr) registros = new void*[1] {};
    else registros[num] = nullptr;
    pacientes = registros;
}

void cargarDoctores(const char* nombreArchivo, void*& doctores) {
    ifstream archivo(nombreArchivo, ios::in);
    void** registros = nullptr;
    int num = 0, capacidad = 0;
    void* doctor;

    while (leerDoctor(archivo, doctor)) {
        if (num == capacidad) {
            incrementarCapacidad(registros, num, capacidad);
        }
        registros[num++] = doctor;
    }

    if (registros == nullptr) registros = new void*[1] {};
    else registros[num] = nullptr;
    doctores = registros;
}

void cargarCitas(const char* nombreArchivo, void* clinica) {
    void** regClinica = (void**)clinica;
    void* pacientes = regClinica[cliPacientes];

    ifstream archivo(nombreArchivo, ios::in);
    void* cita;
    int dniPaciente;

    while (leerCita(archivo, cita, dniPaciente)) {
        void** paciente = (void**)buscarPaciente(dniPaciente, pacientes);
        if (paciente != nullptr) {
            void** citasPaciente = (void**)paciente[pacCitas];
            agregarRegistroExacto(citasPaciente, cita);
            paciente[pacCitas] = citasPaciente;
        }
        else {
            void** regCita = (void**)cita;
            delete (int*)regCita[citaFecha];
            delete (int*)regCita[citaHora];
            delete (int*)regCita[citaDniDoctor];
            delete (int*)regCita[citaEstado];
            delete[] regCita;
        }
    }
}

void cargarCancelaciones(const char* nombreArchivo, void* clinica) {
    void** regClinica = (void**)clinica;
    void* pacientes = regClinica[cliPacientes];

    ifstream archivo(nombreArchivo, ios::in);
    void* cancelacion;
    int dniPaciente;

    while (leerCancelacion(archivo, cancelacion, dniPaciente)) {
        void** paciente = (void**)buscarPaciente(dniPaciente, pacientes);
        if (paciente != nullptr) {
            void** cancelacionesPaciente = (void**)paciente[pacCancelaciones];
            agregarRegistroExacto(cancelacionesPaciente, cancelacion);
            paciente[pacCancelaciones] = cancelacionesPaciente;
        }
        else {
            void** regCancelacion = (void**)cancelacion;
            delete (int*)regCancelacion[canFecha];
            delete (int*)regCancelacion[canHora];
            delete (int*)regCancelacion[canDniPaciente];
            delete (int*)regCancelacion[canDniDoctor];
            delete[] regCancelacion;
        }
    }
}

bool leerPaciente(ifstream& archivo, void*& paciente) {
    int dni;
    if (!(archivo >> dni)) return false;

    archivo.ignore();
    char* nombre = leerCadena(archivo);

    int edad;
    archivo >> edad;
    archivo.ignore();

    char genero;
    archivo >> genero;
    if (archivo.peek() == '\n') archivo.get();

    void** reg = new void*[pacNumCampos] {};
    reg[pacDni] = new int(dni);
    reg[pacNombre] = nombre;
    reg[pacEdad] = new int(edad);
    reg[pacGenero] = new char(genero);
    reg[pacCitas] = nullptr;
    reg[pacCancelaciones] = nullptr;

    paciente = reg;
    return true;
}

bool leerDoctor(ifstream& archivo, void*& doctor) {
    int dni;
    if (!(archivo >> dni)) return false;

    archivo.ignore();
    char* nombre = leerCadena(archivo);

    int especialidad;
    archivo >> especialidad;
    if (archivo.peek() == '\n') archivo.get();

    void** reg = new void*[docNumCampos];
    reg[docDni] = new int(dni);
    reg[docNombre] = nombre;
    reg[docEspecialidad] = new int(especialidad);

    doctor = reg;
    return true;
}

bool leerCita(ifstream& archivo, void*& cita, int& dniPaciente) {
    int anho;
    if (!(archivo >> anho)) return false;

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
    int dniDoctor;
    archivo >> dniPaciente;
    archivo.ignore();
    archivo >> dniDoctor;
    archivo.ignore();

    int estado;
    archivo >> estado;
    if (archivo.peek() == '\n') archivo.get();

    void** reg = new void*[citaNumCampos];
    reg[citaFecha] = new int(fecha);
    reg[citaHora] = new int(horaCompleta);
    reg[citaDniDoctor] = new int(dniDoctor);
    reg[citaEstado] = new int(estado);

    cita = reg;
    return true;
}

bool leerCancelacion(ifstream& archivo, void*& cancelacion, int& dniPaciente) {
    int anho;
    if (!(archivo >> anho)) return false;

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
    int dniDoctor;
    archivo >> dniPaciente;
    archivo.ignore();
    archivo >> dniDoctor;
    if (archivo.peek() == '\n') archivo.get();

    void** reg = new void*[canNumCampos];
    reg[canFecha] = new int(fecha);
    reg[canHora] = new int(horaCompleta);
    reg[canDniPaciente] = new int(dniPaciente);
    reg[canDniDoctor] = new int(dniDoctor);

    cancelacion = reg;
    return true;
}

void agregarRegistroExacto(void**& registros, void* registro) {
    int num = 0;
    if (registros != nullptr) {
        while (registros[num]) num++;
    }

    void** aux = new void*[num + 2] {};
    for (int i = 0; i < num; i++) {
        aux[i] = registros[i];
    }
    aux[num] = registro;
    aux[num + 1] = nullptr;

    delete[] registros;
    registros = aux;
}

void incrementarCapacidad(void**& registros, int num, int& capacidad) {
    capacidad += 5;

    if (registros == nullptr) {
        registros = new void*[capacidad + 1] {};
    }
    else {
        void** aux = new void*[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = registros[i];
        }
        delete[] registros;
        registros = aux;
    }
}

char* leerCadena(ifstream& archivo, char separador) {
    char buffer[256];
    archivo.getline(buffer, 256, separador);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void* buscarPaciente(int dniPaciente, const void* pacientes) {
    const void** regPacientes = (const void**)pacientes;
    if (regPacientes == nullptr) return nullptr;

    for (int i = 0; regPacientes[i]; i++) {
        void** paciente = (void**)regPacientes[i];
        int dni = *(int*)paciente[pacDni];
        if (dni == dniPaciente) return paciente;
    }

    return nullptr;
}

void* buscarDoctor(int dniDoctor, const void* doctores) {
    const void** regDoctores = (const void**)doctores;
    if (regDoctores == nullptr) return nullptr;

    for (int i = 0; regDoctores[i]; i++) {
        void** doctor = (void**)regDoctores[i];
        int dni = *(int*)doctor[docDni];
        if (dni == dniDoctor) return doctor;
    }

    return nullptr;
}

bool esMismaCita(const void* cita, int fecha, int hora, int dniDoctor) {
    const void** regCita = (const void**)cita;
    int fechaCita = *(int*)regCita[citaFecha];
    int horaCita = *(int*)regCita[citaHora];
    int doctorCita = *(int*)regCita[citaDniDoctor];

    return fechaCita == fecha && horaCita == hora && doctorCita == dniDoctor;
}

void cancelarCita(void*& cita) {
    void** regCita = (void**)cita;
    int* estado = (int*)regCita[citaEstado];
    *estado = 0;
}

void cancelarCitas(void* clinica) {
    void** regClinica = (void**)clinica;
    void** regPacientes = (void**)regClinica[cliPacientes];
    if (regPacientes == nullptr) return;

    for (int i = 0; regPacientes[i]; i++) {
        void** paciente = (void**)regPacientes[i];
        procesarCancelacionesPaciente(paciente);
    }
}

void procesarCancelacionesPaciente(void** paciente) {
    void** cancelaciones = (void**)paciente[pacCancelaciones];
    if (cancelaciones == nullptr) return;

    for (int i = 0; cancelaciones[i]; i++) {
        aplicarCancelacionPaciente(paciente, cancelaciones[i]);
    }
}

void aplicarCancelacionPaciente(void** paciente, void* cancelacion) {
    void** regCancelacion = (void**)cancelacion;

    int fecha = *(int*)regCancelacion[canFecha];
    int hora = *(int*)regCancelacion[canHora];
    int dniCanPaciente = *(int*)regCancelacion[canDniPaciente];
    int dniDoctor = *(int*)regCancelacion[canDniDoctor];

    int dniPaciente = *(int*)paciente[pacDni];
    if (dniCanPaciente != dniPaciente) return;

    void* cita = buscarCitaPaciente(paciente, fecha, hora, dniDoctor);
    if (cita != nullptr) {
        cancelarCita(cita);
    }
}

void* buscarCitaPaciente(void** paciente, int fecha, int hora, int dniDoctor) {
    void** citas = (void**)paciente[pacCitas];
    if (citas == nullptr) return nullptr;

    for (int i = 0; citas[i]; i++) {
        void* cita = citas[i];
        if (esMismaCita(cita, fecha, hora, dniDoctor)) {
            return cita;
        }
    }

    return nullptr;
}

void imprimirReporte(ofstream& archivo, const void* clinica) {
    const void** regClinica = (const void**)clinica;
    const void** regPacientes = (const void**)regClinica[cliPacientes];
    const void* doctores = regClinica[cliDoctores];
    if (regPacientes == nullptr) return;

    for (int i = 0; regPacientes[i]; i++) {
        imprimirCitasPaciente(archivo, regPacientes[i], doctores);
    }
}

void imprimirCitasPaciente(ofstream& archivo, const void* paciente, const void* doctores) {
    const void** citas = (const void**)((const void**)paciente)[pacCitas];
    if (citas == nullptr) return;

    for (int i = 0; citas[i]; i++) {
        imprimirDetalleCita(archivo, paciente, citas[i]);

        int dniDoctor = *(int*)((const void**)citas[i])[citaDniDoctor];
        const void* doctor = buscarDoctor(dniDoctor, doctores);
        imprimirDoctor(archivo, doctor);

        archivo << "------------------------------" << endl;
        archivo << "==============================" << endl << endl;
    }
}

void imprimirDetalleCita(ofstream& archivo, const void* paciente, const void* cita) {
    const void** regCita = (const void**)cita;
    int fecha = *(int*)regCita[citaFecha];
    int hora = *(int*)regCita[citaHora];
    int estado = *(int*)regCita[citaEstado];

    imprimirCita(archivo, fecha, hora, estado);
    imprimirPaciente(archivo, paciente);
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

void imprimirPaciente(ofstream& archivo, const void* paciente) {
    if (paciente != nullptr) {
        const void** regPaciente = (const void**)paciente;
        int dni = *(int*)regPaciente[pacDni];
        const char* nombre = (const char*)regPaciente[pacNombre];
        int edad = *(int*)regPaciente[pacEdad];
        char genero = *(char*)regPaciente[pacGenero];

        archivo << "DNI: " << dni << endl;
        archivo << "Nombre: " << nombre << endl;
        archivo << "Edad: " << edad << endl;
        archivo << "Genero: " << genero << endl;
    }

    archivo << "------------------------------" << endl;
    archivo << "DATOS DEL DOCTOR" << endl;
    archivo << "------------------------------" << endl;
}

void imprimirDoctor(ofstream& archivo, const void* doctor) {
    if (doctor != nullptr) {
        const void** regDoctor = (const void**)doctor;
        int dni = *(int*)regDoctor[docDni];
        const char* nombre = (const char*)regDoctor[docNombre];
        int especialidad = *(int*)regDoctor[docEspecialidad];

        archivo << "DNI: " << dni << endl;
        archivo << "Nombre: " << nombre << endl;
        imprimirEspecialidad(archivo, especialidad);
    }
}

void imprimirFecha(ostream& os, int fecha) {
    int anho = fecha / 10000;
    int mes = (fecha / 100) % 100;
    int dia = fecha % 100;

    os << "Fecha: " << anho << "-";
    if (mes < 10) os << "0";
    os << mes << "-";
    if (dia < 10) os << "0";
    os << dia << endl;
}

void imprimirHora(ostream& os, int hora) {
    int horas = hora / 100;
    int minutos = hora % 100;

    os << "Hora: ";
    if (horas < 10) os << "0";
    os << horas << ":";
    if (minutos < 10) os << "0";
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

void liberarPacientes(void*& pacientes) {
    void** regPacientes = (void**)pacientes;
    if (regPacientes == nullptr) return;

    for (int i = 0; regPacientes[i]; i++) {
        void* paciente = regPacientes[i];
        liberarPaciente(paciente);
    }

    delete[] regPacientes;
    pacientes = nullptr;
}

void liberarPaciente(void*& paciente) {
    void** regPaciente = (void**)paciente;
    if (regPaciente == nullptr) return;

    liberarCitasPaciente(regPaciente[pacCitas]);
    liberarCancelacionesPaciente(regPaciente[pacCancelaciones]);

    delete (int*)regPaciente[pacDni];
    delete[] (char*)regPaciente[pacNombre];
    delete (int*)regPaciente[pacEdad];
    delete (char*)regPaciente[pacGenero];
    delete[] regPaciente;
    paciente = nullptr;
}

void liberarCitasPaciente(void*& citas) {
    void** regCitas = (void**)citas;
    if (regCitas == nullptr) return;

    for (int i = 0; regCitas[i]; i++) {
        void** cita = (void**)regCitas[i];
        delete (int*)cita[citaFecha];
        delete (int*)cita[citaHora];
        delete (int*)cita[citaDniDoctor];
        delete (int*)cita[citaEstado];
        delete[] cita;
    }

    delete[] regCitas;
    citas = nullptr;
}

void liberarCancelacionesPaciente(void*& cancelaciones) {
    void** regCancelaciones = (void**)cancelaciones;
    if (regCancelaciones == nullptr) return;

    for (int i = 0; regCancelaciones[i]; i++) {
        void** cancelacion = (void**)regCancelaciones[i];
        delete (int*)cancelacion[canFecha];
        delete (int*)cancelacion[canHora];
        delete (int*)cancelacion[canDniPaciente];
        delete (int*)cancelacion[canDniDoctor];
        delete[] cancelacion;
    }

    delete[] regCancelaciones;
    cancelaciones = nullptr;
}

void liberarDoctores(void*& doctores) {
    void** regDoctores = (void**)doctores;
    if (regDoctores == nullptr) return;

    for (int i = 0; regDoctores[i]; i++) {
        void** doctor = (void**)regDoctores[i];
        delete (int*)doctor[docDni];
        delete[] (char*)doctor[docNombre];
        delete (int*)doctor[docEspecialidad];
        delete[] doctor;
    }

    delete[] regDoctores;
    doctores = nullptr;
}

void liberarClinica(void*& clinica) {
    void** regClinica = (void**)clinica;
    if (regClinica == nullptr) return;

    liberarPacientes(regClinica[cliPacientes]);
    liberarDoctores(regClinica[cliDoctores]);

    delete[] regClinica;
    clinica = nullptr;
}
