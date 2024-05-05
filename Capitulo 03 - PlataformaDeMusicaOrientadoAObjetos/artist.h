/* 
 * File:   artist.h
 * Author: erichuiza
 *
 * Created on May 2, 2024, 6:12 PM
 */

#ifndef ARTIST_H
#define ARTIST_H

#include "record.h"
#include "album.h"

using namespace std;

class Artist : public Record {
private:
    char* genre;
public:
    Artist();
    
    Album** getArtistAlbums(Album**&, int&);
    void loadData(ifstream&) override;
    void print() override;
    
    ~Artist() override;
};

#endif /* ARTIST_H */

