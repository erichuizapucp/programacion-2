/* 
 * File:   artistproduction.h
 * Author: erichuiza
 *
 * Created on May 2, 2024, 6:13 PM
 */

#ifndef ARTISTPRODUCTION_H
#define ARTISTPRODUCTION_H

#include "artist.h"
#include "album.h"

class ArtistProduction final {
private:
    int *artistId;
    char **artistName;
    char ***artistAlbums;
    int *numArtistAlbums;
public:
    ArtistProduction(Artist**&, Album**&, int);
    
    int* getArtistId();
    char** getArtistName();
    char*** getArtistAlbums();
    int* getNumArtistAlbums();
    
    ~ArtistProduction();
};

#endif /* ARTISTPRODUCTION_H */

