#ifndef TXTWRITER_H
#define TXTWRITER_H


#include <iostream>
#include "WriteManager.h"


class TxtWriter : public WriteManager{
    private:
        string txtData;
    public:
        TxtWriter();
        bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas) override;
        bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) override;
        bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) override;
};


#endif