#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <cctype>

using namespace std;

bool compararFrecuenciaDesc(const pair<std::string, int>& a,
                            const pair<std::string, int>& b) {
    return a.second > b.second;
}

int main() {
    string texto = R"(En una galaxia muy, muy lejana, una guerra eterna se desata entre el bien y el mal, entre la luz y la oscuridad. La Guerra de las Galaxias es más que una simple batalla; es una lucha épica que atraviesa generaciones, donde héroes y villanos se enfrentan en un universo vasto y misterioso. La Fuerza, una energía mística que permea todo el cosmos, guía a quienes pueden sentirla, otorgándoles poderes más allá de la comprensión humana.
Los Jedi, guardianes de la paz y la justicia, canalizan la Fuerza para proteger a los inocentes y mantener el equilibrio. Con sus sables de luz resplandecientes, defienden los valores de la esperanza y el honor. Son sabios y disciplinados, entrenados desde jóvenes para resistir las tentaciones del lado oscuro.
Sin embargo, siempre acecha una amenaza mayor: los Sith, seguidores del lado oscuro de la Fuerza, que buscan dominar la galaxia y someterla a su voluntad. Usan la ira, el odio y la codicia para incrementar su poder, y su ambición no conoce límites. Su presencia es una sombra oscura que corrompe planetas enteros y destruye civilizaciones.
La historia cuenta que hace mucho tiempo, la galaxia vivió una era dorada bajo la protección de los Jedi. Pero con la llegada de los Sith, la guerra estalló y el equilibrio se rompió. Batallas épicas, alianzas inesperadas y sacrificios heroicos marcaron el destino de incontables mundos.
En medio de este conflicto, surgieron figuras legendarias: Luke Skywalker, el joven granjero destinado a convertirse en un Jedi poderoso; Darth Vader, el guerrero oscuro cuyo pasado estaba envuelto en tragedia; y la princesa Leia, líder valiente y símbolo de la resistencia.
Cada planeta, cada rincón del cosmos, fue escenario de combates frenéticos y momentos de esperanza. Las estrellas brillaban como testigos silenciosos de un destino que solo podría cumplirse cuando la Fuerza se equilibrara de nuevo.
Así, la saga de La Guerra de las Galaxias sigue viva en los corazones de todos aquellos que creen en la lucha entre la luz y la oscuridad, en la fuerza que mueve el universo y en la eterna esperanza de que, al final, el bien prevalecerá.)";

    set<string> stopWords = {
        "se", "a", "su", "que", "la", "de", "las", "es", "un", "una", "en", "los", "y", "el", "del", "por", "para", "con"
    };

    map<string, int> bagOfWords;

    // Convertir el texto a minúsculas y eliminar símbolos de puntuación palabra por palabra
    istringstream iss(texto);
    string palabra;

    while (iss >> palabra) {
        // Convertir a minúsculas
        for (char& c : palabra) {
            c = tolower(c);
        }

        // Eliminar puntuación simple al final
        while (!palabra.empty() && ispunct(palabra.back())) {
            palabra.pop_back();
        }

        // Solo contar si no es stop word
        if (stopWords.find(palabra) == stopWords.end() && !palabra.empty()) {
            ++bagOfWords[palabra];
        }
    }

    // Mostrar resultados desordenados
    cout << "\n--- Bag of Words Desordenado ---\n";
    for (const pair<const string, int>& pair : bagOfWords) {
        cout 
            << "Palabra: " << pair.first 
            << " - Frecuencia: " << pair.second << endl;
    }
    
    cout << endl;
    cout << "\n--- Bag of Words Ordenado ---\n";
    // Mostrar resultados ordenados
    vector<pair<string, int>> vec(bagOfWords.begin(), bagOfWords.end());
    sort(vec.begin(), vec.end(), compararFrecuenciaDesc);
    for (const pair<const string, int>& pair : vec) {
        cout 
            << "Palabra: " << pair.first 
            << " - Frecuencia: " << pair.second << endl;
    }
    
    // Usar find para buscar una subcadena (ejemplo con "fuerza")
    string ejemplo1 = "el lado oscuro de la fuerza";
    size_t pos = ejemplo1.find("fuerza");
    if (pos != string::npos) {
        cout << "La palabra contiene 'fuerza': " << palabra << endl;
    }
    
    // Ejemplo de substr
    string ejemplo2 = "galaxias";
    string sub = ejemplo2.substr(0, 4);  // "gala"
    cout << "\nSubcadena de '" << ejemplo2 << "': " << sub << endl;

    return 0;
}
