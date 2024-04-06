/* 
 * File:   structs.h
 * Author: erichuiza
 *
 * Created on April 4, 2024, 10:46 PM
 */

#ifndef STRUCTS_H
#define STRUCTS_H

struct Client {
    int id;
    char* name;
    char* subscriptionDate;
    char* category;
};

struct Artist {
    int id;
    char* name;
    char* genre;
};

struct Album {
    int id;
    int artist;
    char* name;
};

struct Song {
    int id;
    int duration;
    int album;
    char* name;
};

struct Playlist {
    int id;
    int clientId;
    char* name;
    int* songs;
    int numSongs;
};

struct ArtistsProduction {
    int *artistId;
    char **artistName;
    char ***artistAlbums;
};

struct ClientPreferences {
    int *clientId;
    char **clientName;
    char ***songs;
};

#endif /* STRUCTS_H */

