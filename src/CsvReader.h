#ifndef CSV_READER_H
#define CSV_READER_H

#include "FileManager.h"

using namespace std;

class CsvReader: public FileManger
{
public:
    CsvReader() = default;
    virtual vector<int> leerProgramasCsv(string &ruta) override;
    virtual vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies) override;
    virtual vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
    virtual vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
};

#endif