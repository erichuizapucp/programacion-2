#include "pruebas.h"

void probarCargaInventario(const char* nombreArchivo, const void* inventario) {
    ofstream archivo(nombreArchivo, ios::out);
    
    archivo << left << setw(10) << "CODIGO"
            << setw(50) << "NOMBRE"
            << setw(12) << "CANT. D"
            << setw(12) << "CANT. R"
            << setw(10) << "U. MEDIDA" << endl;
    
    const void** insumos = (const void**)inventario;
    for (int i = 0; insumos[i]; i++) {
        const void** insumo = (const void**)insumos[i];
        
        const char* codigo = (const char*)insumo[cps::invCodigo];
        const char* nombre = (const char*)insumo[cps::invNombre];
        const double cantidadDisponible = *(const double*)insumo[cps::invCantDisponible];
        const double cantidadRequerida = *(const double*)insumo[cps::invCantRequerida];
        const char* unidadMedida = (const char*)insumo[cps::invUnidadMedida];
        
        archivo << left << setw(10) << codigo
                << setw(50) << nombre
                << right << setw(12) << fixed << setprecision(2) << cantidadDisponible
                << setw(12) << fixed << setprecision(2) << cantidadRequerida
                << setw(10) << unidadMedida << endl;
    }
}

void pruebaCargaMenu(const char* nombreArchivo, const void* menu) {
    ofstream archivo(nombreArchivo, ios::out);
    
    archivo << "============================= Menú del día ======================================" << endl;
    
    const void** bebidas = (const void**)menu;
    for (int i = 0; bebidas[i]; i++) {
        const void** bebida = (const void**)bebidas[i];
        
        const char* nombre = (const char*)bebida[cps::bebNombre];
        const char* descripcion = (const char*)bebida[cps::bebDescripcion];
        const char tipo = *(const char*)bebida[cps::bebTipo];
        const bool disponible = *(const bool*)bebida[cps::bebDisponible];
        const double precio = *(const double*)bebida[cps::bebPrecio];
     
        const char* nombreTipoBebida = tipoBebida(tipo);
        
        archivo << nombreTipoBebida << ": " << nombre << endl;
        archivo << descripcion << endl;
        archivo << "Precio: S/ " << fixed << setprecision(2) << precio << endl;
        archivo << "Disponible: " << (disponible ? "Si" : "No") << endl;
        
        archivo << "---------------------------------------------------------------------------------" << endl;
    }
}

const char* tipoBebida(const char tipo) {
    const char* tipoStr;
    switch (tipo) {
        case 'C':
            tipoStr = "Café";
            break;
        case 'T':
            tipoStr = "Té";
            break;
        case 'H':
            tipoStr = "Chocolate";
            break;
        case 'I':
            tipoStr = "Infusión";
            break;
        default:
            tipoStr = "Café";

    }
    return tipoStr;
}