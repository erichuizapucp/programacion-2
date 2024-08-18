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

const struct Client* loadClients(const char*, int&);
const struct Artist* loadArtists(const char*, int&);
const struct Song* loadSongs(const char*, int&);
const struct Album* loadAlbums(const char*, int&);
const struct Playlist* loadPlaylists(const char*, int&);

const struct Album* getArtistAlbums(const int&, 
                                    const struct Album* const&, 
                                    const int&, 
                                    int&);
const struct ArtistsProduction* getArtistsProduction(const struct Artist* const&, 
                                                     const int&, 
                                                     const struct Album* const&, 
                                                     const int&);
const struct ClientPreferences* getClientPreferences(const struct Client*&, 
                                                     const struct Playlist*&, 
                                                     const struct Song*&);

void writeArtistsProductionReport(const char*, const struct ArtistsProduction* const&, const int&);

#endif /* PLATFORM_H */

