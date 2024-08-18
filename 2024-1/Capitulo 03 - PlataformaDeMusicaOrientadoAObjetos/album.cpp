#include "album.h"

void Album::loadData(ifstream &file) { 
    Record::loadData(file);
    file >> this->artist;
}

void Album::print() {
    Record::print();
    cout << setw(10) << this->artist << endl;
}

int Album::getArtistId() {
    return artist;
}