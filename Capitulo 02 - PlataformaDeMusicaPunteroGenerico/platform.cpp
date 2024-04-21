#include "platform.h"

/**
 * Carga todos los clientes usando asignación de memoria por incrementos.
 * Los nombres de los clientes son cargados usando asignación exacta de memoria.
 * @param fileName es el nombre del archivo a cargar.
 * @param clients es la referencia a un puntero / arreglo de clientes.
 * @param numClients almacena la cantidad de clientes cargados.
 * @return puntero a los clientes de la plataforma.
 */
const void* loadClients(const char* fileName, int &numClients) {
    void** clients = nullptr;
    
    int capacity = 0;
    numClients = 0;
    char comma;
    
    struct Client* client;
    
    ifstream file;
    openFile(fileName, file);
    
    while (1) {
        if (file.eof()) {
            break;
        }
        
        client = new struct Client;
        file >> client->id >> comma;
        readString(file, client->name, ',');
        readString(file, client->subscriptionDate, ',');
        readString(file, client->category, '\n');

        if (numClients == capacity) {
            incrementMemorySpaces(clients, numClients, capacity);
        }

        clients[numClients] = client;
        numClients++;
    }

    file.close();

    return clients;
}

/**
 * Carga todos los artistas usando asignación de memoria por incrementos.
 * Los nombres de los artistas son cargados usando asignación exacta de memoria.
 * @param fileName es el nombre del archivo a cargar.
 * @param artists es la referencia a un puntero / arreglo de artistas.
 * @param numArtists almacena la cantidad de artistas cargados.
 * @return puntero a los artistas de la plataforma.
 */
const void* loadArtists(const char* fileName, int& numArtists) {
    void** artists = nullptr;
    
    int capacity = 0;
    numArtists = 0;
    char comma;
    
    struct Artist* artist;
    
    ifstream file;
    openFile(fileName, file);
    
    while (1) {
        if (file.eof()) {
            break;
        }

        artist = new struct Artist;
        file >> artist->id >> comma;
        readString(file, artist->name, ',');
        readString(file, artist->genre, '\n');

        if (numArtists == capacity) {
            incrementMemorySpaces(artists, numArtists, capacity);
        }

        artists[numArtists] = artist;
        numArtists++;
    }

    file.close();

    return artists;
}

/**
 * Carga todos los albumes usando asignación de memoria por incrementos.
 * Los nombres de los albumes son cargados usando asignación exacta de memoria.
 * @param fileName es el nombre del archivo a cargar.
 * @param albums es la referencia a un puntero / arreglo de albumes.
 * @param numAlbums almacena la cantidad de albumes cargados.
 * @return puntero a los albumes de la plataforma.
 */
const void* loadAlbums(const char* fileName, int& numAlbums) {
    void** albums = nullptr;
    
    int capacity = 0;
    numAlbums = 0;
    char comma;
    
    struct Album *album;
    
    ifstream file;
    openFile(fileName, file);
    while (1) {
        if (file.eof()) {
            break;
        }
        
        album = new struct Album;
        file >> album->id >> comma;
        file >> album->artist >> comma;
        readString(file, album->name, '\n');

        if (numAlbums == capacity) {
            incrementMemorySpaces(albums, numAlbums, capacity);
        }

        albums[numAlbums] = album;
        numAlbums++;
    }

    file.close();
    
    return albums;
}

/**
 * Carga todas las canciones usando asignación de memoria por incrementos.
 * Los nombres de las canciones son cargadas usando asignación exacta de 
 * memoria.
 * @param fileName es el nombre del archivo a cargar.
 * @param songs es la referencia a un puntero / arreglo de canciones.
 * @param numSongs almacena la cantidad de canciones cargadas.
 * @return puntero a los canciones de la plataforma.
 */
const void* loadSongs(const char* fileName, int& numSongs) {
    void** songs = nullptr;
    
    int capacity = 0;
    numSongs = 0;
    char comma;
    
    struct Song *song;
    
    ifstream file;
    openFile(fileName, file);
    while (1) {
        if (file.eof()) {
            break;
        }
        
        song = new struct Song;
        file >> song->id >> comma;
        file >> song->duration >> comma; 
        file >> song->album >> comma;
        readString(file, song->name, '\n');

        if (numSongs == capacity) {
            incrementMemorySpaces(songs, numSongs, capacity);
        }

        songs[numSongs] = song;
        numSongs++;
    }

    file.close();
    
    return songs;
}

