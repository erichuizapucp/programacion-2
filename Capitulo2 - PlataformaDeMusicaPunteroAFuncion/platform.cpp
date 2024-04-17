#include "platform.h"

/**
 * Carga datos usando asignación de memoria por incrementos.
 * @param fileName es el nombre del archivo a cargar.
 * @param numData almacena la cantidad de datos cargados.
 * @return puntero genérico.
 */
const void* loadRecords(
    const char* fileName, 
    int &numRecords, 
    void* (*readRecord)(ifstream &file), 
    int (*cmp)(const void* a, const void* b)
) { 
    void** records = nullptr;
    
    int capacity = 0;
    numRecords = 0;
    
    ifstream file;
    openFile(fileName, file);
    
    while (1) {
        if (file.eof()) {
            break;
        }
        
        // Ejecuta la función a través del puntero a función
        void* record = readRecord(file);
        
        if (numRecords == capacity) {
            incrementMemorySpaces(records, numRecords, capacity);
        }

        records[numRecords] = record;
        numRecords++;
    }

    file.close();

    // ordenar los registros antes de devolver los resultados.
    qsort(records, numRecords, sizeof(void*), cmp);
    
    return records;
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

void* readClientData(ifstream &file) {
    struct Client* client = new struct Client;
    char comma;
    
    file >> client->id >> comma;
    readString(file, client->name, ',');
    readString(file, client->subscriptionDate, ',');
    readString(file, client->category, '\n');
    
    return client;
}

void* readArtistData(ifstream &file) {
    struct Artist* artist = new struct Artist;
    char comma;
    
    file >> artist->id >> comma;
    readString(file, artist->name, ',');
    readString(file, artist->genre, '\n');
    
    return artist;
}

void* readAlbumData(ifstream &file) {
    struct Album* album = new struct Album;
    char comma;
    
    file >> album->id >> comma;
    file >> album->artist >> comma;
    readString(file, album->name, '\n');
    
    return album;
}

void* readSongData(ifstream &file) {
    struct Song* song = new struct Song;
    char comma;
    
    file >> song->id >> comma;
    file >> song->duration >> comma; 
    file >> song->album >> comma;
    readString(file, song->name, '\n');
    
    return song;
}

void* readPlaylistData(ifstream &file) {
    struct Playlist* playlist = new struct Playlist;
    char comma, *songsStr;
    int numSongs;
    
    file >> playlist->id >> comma >> playlist->clientId >> comma;
    readString(file, playlist->name, ',');
    readString(file, songsStr, '\n');

    const char* input = songsStr;
    readIntArray(input, playlist->songs, numSongs);
    delete[] songsStr;

    playlist->numSongs = numSongs;
    
    return playlist;
}

int clientsCmp(const void* a, const void* b) {
    struct Client* client1 = *(struct Client**)a;
    struct Client* client2 = *(struct Client**)b;
    
    return strcmp(client1->name, client2->name);
}

int artistsCmp(const void* a, const void* b) {
    struct Artist* artist1 = *(struct Artist**)a;
    struct Artist* artist2 = *(struct Artist**)b;
    
    return strcmp(artist1->name, artist2->name);
}

int albumsCmp(const void* a, const void* b) {
    struct Album* album1 = *(struct Album**)a;
    struct Album* album2 = *(struct Album**)b;
    
    return strcmp(album1->name, album2->name);
}

int songsCmp(const void* a, const void* b) {
    struct Song* song1 = *(struct Song**)a;
    struct Song* song2 = *(struct Song**)b;
    
    return strcmp(song1->name, song2->name);
}

int playlistsCmp(const void* a, const void* b) {
    struct Playlist* playlist1 = *(struct Playlist**)a;
    struct Playlist* playlist2 = *(struct Playlist**)b;
    
    return strcmp(playlist1->name, playlist2->name);
}

void testClientLoad(
    const void* const& cli, 
    int& numClients
) {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(50) << "NOMBRE" 
         << setw(30) << "CATEGORÍA" 
         << setw(30) << "FECHA" << endl;
    cout << setfill('=') << setw(120) << "=" << setfill(' ') << endl;
    
    void** clients = (void**)cli;
    
    for (int i = 0; i < numClients; i++) {
        struct Client* client = (struct Client*)clients[i];
        cout << left << setw(10) << client->id
             << setw(50) << client->name
             << setw(30) << client->category
             << setw(30) << client->subscriptionDate << endl;
    }
    cout << endl;
}

void testArtistsLoad(
    const void* const& art, 
    int& numArtists
) {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(50) << "NOMBRE" 
         << setw(30) << "GÉNERO" << endl;
    cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
    
    void** artists = (void**)art;
    
    for (int i = 0; i < numArtists; i++) {
        struct Artist* artist = (struct Artist*)artists[i];
        cout << left << setw(10) << artist->id
             << setw(50) << artist->name
             << setw(30) << artist->genre << endl;
    }
    cout << endl;
}

void testSongsLoad(
    const void* const& son, 
    int& numSongs
) {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(50) << "NOMBRE"
         << setw(10) << "DURACIÓN"
         << setw(10) << "ALBUM" << endl;
    cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
    
    void** songs = (void**)son;
    
    for (int i = 0; i < numSongs; i++) {
        struct Song* song = (struct Song*)songs[i];
        cout << left << setw(10) << song->id
             << setw(50) << song->name
             << setw(10) << song->duration
             << setw(10) << song->album << endl;
    }
    cout << endl;
}

void testAlbumsLoad(
    const void* const& alb, 
    int& numAlbums
) {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(50) << "NOMBRE"
         << setw(10) << "ARTISTA" << endl;
    cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
    
    void** albums = (void**)alb;
    
    for (int i = 0; i < numAlbums; i++) {
        struct Album* album = (struct Album*)albums[i];
        cout << left << setw(10) << album->id
             << setw(50) << album->name
             << setw(10) << album->artist << endl;
    }
    cout << endl;
}

void testPlaylistsLoad(
    const void* const& plst, 
    int& numPlayLists
) {
    cout << left << setw(10) << "CÓDIGO" 
         << setw(60) << "NOMBRE"
         << setw(10) << "CLIENTE"
         << setw(80) << "CANCIONES" << endl;
    cout << setfill('=') << setw(90) << "=" << setfill(' ') << endl;
    
    void** playlists = (void**)plst;
    
    for (int i = 0; i < numPlayLists; i++) {
        struct Playlist* playlist = (struct Playlist*)playlists[i];
        cout << left << setw(10) << playlist->id
             << setw(60) << playlist->name
             << setw(10) << playlist->clientId;
        for (int j = 0; j < playlist->numSongs; j++) {
            cout << playlist->songs[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void freeMemory(
        const void* const &clients, 
        const void* const &artists, 
        const void* const &albums, 
        const void* const &songs, 
        const void* const &playlists, 
        const void* const &platformProduction, 
        int& numClients, 
        int& numArtists, 
        int& numAlbums, 
        int& numSongs,
        int& numPlaylists
) {
    /*
     * Casting para poder liberar memoria
     */
    void** cli = (void**)clients;
    void** arts = (void**)artists;
    void** albms = (void**)albums;
    void** sngs = (void**)songs;
    void** plsts = (void**)playlists;
    struct ArtistsProduction* prod = 
        (struct ArtistsProduction*)platformProduction;
    
    /*
     * Liberar memoria usada para la carga de datos
     */
    for (int i = 0; i < numClients; i++) {
        struct Client* client = (struct Client*)cli[i];
        delete[] client->category;
        delete[] client->name;
        delete[] client->subscriptionDate;
        delete client;
    }
    delete[] cli;
    
    for (int i = 0; i < numArtists; i++) {
        struct Artist* artist = (struct Artist*)arts[i];
        delete[] artist->genre;
        delete[] artist->name;
        delete artist;
    }
    delete[] arts;
    
    for (int i = 0; i < numAlbums; i++) {
        struct Album* album = (struct Album*)albms[i];
        delete[] album->name;
        delete album;
    }
    delete[] albms;
    
    for (int i = 0; i < numSongs; i++) {
        struct Song* song = (struct Song*)sngs[i];
        delete[] song->name;
        delete song;
    }
    delete[] sngs;
    
    for (int i = 0; i < numPlaylists; i++) {
        struct Playlist* playlist = (struct Playlist*)plsts[i];
        delete[] playlist->name;
        delete[] playlist->songs;
        delete playlist;
    }
    delete[] plsts;
    
    /*
     * Libera memoria usada para almacenar la producción músical
     */
    delete[] prod->artistAlbums;
    delete[] prod->artistId;
    delete[] prod->artistName;
    delete[] prod->numArtistAlbums;
    delete prod;
}