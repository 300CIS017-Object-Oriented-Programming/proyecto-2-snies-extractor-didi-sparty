#include "WriteManager.h"

WriteManager::WriteManager() = default;

bool WriteManager::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas){return true;}
bool WriteManager::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas){return true;}
bool WriteManager::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir){return true;}