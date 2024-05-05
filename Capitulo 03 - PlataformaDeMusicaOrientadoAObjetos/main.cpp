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
    if (argc < 7) {
        cerr << "El número de argumentos es incorrecto.";
        exit(1);
    }
    
    const char* clientsFileName = argv[1];
    const char* artistsFileName = argv[2];
    const char* albumsFileName = argv[3];
    const char* songsFileName = argv[4];
    const char* playListsFileName = argv[5];
    const char* reportFileName = argv[6];
    
    Platform *platform = new Platform(
        clientsFileName, 
        artistsFileName, 
        albumsFileName, 
        songsFileName, 
        playListsFileName
    );
    
    platform->testLoad<Client>(platform->getClients(), Platform::printClientHeader);
    platform->testLoad<Artist>(platform->getArtists(), Platform::printArtistHeader);
    platform->testLoad<Album>(platform->getAlbums(), Platform::printAlbumHeader);
    platform->testLoad<Song>(platform->getSongs(), Platform::printSongHeader);
    platform->testLoad<Playlist>(platform->getPlaylists(), Platform::printPlaylistHeader);
    
    platform->writeArtistsProductionReport(reportFileName);
    
    delete platform;
    
    return 0;
}

