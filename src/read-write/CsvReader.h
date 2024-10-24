#ifndef CSV_READER_H
#define CSV_READER_H


using namespace std;

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include "../ProgramaAcademico.h"
#include "../Consolidado.h"
#include "../Settings.h"
#include "../../include/rapidcsv.h"
#include "../Utility.h"

using namespace rapidcsv;
using namespace std;

class CsvReader {
public:
    CsvReader() = default;

    vector<string> leerProgramasCsv();
    /*
    * inputs el nombre completo del archivo Ej: admitidos2021.csv y un vector con todos los codigos SNIES que esta filtrando
    * outputs un maopa con llavves los codigos SNIES y valor otro mapa con llaves el nombre de cada columna y valores los datos
    */
    map<string, vector<vector<string>>> leerArchivo(string &nombreArchivo, vector<string> &codigosSnies);
    
};

#endif