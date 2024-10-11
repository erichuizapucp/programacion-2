#include "funciones.h"

bool operator>>(ifstream& archivo, Insumo& insumo) {
    char* codigo;
    char* nombre;
    double cantidadDisponible;
    char* unidadMedida;
    
    if (!archivo.eof()) {
        insumo.setCodigo(leeCadena(archivo));
        insumo.setNombre(leeCadena(archivo));
        
        archivo >> cantidadDisponible;
        insumo.setCantDisponible(cantidadDisponible);
        insumo.setCantRequerida(0.00);
        archivo.ignore();
        
        insumo.setUnidadMedida(leeCadena(archivo, '\n'));
        
        return true;
    }
    
    return false;
}

bool operator>>(ifstream& archivo, Bebida& bebida) {
    char* codigo;
    char* nombre;
    char* descripcion;
    char tipo;
    double precio;
    int cantVent;
    
    if (!archivo.eof()) {
        codigo = leeCadena(archivo);
        nombre = leeCadena(archivo);
        descripcion = leeCadena(archivo);
        archivo >> tipo;
        archivo.ignore();
        archivo >> precio;
        archivo.ignore();
        archivo >> cantVent;
        archivo.ignore();
        
        bebida.setCodigo(codigo);
        bebida.setNombre(nombre);
        bebida.setDescripcion(descripcion);
        bebida.setTipo(tipo);
        bebida.setPrecio(precio);
        bebida.setCantVent(cantVent);
        bebida.setDisponible(true);
        
        return true;
    }
    
    return false;
}

void operator<<(ofstream& archivo, const Menu& menu) {
    archivo << "============================= Menú del día ======================================" << endl;
    
    const Bebida* bebidas = menu.getBebidas();
    const int cantidad = menu.getCantidad();
    
    for (int i = 0; i < cantidad; i++) {
        archivo << bebidas[i];
        archivo << "---------------------------------------------------------------------------------" << endl;
    }
}

void operator<<(ofstream& archivo, const Bebida& bebida) {
    archivo << bebida.getNombreTipoBebida() << ": " << bebida.getNombre() << endl;
    archivo << bebida.getDescripcion() << endl;
    archivo << "Precio: S/ " << fixed << setprecision(2) << bebida.getPrecio() << endl;
    archivo << "Disponible: " << (bebida.getDisponible() ? "Si" : "No") << endl;
}

char* leeCadena(ifstream& archivo, char delimitador) {
    char buffer[tam::buffer];
    archivo.getline(buffer, tam::buffer, delimitador);
    char* cadena = new char[strlen(buffer) + 1];
    
    strcpy(cadena, buffer);
    
    return cadena;
}