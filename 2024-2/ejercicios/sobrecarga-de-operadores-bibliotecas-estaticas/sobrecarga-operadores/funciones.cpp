#include "funciones.h"

void operator>>(Datos& datos, Cliente*& clientes) {
    int num;
    // itera hasta llegar al final de los DNIs para saber la cantidad de clientes
    for (num = 0; datos.dnis[num] != -1; num++);
    
    // siempre agregamos un elemento más para saber cuando parar al recorrer el arreglo
    clientes = new Cliente[num + 1];
    // declaramos un puntero temporal para moverse a través del arreglo usando aritmética de punteros.
    // no se recomienda usar el arreglo para realizar el movimiento porque eso causará que se pierda
    // la referencia a la ubicación original.
    Cliente* ptr = clientes;
    while (datos >> *ptr) {
        ptr++;
    }
}

bool operator>>(Datos& datos, Cliente& cliente) {
    if (datos.dnis == nullptr || datos.subTotales == nullptr) {
        return false;
    }
    
    int dni = *datos.dnis;
    int subTotal = *datos.subTotales;
    
    if (dni != -1 && subTotal != -1.0) {
        cliente.dni = dni;
        cliente.subTotal = subTotal;
        datos.dnis++;
        datos.subTotales++;
        
        return true;
    }
    
    // colocamos los datos de cierre en la posición final
    cliente.dni = -1;
    cliente.subTotal = -1.0;
    
    return false;
}

void calcularTotales(Cliente*& clientes, double limiteDesc) {
    for (Cliente* cliente = clientes; cliente->dni != -1; cliente++) {
        // si el subtotal es superior a 180 se agrega un 5% de descuento antes de impuestos
        if (cliente->subTotal >= limiteDesc) {
            descuento(cliente);
        }
        calcular(cliente);
    }
}

ostream& operator<<(ostream& os, Cliente* clientes) {
    os << setw(8) << "DNI" 
            << setw(10) << "SUBTOTAL" 
            << setw(10) << "DESCUENTO" 
            << setw(14) << "SUBTOTALDESC" 
            << setw(10) << "IGV" 
            << setw(10) << "TOTAL" 
            << endl;
    
    for (Cliente* cliente = clientes; cliente->dni != -1; cliente++) {
        os << *cliente;
    }
    
    return os;
}

ostream& operator<<(ostream& os, Cliente& cliente) {
    os << left << setw(8) << cliente.dni 
            << right
            << setw(10) << fixed << setprecision(2) << cliente.subTotal 
            << setw(10) << setprecision(2) << cliente.descuento
            << setw(14) << setprecision(2) << cliente.subTotalDescuento
            << setw(10) << setprecision(2) << cliente.igv
            << setw(10) << setprecision(2) << cliente.total 
            << endl;
    
    return os;
}

void calcular(Cliente*& cliente) {
    calcular(cliente->subTotal, cliente->descuento, 
            cliente->subTotalDescuento, cliente->igv, cliente->total);
}

void calcular(double subTotal, double descuento, double& subTotalDescuento, 
        double& igv, double& total, double tarifaIgv) {
    subTotalDescuento = subTotal - descuento;
    igv = subTotalDescuento * tarifaIgv;
    total = subTotalDescuento + igv;
}

void descuento(Cliente*& cliente) {
    descuento(cliente->subTotal, cliente->descuento);
}

void descuento(double subTotal, double& descuento, double tarifa) {
    descuento = subTotal * tarifa;
}