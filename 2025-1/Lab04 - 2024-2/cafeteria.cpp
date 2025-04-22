#include "cafeteria.h"
#include "enums.h"

void cargarInventario(const char* nombreArchivo, void*& inventario) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarInventario(archivo, inventario);
}

void cargarInventario(ifstream& archivo, void*& inventario) {
    void** buffer = new void*[tam::buffer];
    int num = 0;
    while (cargarInsumoInventario(archivo, 
            buffer[num])) num++;
    
    void** vv = new void*[num + 1] {};
    for (int i = 0; i < num; i++) {
        vv[i] = buffer[i];
    }
    
    inventario = vv;
    
    delete[] buffer;
}

bool cargarInsumoInventario(ifstream& archivo, void*& insumo) {
    char* codigo;
    char* nombre;
    double cantidadDisponible;
    char* unidadMedida;
    
    if (!archivo.eof()) {
        void** vv = new void*[tam::invNumCampos];
        
        codigo = leeCadena(archivo);
        nombre = leeCadena(archivo);
        archivo >> cantidadDisponible;
        archivo.ignore();
        unidadMedida = leeCadena(archivo, '\n');
        
        vv[cps::invCodigo] = codigo;
        vv[cps::invNombre] = nombre;
        vv[cps::invCantDisponible] = new double(cantidadDisponible);
        vv[cps::invCantRequerida] = new double(0);
        vv[cps::invUnidadMedida] = unidadMedida;
        
        insumo = vv;
        
        return true;
    }
    
    return false;
}

void cargarMenu(const char* nombreArchivo, void*& menu) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarMenu(archivo, menu);
}

void cargarMenu(ifstream& archivo, void*& menu) {
    void** buffer = new void*[tam::buffer];
    int num = 0;
    while (cargarBebida(archivo, buffer[num])) num++;
    
    void** vv = new void*[num + 1] {};
    for (int i = 0; i < num; i++) {
        vv[i] = buffer[i];
    }
    
    menu = vv;
    
    delete[] buffer;
}

bool cargarBebida(ifstream& archivo, void*& bebida) {
    char* codigo;
    char* nombre;
    char* descripcion;
    char* tipo;
    double precio;
    int cantVent;
    
    if (!archivo.eof()) {
        char* codigo = leeCadena(archivo);
        char* nombre = leeCadena(archivo);
        char* descripcion = leeCadena(archivo);
        char* tipo = leeCadena(archivo);
        archivo >> precio;
        archivo.ignore();
        archivo >> cantVent;
        archivo.ignore();
        
        void**vv = new void*[tam::bebNumCampos];
        vv[cps::bebCodigo] = codigo;
        vv[cps::bebNombre] = nombre;
        vv[cps::bebDescripcion] = descripcion;
        vv[cps::bebTipo] = tipo;
        vv[cps::bebDisponible] = new bool(true);
        vv[cps::bebPrecio] = new double(precio);
        vv[cps::bebCantVent] = new int(cantVent);
        vv[cps::bebInsumoInv] = nullptr;
        
        bebida = vv;
        
        return true;
    }
    
    return false;
}

void actualizarMenu(const char* nombreArchivo, void* inventario, void* menu) {
    ifstream archivo(nombreArchivo, ios::in);
    actualizarMenu(archivo, inventario, menu);
}

void actualizarMenu(ifstream& archivo, void* inventario, void* menu) {
    void* insumo;
    char* codigoBebida;
    while(cargarInsumoBebida(archivo, inventario, insumo, codigoBebida)) {
        void* bebida = buscarBebida(codigoBebida, menu);
        agregarInsumoBebida(bebida, insumo);
    }
    
    verificarInventario(menu);
}

void verificarInventario(void* menu) {
    void** bebidas = (void**)menu;
    for (int i = 0; bebidas[i]; i++) {
        void** bebida = (void**)bebidas[i];
        void* insumos = (void**)bebida[cps::bebInsumoInv];
        
        int cantVentDiaria = *(int*)bebida[cps::bebCantVent];
        if (!existeSuficienteInsumoEnInventario(insumos, cantVentDiaria)) {
            *(bool*)bebida[cps::bebDisponible] = false;
        }
    }
}

bool existeSuficienteInsumoEnInventario(void* insumos, int cantVentDiarias) {
    bool suficiente = true;
    void** vv = (void**)insumos;
    for (int i = 0; vv[i]; i++) {
        void** insumo = (void**)vv[i];
        
        void** insumoInventario = (void**)insumo[cps::insCodigoInv];
        double* cantidadDisponible = (double*)insumoInventario[cps::invCantDisponible];
        double* cantidadRequerida = (double*)insumoInventario[cps::invCantRequerida];
        double* cantidadPorBebida = (double*)insumo[cps::insCant];
        
        double nuevaCantidadRequerida = *cantidadRequerida + ((*cantidadPorBebida / 1000.00) * cantVentDiarias);
        
        if (*cantidadDisponible < nuevaCantidadRequerida) {
            suficiente = false;
        }
        
        *cantidadRequerida = nuevaCantidadRequerida;
        insumoInventario[cps::invCantRequerida] = cantidadRequerida;
    }
    
    return suficiente;
}

