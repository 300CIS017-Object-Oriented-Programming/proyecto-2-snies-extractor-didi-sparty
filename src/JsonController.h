#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include <iostream>
#include "json.hpp"
#include <string>
#include "FileManager.h"

using json = nlohmann::json;
using namespace std;

class JsonController : public FileManager{
    private:
        json jsonData;
    public:
        JsonController();
        void newFile(const string&) override;
        bool loadFromFile(const string&) override;
        bool saveToFile(const string&) override;
        json getJson() const;
        void setJson(const json&);


};




#endif
