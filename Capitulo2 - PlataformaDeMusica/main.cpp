/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 4, 2024, 10:17 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "platform.h"
#include "structs.h"

using namespace std;

int main(int argc, char** argv) {
    struct Client* clients;
    struct Artist* artists;
    struct Album* albums;
    struct Song* songs;
    struct Playlist* playlists;
    
    int numClients, numArtists, numAlbums, numSongs, numPlaylists;
    
    loadClients("clients.csv", clients, numClients);
    loadArtists("artists.csv", artists, numArtists);
    loadAlbums("albums.csv", albums, numAlbums);
    loadSongs("songs.csv", songs, numSongs);
    loadPlaylists("playlists.csv", playlists, numPlaylists);
    
//    const struct Artist* readArtists = artists;
//    const struct Album* readAlbums = albums;
//    const struct ArtistsProduction* artistProduction = getArtistProduction(readArtists, numArtists, readAlbums, numAlbums);
    
    for (int index = 0; index < numPlaylists; index++) {
        struct Playlist playlist = playlists[index];
        
        cout << playlist.id << endl;
        cout << playlist.clientId << endl;
        cout << playlist.name << endl;
        
        for (int songIndex = 0; songIndex < playlist.numSongs; songIndex++) {
            cout << playlist.songs[songIndex] << " ";
        }
        
        cout << endl;
    }
    
    delete[] clients;
    delete[] artists;
    delete[] albums;
    delete[] songs;
    delete[] playlists;
    
    return 0;
}

