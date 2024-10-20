//
// Created by Samuel Bonilla on 19/10/2024.
//
#include "Settings.h"

// Declaración:
// Inicialización: La inicialización de estas variables se realiza fuera de la clase. Esto es necesario porque las variables estáticas deben ser definidas en un solo lugar en el archivo de implementación (o en el mismo archivo, pero fuera de la clase) para que el compilador sepa cuánto espacio reservar en memoria.
const fs::path Settings::BASE_PATH = fs::current_path() / fs::path(R"(..\docs\)");
const fs::path Settings::PROGRAMAS_FILTRAR_FILE_PATH = BASE_PATH / fs::path(R"(inputs\programas.csv)");
const fs::path Settings::INPUT_PATH = BASE_PATH / fs::path(R"(inputs\)");
const fs::path Settings::OUTPUT_PATH = BASE_PATH / fs::path(R"(outputs\)");

const char Settings::DELIMITADOR = ';';