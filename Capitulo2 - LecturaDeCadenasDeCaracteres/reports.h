#ifndef REPORTS_H
#define REPORTS_H

#include <fstream>

using namespace std;

void showreport(ifstream&);
void writereport(ifstream&, ofstream&);

void showreportoptimized(ifstream&);
void readData(ifstream&, char *&, char='\n');

#endif

