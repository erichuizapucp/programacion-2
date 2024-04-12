#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

void leeDatosExactos(int *&datos, int &numDat) { 
    int buff[1000];
    numDat=0; 
    
    while(1) {
      cin >> buff[numDat];
      if(cin.eof()) {
          break;
      }
      numDat++;
    } 
    
    datos = new int [numDat]; 
    for(int i = 0; i < numDat; i++) {
        datos[i] = buff[i];
    }
}

 void imprimeDatos(const int *datos, int numDat) { 
     for (int i = 0; i < numDat; i++) {
         cout<<setw(5)<<datos[i];
     }
     cout<<endl;
 }
   
  