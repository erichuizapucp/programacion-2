#include "artist.h"
#include "album.h"

Artist::Artist() {
}

void Artist::loadData(ifstream &file) {
    Record::loadData(file);
    readString(file, this->genre, '\n');
}

void Artist::print() {
    Record::print();
    cout << setw(30) << this->genre << endl;
}

Album** Artist::getArtistAlbums(Album** &allAlbums, int &numArtistAlbums) {
    Album** artistAlbums = nullptr;
    
    int capacity = 0;
    numArtistAlbums = 0;
    
    for (int index = 0; allAlbums[index] != nullptr; index++) {
        Album *album = allAlbums[index];
        if (album->getArtistId() == this->getId()) {
            if (numArtistAlbums == capacity) {
                incrementMemorySpaces(artistAlbums, numArtistAlbums, capacity);
            }
            
            artistAlbums[numArtistAlbums] = allAlbums[index];
            numArtistAlbums++;
        }
    }
    
    return artistAlbums;
}

Artist::~Artist() {
    delete[] genre;
}
