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
     * Se realiza la carga de datos.
     * Los datos cargados no se deben cambiar es por eso que se declaran 
     * punteros constantes a constantes
     */
    const void* const clients = loadClients("clients.csv", numClients);
    const void* const artists = loadArtists("artists.csv", numArtists);
    const void* const albums = loadAlbums("albums.csv", numAlbums);
    const void* const songs = loadSongs("songs.csv", numSongs);
    const void* const playlists = loadPlaylists("playlists.csv", numPlaylists);

//    testClientLoad(clients, numClients);
//    testArtistsLoad(artists, numArtists);
//    testAlbumsLoad(albums, numAlbums);
//    testSongsLoad(songs, numSongs);
//    testPlaylistsLoad(playlists, numPlaylists);
    
    /*
     * Obtiene toda la producción artística de la plataforma
     */
    const void* platformProduction = getArtistsProduction(
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
    delete[] cli;
    delete[] arts;
    delete[] albms;
    delete[] sngs;
    delete[] plsts;
    
    /*
     * Libera memoria usada para almacenar la producción músical
     */
    delete[] prod->artistAlbums;
    delete[] prod->artistId;
    delete[] prod->artistName;
    delete[] prod->numArtistAlbums;
    delete prod;
    
    return 0;
}

