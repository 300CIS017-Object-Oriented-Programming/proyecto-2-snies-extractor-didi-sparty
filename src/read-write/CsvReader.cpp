#include "CsvReader.h"




vector<string> CsvReader::leerProgramasCsv() {
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

map<string, vector<vector<string>>> leerArchivo(string &nombreArchivo, vector<string> &codigosSnies) {

    map<string, vector<vector<string>>> out;
    string ruta = Settings::INPUT_PATH.string() + nombreArchivo;
    Document doc(ruta, LabelParams(0,0),SeparatorParams(';'));




    vector<string> columnaCodigos = doc.GetColumn<string>("CÓDIGO SNIES DEL PROGRAMA");
    vector<string> header = doc.GetColumnNames();

    out["HEAD"] = vector<vector<string>>(1, header);

    map<string, vector<string>> tabla;
    for (const auto &c : header) {
        tabla[c] = doc.GetColumn<string>(c);
    }
    int i = 0;
    for (const auto &codeCsv : columnaCodigos) {
        for (const auto &codeSearch : codigosSnies) {
            if (codeCsv == codeSearch) {
                if (out.find(codeCsv) != out.end()) {
                    out[codeCsv].push_back(returnFila(tabla, header, i));
                }else {
                    vector<vector<string>> aux;
                    aux.push_back(returnFila(tabla, header, i));
                    out[codeCsv] = aux;
                }

            }
            i++;
        }
    }

    return out;
}
