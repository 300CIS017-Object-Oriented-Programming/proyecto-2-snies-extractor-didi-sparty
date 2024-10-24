#ifndef JSON_WRITER_H
#define JSON_WRITER_H

#include <iostream>
#include "../../include/json.hpp"
#include <string>
#include "WriteManager.h"

using json = nlohmann::json;
using namespace std;

class JsonWriter : public WriteManager{
    private:
        json jsonData;
    public:
        JsonWriter();
        bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas) override;
        bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) override;
        bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) override;


};




#endif
