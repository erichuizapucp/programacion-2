#include "utils.h"
#include <cstring>

using namespace std;

void openFile(const char* fileName, ifstream& file) {
    file.open(fileName, ios::in);
    
    if (!file.is_open()) {
        cerr << "Error abriendo el archivo de entrada." << fileName << endl;
        exit(1);
    }
}

void openFile(const char* fileName, ofstream& file) {
    file.open(fileName, ios::out);
    
    if (!file.is_open()) {
        cerr << "Error abriendo el archivo de entrada." << fileName << endl;
        exit(1);
    }
}

void readString(ifstream& input, char* &data, char delim) {
    char buffer[50];
    input.getline(buffer, 50, delim);
    
    data = new char[strlen(buffer) + 1];
    strcpy(data, buffer);
}

void readIntArray(const char* input, int *&arr, int &numData) {
    istringstream ss(input);
    
    int buffer[100];
    numData = 0;
    while(1) {
        if (ss.eof()) {
            break;
        }
        ss >> buffer[numData];
        ss.get(); // no se lee la coma
        numData++;
    }
    
    arr = new int[numData];
    
    for (int index = 0; index < numData; index++) {
        arr[index] = buffer[index];
    }
}
