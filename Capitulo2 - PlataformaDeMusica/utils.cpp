#include "utils.h"
#include "structs.h"
#include <cstring>
#include <sstream>

using namespace std;

bool openFile(const char* fileName, ifstream& file) {
    file.open(fileName);
    
    if (!file.is_open()) {
        cerr << "Error abriendo el archivo de entrada." << endl;
        return false;
    }
    
    return true;
}

void readString(ifstream& input, char *&data, char delim) {
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
