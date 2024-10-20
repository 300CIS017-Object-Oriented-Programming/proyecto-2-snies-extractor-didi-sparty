#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
using namespace std;

class WriteManager{
    public:
        WriteManager();
        vector<int> leerProgramasCsv(string &ruta);
        vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
        vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
        vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
        virtual void newFile(const string&) = 0;
        virtual bool loadFromFile(const string&) = 0;
        virtual bool saveToFile(const string&) = 0;

};

#endif