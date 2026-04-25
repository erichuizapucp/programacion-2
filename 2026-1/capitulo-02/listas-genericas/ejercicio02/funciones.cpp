//
// Created by Eric Huiza on 3/26/26.
//

#include "funciones.h"
#include "listas/cola.h"

void cargarDatos(void*& clinica,
        const char* archivoPacientes,
        const char* archivoDoctores,
        const char* archivoCitas,
        const char* archivoCancelaciones) {

    void* pacientes;
    void* doctores;

    cargarRegistros(archivoPacientes, pacientes, leerPaciente, cmpPacientePorNombre);
    cargarRegistros(archivoDoctores, doctores, leerDoctor, cmpDoctorPorDni);

    clinica = new void*[cliNumCampos] {};
    void** regClinica = (void**)clinica;
    regClinica[cliPacientes] = pacientes;
    regClinica[cliDoctores] = doctores;

    cargarEventos(archivoCitas, clinica, pacCitas,
        leerCita, cmpCitaPorFechaHora, liberarCita);
    cargarEventos(archivoCancelaciones, clinica,pacCancelaciones,
        leerCancelacion, cmpCancelacionPorFechaHora, liberarCancelacion);
}

void cargarRegistros(const char* nombreArchivo, void*& datos,
    bool (*leerRegistro)(ifstream&, void*&),
    int (*cmp)(const void*, const void*)) {

    ifstream archivo(nombreArchivo, ios::in);
    void** registros = nullptr;
    int num = 0, capacidad = 0;
    void* dato;

    while (leerRegistro(archivo, dato)) {
        if (num == capacidad) {
            incrementarCapacidad(registros, num, capacidad);
        }
        registros[num++] = dato;
    }

    if (registros == nullptr) registros = new void*[1] {};
    else registros[num] = nullptr;

    qsort(registros, num, sizeof(int*), cmp);
    datos = registros;
}

void cargarEventos(const char* nombreArchivo, void*& clinica, int pos,
    bool (*leerEvento)(ifstream&, void*&, int&),
    int (*cmp)(const void*, const void*),
    void (*liberarEventoNoAsociado)(void*&)) {

    void** regClinica = (void**)clinica;
    void* pacientes = regClinica[cliPacientes];
    void** regPacientes = (void**)pacientes;

    int nPac = numElementos(regPacientes);
    void** copiaPacientes = new void*[nPac + 1] {};
    for (int i = 0; i < nPac; i++) copiaPacientes[i] = regPacientes[i];

    qsort(copiaPacientes, nPac, sizeof(int*), cmpPacientePorDni);

    ifstream archivo(nombreArchivo, ios::in);
    void* dato;
    int dniPaciente;

    while (leerEvento(archivo, dato, dniPaciente)) {
        void** paciente = (void**)buscarPaciente(dniPaciente, copiaPacientes);
        if (paciente != nullptr) {
            void** eventosPaciente = (void**)paciente[pos];
            agregarRegistroExacto(eventosPaciente, dato);
            paciente[pos] = eventosPaciente;
        }
        else {
            liberarEventoNoAsociado(dato);
        }
    }

    for (int i = 0; regPacientes[i]; i++) {
        void** paciente = (void**)regPacientes[i];
        void** eventosPaciente = (void**)paciente[pos];
        if (eventosPaciente != nullptr) {
            qsort(eventosPaciente, numElementos(eventosPaciente), sizeof(int*), cmp);
        }
    }

    delete[] copiaPacientes;
}

int numElementos(void** registros) {
    int num = 0;
    for (int i = 0; registros[i]; i++) num++;
    return num;
}

int cmpPacientePorNombre(const void* a, const void* b) {
    const void** pacientePtr1 = (const void**)a;
    const void** pacientePtr2 = (const void**)b;

    const void** paciente1 = (const void**)*pacientePtr1;
    const void** paciente2 = (const void**)*pacientePtr2;

    const char* nombrePaciente1 = (const char*)paciente1[pacNombre];
    const char* nombrePaciente2 = (const char*)paciente2[pacNombre];

    return strcmp(nombrePaciente1, nombrePaciente2);
}

