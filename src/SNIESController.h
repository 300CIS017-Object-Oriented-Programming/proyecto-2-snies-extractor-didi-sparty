#ifndef SNIES_CONTROLLER_H
#define SNIES_CONTROLLER_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include "ProgramaAcademico.h"
#include "Consolidado.h"
#include "read-write/CsvReader.h"

using namespace std;

class SNIESController
{

private:
    map<int, ProgramaAcademico *> programasAcademicos;
    CsvReader CsvReaderObj;
    CsvWriter csvWriter;
    JsonWriter jsonWriter;
    TxtWriter txtWriter;
    vector<string> etiquetasColumnas;
    string rutaAdmitidos;
    string rutaGraduados;
    string rutaInscritos;
    string rutaMatriculados;
    string rutaMatriculadosPrimerSemestre;
    string rutaOutput;

public:
    SNIESController() = default;
    ~SNIESController();
    void procesarDatosCsv(string &, string &);
    void calcularDatosExtra(bool);
    void buscarProgramas(bool, string &, int);
    void consolidados(vector<string>&, vector<vector<string>>&);
    
};

#endif