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
#include "../Settings.h"
#include "../ProgramaAcademico.h"

using namespace std;

class WriteManager{
    public:
        WriteManager();
        ~WriteManager();
        virtual bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas) = 0;
        virtual bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) = 0;
        virtual bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir);
};

#endif