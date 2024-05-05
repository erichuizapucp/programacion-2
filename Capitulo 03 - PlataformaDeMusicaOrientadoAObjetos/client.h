/* 
 * File:   client.h
 * Author: erichuiza
 *
 * Created on May 2, 2024, 6:12 PM
 */

#ifndef CLIENT_H
#define CLIENT_H

#include "record.h"

using namespace std;

class Client : public Record {
private:
    char* subscriptionDate;
    char* category;
public:
    void loadData(ifstream&) override;
    void print() override;
    
    ~Client() override;
};

#endif /* CLIENT_H */

