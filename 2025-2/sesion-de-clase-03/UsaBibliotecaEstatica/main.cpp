#include <iostream>
#include "RedSocial/estructuras.h"
#include "RedSocial/funciones.h"

using namespace std;

int main() {
    RedSocial red { "PUCP Network", {}, 0 };
    cargarRedSocial(red);

    cout << red << endl;

    return 0;
}