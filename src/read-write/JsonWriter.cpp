#include "JsonWriter.h"
#include <fstream>


JsonWriter::JsonWriter() = default;

void JsonWriter::newFile(const string& fileName){
    ofstream file(fileName);
    if (file.is_open()) {
        file << "{}";
        file.close();
    }
}

bool JsonWriter::loadFromFile(const string& fileName){
    bool isOpen = true;
    ifstream file(fileName);
    if(!file.is_open())
        isOpen = false;
    else{
        file >> jsonData;
        file.close();
    }
    return isOpen;
}

bool JsonWriter::saveToFile(const string& fileName) {
    bool isOpen = true;
    ofstream file(fileName);
    if (!file.is_open())
        isOpen = false;
    else{
        file << jsonData.dump(4);
        file.close();
    }
    return isOpen;
}

json JsonWriter::getJson() const {
    return jsonData;
}

void JsonWriter::setJson(const json& jsonD){
    jsonData = jsonD;
}