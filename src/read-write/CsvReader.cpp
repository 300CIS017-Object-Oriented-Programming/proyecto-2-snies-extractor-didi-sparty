#include "CsvReader.h"



vector<string> CsvReader::leerProgramasCsv()
{
    vector<string> codigosSniesRetorno;
    ifstream archivoProgramasCsv(Settings::PROGRAMAS_FILTRAR_FILE_PATH);
    if (!(archivoProgramasCsv.is_open()))
    {
        cout << "Archivo " << Settings::PROGRAMAS_FILTRAR_FILE_PATH << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string linea;
        string dato;
        // Saltarse la primera linea
        getline(archivoProgramasCsv, linea);
        // Leer los programas
        while (getline(archivoProgramasCsv, linea))
        {
            cout << "leyendo linea " << linea << endl;
            stringstream streamLinea(linea);
            if (getline(streamLinea, dato, Settings::DELIMITADOR))
            {
                try
                {
                    codigosSniesRetorno.push_back(dato);
                }
                catch (invalid_argument &e)
                {
                    cerr << "Error de conversión: " << e.what() << endl; // si es un dato invalido
                }
                catch (out_of_range &e)
                {
                    cerr << "Número fuera de rango " << e.what() << endl; // si es un numero que un int no puede soportar
                }
            }
        }
    }
    archivoProgramasCsv.close();
    return codigosSniesRetorno;
}

map<vector<vector<string>>> CsvReader::leerArchivo(string &nombreArchivo, vector<string> &codigosSnies){  // Saca los encabezados

    string ruta = Settings::INPUT_PATH.string() + nombreArchivo;
    Document archivo(ruta, LabelParams(0, 0), SeparatorParams(';'));  // Se crea un objeto tipo rapid csv
    
    map<string, string> auxMap;
    map<string, map<string, string>> res;

    vector<string> headers = archivo.GetColumnNames();

    for(vector<string>::iterator it = codigosSnies.begin(); it != codigosSnies.end(); it++){
        res[*it] = auxMap;
    }
    
    return res;
}
