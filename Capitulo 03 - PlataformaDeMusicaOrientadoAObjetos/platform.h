/* 
 * File:   platform.h
 * Author: erichuiza
 *
 * Created on April 4, 2024, 11:07 PM
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <fstream>
#include <iomanip>

#include "record.h"
#include "client.h"
#include "artist.h"
#include "album.h"
#include "song.h"
#include "playlist.h"
#include "artistproduction.h"

using namespace std;

class Platform final : public AsignaMemoria {
private:
    Client** clients;
    Artist** artists;
    Album** albums;
    Song** songs;
    Playlist** playlists;
    
    int numClients;
    int numArtists;
    int numAlbums;
    int numSongs;
    int numPlaylists;
    
    template<typename T>
    T** loadRecords(
        const char*, 
        int&, 
        int (*)(const void*, const void*)
    );
    
    void openFile(const char*, ifstream&);
    void openFile(const char*, ofstream&);
public:
    Platform(const char*, const char*, const char*, const char*, const char*);
    
    Client** getClients();
    Artist** getArtists();
    Album** getAlbums();
    Song** getSongs();
    Playlist** getPlaylists();
    
    void writeArtistsProductionReport(const char*);
    
    template<typename T>
    void testLoad(T** records, void (*printHead)()) {
        printHead();

        for (int i = 0; records[i] != nullptr; i++) {
            records[i]->print();
        }
        cout << endl;
    }
    
    static void printClientHeader();
    static void printArtistHeader();
    static void printAlbumHeader();
    static void printSongHeader();
    static void printPlaylistHeader();
    
    ~Platform();
};

#endif /* PLATFORM_H */

