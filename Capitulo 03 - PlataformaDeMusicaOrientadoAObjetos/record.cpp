#include "record.h"

int Record::getId() {
    return id;
}

char* Record::getName() {
    return name;
}

void Record::readString(ifstream& input, char* &data, char delim) {
    char buffer[50];
    input.getline(buffer, 50, delim);
    
    data = new char[strlen(buffer) + 1];
    strcpy(data, buffer);
}

void Record::readIntArray(const char* input, int *&arr, int &numData) {
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

void Record::loadData(ifstream &file) {
    char comma;
    
    file >> this->id >> comma;
    readString(file, this->name);
}

void Record::print() {
    cout << left << setw(10) << this->id
         << setw(50) << this->name;
}

int Record::cmp(const void* a, const void* b) {
    Record* rec1 = *(Record**)a;
    Record* rec2 = *(Record**)b;
    
    return strcmp(rec1->name, rec2->name);
}

//bool Record::equals(Record &other) {
//    return this->id == other->id && this->name == other->name;
//}
//
//bool Record::compareTow(Record &r1, Record &r2) {
//    return r1->id == r2->id && r1->name == r2->name;
//}

Record::~Record() {
    delete[] name;
}