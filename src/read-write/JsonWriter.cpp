#include "JsonWriter.h"
#include <fstream>

using json = nlohmann::json;

JsonWriter::JsonWriter() = default;

bool JsonWriter::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.json";
    ofstream archivoResultados(rutaCompleta);
    
    if (archivoResultados.is_open()) {
        json datos;
    }
    return estadoCreacion;
}

bool JsonWriter::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados_extra.json";
    ofstream archivoResultados(rutaCompleta);
    
    if (archivoResultados.is_open()) {
        json datos;

        // Añadir datos a imprimir
        for (const auto& fila : datosAImprimir) {
            json filaJson;
            for (const auto& elemento : fila) {
                filaJson.push_back(elemento);
            }
            datos["datos"].push_back(filaJson);
        }

        // Escribir el objeto JSON en el archivo
        archivoResultados << datos.dump(4); // 4 es el número de espacios para la indentación
        estadoCreacion = true;
        archivoResultados.close();
    }

    return estadoCreacion;
}