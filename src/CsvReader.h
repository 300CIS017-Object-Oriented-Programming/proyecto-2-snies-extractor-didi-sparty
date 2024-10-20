#ifndef CSV_READER_H
#define CSV_READER_H


using namespace std;

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include "ProgramaAcademico.h"
#include "Consolidado.h"

class CsvReader
{
public:
    CsvReader() = default;
    vector<int> leerProgramasCsv(string &ruta);
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
    // vector<map<string, string>> leerArchivoFlexible(string &rutaBase, string &ano);
};

#endif