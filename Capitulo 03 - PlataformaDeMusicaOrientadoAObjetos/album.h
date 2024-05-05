/* 
 * File:   album.h
 * Author: erichuiza
 *
 * Created on May 2, 2024, 6:12 PM
 */

#ifndef ALBUM_H
#define ALBUM_H

#include "record.h"

using namespace std;

class Album : public Record {
private:
    int artist;
public:
    void loadData(ifstream&) override;
    void print() override;
    
    int getArtistId();
};

#endif /* ALBUM_H */

