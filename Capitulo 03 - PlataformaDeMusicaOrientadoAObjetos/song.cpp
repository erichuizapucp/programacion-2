#include "song.h"

void Song::loadData(ifstream &file) {
    Record::loadData(file);
    
    char comma;
    file >> this->duration >> comma; 
    file >> this->album;
}

void Song::print() {
    Record::print();
    cout << setw(10) << this->duration
         << setw(10) << this->album << endl;
}