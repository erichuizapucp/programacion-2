/* 
 * File:   platform.h
 * Author: erichuiza
 *
 * Created on April 4, 2024, 11:07 PM
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#include "utils.h"
#include "structs.h"
#include <iomanip>

void* readClientData(ifstream&);
void* readArtistData(ifstream&);
void* readAlbumData(ifstream&);
void* readSongData(ifstream&);
void* readPlaylistData(ifstream&);
const void* loadRecords(
    const char*, 
    int&, 
    void*(*)(ifstream&)
);

const void* getArtistAlbums(
    const int&, 
    const void* const&, 
    const int&, 
    int&
);
const void* getArtistsProduction(
    const void* const&, 
    const int&, 
    const void* const&, 
    const int&
);

void writeArtistsProductionReport(
    const char*, 
    const void* const&, 
    const int&
);

void testClientLoad(
    const void* const&, 
    int&
);
void testArtistsLoad(
    const void* const&, 
    int&
);
void testSongsLoad(
    const void* const&, 
    int&
);
void testAlbumsLoad(
    const void* const&, 
    int&
);
void testPlaylistsLoad(
    const void* const&, 
    int&
);

void freeMemory(
    const void* const&, 
    const void* const&, 
    const void* const&, 
    const void* const&, 
    const void* const&, 
    const void* const&, 
    int&, 
    int&, 
    int&, 
    int&, 
    int&
);

#endif /* PLATFORM_H */

