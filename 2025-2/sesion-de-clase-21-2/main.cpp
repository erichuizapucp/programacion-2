#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str1 = "Hello, ";
    string str2 = "World";
    cout << str1 + str2 << endl;

    vector<string> cadenas;
    cadenas.push_back("Hello, ");
    cadenas.push_back("world.");


    vector<int> numeros;
    numeros.push_back(1);
    numeros.push_back(2);
    numeros.push_back(3);

    return 0;
}