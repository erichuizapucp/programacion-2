#include "restaurante.h"

const int MAX_NO_MESAS = 100;
const int MAX_NO_MESEROS = 100;
const int MAX_NO_RESERVAS = 100;
const int MAX_NO_ARTICULOS = 10;
const int MAX_NO_CARACTERES = 100;
const char* CODIGO_MESA_INVALIDO = "0000000";
const int DNI_INVALIDO = -1;


void cargarDatos(const char* nombreArchivoMesas, const char* nombreArchivoMeseros, 
        Mesa*& mesas, Mesero*& meseros) {
    ifstream archivoMesas;
    abrirArchivo(nombreArchivoMesas, archivoMesas);
    
    mesas = new Mesa[MAX_NO_MESAS];
    Mesa* mesaPtr = mesas;
    while (archivoMesas >> mesaPtr) {
        mesaPtr++;
    }
    
    ifstream archivoMeseros;
    abrirArchivo(nombreArchivoMeseros, archivoMeseros);
    
    meseros = new Mesero[MAX_NO_MESEROS];
      
}

void   (const char* nombreArchivo, Mesa*& mesas, Mesero*& meseros, ListaReservas& reservas) {
    ifstream archivo;
    abrirArchivo(nombreArchivo, archivo);
    
    inicializarListaReservas(reservas);
    Reserva* reservaPtr = new Reserva();
    while (archivo >> reservaPtr) {
        asignarMesa(reservaPtr, mesas);
        asignarMeseros(reservaPtr, meseros);
        
        reservas += reservaPtr;
        reservaPtr = new Reserva();
    }
    
    delete reservaPtr;
}

bool operator>>(ifstream& archivo, Mesa*& mesa) {
    char codigo[100];
    archivo.getline(codigo, 100, ',');
    
    if (!archivo.eof() && strlen(codigo) > 0) {
        mesa->codigo = obtenerCadena(codigo);
        archivo >> mesa->tipo;
        archivo.ignore(); // ignorar la coma
        mesa->ubicacion = obtenerCadena(archivo);
        archivo >> mesa->capacidad;

        if (mesa->tipo == TIPO_MESA::PREMIUM) {
            archivo.ignore(); // ignorar la coma
            char c;
            mesa->articulos = new char[MAX_NO_ARTICULOS];
            char* pa = mesa->articulos;
            while ((c = archivo.get()) && c != '\n') {
                if (c != ',') {
                    *pa = c;
                    pa++;
                }
            }
        }
        else {
            archivo.ignore(); //ignorar el salto de línea
        }

        return true;
    }
    
    mesa->codigo = obtenerCadena(CODIGO_MESA_INVALIDO);
    
    return false;
}

bool operator>>(ifstream& archivo, Mesero*& mesero) {
    if (!archivo.eof() && archivo >> mesero->dni) {
        archivo.ignore(); // ignorar la coma
        mesero->nombre = obtenerCadena(archivo);
        archivo >> mesero->sueldoBruto;
        archivo.ignore(); // ignorar la coma
        archivo >> mesero->experiencia;
        archivo.ignore(); // ignorar el salto de línea
        
        return true;
    }
    
    mesero->dni = -1;
    
    return false;
}

bool operator>>(ifstream& archivo, Reserva*& reserva) {
    int dni, turno, noPersonas;
    char *nombre, *articulos;
    char ubicacion;
    
    while (!archivo.eof() && archivo >> dni) {
        archivo.ignore();
        nombre = obtenerCadena(archivo);
        archivo >> ubicacion;
        archivo.ignore();
        
        if (ubicacion == UBICACION_RESERVA::SALON_PRIVADO) {
            turno = 0;
            char c;
            articulos = new char[MAX_NO_ARTICULOS];
            char* pa = articulos;
            while ((c = archivo.get()) && !isdigit(c)) {
                if (c != ',') {
                    *pa = c;
                    pa++;
                }
            }
            noPersonas = c - '0';
        }
        else {
            archivo >> turno;
            archivo.ignore();
            archivo >> noPersonas;
            articulos = nullptr;
        }
        archivo.ignore();        
        llenarReserva(reserva, dni, nombre, ubicacion, turno, noPersonas, articulos);
        
        return true;
    }
    reserva->dni = -1;
    
    return false;
}

void llenarReserva(Reserva*& reserva, int dni, char* nombre, char ubicacion, int turno, int noPersonas, char* articulos) {
    reserva->dni = dni;
    reserva->nombre = nombre;
    reserva->ubicacion = ubicacion;
    reserva->turno = turno;
    reserva->noPersonas = noPersonas;
    reserva->articulos = articulos;
}

void asignarMesa(Reserva*& reserva, Mesa*& mesas) {
    for (int i = 0; strcmp(mesas[i].codigo, CODIGO_MESA_INVALIDO) != 0; i++) {
        if (reserva->ubicacion == UBICACION_RESERVA::SALON_PRIVADO && mesas[i].tipo == TIPO_MESA::PREMIUM && !mesas[i].reservadaTurno1 && !mesas[i].reservadaTurno2) {
            reserva->mesa = &mesas[i];
            mesas[i].reservadaTurno1 = true;
            mesas[i].reservadaTurno2 = true;
            
            break;
        }
        else if ((reserva->ubicacion == UBICACION_RESERVA::SALON || reserva->ubicacion == UBICACION_RESERVA::TERRAZA) && mesas[i].tipo == TIPO_MESA::REGULAR) {
            int turno = reserva->turno;

            if (turno == 1 && !mesas[i].reservadaTurno1) {
                reserva->mesa = &mesas[i];
                mesas[i].reservadaTurno1 = true;
                
                break;
            }
            else if (turno == 2 && !mesas[i].reservadaTurno2) {
                reserva->mesa = &mesas[i];
                mesas[i].reservadaTurno2 = true;
                
                break;
            }
        }
    }
}

