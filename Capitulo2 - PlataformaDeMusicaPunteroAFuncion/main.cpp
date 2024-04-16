/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 4, 2024, 10:17 PM
 */

#include <cstdlib>
#include <iomanip>
#include "platform.h"

using namespace std;

int main(int argc, char** argv) {
    /*
     * Estas variables almacenan la cantidad de clientes, artistas, albums, 
     * canciones y listas de reproducción cargadas.
     */
    int numClients, numArtists, numAlbums, numSongs, numPlaylists;
    
    /*
     * Se realiza la carga de datos usando punteros a funciones.
     * Los datos cargados no se deben cambiar es por eso que se declaran 
     * punteros constantes a constantes
     */
//    void* (*leeCliente)(ifstream &file);
//    leeCliente = readClientData;
    
    const void* const clients = loadRecords(
        "clients.csv", 
        numClients, 
        readClientData
    );
    const void* const artists = loadRecords(
        "artists.csv", 
        numArtists, 
        readArtistData
    );
    const void* const albums = loadRecords(
        "albums.csv", 
        numAlbums, 
        readAlbumData
    );
    const void* const songs = loadRecords(
        "songs.csv", 
        numSongs, 
        readSongData
    );
    const void* const playlists = loadRecords(
        "playlists.csv", 
        numPlaylists, 
        readPlaylistData
    );

//    testClientLoad(clients, numClients);
//    testArtistsLoad(artists, numArtists);
//    testAlbumsLoad(albums, numAlbums);
//    testSongsLoad(songs, numSongs);
//    testPlaylistsLoad(playlists, numPlaylists);

    /*
     * Obtiene toda la producción artística de la plataforma
     */
    const void* const platformProduction = getArtistsProduction(
        artists, 
        numArtists, 
        albums, 
        numAlbums
    );
    
    writeArtistsProductionReport(
        "reporte-producción-musical.txt", 
        platformProduction, 
        numArtists
    ); 
    
    freeMemory(
        clients, 
        artists, 
        albums, 
        songs, 
        playlists, 
        platformProduction, 
        numClients, 
        numArtists, 
        numAlbums, 
        numSongs, 
        numPlaylists
    );
    
    return 0;
}

