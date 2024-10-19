#include "JsonController.h"
#include <fstream>


JsonController::JsonController() = default;

void JsonController::newFile(const string& fileName){
    ofstream file(fileName);
    if (file.is_open()) {
        file << "{}";
        file.close();
    }
}

bool JsonController::loadFromFile(const string& fileName){
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

bool JsonController::saveToFile(const string& fileName) {
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

json JsonController::getJson() const {
    return jsonData;
}

void JsonController::setJson(const json& jsonD){
    jsonData = jsonD;
}