void asignarMeseros(Reserva*& reserva, Mesero*& meseros) {
    for (int i = 0; meseros[i].dni != DNI_INVALIDO; i++) {
        if (reserva->ubicacion == UBICACION_RESERVA::SALON_PRIVADO && meseros[i].experiencia >= 5) {
            reserva->mesero = &meseros[i];
            meseros[i].asignadoTurno1 = true;
            meseros[i].asignadoTurno2 = true;
            
            break;
        }
        else {
            reserva->mesero = &meseros[i];
            meseros[i].asignadoTurno1 = reserva->turno == 1;
            meseros[i].asignadoTurno2 = reserva->turno == 2;
            
            break;
        }
    }
}

void inicializarListaReservas(ListaReservas& reservas) {
    reservas.cantidad = 0;
    reservas.cabeza = nullptr;
    reservas.cola = nullptr;
}

void operator+=(ListaReservas& listaReservas, const Reserva* datosReserva) {
    bool esNuevaReservaPremium = datosReserva->ubicacion == UBICACION_RESERVA::SALON_PRIVADO;
    
    NodoReserva* actual = listaReservas.cabeza;
    NodoReserva* anterior = nullptr;
    
    while (actual != nullptr) {
        bool esReservaPremium = actual->datos->ubicacion == UBICACION_RESERVA::SALON_PRIVADO;
        
        if (esNuevaReservaPremium && !esReservaPremium) {
            insertarSiguienteReserva(listaReservas, anterior, datosReserva);
            return;
        }
        // Si es una reserva Regular, buscar la última Premium y colocarla después.
        else if (!esNuevaReservaPremium && (!esReservaPremium || actual->siguiente == nullptr)) {
            insertarSiguienteReserva(listaReservas, actual, datosReserva);
            return;
        }
        
        anterior = actual;
        actual = actual->siguiente;
    }
    
    // Si es la primera reserva o si todas son premium, entonces inserta al final
    insertarSiguienteReserva(listaReservas, anterior, datosReserva);
}

void insertarSiguienteReserva(ListaReservas& listaReservas, NodoReserva* reservaAnterior, const Reserva* datosReserva) {
    NodoReserva* nuevaReserva = new NodoReserva();
    nuevaReserva->datos = datosReserva;
    
    if (reservaAnterior == nullptr) { // insertar como primera reserva
        if (listaReservas.cantidad == 0) {
            listaReservas.cola = nuevaReserva;
        }
        
        nuevaReserva->siguiente = listaReservas.cabeza;
        listaReservas.cabeza = nuevaReserva;
    }
    else {
        if (reservaAnterior->siguiente == nullptr) { // insertar como última reserva
            listaReservas.cola = nuevaReserva;
        }
        
        nuevaReserva->siguiente = reservaAnterior->siguiente;
        reservaAnterior->siguiente = nuevaReserva;
    }
    
    listaReservas.cantidad++;
}

void generarReporte(const char* nombreArchivo, ListaReservas& listaReservas) {
    ofstream archivo;
    abrirArchivo(nombreArchivo, archivo);
    archivo << listaReservas;
}

ofstream& operator<<(ofstream& archivo, const ListaReservas& listaReservas) {
    NodoReserva* actual = listaReservas.cabeza;
    while (actual != nullptr) {
        archivo << actual->datos;
        actual = actual->siguiente;
    }
    
    return archivo;
}

ofstream& operator<<(ofstream& archivo, const Reserva* reserva) {
    archivo << left << setw(8) << reserva->dni 
            << setw(50) << reserva->nombre
            << setw(10) << reserva->ubicacion
            << setw(5) << reserva->turno
            << setw(5) << reserva->noPersonas
            << endl;
    //TODO: completar la generación del reporte.
//    int dni;
//    char* nombre;
//    char ubicacion;
//    int turno;
//    int noPersonas;
//    char* articulos;
//    Mesa* mesa;
//    Mesero* mesero;
            
    return archivo;
}

char* obtenerCadena(ifstream& archivo, char delimitador) {
    char* cadena = new char[MAX_NO_CARACTERES];
    archivo.getline(cadena, MAX_NO_CARACTERES, delimitador);
    
    return cadena;
}

char* obtenerCadena(const char* cadena) {
    char* nuevaCadena = new char[100];
    strcpy(nuevaCadena, cadena);
    
    return nuevaCadena;
}

void liberarMemoria(Mesa*& mesas, Mesero*& meseros, ListaReservas*& reservas) {
    int imesa = 0;
    for (imesa = 0; strcmp(mesas[imesa].codigo, CODIGO_MESA_INVALIDO) == 0; imesa++) {
        Mesa mesa = mesas[imesa];
        delete[] mesa.codigo;
        delete[] mesa.ubicacion;
        
        if (mesas[imesa].articulos) {
            delete[] mesa.articulos;
        }
    }
    delete[] mesas[imesa].codigo;
    delete[] mesas;
    
    for (int i = 0; meseros[i].dni != DNI_INVALIDO; i++) {
        Mesero mesero = meseros[i];
        delete[] mesero.nombre;
    }
    delete[] meseros;
    
//    for (int i = 0; reservas[i].dni != DNI_INVALIDO; i++) {
//        delete[] reservas[i].nombre;
//        
//        if (reservas[i].articulos) {
//            delete[] reservas[i].articulos;
//        }
//    }
    delete reservas;
}
