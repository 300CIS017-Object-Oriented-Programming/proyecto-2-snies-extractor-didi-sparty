//
// Created by Samuel Bonilla on 20/10/2024.
//

#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include "../ProgramaAcademico.h"
#include "../Consolidado.h"
#include "WriteManager.h"

using namespace std;

class CsvWriter : public WriteManager {
public:
    CsvWriter() = default;
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas);
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir);
};







#endif //CSVWRITER_H
