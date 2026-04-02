#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const char* saludo = "hola mundo";
    const char* saludo3 = ", C++";
    char* saludo2 = new char[strlen(saludo) + 1];
    strcpy(saludo2, saludo);

    char* saludo4 = new char[strlen(saludo) + strlen(saludo3) + 1];
    strcpy(saludo4, saludo);
    strcat(saludo4, saludo3);

    int longitud = strlen(saludo4);

    if (strcmp(saludo, saludo4) == 0) {
        cout << "saludo y saludo2 son iguales." << endl;
    } else {
        cout << "saludo y saludo2 son diferentes." << endl;
    }

    cout << saludo4 << ", Longitud: " << longitud << endl;

    return 0;
}
