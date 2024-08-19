#include "cliente.h"

void cargarClientes(int* dnis, double* subTotales, Cliente*& clientes) {
    int num;
    for (num = 0; dnis[num] != -1; num++);
    
    clientes = new Cliente[num + 1];
    
    // se usa <= num porque se quiere copiar el valor de corte dni == -1
    for (int i = 0; i <= num; i++) {
        clientes[i].dni = dnis[i];
        clientes[i].subTotal = subTotales[i];
    }
}

void calcularTotales(Cliente*& clientes, double limiteDesc) {
    for (Cliente* cliente = clientes; cliente->dni != -1; ++cliente) {
        // si el subtotal es superior a 180 se agrega un 5% de descuento antes de impuestos
        if (cliente->subTotal >= limiteDesc) {
            descuento(cliente);
        }
        calcular(cliente);
    }
}

void imprimirClientes(Cliente* clientes) {
    cout << left 
            << setw(10) << "DNI" 
            << setw(10) << "SUBTOTAL" 
            << setw(10) << "DESCUENTO" 
            << setw(14) << "SUBTOTALDESC" 
            << setw(10) << "IGV" 
            << setw(10) << "TOTAL" 
            << endl;
    
    for (Cliente* cliente = clientes; cliente->dni != -1; ++cliente) {
        imprimir(cliente);
    }
}

void calcular(Cliente*& cliente) {
    calcular(cliente->subTotal, cliente->descuento, 
            cliente->subTotalDescuento, cliente->igv, cliente->total);
}

void calcular(double subTotal, double descuento, double& subTotalDescuento, 
        double& igv, double& total, double porcetajeIgv) {
    subTotalDescuento = subTotal - descuento;
    igv = subTotalDescuento * porcetajeIgv;
    total = subTotalDescuento + igv;
}

void descuento(Cliente*& cliente) {
    descuento(cliente->subTotal, cliente->descuento);
}

void descuento(double subTotal, double& descuento, double porcentajeDescuento) {
    descuento = subTotal * porcentajeDescuento;
}

void imprimir(Cliente* cliente) {
    cout << setw(10) << cliente->dni 
            << setw(10) << fixed << setprecision(2) << cliente->subTotal 
            << setw(10) << setprecision(2) << cliente->descuento
            << setw(14) << setprecision(2) << cliente->subTotalDescuento
            << setw(10) << setprecision(2) << cliente->igv
            << setw(10) << setprecision(2) << cliente->total 
            << endl;
}