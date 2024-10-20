#include "TxtWriter.h"

TxtWriter::TxtWriter() = default;

void TxtWriter::newFile(const string& fileName) {
    ofstream file(fileName);
    if(file.is_open()){
        file << "";
        file.close();
    }
}

bool TxtWriter::loadFromFile(const string& fileName){
    bool isOpen = true;
    ifstream file(fileName);
    if(!file.is_open())
        isOpen = false;
    else{
        file >> txtData;
        file.close();
    }
    return isOpen;
}

bool TxtWriter::saveToFile(const string& fileName){
    bool isOpen = true;
    ofstream file(fileName);
    if (!file.is_open())
        isOpen = false;
    else{
        file << txtData;
        file.close();
    }
    return isOpen;
}

string TxtWriter::getTxtData() const{
    return txtData;
}

void TxtWriter::setTxtData(const string& data){
    txtData = data;
}