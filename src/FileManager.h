#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include "ProgramaAcademico.h"
#include "Consolidado.h"

using namespace std;

class FileManger
{
public:
    FileManger() = default;
    virtual vector<int> leerProgramasCsv(string &ruta) = 0;
    virtual vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies) = 0;
};

#endif