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

void loadClients(const char*, struct Client*&, int&);
void loadArtists(const char*, struct Artist*&, int&);
void loadSongs(const char*, struct Song*&, int&);
void loadAlbums(const char*, struct Album*&, int&);
void loadPlaylists(const char*, struct Playlist*&, int&);

const struct ArtistsProduction* getArtistProduction(const struct Artist*&, const int&, const struct Album*&, int&);
const struct ClientPreferences* getClientPreferences(const struct Client*&, const struct Playlist*&, const struct Song*&);
const struct Album* getAlbumsByArtist(const struct Album*&, const int&, const int&, int&);

#endif /* PLATFORM_H */