/**
 * Carga todas las listas de reproducción usando asignación de memoria por 
 * incrementos. Los nombres de las listas de de reproducción son cargados usando
 * asignación exacta de memoria. Los códigos de las canciones pertenecientes a 
 * las listas de reproducción son cargados usando asignación exacta de memoria.
 * @param fileName es el nombre del archivo a cargar.
 * @param playlists es la referencia a un puntero / arreglo de listas de 
 * reproducción.
 * @param numPlayLists almacena la cantidad de listas de reproducción cargadas.
 * @return puntero a las listas de reproducción de la plataforma.
 */
const void* loadPlaylists(const char* fileName, int& numPlayLists) {
    void** playlists = nullptr;
    
    int numSongs, capacity = 0;
    char comma, *songsStr;
    
    numPlayLists = 0;
    
    struct Playlist *playlist;
    
    ifstream file;
    openFile(fileName, file);
    
    while (1) {
        if (file.eof()) {
            break;
        }

        playlist = new struct Playlist;
        file >> playlist->id >> comma >> playlist->clientId >> comma;
        readString(file, playlist->name, ',');
        readString(file, songsStr, '\n');

        const char* input = songsStr;
        readIntArray(input, playlist->songs, numSongs);
        delete[] songsStr;

        playlist->numSongs = numSongs;

        if (numPlayLists == capacity) {
            incrementMemorySpaces(playlists, numPlayLists, capacity);
        }

        playlists[numPlayLists] = playlist;
        numPlayLists++;
    }

    file.close();
    
    return playlists;
}

/**
 * 
 * Retorna albums pertenecientes a un artista.
 * @param artistId es el código del artista.
 * @param allAlbums contiene todos los albums en la plataforma.
 * @param numTotalAlbums es el número total de albums en la plataforma.
 * @param numArtistAlbums es el número de albumes del artista.
 * @return Albums pertenecientes a un artista.
 */
const void* getArtistAlbums(
    const int &artistId, 
    const void* const& allAlb,   
    const int &numTotalAlbums, 
    int &numArtistAlbums
) {
    void** artistAlbums = nullptr;
    
    int capacity = 0;
    numArtistAlbums = 0;
    
    void** allAlbums = (void**)allAlb;
    for (int index = 0; index < numTotalAlbums; index++) {
        struct Album *album = (struct Album*)allAlbums[index];
        if (album->artist == artistId) {
            if (numArtistAlbums == capacity) {
                incrementMemorySpaces(artistAlbums, numArtistAlbums, capacity);
            }
            
            artistAlbums[numArtistAlbums] = allAlbums[index];
            numArtistAlbums++;
        }
    }
    
    return artistAlbums;
}

/**
 * Obtiene toda la producción musical de la plataforma.
 * @param artists referencia a un puntero al arreglo de todos los artistas.
 * @param numArtists número de artistas en la plataforma.
 * @param albums referencia a un puntero al arreglo de todos los álbumes.
 * @param numAlbums número de álbumes.
 * @return un puntero a una structura ArtistsProduction.
 */
