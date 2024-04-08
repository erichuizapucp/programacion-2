#include "platform.h"

/**
 * Carga todos los clientes usando asignación de memoria por incrementos.
 * Los nombres de los clientes son cargados usando asignación exacta de memoria.
 * @param fileName es el nombre del archivo a cargar.
 * @param clients es la referencia a un puntero / arreglo de clientes.
 * @param numClients almacena la cantidad de clientes cargados.
 * @return puntero a los clientes de la plataforma.
 */
const struct Client* loadClients(const char* fileName, int &numClients) {
    struct Client* clients = nullptr;
    
    int capacity = 0;
    numClients = 0;
    char comma;
    
    struct Client client;
    
    ifstream file;
    openFile(fileName, file);
    
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
const struct Artist* loadArtists(const char* fileName, int& numArtists) {
    struct Artist* artists = nullptr;
    
    int capacity = 0;
    numArtists = 0;
    char comma;
    
    struct Artist artist;
    
    ifstream file;
    openFile(fileName, file);
    
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
const struct Album* loadAlbums(const char* fileName, int& numAlbums) {
    struct Album* albums = nullptr;
    
    int capacity = 0;
    numAlbums = 0;
    char comma;
    
    struct Album album;
    
    ifstream file;
    openFile(fileName, file);
    while (1) {
        if (file.eof()) {
            break;
        }

        file >> album.id >> comma;
        file >> album.artist >> comma;
        readString(file, album.name, '\n');

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
const struct Song* loadSongs(const char* fileName, int& numSongs) {
    struct Song* songs = nullptr;
    
    int capacity = 0;
    numSongs = 0;
    char comma;
    
    struct Song song;
    
    ifstream file;
    openFile(fileName, file);
    while (1) {
        if (file.eof()) {
            break;
        }

        file >> song.id >> comma;
        file >> song.duration >> comma; 
        file >> song.album >> comma;
        readString(file, song.name, '\n');

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
const struct Playlist* loadPlaylists(const char* fileName, int& numPlayLists) {
    struct Playlist* playlists = nullptr;
    
    int numSongs, capacity = 0;
    char comma, *songsStr;
    
    numPlayLists = 0;
    
    struct Playlist playlist;
    
    ifstream file;
    openFile(fileName, file);
    
    while (1) {
        if (file.eof()) {
            break;
        }

        file >> playlist.id >> comma >> playlist.clientId >> comma;
        readString(file, playlist.name, ',');
        readString(file, songsStr, '\n');

        const char* input = songsStr;
        readIntArray(input, playlist.songs, numSongs);
        delete[] songsStr;

        playlist.numSongs = numSongs;

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
const struct Album* getArtistAlbums(
    const int &artistId, 
    const struct Album* const& allAlbums,   
    const int &numTotalAlbums, 
    int &numArtistAlbums
) {
    struct Album* artistAlbums = nullptr;
    struct Album album;
    
    int capacity = 0;
    numArtistAlbums = 0;
    
    for (int index = 0; index < numTotalAlbums; index++) {
        if (allAlbums[index].artist == artistId) {
            album = allAlbums[index];
            
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
const struct ArtistsProduction* getArtistsProduction(
    const struct Artist* const& artists, 
    const int &numArtists, 
    const struct Album* const& albums, 
    const int &numAlbums
) {    
    int* artistsIds = new int[numArtists];
    int* numAlbumsPerArtist = new int[numArtists];
    char** artistsNames = new char*[numArtists];
    char*** artistsAlbumNames = new char**[numArtists];
    
    for (int artistIndex = 0; artistIndex < numArtists; artistIndex++) {
        const int artistId = artists[artistIndex].id;
        artistsIds[artistIndex] = artistId;
        artistsNames[artistIndex] = artists[artistIndex].name;
        
        int numArtistAlbums;
        const struct Album* const artistAlbums = 
            getArtistAlbums(
                artistId, 
                albums, 
                numAlbums, 
                numArtistAlbums
            );
        numAlbumsPerArtist[artistIndex] = numArtistAlbums;
        
        char** albumNames = new char*[numArtistAlbums];
        for (int albumIndex = 0; albumIndex < numArtistAlbums; albumIndex++) {
            albumNames[albumIndex] = artistAlbums[albumIndex].name;
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

void writeArtistsProductionReport(const char* fileName, const struct ArtistsProduction* const& production, const int& numArtists) {
    ofstream file;
    openFile(fileName, file);
    
    file << "REPORTE DE LA PRODUCCIÓN DE LA PLATAFORMA" << endl << endl;
    file << left << setw(20) << "Código Artista" << setw(50) << "Nombre Artista" << "Producción Musical" << endl;
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
