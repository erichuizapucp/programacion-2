/* 
 * File:   playlist.h
 * Author: erichuiza
 *
 * Created on May 2, 2024, 6:13 PM
 */

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "record.h"

using namespace std;

class Playlist : public Record {
private:
    int clientId;
    int* songs;
    int numSongs;
public:
    void loadData(ifstream&) override;
    void print() override;
    
    ~Playlist() override;
};

#endif /* PLAYLIST_H */

