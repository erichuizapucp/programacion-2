#include <cstdlib>
#include "cafeteria.h"
#include "pruebas.h"

using namespace std;

int main(int argc, char** argv) {
    void *inventario, *menu;
    
    cargarInventario("inventario.csv", inventario);
    probarCargaInventario("prueba-inventario.txt", inventario);
    
    cargarMenu("menu.csv", menu);
    pruebaCargaMenu("menu-inicial.txt", menu);
    actualizarMenu("insumos-bebidas.csv", inventario, menu);    
    reporteMenu("menu.txt", menu);
    
    return 0;
}