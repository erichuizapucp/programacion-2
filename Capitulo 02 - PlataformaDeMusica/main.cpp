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
    const struct Client* const clients = 
        loadClients("clients.csv", numClients);
    
    const struct Artist* const artists = 
        loadArtists("artists.csv", numArtists);
    
    const struct Album* const albums = 
        loadAlbums("albums.csv", numAlbums);
    
    const struct Song* const songs = 
        loadSongs("songs.csv", numSongs);
    
    const struct Playlist* const playlists = 
        loadPlaylists("playlists.csv", numPlaylists);

    /*
     * Obtiene toda la producción artística de la plataforma
     */
    const struct ArtistsProduction* platformProduction = 
        getArtistsProduction(
            artists, 
            numArtists, 
            albums, 
            numAlbums
        );
    writeArtistsProductionReport("reporte-producción-musical.txt", platformProduction, numArtists);
    
//    const int artistId = 1;
//    int numArtistAlbums;
//    const struct Album* const artistAlbums = getArtistAlbums(artistId, albums, numAlbums, numArtistAlbums);
//    
//    for (int index = 0; index < numArtistAlbums; index++) {
//        cout << left << setw(5) << artistAlbums[index].id 
//                << setw(5) << artistAlbums[index].artist 
//                << setw(100) << artistAlbums[index].name 
//                << endl;
//    }
//    
//    delete[] artistAlbums;
    
//    for (int index = 0; index < numPlaylists; index++) {
//        struct Playlist playlist = playlists[index];
//        
//        cout << playlist.id << endl;
//        cout << playlist.clientId << endl;
//        cout << playlist.name << endl;
//        
//        for (int songIndex = 0; songIndex < playlist.numSongs; songIndex++) {
//            cout << playlist.songs[songIndex] << " ";
//        }
//        
//        cout << endl;
//    }
    
    delete[] clients;
    delete[] artists;
    delete[] albums;
    delete[] songs;
    delete[] playlists;
    
    return 0;
}

