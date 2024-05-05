/* 
 * File:   song.h
 * Author: erichuiza
 *
 * Created on May 2, 2024, 6:13 PM
 */

#ifndef SONG_H
#define SONG_H

#include "record.h"

using namespace std;

class Song : public Record {
private:
    int duration;
    int album;
public:
    void loadData(ifstream&) override;
    void print() override;
};

#endif /* SONG_H */