int cmpPacientesPorEdad(const void* a, const void* b) {
    const void** pacientePtr1 = (const void**)a;
    const void** pacientePtr2 = (const void**)b;

    const void** paciente1 = (const void**)*pacientePtr1;
    const void** paciente2 = (const void**)*pacientePtr2;

    const int* edadPaciente1 = (const int*)paciente1[pacEdad];
    const int* edadPaciente2 = (const int*)paciente2[pacEdad];

    return *edadPaciente1 - *edadPaciente2;
}

int cmpPacientePorDni(const void* a, const void* b) {
    const void** pacientePtr1 = (const void**)a;
    const void** pacientePtr2 = (const void**)b;

    const void** paciente1 = (const void**)*pacientePtr1;
    const void** paciente2 = (const void**)*pacientePtr2;

    const int* dniPaciente1 = (const int*)paciente1[pacDni];
    const int* dniPaciente2 = (const int*)paciente2[pacDni];

    return *dniPaciente1 - *dniPaciente2;
}

int cmpDoctorPorNombre(const void* a, const void* b) {
    const void** doctorPtr1 = (const void**)a;
    const void** doctorPtr2 = (const void**)b;

    const void** doctor1 = (const void**)*doctorPtr1;
    const void** doctor2 = (const void**)*doctorPtr2;

    const char* nombreDoctor1 = (const char*)doctor1[docNombre];
    const char* nombreDoctor2 = (const char*)doctor2[docNombre];

    return strcmp(nombreDoctor1, nombreDoctor2);
}

int cmpDoctorPorDni(const void* a, const void* b) {
    const void** doctorPtr1 = (const void**)a;
    const void** doctorPtr2 = (const void**)b;

    const void** doctor1 = (const void**)*doctorPtr1;
    const void** doctor2 = (const void**)*doctorPtr2;

    const int* dniDoctor1 = (const int*)doctor1[docDni];
    const int* dniDoctor2 = (const int*)doctor2[docDni];

    return *dniDoctor1 - *dniDoctor2;
}

int cmpCitaPorFechaHora(const void* a, const void* b) {
    const void** citaPtr1 = (const void**)a;
    const void** citaPtr2 = (const void**)b;

    const void** cita1 = (const void**)*citaPtr1;
    const void** cita2 = (const void**)*citaPtr2;

    int fecha1 = *(int*)cita1[citaFecha];
    int fecha2 = *(int*)cita2[citaFecha];

    if (fecha1 != fecha2) {
        return fecha1 - fecha2;
    }

    int hora1 = *(int*)cita1[citaHora];
    int hora2 = *(int*)cita2[citaHora];

    return hora1 - hora2;
}

int cmpCancelacionPorFechaHora(const void* a, const void* b) {
    const void** cancelacionPtr1 = (const void**)a;
    const void** cancelacionPtr2 = (const void**)b;

    const void** cancelacion1 = (const void**)*cancelacionPtr1;
    const void** cancelacion2 = (const void**)*cancelacionPtr2;

    int fecha1 = *(int*)cancelacion1[canFecha];
    int fecha2 = *(int*)cancelacion2[canFecha];

    if (fecha1 != fecha2) {
        return fecha1 - fecha2;
    }

    int hora1 = *(int*)cancelacion1[canHora];
    int hora2 = *(int*)cancelacion2[canHora];

    return hora1 - hora2;
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
    reg[docColaAtencion] = nullptr;

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

    void** clavePaciente = new void*[pacNumCampos] {};
    clavePaciente[pacDni] = &dniPaciente;
    void* clave = clavePaciente;

    const void* pacientePtr =
        bsearch(&clave,
            regPacientes,
            numElementos((void**)regPacientes),
            sizeof(int*),
            cmpPacientePorDni);

    if (pacientePtr == nullptr) return nullptr;
    return *(void**)pacientePtr;
}