void agregarInsumoBebida(void*& bebida, void* insumo) {
    void** vv = (void**)bebida;
    void** insumos = (void**)vv[cps::bebInsumoInv];
    
    int numInsumos = numInsumosBebida(insumos);
    incrementarInsumos(insumos, numInsumos, 1);
    insumos[numInsumos++] = insumo;
    vv[cps::bebInsumoInv] = insumos;
    bebida = vv;
}

void incrementarInsumos(void**& insumos, int num, int inc) {
    int cap = num + inc;
    void** vv = (void**)insumos;
    if (vv == nullptr) {
        vv = new void*[cap + 1] {};
    }
    else {
        void** aux = new void*[cap + 1] {};
        for (int i = 0; vv[i]; i++) {
            aux[i] = vv[i];
        }
        delete[] vv;
        vv = aux;
    }
    insumos = vv;
}

int numInsumosBebida(const void* insumos) {
    int num = 0;
    const void** vv = (const void**)insumos;
    if (vv != nullptr) 
        for (;vv[num];num++);
    
    return num;
}

bool cargarInsumoBebida(ifstream& archivo, const void* inventario, void*& insumo, char*& codigoBebida) {
    char* codigoInsumo;
    double cantidad;
    char* unidadMedida;
    
    if (!archivo.eof()) {
        codigoBebida = leeCadena(archivo);
        codigoInsumo = leeCadena(archivo);
        archivo >> cantidad;
        archivo.ignore();
        unidadMedida = leeCadena(archivo, '\n');
        
        void** vv = new void*[tam::insNumCapos];
        vv[cps::insCodigoInv] = buscarInsumo(codigoInsumo, inventario);
        vv[cps::insCant] = new double(cantidad);
        vv[cps::insUnidadMedida] = unidadMedida;
        
        insumo = vv;
        
        return true;
    }
    
    return false;
}

void* buscarInsumo(const char* codigoInsumo, const void* inventario) {
    const void** insumos = (const void**)inventario;
    void** resultado = nullptr;
    
    for (int i = 0; insumos[i]; i++) {
        void** insumo = (void**)insumos[i];
        char* codigo = (char*)insumo[0];
        
        if (strcmp(codigoInsumo, codigo) == 0) {
            resultado = insumo;
            break;
        }
    }
    
    return resultado;
}

void* buscarBebida(const char* codigoBebida, const void* menu) {
    const void** bebidas = (const void**)menu;
    void** resultado = nullptr;
    
    for (int i = 0; bebidas[i]; i++) {
        void** bebida = (void**)bebidas[i];
        char* codigo = (char*)bebida[0];
        
        if (strcmp(codigoBebida, codigo) == 0) {
            resultado = bebida;
            break;
        }
    }
    
    return resultado;
}

void reporteMenu(const char* nombreArchivo, const void* menu) {
    ofstream archivo(nombreArchivo, ios::out);
    reporteMenu(archivo, menu);
}

void reporteMenu(ofstream& archivo, const void* menu) {
    archivo << "============================= Menú del día ======================================" << endl;
    
    const void** bebidas = (const void**)menu;
    for (int i = 0; bebidas[i]; i++) {
        const void** bebida = (const void**)bebidas[i];
        
        const char* nombre = (const char*)bebida[cps::bebNombre];
        const char* descripcion = (const char*)bebida[cps::bebDescripcion];
        const char tipo = *(const char*)bebida[cps::bebTipo];
        const bool disponible = *(const bool*)bebida[cps::bebDisponible];
        const double precio = *(const double*)bebida[cps::bebPrecio];
     
        const char* nombreTipoBebida = getNombreTipoBebida(tipo);
        
        archivo << nombreTipoBebida << ": " << nombre << endl;
        archivo << descripcion << endl;
        archivo << "Precio: S/ " << fixed << setprecision(2) << precio << endl;
        archivo << "Disponible: " << (disponible ? "Si" : "No") << endl;
        
        archivo << "---------------------------------------------------------------------------------" << endl;
    }
}

const char* getNombreTipoBebida(const char tipo) {
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

char* leeCadena(ifstream& archivo, char delimitador) {
    char buffer[tam::buffer];
    archivo.getline(buffer, tam::buffer, delimitador);
    char* cadena = new char[strlen(buffer) + 1];
    
    strcpy(cadena, buffer);
    
    return cadena;
}
