#include "client.h"
#include "album.h"

void Client::loadData(ifstream &file) {
    Record::loadData(file);
    readString(file, this->subscriptionDate, ',');
    readString(file, this->category, '\n');
}

void Client::print() {
    Record::print();
    cout << setw(30) << this->category
         << setw(30) << this->subscriptionDate << endl;
}

Client::~Client() {
    delete[] subscriptionDate;
    delete[] category;
}