#include "Persona.h"

Persona::Persona(
) : dni(0), 
    edad(0), 
    altura(0.0), 
    peso(0.0), 
    nombre(nullptr), 
    nacionalidad(Nacionalidad::Otro) {
    cout << "Constructor por defecto de Persona." << endl;
}

Persona::Persona(
    int dni, 
    char* nombre, 
    int edad, 
    double altura, 
    double peso, 
    Nacionalidad nacionalidad
) : dni(dni), 
    edad(edad), 
    altura(altura), 
    peso(peso), 
    nombre(nombre), 
    nacionalidad(nacionalidad) {
    cout << "Constructor sobrecargado de Persona." << endl;
}

void Persona::setNombre(char* nombre) {
    this->nombre = nombre;
}

void Persona::setDni(int dni) {
    this->dni = dni;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setAltura(double altura) {
    this->altura = altura;
}

void Persona::setPeso(double peso) {
    this->peso = peso;
}

void Persona::setNacionalidad(Nacionalidad nacionalidad) {
    this->nacionalidad = nacionalidad;
}

void Persona::cargar(ifstream &archivo) {
    char comma;
    archivo >> this->dni >> comma;
    this->nombre = leerCadena(archivo);
    archivo >> this->edad >> comma;
    archivo >> this->altura >> comma;
    archivo >> this->peso >> comma;
    
    char* strNacionalidad = leerCadena(archivo);
    this->nacionalidad = nacionalidadAEnum(strNacionalidad);
}

void Persona::imprimir(ostream &os) {
    if (dni > 0) {
        os << "DNI: " << dni << endl;
    }
    
    if (nombre != nullptr) {
        os << "Nombre: " << nombre << endl;
    }
    
    if (edad > 0) {
        os << "Edad: " << edad << endl; 
    }
    
    if (altura > 0.0) {
        os << "Altura: " << altura << endl;
    }
    
    if (peso > 0.0) {
        os << "Peso: " << peso << endl;;
    }
    
    if (nacionalidad != Nacionalidad::Otro) {
        os << "Nacionalidad: " << nacionalidadACadena(nacionalidad) << endl;
    }
}

void Persona::grabar(ofstream& archivo) {
    archivo << dni << "," << nombre << "," << edad << "," << altura << ","
            << peso << "," << nacionalidadACadena(nacionalidad) << ",";
}

const char* Persona::nacionalidadACadena(Nacionalidad nac) {
    const char* nacionalidad;
    switch (nac) {
        case Nacionalidad::Peru:
            nacionalidad = "Perú";
            break;
        case Nacionalidad::Argentina:
            nacionalidad = "Argentina";
            break;
        case Nacionalidad::Brasil:
            nacionalidad = "Brasil";
            break;
        case Nacionalidad::Bolivia:
            nacionalidad = "Bolivia";
            break;
        case Nacionalidad::Chile:
            nacionalidad = "Chile";
            break;
        case Nacionalidad::Colombia:
            nacionalidad = "Colombia";
            break;
        case Nacionalidad::Ecuador:
            nacionalidad = "Ecuador";
            break;
        case Nacionalidad::Paraguay:
            nacionalidad = "Paraguay";
            break;
        case Nacionalidad::Uruguay:
            nacionalidad = "Uruguay";
            break;
        case Nacionalidad::Venezuela:
            nacionalidad = "Venezuela";
            break;
        case Nacionalidad::EstadosUnidos:
            nacionalidad = "Estados Unidos";
            break;
        case Nacionalidad::Espanna:
            nacionalidad = "España";
            break;
        case Nacionalidad::Francia:
            nacionalidad = "Francia";
            break;
        case Nacionalidad::Italia:
            nacionalidad = "Italia";
            break;
        case Nacionalidad::Alemania:
            nacionalidad = "Alemania";
            break;
        default:
            nacionalidad = "Otro";
            break;
    }
    
    return nacionalidad;
}

Nacionalidad Persona::nacionalidadAEnum(char* strNacionalidad) {
    Nacionalidad nac;
    
    if (strcmp(strNacionalidad, "Perú") == 0) {
        nac = Nacionalidad::Peru;
    }
    else if (strcmp(strNacionalidad, "Argentina") == 0) {
        nac = Nacionalidad::Argentina;
    }
    else if (strcmp(strNacionalidad, "Brasil") == 0) {
        nac = Nacionalidad::Brasil;
    }
    else if (strcmp(strNacionalidad, "Bolivia") == 0) {
        nac = Nacionalidad::Bolivia;
    }
    else if (strcmp(strNacionalidad, "Chile") == 0) {
        nac = Nacionalidad::Chile;
    }
    else if (strcmp(strNacionalidad, "Colombia") == 0) {
        nac = Nacionalidad::Colombia;
    }
    else if (strcmp(strNacionalidad, "Ecuador") == 0) {
        nac = Nacionalidad::Ecuador;
    }
    else if (strcmp(strNacionalidad, "Paraguay") == 0) {
        nac = Nacionalidad::Paraguay;
    }
    else if (strcmp(strNacionalidad, "Uruguay") == 0) {
        nac = Nacionalidad::Uruguay;
    }
    else if (strcmp(strNacionalidad, "Venezuela") == 0) {
        nac = Nacionalidad::Venezuela;
    }
    else if (strcmp(strNacionalidad, "Estados Unidos") == 0) {
        nac = Nacionalidad::EstadosUnidos;
    }
    else if (strcmp(strNacionalidad, "España") == 0) {
        nac = Nacionalidad::Espanna;
    }
    else if (strcmp(strNacionalidad, "Francia") == 0) {
        nac = Nacionalidad::Francia;
    }
    else if (strcmp(strNacionalidad, "Italia") == 0) {
        nac = Nacionalidad::Italia;
    }
    else if (strcmp(strNacionalidad, "Alemania") == 0) {
        nac = Nacionalidad::Alemania;
    }
    else {
        nac = Nacionalidad::Otro;
    }
    
    return nac;
}

Persona::~Persona() {
    cout << "Destructor de Persona" << endl;
}