#include <cstdlib>
#include "lista.h"
#include "cola.h"
#include "funciones.h"

using namespace std;


int main(int argc, char** argv) {    
    cout << "Lista de Enteros" << endl;
    Lista lista {};
    inicializar(lista, destruirEntero);

    insertar(lista, lista.cola, new int(1));
    insertar(lista, lista.cola, new int(2));
    insertar(lista, lista.cola, new int(3));
    insertar(lista, lista.cola, new int(4));
    insertar(lista, lista.cola, new int(5));

    recorrer(lista, mostrarEntero);

    destruir(lista);
    
    // Meseros
    inicializar(lista, destruirMesero);
    cargarDatos("meseros.csv", lista, cargarMesero);
    mostrarDatos("reporteMeseros.txt", lista, mostrarCabeceraMeseros, mostrarMesero);
    destruir(lista);
    
    cout << endl << "Cola de Enteros" << endl;
    
    Cola cola {};
    inicializar(cola, destruirEntero);
    
    encolar(cola, new int(1));
    encolar(cola, new int(2));
    encolar(cola, new int(3));
    encolar(cola, new int(4));
    encolar(cola, new int(5));

    void* dato;
    if (desencolar(cola, dato)) {
        cout << "Dato desencolado: " << *(int*)dato << endl;
    }
    
    recorrer(cola, mostrarEntero);
    
    destruir(cola);
    
    return 0;
}

