
#include "artistproduction.h"
#include "artist.h"

ArtistProduction::ArtistProduction(Artist** &artists, Album** &albums, int numArtists) {
    int* artistsIds = new int[numArtists];
    int* numAlbumsPerArtist = new int[numArtists];
    char** artistsNames = new char*[numArtists];
    char*** artistsAlbumNames = new char**[numArtists];
    
    for (int artistIndex = 0; artistIndex < numArtists; artistIndex++) {
        Artist* artist = artists[artistIndex];
        
        const int artistId = artist->getId();
        artistsIds[artistIndex] = artistId;
        artistsNames[artistIndex] = artist->getName();
        
        int numArtistAlbums;
        Album** artistAlbums = artist->getArtistAlbums(albums, numArtistAlbums);
        
        numAlbumsPerArtist[artistIndex] = numArtistAlbums;
        
        char** albumNames = new char*[numArtistAlbums];
        for (int albumIndex = 0; albumIndex < numArtistAlbums; albumIndex++) {
            struct Album* album = (struct Album*)artistAlbums[albumIndex];
            albumNames[albumIndex] = album->getName();
        }
        
        artistsAlbumNames[artistIndex] = albumNames;
    }
    
    this->artistId = artistsIds;
    this->artistName = artistsNames;
    this->artistAlbums = artistsAlbumNames;
    this->numArtistAlbums = numAlbumsPerArtist;
}

int* ArtistProduction::getArtistId() {
    return artistId;
}

char** ArtistProduction::getArtistName() {
    return artistName;
}

char*** ArtistProduction::getArtistAlbums() {
    return artistAlbums;
}

int* ArtistProduction::getNumArtistAlbums() {
    return numArtistAlbums;
}

ArtistProduction::~ArtistProduction() {
    delete[] artistId;
    delete[] numArtistAlbums;
    
    delete[] artistName;
    delete[] artistAlbums;
}