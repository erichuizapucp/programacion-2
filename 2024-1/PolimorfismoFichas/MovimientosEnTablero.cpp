#include "MovimientosEnTablero.h"

void MovimientosEnTablero::cagar_y_moverfichas(
    const char* nombArchFichas, 
    const char* nombArchMovimientos, 
    const char* nombArchReporte
) {
    ifstream archFichas(nombArchFichas, ios::in);
    if (!archFichas) {
        cout << "No se puede abrir el archivo: " << nombArchFichas << endl;
        exit(1);
    }
    
    ifstream archMovimientos(nombArchMovimientos, ios::in);
    if (!archMovimientos) {
        cout << "No se puede abrir el archivo: " << nombArchMovimientos << endl;
        exit(1);
    }
    
    ofstream archReporte(nombArchReporte, ios::out);
    if (!archReporte) {
        cout << "No se puede abrir el archivo: " << nombArchReporte << endl;
        exit(1);
    }
    
    tablero.leerFichas(archFichas);
    archReporte << "Posiciones iniciales de las fichas: " << endl;
    tablero.imprimeDatos(archReporte);
    archReporte << endl << endl;
    tablero.leerMovimientos(archMovimientos);
    archReporte << "Posiciones finales: " << endl;
    tablero.imprimeDatos(archReporte);
}