#include "funciones.h"

bool operator>>(Datos& datos, Cliente& cliente) {
    if (datos.dnis == nullptr || datos.montos == nullptr) {
        return false;
    }
    
    int dni = *datos.dnis;
    int monto = *datos.montos;
    
    if (dni != -1 && monto != -1.0) {
        cliente.dni = dni;
        cliente.subTotal = monto;
        datos.dnis++;
        datos.montos++;
        
        return true;
    }
    
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
    os   << setw(8) << "DNI" 
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

void descuento(Cliente*& cliente, double tarifa) {
    descuento(cliente->subTotal, cliente->descuento, tarifa);
}

void descuento(double monto, double& descuento, double tarifa) {
    descuento = monto * tarifa;
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

bool operator>>(Datos& datos, Empleado& empleado) {
    if (datos.dnis == nullptr || datos.montos == nullptr) {
        return false;
    }
    
    int dni = *datos.dnis;
    int monto = *datos.montos;
    
    if (dni != -1 && monto != -1.0) {
        empleado.dni = dni;
        empleado.sueldoBruto = monto;
        datos.dnis++;
        datos.montos++;
        
        return true;
    }
    
    empleado.dni = -1;
    empleado.sueldoBruto = -1.0;
    
    return false;
}

ostream& operator<<(ostream& os, Empleado* empleados) {
    os  << setw(8) << "DNI" 
            << setw(15) << "SUELDOBRUTO" 
            << setw(10) << "IMPUESTOS" 
            << setw(15) << "SUELDONETO" 
            << endl;
    
    for (Empleado* empleado = empleados; empleado->dni != -1; empleado++) {
        os << *empleado;
    }
    
    return os;
}

ostream& operator<<(ostream& os, Empleado& empleado) {
    os << left << setw(8) << empleado.dni 
            << right 
            << setw(15) << fixed << setprecision(2) << empleado.sueldoBruto 
            << setw(10) << setprecision(2) << empleado.impuestos
            << setw(15) << setprecision(2) << empleado.sueldoNeto
            << endl;
    
    return os;
}

void calcularTotales(Empleado*& empleados, double limite) {
    for (Empleado* empleado = empleados; empleado->dni != -1; empleado++) {
        // si el subtotal es superior a 180 se agrega un 5% de descuento antes de impuestos
        if (empleado->sueldoBruto >= limite) {
            descuento(empleado, 0.08);
        }
        else {
            descuento(empleado, 0.0);
        }
        calcular(empleado);
    }
}

void calcular(Empleado*& empleado) {
    calcular(empleado->sueldoBruto, empleado->impuestos, empleado->sueldoNeto);
}

void calcular(double sueldoBruto, double impuestos, double& sueldoNeto) {
    sueldoNeto =  sueldoBruto - impuestos;
}

void descuento(Empleado*& empleado, double tarifa) {
    descuento(empleado->sueldoBruto, empleado->impuestos, tarifa);
}