void* buscarDoctor(int dniDoctor, const void* doctores) {
    const void** regDoctores = (const void**)doctores;
    if (regDoctores == nullptr) return nullptr;

    void** claveDoctor = new void*[docNumCampos] {};
    claveDoctor[docDni] = &dniDoctor;
    void* clave = claveDoctor;

    const void* doctor =
        bsearch(&clave,
            regDoctores,
            numElementos((void**)regDoctores),
            sizeof(int*),
            cmpDoctorPorDni);

    if (doctor == nullptr) return nullptr;

    return *(void**)doctor;
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

void imprimirReporte(const char* nombreArchivo, const void* clinica) {
    const int anchoTotal = 86;
    const int anchoTitulo = 16;
    ofstream archivo(nombreArchivo, ios::out);
    const void** regClinica = (const void**)clinica;
    const void** regPacientes = (const void**)regClinica[cliPacientes];
    const void* doctores = regClinica[cliDoctores];
    if (regPacientes == nullptr) return;

    archivo << setfill('=') << setw(anchoTotal) << "" << setfill(' ') << endl;
    archivo << setw((anchoTotal + anchoTitulo) / 2) << "REPORTE DE CITAS" << endl;
    archivo << setfill('=') << setw(anchoTotal) << "" << setfill(' ') << endl << endl;

    for (int i = 0; regPacientes[i]; i++) {
        imprimirCitasPaciente(archivo, regPacientes[i], doctores);
    }
}

void liberarColaAtencionDoctor(void*& colaDoctor) {
    if (colaDoctor == nullptr) return;

    void* dato;
    while (desencolar(colaDoctor, dato)) {}

    destruirCola(colaDoctor);
    colaDoctor = nullptr;
}

void encolarCitasPacienteDoctor(void* colaDoctor, const void* paciente, int dniDoctor) {
    const void** regPaciente = (const void**)paciente;
    const void** citas = (const void**)regPaciente[pacCitas];
    if (citas == nullptr) return;

    for (int i = 0; citas[i]; i++) {
        const void** regCita = (const void**)citas[i];
        int dniCitaDoctor = *(int*)regCita[citaDniDoctor];
        int estadoCita = *(int*)regCita[citaEstado];

        if (dniCitaDoctor == dniDoctor && estadoCita == 1) {
            encolar(colaDoctor, (void*)citas[i]);
        }
    }
}

void construirColaAtencionDoctor(void* doctor, const void* pacientes) {
    void** regDoctor = (void**)doctor;
    const void** regPacientes = (const void**)pacientes;
    int dniDoctor = *(int*)regDoctor[docDni];

    liberarColaAtencionDoctor(regDoctor[docColaAtencion]);
    regDoctor[docColaAtencion] = crearCola();
    void* colaDoctor = regDoctor[docColaAtencion];

    for (int i = 0; regPacientes[i]; i++) {
        encolarCitasPacienteDoctor(colaDoctor, regPacientes[i], dniDoctor);
    }
}

void construirColasDeAtencion(void* clinica) {
    void** regClinica = (void**)clinica;
    void** regDoctores = (void**)regClinica[cliDoctores];
    const void** regPacientes = (const void**)regClinica[cliPacientes];

    if (regDoctores == nullptr || regPacientes == nullptr) return;

    for (int i = 0; regDoctores[i]; i++) {
        construirColaAtencionDoctor(regDoctores[i], regPacientes);
    }
}

void* buscarPacientePorCita(const void* clinica, const void* citaBuscada) {
    const void** regClinica = (const void**)clinica;
    const void** regPacientes = (const void**)regClinica[cliPacientes];
    if (regPacientes == nullptr) return nullptr;

    for (int i = 0; regPacientes[i]; i++) {
        if (pacienteTieneCita(regPacientes[i], citaBuscada)) {
            return (void*)regPacientes[i];
        }
    }

    return nullptr;
}

bool pacienteTieneCita(const void* paciente, const void* citaBuscada) {
    const void** regPaciente = (const void**)paciente;
    const void** citas = (const void**)regPaciente[pacCitas];
    if (citas == nullptr) return false;

    for (int i = 0; citas[i]; i++) {
        if (citas[i] == citaBuscada) {
            return true;
        }
    }

    return false;
}

void imprimirAtencionDoctor(ofstream& archivo, void* doctor, const void* clinica) {
    const int anchoTotal = 86;
    imprimirDoctor(archivo, doctor);

    void** regDoctor = (void**)doctor;
    void* colaAtencion = regDoctor[docColaAtencion];

    if (colaAtencion == nullptr || colaVacia(colaAtencion)) {
        archivo << setw(8) << "" << "Sin pacientes en cola de atencion." << endl;
    }
    else {
        int turno = 1;
        void* dato;

        while (desencolar(colaAtencion, dato)) {
            const void* cita = dato;
            const void* paciente = buscarPacientePorCita(clinica, cita);
            if (paciente == nullptr) continue;

            const void** regPaciente = (const void**)paciente;
            const void** regCita = (const void**)cita;

            const char* nombrePaciente = (const char*)regPaciente[pacNombre];
            int dniPaciente = *(int*)regPaciente[pacDni];
            int fecha = *(int*)regCita[citaFecha];
            int hora = *(int*)regCita[citaHora];

            archivo << setw(8) << "" << "Turno " << turno++ << ": "
                    << left << setw(24) << nombrePaciente
                    << "DNI: " << dniPaciente << "  Fecha: ";
            imprimirFecha(archivo, fecha);
            archivo << "  Hora: ";
            imprimirHora(archivo, hora);
            archivo << endl;
        }
    }

    archivo << setfill('-') << setw(anchoTotal) << "" << setfill(' ') << endl;
}

void imprimirReporteAtencionDoctores(const char* nombreArchivo, void* clinica) {
    const int anchoTotal = 86;
    const int anchoTitulo = 34;
    ofstream archivo(nombreArchivo, ios::out);

    void** regClinica = (void**)clinica;
    void** regDoctores = (void**)regClinica[cliDoctores];
    if (regDoctores == nullptr) return;

    archivo << setfill('=') << setw(anchoTotal) << "" << setfill(' ') << endl;
    archivo << setw((anchoTotal + anchoTitulo) / 2) << "REPORTE DE ATENCION POR DOCTOR" << endl;
    archivo << setfill('=') << setw(anchoTotal) << "" << setfill(' ') << endl << endl;

    for (int i = 0; regDoctores[i]; i++) {
        imprimirAtencionDoctor(archivo, regDoctores[i], clinica);
    }
}

void imprimirCitasPaciente(ofstream& archivo, const void* paciente, const void* doctores) {
    const int anchoTotal = 86;
    const int anchoInterno = 82;
    const void** citas = (const void**)((const void**)paciente)[pacCitas];
    if (citas == nullptr) return;

    imprimirPaciente(archivo, paciente);
    archivo << setw(4) << "" << setfill('-') << setw(anchoInterno) << "" << setfill(' ') << endl;

    for (int i = 0; citas[i]; i++) {
        imprimirDetalleCita(archivo, paciente, citas[i]);

        int dniDoctor = *(int*)((const void**)citas[i])[citaDniDoctor];
        const void* doctor = buscarDoctor(dniDoctor, doctores);
        imprimirDoctor(archivo, doctor);

        if (citas[i + 1]) {
            archivo << setw(8) << "" << setfill('.') << setw(78) << "" << setfill(' ') << endl;
        }
    }

    archivo << setfill('=') << setw(anchoTotal) << "" << setfill(' ') << endl << endl;
}

void imprimirDetalleCita(ofstream& archivo, const void* paciente, const void* cita) {
    const void** regCita = (const void**)cita;
    int fecha = *(int*)regCita[citaFecha];
    int hora = *(int*)regCita[citaHora];
    int estado = *(int*)regCita[citaEstado];

    imprimirCita(archivo, fecha, hora, estado);
}

void imprimirCita(ofstream& archivo, int fecha, int hora, int estado) {
    archivo << setw(6) << "" << left << setw(8) << "Fecha:";
    imprimirFecha(archivo, fecha);
    archivo << "   " << left << setw(7) << "Hora:";
    imprimirHora(archivo, hora);
    archivo << "   " << left << setw(9) << "Estado:";
    imprimirEstado(archivo, estado);
    archivo << endl;
}

void imprimirPaciente(ofstream& archivo, const void* paciente) {
    const int anchoEtiqueta = 10;
    if (paciente != nullptr) {
        const void** regPaciente = (const void**)paciente;
        int dni = *(int*)regPaciente[pacDni];
        const char* nombre = (const char*)regPaciente[pacNombre];
        int edad = *(int*)regPaciente[pacEdad];
        char genero = *(char*)regPaciente[pacGenero];

        archivo << left << setw(anchoEtiqueta) << "Paciente:"
                << left << setw(22) << nombre
                << left << setw(6) << "DNI:" << dni
                << "   " << left << setw(6) << "Edad:" << edad
                << "   " << left << setw(8) << "Genero:" << genero << endl;
    }
}

void imprimirDoctor(ofstream& archivo, const void* doctor) {
    const int sangria = 10;
    if (doctor != nullptr) {
        const void** regDoctor = (const void**)doctor;
        int dni = *(int*)regDoctor[docDni];
        const char* nombre = (const char*)regDoctor[docNombre];
        int especialidad = *(int*)regDoctor[docEspecialidad];

        archivo << setw(sangria) << "" << left << setw(10) << "Doctor:"
                << left << setw(6) << "DNI:" << dni
                << "   " << left << setw(9) << "Nombre:" << nombre
                << "   " << left << setw(14) << "Especialidad:";
        imprimirEspecialidad(archivo, especialidad);
        archivo << endl;
    }
}

void imprimirFecha(ostream& os, int fecha) {
    int anho = fecha / 10000;
    int mes = (fecha / 100) % 100;
    int dia = fecha % 100;

    os << right << setw(4) << setfill('0') << anho << "-"
            << setw(2) << mes << "-"
            << setw(2) << dia << setfill(' ');
}

void imprimirHora(ostream& os, int hora) {
    int horas = hora / 100;
    int minutos = hora % 100;

    os << right << setw(2) << setfill('0') << horas << ":"
            << setw(2) << minutos << setfill(' ');
}

void imprimirEstado(ostream& os, int estado) {
    if (estado == 1) {
        os << "RESERVADA";
    }
    else if (estado == 0) {
        os << "CANCELADA";
    }
    else {
        os << "NA";
    }
}

void imprimirEspecialidad(ostream& os, int especialidad) {
    switch (especialidad) {
        case 0: os << "CARDIOLOGIA"; break;
        case 1: os << "DERMATOLOGIA"; break;
        case 2: os << "NEUROLOGIA"; break;
        case 3: os << "PEDIATRIA"; break;
        case 4: os << "PSIQUIATRIA"; break;
        case 5: os << "TRAUMATOLOGIA"; break;
        case 6: os << "ENDOCRINOLOGIA"; break;
        case 7: os << "GINECOLOGIA"; break;
        case 8: os << "PSICOLOGIA"; break;
        case 9: os << "ORTOPEDIA"; break;
        default: os << "GENERAL"; break;
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
        liberarCita(regCitas[i]);
    }

    delete[] regCitas;
    citas = nullptr;
}

void liberarCancelacionesPaciente(void*& cancelaciones) {
    void** regCancelaciones = (void**)cancelaciones;
    if (regCancelaciones == nullptr) return;

    for (int i = 0; regCancelaciones[i]; i++) {
        liberarCancelacion(regCancelaciones[i]);
    }

    delete[] regCancelaciones;
    cancelaciones = nullptr;
}

void liberarDoctores(void*& doctores) {
    void** regDoctores = (void**)doctores;
    if (regDoctores == nullptr) return;

    for (int i = 0; regDoctores[i]; i++) {
        void** doctor = (void**)regDoctores[i];
        liberarColaAtencionDoctor(doctor[docColaAtencion]);
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


void liberarCita(void*& cita) {
    void** regCita = (void**)cita;
    delete (int*)regCita[citaFecha];
    delete (int*)regCita[citaHora];
    delete (int*)regCita[citaDniDoctor];
    delete (int*)regCita[citaEstado];
    delete[] regCita;
}

void liberarCancelacion(void*& cancelacion) {
    void** regCancelacion = (void**)cancelacion;
    delete (int*)regCancelacion[canFecha];
    delete (int*)regCancelacion[canHora];
    delete (int*)regCancelacion[canDniPaciente];
    delete (int*)regCancelacion[canDniDoctor];
    delete[] regCancelacion;
}