#include "platform.h"

Platform::Platform(
    const char* clientsFileName, 
    const char* artistsFileName, 
    const char* albumsFileName, 
    const char* songsFileName, 
    const char* playListsFileName
) {
    clients = loadRecords<Client>(clientsFileName, numClients, Record::cmp);
    artists = loadRecords<Artist>(artistsFileName, numArtists, Record::cmp);
    albums = loadRecords<Album>(albumsFileName, numAlbums, Record::cmp);
    songs = loadRecords<Song>(songsFileName, numSongs, Record::cmp);
    playlists = loadRecords<Playlist>(playListsFileName, numPlaylists, Record::cmp);
}

template<typename T>
T** Platform::loadRecords(
    const char* fileName, 
    int &numRecords, 
    int (*cmp)(const void* a, const void* b)
) {
    T** records = nullptr;
    
    int capacity = 0;
    numRecords = 0;
    
    ifstream file;
    openFile(fileName, file);
    
    while (1) {
        if (file.eof()) {
            break;
        }
        
        T* record = new T();
        record->loadData(file);
        
        if (numRecords == capacity) {
            incrementMemorySpaces(records, numRecords, capacity);
        }

        records[numRecords] = record;
        numRecords++;
    }

    file.close();

    // ordenar los registros antes de devolver los resultados.
    qsort(records, numRecords, sizeof(T*), cmp);
    
    return records;
}

Client** Platform::getClients() {
    return clients;
}

Artist** Platform::getArtists() {
    return artists;
}

Album** Platform::getAlbums() {
    return albums;
}

Song** Platform::getSongs() {
    return songs;
}

Playlist** Platform::getPlaylists() {
    return playlists;
}

void Platform::printClientHeader() {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(50) << "NOMBRE" 
         << setw(30) << "CATEGORÍA" 
         << setw(30) << "FECHA" << endl;
    cout << setfill('=') << setw(120) << "=" << setfill(' ') << endl;
}

void Platform::printArtistHeader() {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(50) << "NOMBRE" 
         << setw(30) << "GÉNERO" << endl;
    cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
}

void Platform::printAlbumHeader() {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(50) << "NOMBRE"
         << setw(10) << "ARTISTA" << endl;
    cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
}

void Platform::printSongHeader() {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(50) << "NOMBRE"
         << setw(10) << "DURACIÓN"
         << setw(10) << "ALBUM" << endl;
    cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
}

void Platform::printPlaylistHeader() {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(60) << "NOMBRE"
         << setw(10) << "CLIENTE"
         << setw(80) << "CANCIONES" << endl;
    cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
}

void Platform::openFile(const char* fileName, ifstream& file) {
    file.open(fileName, ios::in);
    
    if (!file.is_open()) {
        cerr << "Error abriendo el archivo de entrada." << fileName << endl;
        exit(1);
    }
}

void Platform::openFile(const char* fileName, ofstream& file) {
    file.open(fileName, ios::out);
    
    if (!file.is_open()) {
        cerr << "Error abriendo el archivo de entrada." << fileName << endl;
        exit(1);
    }
}

void Platform::writeArtistsProductionReport(const char* fileName) {
    ofstream file;
    openFile(fileName, file);
    
    file << "REPORTE DE LA PRODUCCIÓN DE LA PLATAFORMA" << endl << endl;
    file << left << setw(20) << "Código Artista" << setw(50) << "Nombre Artista" 
         << "Producción Musical" << endl;
    
    ArtistProduction* production = new ArtistProduction(artists, albums, numArtists);
    
    for (int index = 0; index < numArtists; index++) {
        file << setw(20) << production->getArtistId()[index];
        file << setw(50) << production->getArtistName()[index];

        for (int albumIndex = 0; 
             albumIndex < production->getNumArtistAlbums()[index];
             albumIndex++) {

            if (albumIndex > 0) {
                file << ", ";
            }
            file << production->getArtistAlbums()[index][albumIndex];
        }

        file << endl;
    }
}

Platform::~Platform() {
    for (int i = 0; i < numClients; i++) {
        delete clients[i];
    }
    delete[] clients;
    
    for (int i = 0; i < numArtists; i++) {
        delete artists[i];
    }
    delete[] artists;
    
    for (int i = 0; i < numAlbums; i++) {
        delete albums[i];
    }
    delete[] albums;
    
    for (int i = 0; i < numSongs; i++) {
        delete songs[i];
    }
    delete[] songs;
    
    for (int i = 0; i < numPlaylists; i++) {
        delete playlists[i];
    }
    delete[] playlists;
}