const void* getArtistsProduction(
    const void* const& art, 
    const int &numArtists, 
    const void* const& albums, 
    const int &numAlbums
) {    
    int* artistsIds = new int[numArtists];
    int* numAlbumsPerArtist = new int[numArtists];
    char** artistsNames = new char*[numArtists];
    char*** artistsAlbumNames = new char**[numArtists];
    
    void** artists = (void**)art;
    
    for (int artistIndex = 0; artistIndex < numArtists; artistIndex++) {
        struct Artist* artist = (struct Artist*)artists[artistIndex];
        
        const int artistId = artist->id;
        artistsIds[artistIndex] = artistId;
        artistsNames[artistIndex] = artist->name;
        
        int numArtistAlbums;
        const void* const artAlbms = 
            getArtistAlbums(
                artistId, 
                albums, 
                numAlbums, 
                numArtistAlbums
            );
        void** artistAlbums = (void**)artAlbms;
        numAlbumsPerArtist[artistIndex] = numArtistAlbums;
        
        char** albumNames = new char*[numArtistAlbums];
        for (int albumIndex = 0; albumIndex < numArtistAlbums; albumIndex++) {
            struct Album* album = (struct Album*)artistAlbums[albumIndex];
            albumNames[albumIndex] = album->name;
        }
        
        artistsAlbumNames[artistIndex] = albumNames;
    }
    
    ArtistsProduction* productions = new ArtistsProduction();
    productions->artistId = artistsIds;
    productions->artistName = artistsNames;
    productions->artistAlbums = artistsAlbumNames;
    productions->numArtistAlbums = numAlbumsPerArtist;
    
    return productions;
}

/**
 * Carga todos los clientes usando asignación de memoria por incrementos.
 * Los nombres de los clientes son cargados usando asignación exacta de memoria.
 * @param fileName es el nombre del archivo a cargar
 * @param clients es la referencia a un puntero / arreglo de clientes
 * @param numClients almacena la cantidad de clientes cargados
 */
const struct ClientPreferences* getClientPreferences(
    const struct Client*& clients, 
    const struct Playlist*& playlists, 
    const struct Song*& songs
) {    
    struct ClientPreferences* preferences;
    
    return preferences;
}

void writeArtistsProductionReport(const char* fileName, const void* const& prod, const int& numArtists) {
    ofstream file;
    openFile(fileName, file);
    
    file << "REPORTE DE LA PRODUCCIÓN DE LA PLATAFORMA" << endl << endl;
    file << left << setw(20) << "Código Artista" << setw(50) << "Nombre Artista" << "Producción Musical" << endl;
    
    struct ArtistsProduction* production = (struct ArtistsProduction*)prod;
    
    for (int index = 0; index < numArtists; index++) {
        file << setw(20) << production->artistId[index];
        file << setw(50) << production->artistName[index];

        for (int albumIndex = 0; 
             albumIndex < production->numArtistAlbums[index];
             albumIndex++) {

            if (albumIndex > 0) {
                file << ", ";
            }
            file << production->artistAlbums[index][albumIndex];
        }

        file << endl;
    }
}

void testClientLoad(const void* const& cli, int& numClients) {
    void** clients = (void**)cli;
    for (int i = 0; i < numClients; i++) {
        struct Client* client = (struct Client*)clients[i];
        cout << client->id << endl;
        cout << client->name << endl;
        cout << client->category << endl;
        cout << client->subscriptionDate << endl;
    }
}

void testArtistsLoad(const void* const& art, int& numArtists) {
    void** artists = (void**)art;
    for (int i = 0; i < numArtists; i++) {
        struct Artist* artist = (struct Artist*)artists[i];
        cout << artist->id << endl;
        cout << artist->name << endl;
        cout << artist->genre << endl;
    }
}

void testSongsLoad(const void* const& son, int& numSongs) {
    void** songs = (void**)son;
    for (int i = 0; i < numSongs; i++) {
        struct Song* song = (struct Song*)songs[i];
        cout << song->id << endl;
        cout << song->album << endl;
        cout << song->duration << endl;
        cout << song->name << endl;
    }
}

void testAlbumsLoad(const void* const& alb, int& numAlbums) {
    void** albums = (void**)alb;
    for (int i = 0; i < numAlbums; i++) {
        struct Album* album = (struct Album*)albums[i];
        cout << album->id << endl;
        cout << album->artist << endl;
        cout << album->name << endl;
    }
}

void testPlaylistsLoad(const void* const& plst, int& numPlayLists) {
    void** playlists = (void**)plst;
    for (int i = 0; i < numPlayLists; i++) {
        struct Playlist* playlist = (struct Playlist*)playlists[i];
        cout << playlist->id << endl;
        cout << playlist->clientId << endl;
        cout << playlist->name << endl;
        
        for (int j = 0; j < playlist->numSongs; j++) {
            cout << playlist->songs[j] << " ";
        }
    }
}