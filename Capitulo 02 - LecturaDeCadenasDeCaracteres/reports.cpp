#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int code_size = 10;
int name_size = 50;
int subjects_size = 30;
int scores_size = 30;

int line_size = code_size + name_size + subjects_size + scores_size;

void readData(ifstream& input, char *&data, char delim) {
    char buffer[50];
    input.getline(buffer, 50, delim);
    
    data = new char[strlen(buffer) + 1];
    strcpy(data, buffer);
}

void showreportoptimized(ifstream& input) {
    cout << "REPORTE DE ESTUDIANTES" << endl << endl;
    cout << "Código" << "\t" << "Nombre\t" << "Cursos\t" << "Notas" << endl;    
    
    char* code;
    char* name;
    char* subjects;
    char* scores;
    
    while (!input.eof()) {
        readData(input, code, ',');
        cout << code << "\t";
        
        readData(input, name, ',');
        cout << name << "\t";
        
        readData(input, subjects, ',');
        cout << subjects << "\t";
        
        readData(input, scores, '\n');
        cout << scores << "\t";
        
        cout << endl;
    }
    
    delete[] code;
    delete[] name;
    delete[] subjects;
    delete[] scores;
}

void showreport(ifstream& input) {
    cout << "REPORTE DE ESTUDIANTES" << endl << endl;
    cout << "Código" << "\t" << "Nombre\t" << "Cursos\t" << "Notas" << endl;    
    
    char code[code_size];
    char name[name_size];
    char subjects[subjects_size];
    char scores[scores_size];
    
    while (!input.eof()) {
        input.getline(code, code_size, ',');
        cout << code << "\t";
        
        input.getline(name, name_size, ',');
        cout << name << "\t";
        
        input.getline(subjects, subjects_size, ',');
        cout << subjects << "\t";
        
        input.getline(scores, scores_size, '\n');
        cout << scores << "\t";
        
        cout << endl;
    }
}

void writereport(ifstream& input, ofstream& output) {
    cout << "Se escribió el reporte en el archivo reporte.txt" << endl;
            
    // Colocarse al inicio del archivo de entrada
    input.clear();
    input.seekg(0, ios::beg);
    
    output << "Código" << "\t" << "Nombre\t" << "Cursos\t" << "Notas" << endl;    
    char code[code_size];
    char name[name_size];
    char subjects[subjects_size];
    char scores[scores_size];
    
    while (!input.eof()) {
        input.getline(code, code_size, ',');
        output << code << "\t";
        
        input.getline(name, name_size, ',');
        output << name << "\t";
        
        input.getline(subjects, subjects_size, ',');
        output << subjects << "\t";
        
        input.getline(scores, scores_size, '\n');
        output << scores << "\t";
        
        output << endl;
    }
}