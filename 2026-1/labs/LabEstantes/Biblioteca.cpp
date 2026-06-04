#include "Biblioteca.h"
#include "funciones.h"
#include <fstream>
#include <iomanip>

Biblioteca::Biblioteca() {
    cantidadEstantesVerticales = 0;
    cantidadEstantesHorizontales = 0;
    cantidadTotalEnciclopedias = 0;
    cantidadTotalNovelas = 0;
}

void Biblioteca::cargarNovela(ifstream& archivo) {
    Novela novela;
    char* codigo = leerCadena(archivo, ',');
    char* nombre = leerCadena(archivo, ',');
    int ancho, alto;
    char* tipo;
    double peso;

    saltarEspacios(archivo);
    archivo >> ancho;
    consumirComa(archivo);
    saltarEspacios(archivo);
    archivo >> alto;
    consumirComa(archivo);
    tipo = leerCadena(archivo, ',');
    saltarEspacios(archivo);
    archivo >> peso;
    consumirFinLinea(archivo);

    novela.setCodigo(codigo);
    novela.setNombre(nombre);
    novela.setAncho(ancho);
    novela.setAlto(alto);
    novela.setTipo(tipo);
    novela.setPeso(peso);
    novela.setColocado(false);

    if (cantidadTotalNovelas < 200) {
        novelas[cantidadTotalNovelas++] = novela;
    }

    delete[] codigo;
    delete[] nombre;
    delete[] tipo;
}

void Biblioteca::cargarEnciclopedia(ifstream& archivo) {
    Enciclopedia enciclopedia;
    char* codigo = leerCadena(archivo, ',');
    char* nombre = leerCadena(archivo, ',');
    int ancho, alto, volumen;
    double peso;

    saltarEspacios(archivo);
    archivo >> ancho;
    consumirComa(archivo);
    saltarEspacios(archivo);
    archivo >> alto;
    consumirComa(archivo);
    saltarEspacios(archivo);
    archivo >> volumen;
    consumirComa(archivo);
    saltarEspacios(archivo);
    archivo >> peso;
    consumirFinLinea(archivo);

    enciclopedia.setCodigo(codigo);
    enciclopedia.setNombre(nombre);
    enciclopedia.setAncho(ancho);
    enciclopedia.setAlto(alto);
    enciclopedia.setVolumen(volumen);
    enciclopedia.setPeso(peso);
    enciclopedia.setColocado(false);

    if (cantidadTotalEnciclopedias < 200) {
        enciclopedias[cantidadTotalEnciclopedias++] = enciclopedia;
    }

    delete[] codigo;
    delete[] nombre;
}

void Biblioteca::cargarLibros() {
    ifstream archivo("libros.csv", ios::in);
    char tipo;
    if (not archivo.is_open()) {
        return;
    }

    while (archivo >> tipo) {
        consumirComa(archivo);
        if (tipo == 'N') {
            cargarNovela(archivo);
        }
        else if (tipo == 'E') {
            cargarEnciclopedia(archivo);
        }
        else {
            consumirFinLinea(archivo);
        }
    }
}

void Biblioteca::cargarEstanteHorizontal(ifstream& archivo) {
    EstanteHorizontal estante;
    char* codigo = leerCadena(archivo, ',');
    int anchura, altura;
    double peso;

    saltarEspacios(archivo);
    archivo >> anchura;
    consumirComa(archivo);
    saltarEspacios(archivo);
    archivo >> altura;
    consumirComa(archivo);
    saltarEspacios(archivo);
    archivo >> peso;

    consumirFinLinea(archivo);

    estante.setCodigo(codigo);
    estante.setAnchura(anchura);
    estante.setAltura(altura);
    estante.setPesoSoportado(peso);
    estante.setPesoActual(0);
    estante.crearMatriz();
    estante.setCantidadNovelas(0);

    if (cantidadEstantesHorizontales < 40) {
        estantesHorizontales[cantidadEstantesHorizontales++] = estante;
    }
    delete[] codigo;
}

void Biblioteca::cargarEstanteVertical(ifstream& archivo) {
    EstanteVertical estante;
    char* codigo = leerCadena(archivo, ',');
    int anchura, altura;
    double peso;

    saltarEspacios(archivo);
    archivo >> anchura;
    consumirComa(archivo);
    saltarEspacios(archivo);
    archivo >> altura;
    consumirComa(archivo);
    saltarEspacios(archivo);
    archivo >> peso;

    consumirFinLinea(archivo);

    estante.setCodigo(codigo);
    estante.setAnchura(anchura);
    estante.setAltura(altura);
    estante.setPesoSoportado(peso);
    estante.setPesoActual(0);
    estante.crearMatriz();
    estante.setCantidadEnciclopedias(0);

    if (cantidadEstantesVerticales < 40) {
        estantesVerticales[cantidadEstantesVerticales++] = estante;
    }
    delete[] codigo;
}

void Biblioteca::cargarEstantes() {
    ifstream archivo("estantes.csv", ios::in);
    char tipo;
    if (not archivo.is_open()) {
        return;
    }

    while (archivo >> tipo) {
        consumirComa(archivo);
        if (tipo == 'H') {
            cargarEstanteHorizontal(archivo);
        }
        else if (tipo == 'V') {
            cargarEstanteVertical(archivo);
        }
        else {
            consumirFinLinea(archivo);
        }
    }
}

bool Biblioteca::colocarNovela(Novela& novela) {
    for (int i = 0; i < cantidadEstantesHorizontales; i++) {
        if (estantesHorizontales[i].insertarNovela(novela)) {
            novela.setColocado(true);
            return true;
        }
    }
    return false;
}

