#include "platform.h"
#include "utils.h"
#include "structs.h"
#include <iostream>

void loadClients(const char* fileName, struct Client*& clients, int &numClients) {
    int capacity = 0;
    numClients = 0;
    char comma;
    
    struct Client client;
    clients = nullptr;
    
    ifstream file;
    if (openFile(fileName, file)) {
        while (1) {
            if (file.eof()) {
                break;
            }
            
            file >> client.id >> comma;
            readString(file, client.name, ',');
            readString(file, client.subscriptionDate, ',');
            readString(file, client.category, '\n');
            
            if (numClients == capacity) {
                incrementMemorySpaces(clients, numClients, capacity);
            }
            
            clients[numClients] = client;
            numClients++;
        }
        
        file.close();
    }
    else {
        cout << "Hubo un error al cargar los clientes." << endl;
    }
}

void loadArtists(const char* fileName, struct Artist*& artists, int& numArtists) {
    int capacity = 0;
    numArtists = 0;
    char comma;
    
    struct Artist artist;
    artists = nullptr;
    
    ifstream file;
    if (openFile(fileName, file)) {
        while (1) {
            if (file.eof()) {
                break;
            }
            
            file >> artist.id >> comma;
            readString(file, artist.name, ',');
            readString(file, artist.genre, '\n');
            
            if (numArtists == capacity) {
                incrementMemorySpaces(artists, numArtists, capacity);
            }
            
            artists[numArtists] = artist;
            numArtists++;
        }
        
        file.close();
    }
    else {
        cout << "Hubo un error al cargar los artistas." << endl;
    }
}

void loadAlbums(const char* fileName, struct Album*& albums, int& numAlbums) {
    int capacity = 0;
    numAlbums = 0;
    char comma;
    
    struct Album album;
    albums = nullptr;
    
    ifstream file;
    if (openFile(fileName, file)) {
        while (1) {
            if (file.eof()) {
                break;
            }
            
            file >> album.id >> comma >> album.artist >> comma;
            readString(file, album.name, '\n');
            
            if (numAlbums == capacity) {
                incrementMemorySpaces(albums, numAlbums, capacity);
            }
            
            albums[numAlbums] = album;
            numAlbums++;
        }
        
        file.close();
    }
    else {
        cout << "Hubo un error al cargar los álbumes." << endl;
    }
}

void loadSongs(const char* fileName, struct Song*& songs, int& numSongs) {
    int capacity = 0;
    numSongs = 0;
    char comma;
    
    struct Song song;
    songs = nullptr;
    
    ifstream file;
    if (openFile(fileName, file)) {
        while (1) {
            if (file.eof()) {
                break;
            }
            
            file >> song.id >> comma >> song.duration >> comma >> song.album >> comma;
            readString(file, song.name, '\n');
            
            if (numSongs == capacity) {
                incrementMemorySpaces(songs, numSongs, capacity);
            }
            
            songs[numSongs] = song;
            numSongs++;
        }
        
        file.close();
    }
    else {
        cout << "Hubo un error al cargar los canciones." << endl;
    }
}

void loadPlaylists(const char* fileName, struct Playlist*& playlists, int& numPlayLists) {
    int capacity = 0;
    numPlayLists = 0;
    char comma;
    char* songsStr;
    int numSongs;
    
    struct Playlist playlist;
    playlists = nullptr;
    
    ifstream file;
    if (openFile(fileName, file)) {
        while (1) {
            if (file.eof()) {
                break;
            }
            
            file >> playlist.id >> comma >> playlist.clientId >> comma;
            readString(file, playlist.name, ',');
            readString(file, songsStr, '\n');
            
            const char* input = songsStr;
            readIntArray(input, playlist.songs, numSongs);
            playlist.numSongs = numSongs;
            
            if (numPlayLists == capacity) {
                incrementMemorySpaces(playlists, numPlayLists, capacity);
            }
            
            playlists[numPlayLists] = playlist;
            numPlayLists++;
        }
        
        file.close();
    }
    else {
        cout << "Hubo un error al cargar las listas de reproducción." << endl;
    }
    
    delete[] songsStr;
}

const struct Album* getAlbumsByArtist(const struct Album*& albums, const int &numAlbums, const int &artistId, int &numAlbumsByArtist) {
    struct Album* albumsByArtist;
    albumsByArtist=nullptr;
    
    struct Album albumByArtist;
    int capacity = 0;
    numAlbumsByArtist = 0;
    
    for (int index = 0; index < numAlbums; index++) {
        if (albums[index].artist == artistId) {
            albumByArtist.id = albums[index].id;
            albumByArtist.name = albums[index].name;
            albumByArtist.artist = albums[index].artist;
            
            if (numAlbumsByArtist == capacity) {
                incrementMemorySpaces(albumsByArtist, numAlbumsByArtist, capacity);
            }
            
            albumsByArtist[numAlbumsByArtist] = albumByArtist;
            numAlbumsByArtist++;
        }
    }
    
    return albumsByArtist;
}

const struct ArtistsProduction* getArtistProduction(const struct Artist*& artists, const int &numArtists, const struct Album*& albums, int &numAlbums) {
    struct ArtistsProduction* production;
    production = nullptr;
    
    int* artistIds = nullptr;
    char** artistNames;
    char*** artistAlbums;
    
    int idsCapacity = 0;
    int namesCapacity = 0;
    int albumsCapacity = 0;
    int num = 0;
    
    for (int index = 0; index < numArtists; index++) {
        int artistId = artists[index].id;
        char* artistName = artists[index].name;
        
        if (num == idsCapacity) {
            incrementMemorySpaces(artistIds, num, idsCapacity);
        }
        artistIds[num] = artistId;
        
        if (num == namesCapacity) {
            incrementMemorySpaces(artistNames, num, namesCapacity);
        }
        artistNames[num] = artistName;

        int numAlbumsByArtist;
        const struct Album* albumsByArtist = getAlbumsByArtist(albums, numAlbums, artistId, numAlbumsByArtist);
        
        for (int aIndex = 0; aIndex < numAlbumsByArtist; aIndex++) {
            
        }
        
        num++;
    }
    
    return production;
}

const struct ClientPreferences* getClientPreferences(const struct Client*& clients, 
        const struct Playlist*& playlists, 
        const struct Song*& songs) {
    struct ClientPreferences* preferences;
    
    return preferences;
}
