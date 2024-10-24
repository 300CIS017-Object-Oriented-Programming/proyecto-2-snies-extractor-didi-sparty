#include "JsonWriter.h"
#include <fstream>


JsonWriter::JsonWriter() = default;
bool JsonWriter::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas) {
    ofstream file(ruta);
    if (file.is_open()) {
        file << "{}";
        file << jsonData.dump(4);
        file.close();
    }
    return true;
}
bool JsonWriter::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) {
    return true;
}


bool JsonWriter::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir){return true;}




