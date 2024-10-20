#ifndef CSV_READER_H
#define CSV_READER_H

#include "FileManager.h"

using namespace std;

class CsvReader: public FileManger
{
public:
    CsvReader() = default;
    vector<int> leerProgramasCsv(string &ruta) override;
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies) override;
    vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
    
};

#endif