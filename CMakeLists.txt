cmake_minimum_required(VERSION 3.19)
project(SNIES_extractor_V2)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

include_directories(include/csv-parser)

add_executable(SNIES_extractor_V2 src/Settings.h src/ProgramaAcademico.h src/ProgramaAcademico.cpp src/Consolidado.h src/Consolidado.cpp src/SNIESController.h src/SNIESController.cpp src/View.h src/View.cpp src/main.cpp
        src/read-write/CsvReader.cpp
        src/read-write/JsonWriter.cpp
        src/read-write/TxtWriter.cpp
        src/read-write/WriteManager.cpp
        src/read-write/CsvWriter.h
        src/read-write/CsvWriter.cpp)

