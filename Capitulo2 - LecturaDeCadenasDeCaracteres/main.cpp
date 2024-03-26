#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include "reports.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "BIENVENIDO A LA APLICACIÓN ESTUDIANTE" << endl;
    cout << "Opciones: " << endl;
    cout << "1: Mostrar Reporte" << endl;
    cout << "2: Escribir Reporte" << endl;
    cout << "3: Mostrar y Escribir Reporte" << endl;
    cout << "Ingrese la opción: ";
    
    ifstream input("students.txt");
    if (!input.is_open()) {
        cerr << "Error abriendo el archivo de entrada." << endl;
        return 1;
    }
    
    ofstream output("report.txt");
    if (!output.is_open()) {
        cerr << "Error abriendo el archivo de salida." << endl;
        return 1;
    }
    
    char c;
    c = cin.get();
    
    switch (c) {
        case '1':
            showreportoptimized(input);
            //showreport(input);
            break;
        case '2':
            writereport(input, output);
            break;
        case '3':
            showreportoptimized(input);
            //showreport(input);
            writereport(input, output);
            break;
    }
    
    input.close();
    output.close();

    return 0;
}