bool Biblioteca::colocarEnciclopedia(Enciclopedia& enciclopedia) {
    for (int i = 0; i < cantidadEstantesVerticales; i++) {
        if (estantesVerticales[i].insertarEnciclopedia(enciclopedia)) {
            enciclopedia.setColocado(true);
            return true;
        }
    }
    return false;
}

void Biblioteca::imprimirDetalleNovelas(EstanteHorizontal& estante) {
    cout << left << setw(10) << "CODIGO" << setw(30) << "NOMBRE"
         << setw(8) << "ANCHO" << setw(8) << "ALTO" << setw(8) << "PESO" << endl;

    for (int j = 0; j < estante.getCantidadNovelas(); j++) {
        const Novela& novela = estante.getNovelas()[j];
        cout << left << setw(10) << novela.getCodigo()
             << setw(30) << novela.getNombre()
             << setw(8) << novela.getAncho()
             << setw(8) << novela.getAlto()
             << setw(8) << novela.getPeso() << endl;
    }
    cout << "-------------------------------------------------------" << endl;
}

void Biblioteca::imprimirDetalleEnciclopedias(EstanteVertical& estante) {
    cout << left << setw(10) << "CODIGO" << setw(30) << "NOMBRE"
         << setw(8) << "ANCHO" << setw(8) << "ALTO" << setw(8) << "PESO" << endl;

    for (int j = 0; j < estante.getCantidadEnciclopedias(); j++) {
        const Enciclopedia& enciclopedia = estante.getEnciclopedias()[j];
        cout << left << setw(10) << enciclopedia.getCodigo()
             << setw(30) << enciclopedia.getNombre()
             << setw(8) << enciclopedia.getAncho()
             << setw(8) << enciclopedia.getAlto()
             << setw(8) << enciclopedia.getPeso() << endl;
    }
    cout << "-------------------------------------------------------" << endl;
}

void Biblioteca::posicionarLibros() {
    for (int i = 0; i < cantidadTotalNovelas; i++) {
        colocarNovela(novelas[i]);
    }
    for (int i = 0; i < cantidadTotalEnciclopedias; i++) {
        colocarEnciclopedia(enciclopedias[i]);
    }
}

void Biblioteca::mostrarDatos() {
    cout << "=======================================================" << endl;
    cout << "       Informacion del posicionamiento de Libros        " << endl;
    cout << "           en los estantes de la Biblioteca             " << endl;
    cout << "=======================================================" << endl;
    cout << "Cantidad de Estantes: "
         << cantidadEstantesHorizontales + cantidadEstantesVerticales << endl;
    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i < cantidadEstantesHorizontales; i++) {
        EstanteHorizontal& estante = estantesHorizontales[i];
        cout << "Codigo Estante: " << left << setw(10) << estante.getCodigo();
        cout << " Cantidad de Libros: " << estante.getCantidadNovelas() << endl;
        cout << "Anchura X Altura : " << estante.getAnchura() << " x " << estante.getAltura();
        cout << "   Peso Maximo: " << fixed << setprecision(2) << estante.getPesoSoportado() << " Kg" << endl;
        cout << "Tipo: Horizontal";
        cout << "            Peso Total: " << setw(6) << estante.getPesoActual() << " Kg" << endl;
        cout << "-------------------------------------------------------" << endl << endl;

        estante.mostrarMatriz(cout);
        cout << endl;
        imprimirDetalleNovelas(estante);
    }

    for (int i = 0; i < cantidadEstantesVerticales; i++) {
        EstanteVertical& estante = estantesVerticales[i];
        cout << "Codigo Estante: " << left << setw(10) << estante.getCodigo();
        cout << " Cantidad de Libros: " << estante.getCantidadEnciclopedias() << endl;
        cout << "Anchura X Altura : " << estante.getAnchura() << " x " << estante.getAltura();
        cout << "   Peso Maximo: " << fixed << setprecision(2) << estante.getPesoSoportado() << " Kg" << endl;
        cout << "Tipo: Vertical";
        cout << "              Peso Total: " << setw(6) << estante.getPesoActual() << " Kg" << endl;
        cout << "-------------------------------------------------------" << endl << endl;

        estante.mostrarMatriz(cout);
        cout << endl;
        imprimirDetalleEnciclopedias(estante);
    }

    cout << "=======================================================" << endl;
    cout << "Informacion de todos los Libros:" << endl;
    cout << "Cantidad de Libros Total: "
         << cantidadTotalNovelas + cantidadTotalEnciclopedias << endl;

    for (int i = 0; i < cantidadTotalNovelas; i++) {
        cout << left << setw(10) << novelas[i].getCodigo()
             << setw(30) << (novelas[i].getColocado() ? novelas[i].getNombre() : "NO SE PUDO COLOCAR")
             << setw(8) << novelas[i].getAncho()
             << setw(8) << novelas[i].getAlto()
             << setw(8) << novelas[i].getPeso() << endl;
    }
    for (int i = 0; i < cantidadTotalEnciclopedias; i++) {
        cout << left << setw(10) << enciclopedias[i].getCodigo()
             << setw(30) << (enciclopedias[i].getColocado() ? enciclopedias[i].getNombre() : "NO SE PUDO COLOCAR")
             << setw(8) << enciclopedias[i].getAncho()
             << setw(8) << enciclopedias[i].getAlto()
             << setw(8) << enciclopedias[i].getPeso() << endl;
    }
    cout << "=======================================================" << endl;
}
