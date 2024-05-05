/* 
 * File:   record.h
 * Author: erichuiza
 *
 * Created on May 2, 2024, 6:21 PM
 */

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#include "AsignaMemoria.h"

using namespace std;

class Record : public AsignaMemoria {
private:
    int id;
    char* name;
public:
    int getId();
    char* getName();
    
    void readString(ifstream&, char*&, char=',');
    void readIntArray(const char*, int*&, int&);
    
    virtual void loadData(ifstream&);
    virtual void print();
    static int cmp(const void*, const void*);
    
//    bool equals(Record&);
//    bool compareTow(Record&, Record&);
    
    virtual ~Record();
};

#endif /* RECORD_H */

