#include "playlist.h"

void Playlist::loadData(ifstream &file) {
    Record::loadData(file);
    
    char comma;
    file >> this->clientId >> comma;
    
    char *songsStr;
    int numSongs;

    readString(file, songsStr, '\n');
    const char* input = songsStr;
    readIntArray(input, this->songs, numSongs);
    delete[] songsStr;

    this->numSongs = numSongs;
}

void Playlist::print() {
    Record::print();
    cout << setw(10) << this->clientId;
    for (int j = 0; j < this->numSongs; j++) {
        cout << this->songs[j] << " ";
    }
    cout << endl;
}

Playlist::~Playlist() {
    delete[] songs;
}
