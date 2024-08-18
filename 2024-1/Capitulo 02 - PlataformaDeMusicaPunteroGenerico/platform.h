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

const void* loadClients(const char*, int&);
const void* loadArtists(const char*, int&);
const void* loadSongs(const char*, int&);
const void* loadAlbums(const char*, int&);
const void* loadPlaylists(const char*, int&);

const void* getArtistAlbums(const int&, 
                            const void* const&, 
                            const int&, 
                            int&);
const void* getArtistsProduction(const void* const&, 
                                 const int&, 
                                 const void* const&, 
                                 const int&);

void writeArtistsProductionReport(const char*, const void* const&, const int&);

void testClientLoad(const void* const&, int&);
void testArtistsLoad(const void* const&, int&);
void testSongsLoad(const void* const&, int&);
void testAlbumsLoad(const void* const&, int&);
void testPlaylistsLoad(const void* const&, int&);

#endif /* PLATFORM_H */

